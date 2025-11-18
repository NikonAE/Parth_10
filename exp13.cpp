#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InvalidAgeException : public exception {
    string message;
public:
    InvalidAgeException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Person {
    string name;
    int age;
public:
    Person(const string& n, int a) {
        if (a < 0 || a > 150)
            throw InvalidAgeException("Invalid Age! Age must be between 0 and 150.");
        name = n;
        age = a;
    }
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

double divide(double a, double b) {
    if (b == 0)
        throw runtime_error("Division by zero error!");
    return a / b;
}

int main() {
    cout << "=== Exception Handling Demo ===" << endl;

    try {
        double x, y;
        cout << "\nEnter two numbers to divide: ";
        cin >> x >> y;
        double result = divide(x, y);
        cout << "Result: " << result << endl;
    } 
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        string name;
        int age;
        cout << "\nEnter person's name: ";
        cin >> name;
        cout << "Enter person's age: ";
        cin >> age;
        Person p(name, age);
        p.display();
    } 
    catch (const InvalidAgeException& e) {
        cout << "Custom Exception caught: " << e.what() << endl;
    }

    cout << "\n=== End of Program ===" << endl;
    return 0;
}
