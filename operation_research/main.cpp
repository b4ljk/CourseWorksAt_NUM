#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

double reverse(double n) { return 1 / n; }
double column(double n, double cnt) { return n / cnt; }
double rowc(double n, double cnt) { return -(n / cnt); }
double other(double cnt, double b, double c, double d) {
  return ((cnt * b) - (d * c)) / cnt;
}
void copy(vector<vector<double>> &rs, queue<double> temp) {
  for (int i = 0; i < rs.size(); i++) {
    for (int j = 0; j < rs[i].size(); j++) {
      rs[i][j] = temp.front();
      temp.pop();
    }
  }
}
void printMatrix(int col, int row, vector<vector<double>> rs) {
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      cout << rs[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  cout << "heden huvisagch : ";
  int n;
  vector<string> row;
  vector<string> col;
  cin >> n;
  for (int i = 0; i < n; i++) {
    row.push_back("x" + to_string(i + 1));
  }
  cout << "heden ilerhiilel : ";
  int m;
  cin >> m;
  vector<vector<double>> matrix(m, vector<double>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == n) {
        cout << "hariu : ";
        string temp;
        cin >> temp;
        col.push_back(temp);
      } else {
        cout << "x" << j + 1 << " = ";
        cin >> matrix[i][j];
      }
    }
  }
  // ilerhiilliin toogoor bodolt hiigdne
  for (int i = 0; i < m; i++) {
    if (i == n) {
      break;
    }
    string temp;
    temp = col[i];
    col[i] = row[i];
    row[i] = temp;
    queue<double> copies;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        // bodolt is here
        if (j == i && k == i) {
          copies.push(reverse(matrix[j][k]));
        } else if (j == i) {
          copies.push(column(matrix[j][k], matrix[i][i]));
        } else if (k == i) {
          copies.push(rowc(matrix[j][k], matrix[i][i]));
        } else {
          copies.push(
              other(matrix[i][i], matrix[j][k], matrix[j][i], matrix[i][k]));
        }
      }
    }
    copy(matrix, copies);
    printMatrix(m, n, matrix);
  }
  for (int i = 0; i < m; i++) {
    double result;
    string resultStr;
    for (int j = 0; j < n; j++) {
      if (j >= m) {
        resultStr =
            resultStr + " + " + to_string(matrix[i][j]) + " * " + row[j];
      } else {
        result = result + matrix[i][j] * stod(row[j]);
        resultStr = to_string(result);
      }
    }
    if (n > m) {
      cout << col[i] << " = " << resultStr << endl;
    } else {
      cout << col[i] << " = " << result << endl;
    }
  }
  return 0;
}