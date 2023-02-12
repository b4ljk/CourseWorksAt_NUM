#include "stack"
#include <iostream>
using namespace std;
int main() {
  class Solution {
  public:
    char parent(char sc) {
      switch (sc) {
      case '[':
        return ']';
      case ']':
        return '[';
      case '(':
        return ')';
      case ')':
        return '(';
      case '{':
        return '}';
      case '}':
        return '{';
      default:
        return ' ';
      }
    }
    bool isValid(string s) {
      stack<char> str;
      for (int i = 0; i < s.size(); i++) {
        if (str.empty() || parent(str.top()) != s[i])
          str.push(s[i]);
        else
          str.pop();
      }
      return str.empty();
    }
  };
  Solution s;
  string str;
  cin >> str;
  cout << s.isValid(str) << endl;

  return 0;
}
