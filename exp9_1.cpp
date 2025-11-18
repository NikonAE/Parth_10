#include<iostream>
using namespace std;

class complex{
    public:
    int real,imag;
    complex(int r,int i){
        real=r;
        imag=i;
    }
    friend ostream& operator<<(ostream &out,const complex &c);
    friend istream& operator>>(istream &out,const complex &c);


    ostream& operator<<(ostream &out,const complex &c){
        out<<c.real;
        out<<"+i"<<c.imag<<endl;
        return out;
    }

    
    ostream& operator<<(ostream &out,const complex &c){
        out<<c.real;
        out<<"+i"<<c.imag<<endl;
        return out;
    }



};