#include <iostream>
 using namespace std;

//#=========purpose of void pointer=========//
class myclass
{
    public:
    myclass()
    {
        cout<<"created of my class invoked"<<endl;
    }
    ~myclass()
    {
        cout<<"deleted of my class invoked"<<endl;
    }
};
//#=========purpose of void pointer=========//


int main()
{   //#=============const pointer===============# 
    //making the value only constant 
    int c=2;//non const
    //const pointer declaration
    const int * inconst;//const int ptr means you cant modify the value by using pointer when which is pointing to a non const variable
    //but we can able to change constant by using another non const or the varibal or refernce directly 
    //but you can change the pointer to another constant or non consatnt one
    inconst=&c;
    //these are used while passing args while when ever a need of not to modify the object
    //beacause normal args create a new value but pointers give normal access
    c+=2;
        // *inconst=*inconst+23//this doenst the follow the read only values rule this shows error 
        //like assignment of read-only location '* inconst'

    //this shows the constant ponter can able to point to other loactions
    cout<<"c' value="<<*(inconst)<<endl;
    int c2=3;
    inconst=&c2;
    cout<<"c2's value="<<*(inconst)<<endl;

    //making the constant pointer as constatnt
    //which means the const pointer pointed value is always constant
    
    int c3=26;
    //making constant type of pointer as constant//for makin the pointer constant
    const int * const constpointer=&c3;//we cant declare we need to initialize 
    //as same as above assigning non const value's address means we can modify the value by using the variable's name 
    //or non constant pointer 
    c3+=24;
    //
    cout<<"c3's value="<<*constpointer;
    return 0;


    //#============== void pointer ================#//
    myclass *myc=new myclass;//this belongs to myclass
    cout<<myc<<typeid(myc).name()<<endl;
    void* my=myc;//this is void pointer so void type
    cout<<my<<typeid(my).name()<<endl;
    myclass *myv=(myclass*)my;//this beloings to myclass no type casted from void* to myclass *
    cout<<myv<<typeid(myv).name()<<endl;
    //c++ can communicate with c function in files so making the pointer 

}