#include <iostream>
using namespace std;

class shape {
private:
  string name;
  int dimensions;

public:
  shape() {}
  shape(string name) { this->name = name; }
  void setname(string name) { this->name = name; }
  string getName() { return name; }
};

class twoDimensionalShape : public shape {
protected:
  double area;
  double coordinates;

public:
  twoDimensionalShape() {}
  twoDimensionalShape(string name) { setname(name); }
  void setArea(double area) { this->area = area; }
  double getArea() { return area; }
  void setCoordinates(double coordinates) { this->coordinates = coordinates; }
  double getCoordinates() { return coordinates; }
};

class threeDimensionalShape : public shape {
protected:
  double volume;
};

class circle : public twoDimensionalShape {
private:
  double radius;

public:
  circle(string name, double radius, double coordinates) {
    setname(name);
    setCoordinates(coordinates);
    this->radius = radius;
  }
  void setRadius(double radius) { this->radius = radius; }
  double getRadius() { return radius; }
  double getArea() { return 3.14 * radius * radius; }
  double getPerimeter() { return 2 * 3.14 * radius; }
};
class quadrat : public twoDimensionalShape {
private:
  double side;

public:
  quadrat(string name, double side, double coordinates) {
    setname(name);
    setCoordinates(coordinates);
    this->side = side;
  }
  void setSide(double side) { this->side = side; }
  double getSide() { return side; }
  double getArea() { return side * side; }
  double getPerimeter() { return 4 * side; }
};

class triangle : public twoDimensionalShape {
private:
  double side;

public:
  triangle(string name, double side, double coordinates) {
    setname(name);
    setCoordinates(coordinates);
    this->side = side;
  }
  void setSide(double side) { this->side = side; }
  double getSide() { return side; }
  double getArea() { return (side * side) / 2; }
  double getPerimeter() { return 3 * side; }
};

int main() {
  circle c("circle", 5, 2);
  cout << c.getName() << endl;
  cout << c.getArea() << endl;
  cout << c.getPerimeter() << endl;
  quadrat q("quadrat", 5, 2);
  cout << q.getName() << endl;
  cout << q.getArea() << endl;
  cout << q.getPerimeter() << endl;
  triangle t("triangle", 5, 2);
  cout << t.getName() << endl;
  cout << t.getArea() << endl;
  cout << t.getPerimeter() << endl;

  return 0;
}