#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point &other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

bool ccw(Point a, Point b, Point c) {
  return (c.y - a.y) * (b.x - a.x) > (b.y - a.y) * (c.x - a.x);
}

vector<Point> convexHull(vector<Point> &points) {
  int n = points.size();
  if (n < 3)
    return {};

  vector<Point> hull;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        bool flag = true;
        for (int m = 0; m < n; m++) {
          if (m == i || m == j || m == k)
            continue;
          if (ccw(points[i], points[j], points[m]) &&
              ccw(points[j], points[k], points[m]) &&
              ccw(points[k], points[i], points[m])) {
            flag = false;
            break;
          }
        }
        if (flag) {
          hull.push_back(points[i]);
          hull.push_back(points[j]);
          hull.push_back(points[k]);
        }
      }
    }
  }

  sort(hull.begin(), hull.end());
  hull.erase(unique(hull.begin(), hull.end()), hull.end());

  return hull;
}

int main() {
  vector<Point> points = {{0, 0}, {0, 3}, {3, 0}, {3, 3}, {1, 1}, {2, 2}};
  vector<Point> hull = convexHull(points);
  cout << "Convex Hull: ";
  for (auto p : hull) {
    cout << "(" << p.x << "," << p.y << ") ";
  }
  cout << endl;
  return 0;
}
