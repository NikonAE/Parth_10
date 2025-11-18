#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Product {
    int id, qty;
    string name;
    double price;
public:
    Product(int i = 0, string n = "", double p = 0, int q = 0)
        : id(i), name(n), price(p), qty(q) {}

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> qty;
    }

    void show() const {
        cout << setw(6) << id
             << setw(12) << name
             << setw(8) << price
             << setw(6) << qty << endl;
    }

    int getId() const { return id; }
    int getQty() const { return qty; }
    double getPrice() const { return price; }
    string getName() const { return name; }

    void reduce(int q) { qty -= q; }

    string toFile() const {
        return to_string(id) + " " + name + " " + to_string(price) + " " + to_string(qty);
    }

    friend ofstream& operator<<(ofstream& fout, const Product& p) {
        fout << p.toFile() << endl;
        return fout;
    }

    friend ifstream& operator>>(ifstream& fin, Product& p) {
        fin >> p.id >> p.name >> p.price >> p.qty;
        return fin;
    }
};

class Inventory {
    vector<Product> list;
public:
    Inventory() { load(); }

    void load() {
        list.clear();
        ifstream fin("inventory.txt");
        Product p;
        while (fin >> p)
            list.push_back(p);
    }

    void save() {
        ofstream fout("inventory.txt");
        for (auto& p : list)
            fout << p;
    }

    void add() {
        Product p;
        p.input();
        list.push_back(p);
        save();
        cout << "✅ Product added successfully!\n";
    }

    void show() {
        cout << setw(6) << "ID" << setw(12) << "Name"
             << setw(8) << "Price" << setw(6) << "Qty\n";
        for (auto& p : list)
            p.show();
    }

    Product* find(int id) {
        for (auto& x : list)
            if (x.getId() == id)
                return &x;
        return nullptr;
    }
};

class Billing : public Inventory {
public:
    void bill() {
        double total = 0;
        int id, q;

        while (true) {
            cout << "\nEnter Product ID (0 to end): ";
            cin >> id;
            if (id == 0)
                break;

            Product* p = find(id);
            if (!p) {
                cout << "❌ Product not found!\n";
                continue;
            }

            if (p->getQty() == 0) {
                cout << "⚠️ Product '" << p->getName() << "' is out of stock!\n";
                continue;
            }

            cout << "Enter Quantity: ";
            cin >> q;

            if (q > p->getQty()) {
                cout << "Only " << p->getQty() << " left in stock!\n";
                continue;
            }

            total += q * p->getPrice();
            p->reduce(q);
            cout << "✅ Added " << q << " x " << p->getName() << " to bill.\n";
        }

        cout << "\n💰 Total Bill = ₹" << total << endl;
        save();
    }
};

int main() {
    Billing inv;
    int ch;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Add Product\n";
        cout << "2. Show Inventory\n";
        cout << "3. Create Bill\n";
        cout << "4. Exit\n";
        cout << "========================\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: inv.add(); break;
            case 2: inv.show(); break;
            case 3: inv.bill(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 4);

    return 0;
}