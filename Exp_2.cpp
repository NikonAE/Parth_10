#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex subtract(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:\n";
    c1.input();

    cout << "\nEnter second complex number:\n";
    c2.input();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\n--- Results ---\n";
    cout << "First Number: ";
    c1.display();
    cout << "Second Number: ";
    c2.display();

    cout << "\nAddition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}