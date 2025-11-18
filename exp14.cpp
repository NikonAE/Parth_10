#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "=== Template Function Demo ===" << endl;
    int a = 10, b = 25;
    double x = 45.6, y = 32.4;

    cout << "Max of " << a << " and " << b << " is: " << findMax(a, b) << endl;
    cout << "Max of " << x << " and " << y << " is: " << findMax(x, y) << endl;

    cout << "\n=== STL Containers Demo ===" << endl;

    cout << "\nVector Example:" << endl;
    vector<int> numbers = {1, 2, 3};
    numbers.push_back(4);
    numbers.push_back(5);

    cout << "Vector elements: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    numbers.pop_back();
    cout << "After pop_back(): ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    cout << "\nList Example:" << endl;
    list<string> fruits = {"Apple", "Banana", "Cherry"};
    fruits.push_front("Mango");
    fruits.push_back("Orange");

    cout << "List elements: ";
    for (const auto &f : fruits)
        cout << f << " ";
    cout << endl;

    fruits.remove("Banana");
    cout << "After removing Banana: ";
    for (const auto &f : fruits)
        cout << f << " ";
    cout << endl;

    cout << "\nMap Example:" << endl;
    map<int, string> students;
    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";

    cout << "Map elements (RollNo -> Name):" << endl;
    for (auto &pair : students)
        cout << pair.first << " -> " << pair.second << endl;

    cout << "Student with roll 102: " << students[102] << endl;

    int roll = 104;
    if (students.find(roll) == students.end())
        cout << "Student with roll " << roll << " not found." << endl;

    cout << "\n=== End of Program ===" << endl;

    return 0;
}
