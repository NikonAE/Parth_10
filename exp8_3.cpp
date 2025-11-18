#include<iostream>
using namespace std;


class MyClass{
    public:
    int val;
    MyClass(int i){
        this->val=i;
    }
    bool operator==(MyClass& other){
        return  val==other.val;

    }

    bool operator!=(MyClass& other){
        return  val!=other.val;
    }

    bool operator<(MyClass& other){
        return  val<other.val;
    }

    bool operator>(MyClass& other){
        return  val>other.val;
    }

    bool operator>=(MyClass& other){
        return  val>=other.val;
    }
    
    bool operator<=(MyClass& other){
        return  val<=other.val;
    }

};

int main(){
    MyClass ob(10);
    MyClass ob2(11);
    
    if (ob==ob2){
        cout<<"ob is equal to ob2\n";
    }
    else
    {
        cout<<"ob is not equal to ob2\n";
    }
    
    if (ob<ob2){
        cout<<"ob is less than ob2\n";
    }
    else
    {
        cout<<"ob is not less than ob2\n";
    }

    if (ob>ob2){
        cout<<"ob is greater than ob2\n";
    }
    else
    {
        cout<<"ob is not greater than ob2\n";
    }


    if (ob!=ob2){
        cout<<"ob is not equal to ob2\n";
    }
    else
    {
        cout<<"ob is  equal to ob2\n";
    }


    if (ob>=ob2){
        cout<<"ob is greater than  equal to ob2\n";
    }
    else
    {
        cout<<"ob is not greater than equal to ob2\n";
    }


    if (ob<=ob2){
        cout<<"ob is less than equal to ob2\n";
    }
    else
    {
        cout<<"ob is not less than equal to ob2\n";
    }

    return EXIT_SUCCESS;

}