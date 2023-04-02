#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

string zuvDaraalal(string s) {
  if (s.size() < 2)
    return "";
  // ! set uusgeh (set ni dahin davtagdahgui <char> baina)
  unordered_set<char> st(begin(s), end(s));
  for (int i = 0; i < s.size(); i++) {
    // ! uussen set dotor tom esvel jijig huvilbar ni bhguig shalgaj bna
    if (st.find((char)toupper(s[i])) == end(st) ||
        st.find((char)tolower(s[i])) == end(st)) {
      string s1 = zuvDaraalal(s.substr(0, i));
      string s2 = zuvDaraalal(s.substr(i + 1));
      return s1.size() >= s2.size() ? s1 : s2;
    }
  }
  cout << s.length() << " ";
  return s;
}

int main() {
  cout << "provide string \t";
  string n;
  cin >> n;
  if (n.size() < 2) {
    cout << "0" << endl;
    return 0;
  }
  cout << zuvDaraalal(n) << endl;

  return 0;
}