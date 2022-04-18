#include <iostream>
#include<vector>
#include <memory>
// make a image database while uploading the same file make use shared pointer to multi ref the same value
//share function ality

class fileobj
{  //file class that imitates object information 
    public:
    std::string name;//name of the file
    std::string url;//url or path of the file
    fileobj(std::string Name)
    {   
        name=Name;
        url="file://"+Name;
    }

    void show_details()
    {   //function the show the details of the file
        std::cout<<"file name = "<<name<<std::endl;
        std::cout<<"fileurl = "<<url<<std::endl;
    }

    fileobj()
    {
        std::cout<<"file deleetd"<<std::endl;
    }
 
};

//anoymous class object  that holds the whole file data base
class 
{   //this store the file names and 

    //list of shared pointr//vetor//arraylist//dynamic array
    std::vector <std::shared_ptr<fileobj>> files;//
    friend class fileobj;
    friend int post(std::string& Filename);
    // int main();

    public:
    int list()
     {//function to list the files stored
        for (int i=0;i<files.size();i++)
        {   //get method return the address of the stored object -> objcet members
            files[i].get()->show_details();
            //use count show the number of times curretly refenced
            std::cout<<"No of shares :"<<files[i].use_count()<<std::endl;
            
            //std::cout<<" stored address "<<files[i].get()<<" name address "<<&(files[i].get()->name)<<" url address "<<&(files[i].get()->url)<<std::endl<<std::endl;
            //name nand get() returned address are same check!
        }
        //returns the file count stored or size of the vector
        return files.size();
    }
}filedatabase;


//function to post a file 
int post(std::string& Filename)
{  
    //check wheater the file is present or not 
    for(int i=0;i<filedatabase.files.size();i++)
        {
            if((filedatabase.files[i].get())->name==Filename)
                {
                    filedatabase.files.push_back(filedatabase.files[i]);
                    return 1;//if present referenced returns 1
                }
        }
    //if not found it created new objct returns 0;
    filedatabase.files.push_back(std::make_shared<fileobj>(Filename));
    return 0;
}


int main()
{   std::string f1="mytext.txt";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;
    f1="mytext2.txt";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;
    f1="mytext.txt";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;
    f1="mytext.img";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;
    f1="myself.img";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;
    f1="mytext.img";
    std::cout<<(post(f1)==0?"Created":"refenced")<<std::endl;

    filedatabase.list();

    return 0;
}

// for(int i=0;i<filedatabase.files.size();i++)
    // {
    //     std::cout<<filedatabase.files[i].get()->name<<" "<<filedatabase.files[i].get()->url<<std::endl;
    //     std::cout<<"no of shares"<<filedatabase.files[i].use_count()<<std::endl;
    //     std::cout<<filedatabase.files[i].get()<<" "<<std::endl<<std::endl;
    // }
//