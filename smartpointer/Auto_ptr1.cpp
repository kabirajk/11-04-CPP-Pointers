#include <iostream>
#include <typeinfo>
using namespace std;
//auto pointer class//allocates and dealocates memomre;
template <typename T>
class Auto_ptr
{   public:
    T * u_ptr=nullptr;
    Auto_ptr( T * ptr=nullptr)
    {   if (u_ptr==nullptr)
            u_ptr=ptr;
    }

    Auto_ptr(Auto_ptr & obj)
    {   
            this->u_ptr=obj.u_ptr;
    }

    ~Auto_ptr()
    {
        delete u_ptr;
    }

    T& operator * ()
    {
        return *u_ptr;
    }
    T * operator -> ()
    {
        return u_ptr;
    }
};

class Employee
{   

    public:
    Employee()
    {
        cout<<"Object created"<<endl;
    }
    ~Employee()
    {
        cout<<"Object deleted"<<endl;
    }

};

void value(Auto_ptr<Employee> res)
{

}

int main()
{   
    // Auto_ptr<Employee> E=new Employee();
    Auto_ptr<Employee> E1(new Employee());
    value(E1);
    Auto_ptr<Employee> E2= E1;
    //main flaw is every time it get created this leads to crush when they point to the same
}
