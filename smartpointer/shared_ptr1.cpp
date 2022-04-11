#include <iostream>
#include <memory>
#include <typeindex>

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
{
    cout<<"outer scope"<<endl;
    shared_ptr<Employee> E=make_shared<Employee>();
    cout<<"No of ptr="<<E.use_count()<<endl;
    {
       cout<<"Inner scope"<<endl;
        shared_ptr<Employee> E1=E;
        cout<<"No of ptr="<<E1.use_count()<<endl;
        cout<<"End of Inner scope"<<endl;
    }
    cout<<"No of ptr="<<E.use_count()<<endl;
    cout<<"End of outer scope"<<endl;
    return 0;
}