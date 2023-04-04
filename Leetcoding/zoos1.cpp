#include "bits/stdc++.h"
using namespace std;
int main() {
  // aldaagui buh testendeer ajillaa.

  int n, m;
  cin >> n >> m;
  int coin[m];
  for (int i = 0; i < m; i++) {
    cin >> coin[i];
  }
  int dp[n + 1];
  // dp array-g max-r duurgej bgaa `n` ni uuruu maximum zadlah too ym
  for (int i = 0; i <= n; i++) {
    dp[i] = INT_MAX - 1;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      // ene if nuhtsul array ehelj bhad arrayn hemjeenees garahaas sergiilne
      if (coin[j] <= i) {
        // odoogin dp-n utga odoogiin `j` coiniig ashiglan umnu ni hamgiin
        // bagaar zadalj chadsan utgiin ali min-g avna yagaad gevel `j` shirheg
        // coin deer ene uildliig hiihed hamgiin baga ni l `dp[i]` deer ochno
        dp[i] = min(dp[i - coin[j]] + 1, dp[i]);
      }
    }
  }

  int output = (dp[n] == INT_MAX - 1) ? -1 : dp[n];
  cout << output;

  return 0;
}