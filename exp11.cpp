#include <iostream>
using namespace std;

class Employee {
public:
    virtual void calculateSalary() = 0; 
};

class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(double salary) : monthlySalary(salary) {}
    void calculateSalary() override {
        cout << "Salaried Employee Salary: " << monthlySalary << endl;
    }
};

class HourlyEmployee : public Employee {
    double hoursWorked;
    double hourlyRate;
public:
    HourlyEmployee(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}
    void calculateSalary() override {
        cout << "Hourly Employee Salary: " << hoursWorked * hourlyRate << endl;
    }
};

class CommissionEmployee : public Employee {
    double baseSalary;
    double commission;
public:
    CommissionEmployee(double base, double comm) : baseSalary(base), commission(comm) {}
    void calculateSalary() override {
        cout << "Commission Employee Salary: " << baseSalary + commission << endl;
    }
};

int main() {
    Employee* emp;

    SalariedEmployee s1(50000);
    HourlyEmployee h1(40, 500);
    CommissionEmployee c1(20000, 7000);

    emp = &s1;
    emp->calculateSalary();

    emp = &h1;
    emp->calculateSalary();

    emp = &c1;
    emp->calculateSalary();

    return 0;
}
