#include "bits/stdc++.h"
#include <cstring>
#include <vector>
using namespace std;
int main() {
  // KNAPSACK-tai adil bodlogo baina
  int n, m;
  cin >> n >> m;
  vector<int> coins;
  for (int i = 1; i <= m; i++) {
    int val;
    cin >> val;
    coins.push_back(val);
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= n; i++) {
      dp[i] += dp[i - coin];
    }
  }
  cout << dp[n];

  return 0;
}