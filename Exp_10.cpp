#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    static constexpr double PI = 3.14; // 'const' must have a type and value
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual ~Shape() {} // always add virtual destructor in base class
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double rad) : radius(rad) {}
    double calculateArea() const override {
        return PI * pow(radius, 2); // correct formula: πr²
    }
    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double len, double wid) : length(len), width(wid) {}
    double calculateArea() const override { // added const + override
        return length * width;
    }
    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}
    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2;
        // Corrected Heron’s formula
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(7.0);
    Rectangle rectangle(10.0, 20.0);
    Triangle triangle(12.0, 10.0, 8.0);

    cout << "--------- Circle ----------\n";
    cout << "Area: " << circle.calculateArea();
    cout << "\nPerimeter: " << circle.calculatePerimeter() << "\n\n";

    cout << "--------- Rectangle ----------\n";
    cout << "Area: " << rectangle.calculateArea();
    cout << "\nPerimeter: " << rectangle.calculatePerimeter() << "\n\n";

    cout << "--------- Triangle ----------\n";
    cout << "Area: " << triangle.calculateArea();
    cout << "\nPerimeter: " << triangle.calculatePerimeter() << "\n";

    return 0;
}