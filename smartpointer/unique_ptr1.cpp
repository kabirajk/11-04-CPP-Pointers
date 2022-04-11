#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

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

int main()
{   cout<<"outer scope"<<endl;
    {
       cout<<"Inner scope"<<endl;
        unique_ptr<Employee> E= make_unique<Employee>();
        // cout<<typeid(E).name()<<endl;
          cout<<"End of Inner scope"<<endl;
    }
    cout<<"End of outer scope"<<endl;
    return 0;
}