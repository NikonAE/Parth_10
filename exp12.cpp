#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data.txt");
    string text;

    cout << "Enter text to write to file: ";
    getline(cin, text);

    outFile << text;
    outFile.close();

    ifstream inFile("data.txt");
    cout << "\nReading from file:\n";
    string line;
    getline(inFile, line);
    cout << line << endl;

    inFile.close();
    return 0;
}
