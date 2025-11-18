#include<iostream>
using namespace std;
class vehicle{
    public:
    vehicle(){
        cout<<"Vehicle invoked\n";
    }
};


class fare{
    public:
    fare(){
        cout<<"fare of vehicle \n";
    }
};


class car:public vehicle{
    public:
    car(){
        cout<<"vehicle is car \n";
    }
};



class bus: public vehicle,public fare{
    public:
    bus(){
        cout<<"bus  with vehicle and fare \n";
    }
};

int main(){
    bus b;
    return EXIT_SUCCESS;
}