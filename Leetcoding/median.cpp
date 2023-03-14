#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right) {
  int pivot = nums[right];
  int i = left - 1;
  for (int j = left; j <= right - 1; j++) {
    if (nums[j] < pivot) {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[right]);
  return i + 1;
}

int findMedian(vector<int> &nums) {
  int n = nums.size();
  int left = 0, right = n - 1, mid = (n - 1) / 2;

  while (left <= right) {
    int pivotIndex = partition(nums, left, right);
    if (pivotIndex == mid) {
      return nums[pivotIndex];
    } else if (pivotIndex < mid) {
      left = pivotIndex + 1;
    } else {
      right = pivotIndex - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cout << "nums ? \t";
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int median = findMedian(nums);
  cout << "Median: " << median << endl;
  return 0;
}
