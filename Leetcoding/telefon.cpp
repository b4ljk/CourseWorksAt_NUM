#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<char, int> map;
  map['a'] = 2;
  map['b'] = 2;
  map['c'] = 2;
  map['d'] = 3;
  map['e'] = 3;
  map['f'] = 3;
  map['g'] = 4;
  map['h'] = 4;
  map['i'] = 1;
  map['j'] = 1;
  map['k'] = 5;
  map['l'] = 5;
  map['m'] = 6;
  map['n'] = 6;
  map['o'] = 0;
  map['p'] = 7;
  map['q'] = 0;
  map['r'] = 7;
  map['s'] = 7;
  map['t'] = 8;
  map['u'] = 8;
  map['v'] = 8;
  map['w'] = 9;
  map['x'] = 9;
  map['y'] = 9;
  map['z'] = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (map.find(s[j]) != map.end()) {
        cout << map[s[j]];
      } else {
        cout << s[j];
      }
    }
    cout << endl;
  }
  return 0;
}