#include <iostream>
using namespace std;

class AreaCalculator {
public:
    // Area of Circle
    double area(double radius) {
        return 3.14159 * radius * radius;
    }

    // Area of Rectangle
    double area(double length, double breadth) {
        return length * breadth;
    }

    // Area of Triangle
    double area(double base, double height, bool isTriangle) {
        return 0.5 * base * height;
    }
};

int main() {
    AreaCalculator calc;
    double r, l, b, h;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of Circle = " << calc.area(r) << endl;

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle = " << calc.area(l, b) << endl;

    cout << "\nEnter base and height of triangle: ";
    cin >> b >> h;
    cout << "Area of Triangle = " << calc.area(b, h, true) << endl;

    return 0;
}
