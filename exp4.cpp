#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "Parameterized constructor called." << endl;
    }

    // Member function to calculate area
    double area() {
        return length * width;
    }

    // Member function to calculate perimeter
    double perimeter() {
        return 2 * (length + width);
    }

    // Display details
    void display() {
        cout << "\nLength: " << length;
        cout << "\nWidth: " << width;
        cout << "\nArea: " << area();
        cout << "\nPerimeter: " << perimeter() << endl;
    }

    // Destructor
    ~Rectangle() {
        cout << "Destructor called for Rectangle." << endl;
    }
};

int main() {
    Rectangle r1;  // default constructor
    Rectangle r2(10, 5);  // parameterized constructor

    cout << "\nRectangle r2 details:";
    r2.display();

    return 0;
}
