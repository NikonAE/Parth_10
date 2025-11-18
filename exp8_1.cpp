#include<iostream>
using namespace std;
class dis{
    public:
    int feet,inch;
    dis(int f,int i){
        this->feet=f;
        this->inch=i;
    }
    void operator-(){
        feet--;
        inch--;
        cout<<feet<<"'"<<inch;

    }
};


int main(){
    dis d(10,2);
    -d;
    return EXIT_SUCCESS;

}