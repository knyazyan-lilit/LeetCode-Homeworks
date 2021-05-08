#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
struct Person{
private:
    std::string name;
    int age;
    std::string id;
public:
  
    
    //setters
    void set_name(std::string n){
        name = n;
    }
    void set_age(int a){
        age = a;
    }
    void set_id(std::string i){
        id = i;
    }

    //getters
    std::string get_name(){
        return name;
    }

    int get_age(){
        return age;
    }
    std::string get_id(){
        return id;
    }
};

void save_in_vec(std::vector<Person>&v,std::fstream &file){
     
    std::string name;
    std::string age;
    std::string id;
   int i=0;
    while(!file.eof()){
      
        Person p;
        file>>name;
        if(name=="---"){
            p.set_name(name);
        }
        else{
        std::getline(file,name,':');
        file>>name;
        p.set_name(name);
        }
        
      

        file>>age;
        if(age=="---"){
            p.set_age(0);
        }
        else{
        std::getline(file,age,':');
        file>>age;
        p.set_age(atoi(age.c_str()));
        }


        file>>id;
        if(id=="---"){
            p.set_id(id);
        }
        else{
            std::getline(file,id,':');
            file>>id;
            p.set_id(id);
        }
        
        v.push_back(p);
       
    }
        
    
}

int main(){
    
    std::fstream file;
    file.open("./f.txt");
    std::vector<Person> v;
    save_in_vec(v,file);
    for(int i=0; i < v.size()-1;++i){
    std::cout<<v[i].get_name()<<" "<<v[i].get_age()<<" "<<v[i].get_id()<<std::endl;
    }
    return 0;
}