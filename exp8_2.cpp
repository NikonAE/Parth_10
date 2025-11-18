#include<iostream>
using namespace std;

class dis{
    public:
    int feet,inch;
    dis(){
        this->feet=0;
        this->inch=0;
    }

    dis(int f,int i){
        this->feet=f;
        this->inch=i;
    }


    dis operator+(dis& d){
        dis d3;
        cout<<"this->feet:"<<this->feet<<endl;
        cout<<"this->inch:"<<this->inch<<endl;
        d3.feet=feet+this->feet;
        d3.inch=inch+this->inch;
        return d3;
    }
};

int main(){
    dis d1(10,20);
    dis d2(12,12);
    dis d3;
    d3=d2+d1;
    cout<<"Feet and inches of d3 are:"<<d3.feet<<"'"<<d3.inch;
    return EXIT_SUCCESS;
}