#include<iostream>

using namespace std;
class Employee
{
    public:
    Employee()
    {
        cout<<"Object created"<<endl;
    }

    void print()
    {
        cout<<"Member Function"<<endl;
    }

    ~Employee()
    {
        cout<<"Object deleted"<<endl;
    }
};
int main()
{   
    Employee * E=new Employee();
    E->print();
    
    delete(E);//free the memorey
    //with delete
    // Object created
    // Member Function
    // Object deleted

    //without delete
    //Object created
    // Member Function
}