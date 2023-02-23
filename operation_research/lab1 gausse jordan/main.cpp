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
void printMatrix(int col, int row, vector<vector<double>> rs,
                 vector<string> matrixColumn, vector<string> matrixRow) {
  for (int i = 0; i < col; i++) {
    if (i == 0) {
      cout << "\t";
      for (int j = 0; j < row; j++) {
        cout << matrixRow[j] << "\t";
      }
      cout << endl;
    }
    cout << matrixColumn[i] << "\t";
    for (int j = 0; j < row; j++) {
      cout << rs[i][j] << "\t";
    }
    cout << endl;
  }
}

void printResult(int n, int m, vector<vector<double>> &matrix,
                 vector<string> &row, vector<string> &col) {

  for (int i = 0; i < m; i++) {
    double result = 0;
    string resultStr;
    for (int j = 0; j < n; j++) {
      if (j >= m) {
        resultStr =
            resultStr + " + " + to_string(matrix[i][j]) + " * " + row[j];
      } else {
        try {
          result = result + matrix[i][j] * stod(row[j]);
          resultStr = to_string(result);
        } catch (...) {
        }
      }
    }
    if (n > m) {
      cout << col[i] << " = " << resultStr << endl;
    } else {
      cout << col[i] << " = " << result << endl;
    }
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
      // shaardalagatai huvisagchuud utga onoogdson gej uzne
      break;
    }
    if (matrix[i][i] == 0) {
      // herev gol huvisagch tegtei tentsuu bol ?
      int rowval = i;

      while (matrix[i][rowval] == 0) {
        rowval++;
        if (rowval >= n) {
          double result = 0;
          int resx;
          for (resx = 0; resx < n; resx++) {
            try {
              result += matrix[i][resx] * stod(row[resx]);
            } catch (...) {
              break;
            }
          }
          if (result == stod(col[i])) {
            printResult(n, resx, matrix, row, col);
          } else {
            cout << "\nniitsgui\n";
          }
          return 0;
        }
      }
      for (int colval = 0; colval < m; colval++) {
        double temp = matrix[colval][i];
        matrix[colval][i] = matrix[colval][rowval];
        matrix[colval][rowval] = temp;
      }
      // huvisagchiig uurchluh (vector dotorh)
      string temp = row[i];
      row[i] = row[rowval];
      row[rowval] = temp;
      cout << "------------\n";
      printMatrix(m, n, matrix, col, row);
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

          copies.push(rowc(matrix[j][k], matrix[i][i]));

        } else if (k == i) {

          copies.push(column(matrix[j][k], matrix[i][i]));

        } else {
          copies.push(
              other(matrix[i][i], matrix[j][k], matrix[j][i], matrix[i][k]));
        }
      }
    }
    copy(matrix, copies);
    printMatrix(m, n, matrix, col, row);
    cout << "--------------------------\n";
  }

  printResult(n, m, matrix, row, col);
  return 0;
}