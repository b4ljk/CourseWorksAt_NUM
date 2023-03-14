#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  double x, y;

  bool operator<(const Point &other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0)
    return 0;
  return (val > 0) ? 1 : 2;
}

vector<Point> convexHull(vector<Point> &points) {
  int n = points.size();
  if (n < 3)
    return {};

  vector<Point> hull;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool valid = true;
      Point p = points[i], q = points[j];
      vector<Point> upper, lower;

      for (int k = 0; k < n; k++) {
        if (k == i || k == j)
          continue;
        Point r = points[k];
        int o = orientation(p, q, r);

        if (o == 0)
          continue;
        if (o == 1)
          upper.push_back(r);
        else
          lower.push_back(r);

        for (int u = 0; u < upper.size(); u++) {
          for (int v = 0; v < lower.size(); v++) {
            if (orientation(p, upper[u], lower[v]) != 2) {
              valid = false;
              break;
            }
          }
          if (!valid)
            break;
        }
        if (!valid)
          break;
      }
      if (valid) {
        hull.push_back(p);
        hull.push_back(q);
      }
    }
  }
  sort(hull.begin(), hull.end());
  hull.erase(unique(hull.begin(), hull.end()), hull.end());
  return hull;
}

int main() {
  vector<Point> points = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {0.5, 0.5}};
  vector<Point> hull = convexHull(points);

  cout << "Convex Hull:\n";
  for (int i = 0; i < hull.size(); i++) {
    cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
  }

  return 0;
}
