#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  // input
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> dp(n);
  dp[0] = nums[0];
  int maxNum = dp[0];
  int firstIndex, lastIndex;
  for (int i = 1; i < n; i++) {
    // 0 ali ashigtaig ni dp arraydaa hadgalaad yvna
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    maxNum = max(maxNum, dp[i]);
  }
}
