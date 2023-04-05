#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN], points[MAXN][MAXN], walls[MAXN][MAXN];
int max_scores[MAXN][MAXN];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> points[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> walls[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (walls[i][j] == 0) {
        max_scores[i][j] = points[i][j];
      } else {
        max_scores[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (walls[i][j] == 1) {
        for (int k = 0; k < i; k++) {
          for (int l = 0; l < j; l++) {
            if (walls[k][l] == 0) {
              int score = dp[k][l] + points[i][j];
              max_scores[k][l] = max(max_scores[k][l], score);
            }
          }
        }
      }
    }
  }

  dp[0][0] = points[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (walls[i][j] == 1) {

        for (int k = 0; k < i; k++) {
          for (int l = 0; l < j; l++) {
            if (max_scores[k][l] >= 0) {
              int score = max_scores[k][l] + dp[i][j];
              dp[i][j] = max(dp[i][j], score);
            }
          }
        }
      } else {
        dp[i][j] += points[i][j];
      }
    }
  }

  cout << dp[n - 1][m - 1] << endl;

  return 0;
}
