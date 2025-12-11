class Solution {
public:
    // Condition: There must be a building on the same y-axis with one smaller
    // x-cord and one bigger x-cord to target There must be a building on the
    // same x-axis with one smaller y-cord and one bigger y-cord to target

    // For each x-cord, store each y-cord on that axis

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> x;
        unordered_map<int, set<int>> y;

        int len = buildings.size();

        for (int i = 0; i < len; i++) {
            x[buildings[i][0]].insert(buildings[i][1]);
            y[buildings[i][1]].insert(buildings[i][0]);
        }

        int cnt = 0;

        for (int i = 0; i < len; i++) {
            int x_val = buildings[i][0];
            int y_val = buildings[i][1];

            auto it = x[x_val].upper_bound(y_val);
            auto it2 = x[x_val].lower_bound(y_val);
            auto it3 = y[y_val].upper_bound(x_val);
            auto it4 = y[y_val].lower_bound(x_val);
            if (it != x[x_val].end() && it3 != y[y_val].end()) {

                if (it2 != x[x_val].begin() && it4 != y[y_val].begin()) {
                    if (it2 != x[x_val].end() && it4 != y[y_val].end()) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
        };