#include<iostream>
using namespace std;


class base1{
    public:
    string s= " Base class1 data\n";
};

class base2{
    public:
    string s1= " Base class2 data\n";
};


class child:public base1,public base2 {
    public:
    string s2= " child class inherit base1 and base2\n";
    void display(){
        cout<<s<<s1<<s2;
    }

};


int main(){

    child c;
    c.display();
return EXIT_SUCCESS;
}