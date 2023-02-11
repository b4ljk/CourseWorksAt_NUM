#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

double urvuu(double n) { return 1 / n; }
double column(double n, double cnt) { return n / cnt; }
double row(double n, double cnt) { return -(n / cnt); }
double other(double cnt, double b, double c, double d) {
  return ((cnt * b) - (d * c)) / cnt;
}
void copy(double rs[4][4], queue<double> temp) {
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      rs[i][j] = temp.front();
      temp.pop();
    }
  }
}

int main() {
  cout << "heden huvisagch ? ";
  int n;
  vector<string> row;
  vector<string> col;
  cin >> n;
  vector<vector<double>> matrix;
  for (int i = 0; i < n; i++) {
    row.push_back("x" + to_string(i));
  }
  cout << "heden ilerhiilel ?";
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == n) {
        cout << "hariu : ";
        cin >> col[i];
      } else {
        cout << "x" << j << " = ";
        cin >> matrix[i][j];
      }
    }
  }

  return 0;
}