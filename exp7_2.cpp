#include<iostream>
using namespace std;
class person{
    public:
    person(){
        cout<<"Person cons invoked\n";
    }
};


class faculty:public person{
    public:
    faculty(){
        cout<<"faculty cons invoked\n";
    }
};


class student : public person{
    public:
    student(){
        cout<<"student cons invoked\n";
    }
};


class ta : public  faculty,public student{
    public:
    ta(){
        cout<<"ta cons invoked\n";
    }
};


int main(){
    ta a;
    return EXIT_SUCCESS;
}