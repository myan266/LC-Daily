// Solution 1:
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> memo(366, 0);

        int dayIndex = 0;

        for (int d = 1; d <= 365; d++) {
            if (dayIndex < n && days[dayIndex] == d) {
                // travel day
                memo[d] = memo[d - 1] + costs[0]; // Buy a 1-day pass
                memo[d] = min(memo[d], memo[max(0, d - 7)] + costs[1]); // Buy a 7-day pass
                memo[d] = min(memo[d], memo[max(0, d - 30)] + costs[2]); // Buy a 30-day pass
                dayIndex++;
            } else {
                memo[d] = memo[d - 1];
            }
        }

        return memo[365];
    }
};

// Solution 2:
class Solution {
private:
    const vector<int> tick = {1, 7, 30};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> memo(n + 1, vector<int>(30, 5e5)); // Memo table: ith day, j extra days

        memo[0][0] = 0;
        int min_sol = 5e5;
        for (int i = 1; i <= n; i++) {
            int gap = (i == 1 ? days[i - 1] : days[i - 1] - days[i - 2]);

            min_sol = 5e5;
            for (int j = 0; j < 30; j++) {
                // If extra days cover the gap
                if (j >= gap) {
                    int remaining = j - gap;
                    memo[i][remaining] = min(memo[i][remaining], memo[i - 1][j]);
                }
                min_sol = min(min_sol, memo[i-1][j]);
            }

            // Buy new tickets
            for (int t = 0; t < 3; t++) {
                int extra = tick[t] - 1;
                memo[i][extra] = min(memo[i][extra], min_sol + costs[t]);
            }
        }

        return *min_element(memo[n].begin(), memo[n].end());
    }
};
