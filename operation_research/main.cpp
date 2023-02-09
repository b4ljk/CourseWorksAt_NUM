#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

double negativePower(double n) { return pow(n, -1); }
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
  double rs[4][4];

  rs[0][1] = 0;
  rs[0][2] = 0;
  rs[0][3] = 0;

  rs[1][0] = 6.0;
  rs[2][0] = 14.0;
  rs[3][0] = 2.0;

  rs[1][1] = 1.0;
  rs[2][1] = 1.0;
  rs[3][1] = 1.0;

  rs[1][2] = 1.0;
  rs[2][2] = 2.0;
  rs[3][2] = -1.0;

  rs[1][3] = 1.0;
  rs[2][3] = 3.0;
  rs[3][3] = 1.0;

  for (int i = 1; i < 4; i++) {
    rs[0][i] = rs[i][0];
    queue<double> temp;
    for (int k = 1; k < 4; k++) {
      for (int j = 1; j < 4; j++) {
        if (i == k && i == j) {
          temp.push(negativePower(rs[k][j]));
        } else if (i == k) {
          temp.push(column(rs[k][j], rs[i][i]));
        } else if (i == j) {
          temp.push(row(rs[k][j], rs[i][i]));
        } else {
          temp.push(other(rs[i][i], rs[k][j], rs[k][i], rs[i][j]));
        }
      }
    }
    copy(rs, temp);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << rs[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 1; i < 4; i++) {
    double total = 0;
    for (int j = 1; j < 4; j++) {
      total = total + (rs[i][j] * rs[0][j]);
    }
    cout << total << endl;
  }

  return 0;
}