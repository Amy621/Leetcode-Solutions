package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"os/exec"
	"strings"

	"golang.org/x/text/cases"
	"golang.org/x/text/language"
)

var notionToken = os.Getenv("NOTION_TOKEN")
var notionDBID = os.Getenv("NOTION_DB_ID")

type QueryResponse struct {
	Results []struct {
		ID string `json:"id"`
	} `json:"results"`
}

func formatProblemName(filename string) string {
	// remove extension
	slug := strings.Split(filename, ".")[0] // "0001-two-sum"

	// remove numeric prefix
	parts := strings.SplitN(slug, "-", 2)
	if len(parts) > 1 {
		slug = parts[1] // "two-sum"
	}

	// replace dashes with spaces
	words := strings.Split(slug, "-")

	// create a Unicode-aware title caser
	caser := cases.Title(language.English)

	for i, w := range words {
		words[i] = caser.String(w) // "two" -> "Two"
	}
	return strings.Join(words, " ") // "Two Sum"
}

func main() {
	// Get changed files in last commit
	cmd := exec.Command("git", "show", "--name-only", "--pretty=", "HEAD")
	out, err := cmd.Output()
	if err != nil {
		panic(err)
	}

	files := strings.Split(strings.TrimSpace(string(out)), "\n")

	for _, file := range files {
		parts := strings.Split(file, "/")
		if len(parts) < 2 {
			continue
		}

		folderName := parts[0]                // "0001-two-sum"
		slug := formatProblemName(folderName) // "Two Sum"

		fmt.Println("Processing:", slug)

		pageID := queryNotion(slug)
		if pageID != "" {
			updateNotion(pageID)
			fmt.Println("✅ Updated:", slug)
		} else {
			fmt.Println("⚠️ Not found in Notion:", slug)
		}
	}
}

func queryNotion(slug string) string {
	body := map[string]any{
		"filter": map[string]any{
			"property": "Title",
			"rich_text": map[string]string{
				"equals": slug,
			},
		},
	}
	b, _ := json.Marshal(body)

	req, _ := http.NewRequest("POST",
		fmt.Sprintf("https://api.notion.com/v1/databases/%s/query", notionDBID),
		bytes.NewBuffer(b),
	)
	req.Header.Set("Authorization", "Bearer "+notionToken)
	req.Header.Set("Content-Type", "application/json")
	req.Header.Set("Notion-Version", "2022-06-28")

	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()

	var qr QueryResponse
	json.NewDecoder(resp.Body).Decode(&qr)

	if len(qr.Results) > 0 {
		return qr.Results[0].ID
	}
	return ""
}

func updateNotion(pageID string) {
	body := map[string]any{
		"properties": map[string]any{
			"Status": map[string]bool{
				"checkbox": true,
			},
		},
	}
	b, _ := json.Marshal(body)

	req, _ := http.NewRequest("PATCH",
		fmt.Sprintf("https://api.notion.com/v1/pages/%s", pageID),
		bytes.NewBuffer(b),
	)
	req.Header.Set("Authorization", "Bearer "+notionToken)
	req.Header.Set("Content-Type", "application/json")
	req.Header.Set("Notion-Version", "2022-06-28")

	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		bodyResp, _ := io.ReadAll(resp.Body)
		fmt.Println(string(bodyResp))

	}
	defer resp.Body.Close()
	if resp.StatusCode >= 200 && resp.StatusCode < 300 {
		fmt.Println("✅ Notion page updated successfully:", pageID)
	} else {
		bodyResp, _ := io.ReadAll(resp.Body)
		fmt.Printf("❌ Failed to update Notion page. Status: %s, Response: %s\n", resp.Status, string(bodyResp))
	}
}
