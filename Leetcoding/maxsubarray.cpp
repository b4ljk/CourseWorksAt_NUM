#include <iostream>
#include <vector>
using namespace std;

vector<int> max_subarray(vector<int> &nums) {
  int max_so_far = nums[0];
  int max_ending_here = 0;
  int start = 0, end = 0, s = 0;
  for (int i = 0; i < nums.size(); i++) {
    max_ending_here += nums[i];
    if (max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start = s;
      end = i;
    }
    if (max_ending_here < 0) {
      max_ending_here = 0;
      s = i + 1;
    }
  }
  return vector<int>(nums.begin() + start, nums.begin() + end + 1);
}

int main() {
  int n;
  cout << "nums ? \t";
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<int> max_subarr = max_subarray(nums);
  cout << "maxsubarray: [ ";
  for (auto num : max_subarr) {
    cout << num << " ";
  }
  cout << "]" << endl;
  return 0;
}
