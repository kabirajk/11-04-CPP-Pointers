#include <iostream>
//pointer to a function;
using namespace std;
int fun()
{
    cout<<"hello"<<endl;
}
int foo( int (*funpoint)())
{
    (*funpoint)();
}

double fun2(int i)
{
    cout<<"this the 1 arg normal function = "<<i<<endl;
}

int main()
{
    cout<<reinterpret_cast<void*>(fun)<<endl;
    cout<<(void*)fun<<endl;
    int (*funptr)()=&fun;
    cout<<"called from function pointer"<<endl;
    (*funptr)();
    cout<<"called from normal function()"<<endl;
    fun();
    cout<<"called from passing to function pointer a function"<<endl;
    foo(funptr);
    int (* funptr2)(int(*)())=foo;//arg=that function pointer is a delaration with int *ptr (0arg call)
            //so the funtion ptr to a function ptr wil match the signature  
    (*funptr2)(funptr);
    // int (*funtpt3)(int i)=fun2;//double (*)(int)' to 'int (*)(int)'
    double (*funptr3)(int i)=fun2;
    (*funptr3)(1);
}