#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

void save_in_file(std::vector<Person> v,std::fstream &file){
   
    for(int i = 0; i < v.size(); ++i){
        file << "name : " << v[i].get_name()<<'\n';
        file << "age : " << v[i].get_age()<<'\n';
        file << "id : " << v[i].get_id()<<'\n';
    } 
}

int main(){
    std::string name;
    int age;
    std::string id;

    std::vector<Person> v;
    int count_of_persons;
    std::cin>>count_of_persons;
    int i=0;

    while(i != count_of_persons && std::cin>>name && std::cin>>age && std::cin>>id){
        Person p;
        p.set_name(name);
        p.set_age(age);
        p.set_id(id);
        v.push_back(p);
        ++i;
    }
   
    std::fstream file;
    file.open("f.txt");
    save_in_file(v,file);
    file.clear();
    return 0;

}