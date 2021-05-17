#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <set>
#include <utility>

const std::string CREATE = "create";
const std::string READ = "read";
const std::string UPDATE = "update";
const std::string INSERT = "insert";
const std::string DROP = "drop";
const std::string DELETE = "delete";
std::set<std::string> files;


void InsertInFile(std::vector<std::string> query){

    std::fstream f;
    std::string filename = query[1]+".txt";
    if(!query[1].empty() && files.find(filename) != files.end()){
        f.open(filename);
        int i = 0;
        
        f.seekp(0,std::ios_base::end);
        while(query[i]!=query.back()){
            if(query[i] == ":"){
                f << query[i-1] <<" "<<":" <<" "<<query[i+1]<<'\n';
                ++i;
            }
            else{
                ++i;
            }
        }
            std::cout<<"Successfully inserted"<<std::endl;
        f << "-"<<'\n';
        
    }
    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
        
}

void CreateFile(std::vector<std::string> query){
    std::ofstream f;
    std::string filename = "./"+query[1]+".txt";
    std::string name = query[1] + ".txt";
    if(!query[1].empty() && files.find(filename) == files.end()){
    
        if(files.find(query[1] + ".txt") != files.end()){
            std::cout<<"Already exists file with this name"<<std::endl;
            return;
        }

        else{
            
            f.open(filename);
            files.insert(query[1]+".txt");
            std::cout<<"Successfully created"<<std::endl;
            f<<"-"<<'\n';
            return;
        }
    }
    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
}

void DropFile(std::vector<std::string> query){
     std::string filename = query[1]+".txt";
    if(!query[1].empty() && files.find(filename) != files.end()){
        char fn[filename.length()+1];
        strcpy(fn, filename.c_str());

        if( remove(fn) != 0 ){
            std::cout<< "Error deleting file"<<std::endl;
            return;
        }

        else{
            files.erase(filename);
            std::cout<<"File successfully deleted"<<std::endl;
            return;
        } 
    }

    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
}


std::pair<std::string,std::string> FindFieldAndValue(std::vector<std::string> query){
    
    int i = 0;
    while(query[i]!=query.back()){
        if(query[i] == ":"){
            return {query[i-1],query[i+1]};
        }
        ++i;
    }
    return {};
}

std::vector<std::map<std::string,std::string>> ReadFileLineByLine(std::fstream& f,std::vector<std::map<std::string,std::string>>& v,int i,std::string &value,std::string &field){
     
    while(true){
        field=value;
        f>>value;
        if(value == "-"){
            break;
        }

        if( value == ":"){
            f>>value;
            v[i].insert({field,value});
            
        }
    }
   return v;
}

std::vector<std::map<std::string,std::string>> ParseEntries(std::string filename){
    std::fstream f;
    f.open(filename);
    std::vector<std::map<std::string,std::string>>v(7);
    int i = 0;
    std::string value;
    std::string field;

    while(!f.eof()){
        
        f>>value;
        ReadFileLineByLine(f,v,i,value,field);
        ++i;

    }
    return v;

}

void Print(std::map<std::string,std::string> entry){
    std::map<std::string,std::string>::iterator itr;
    for (itr = entry.begin(); itr != entry.end(); ++itr) {
        std::cout << '\t' << itr->first
        << '\t' << itr->second << '\n';
    }
}

void ReadFromFile(std::vector<std::string> query){    
    std::string filename = query[1]+".txt";
    if(!query[1].empty() && files.find(filename) != files.end()){
        std::pair<std::string,std::string> pair = FindFieldAndValue(query);
        const auto entries = ParseEntries(filename);
        for (const auto& entry : entries) {
            if (entry.find(pair.first)->second == pair.second) {
                Print(entry);
            }
        }
    }
    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
}

std::pair<std::string,std::string> FindFieldForUpdate(std::vector<std::string> query){
    
    int i = 0;
    while(query[i]!=query.back()){
        if(query[i] == ":"){
            return {query[i-1],query[i+1]};
        }
        ++i;
    }
    return {};
}


std::pair<std::string,std::string> FindFieldAndValue1(std::vector<std::string> query){
    int num = 0;
    int i = 0;
    while(query[i]!=query.back()){
        if(query[i] == ":"){
            ++num;
        }
        if(num == 2){
            return {query[i-1],query[i+1]};
        }
        ++i;
    }
    return {};
}


void WriteInFile(std::vector<std::map<std::string,std::string>>entries,std::fstream& f ,int i){

    f<<"-"<<"\n";
    std::map<std::string, std::string>::iterator itr;
    for (itr = entries[i].begin(); itr != entries[i].end(); ++itr) {
      
        f<< itr->first<<" "<<":"<<" "<< itr->second<<"\n";
        
    }
    
}


void WriteInFileForDelete(std::vector<std::map<std::string,std::string>>entries,std::fstream& f ,int i){

    
    std::map<std::string, std::string>::iterator itr;
    for (itr = entries[i].begin(); itr != entries[i].end(); ++itr) {
       
        f<< itr->first<<" "<<":"<<" "<< itr->second<<"\n";
        
    }
   f<<"-"<<"\n";
}

void Delete(std::vector<std::map<std::string,std::string>> &entries,std::pair< std::string,std::string> field_and_value,std::string filename ){
    
    std::fstream f;
    f.open(filename, std::ios::out | std::ios::trunc);
    int i = 0;
    f<<"-"<<"\n";
    if(entries.empty()){
        
        WriteInFileForDelete(entries, f,i);
    }
    else{
        while(!entries[i].empty()){
           
            WriteInFileForDelete(entries, f,i);
            ++i;
        }
    }
     
}

void Update(std::vector<std::map<std::string,std::string>> &entries,std::pair< std::string,std::string> field_and_value,std::string filename ){
    
    std::fstream f;
    f.open(filename);
    int i = 0;
    if(entries.empty()){
        
        WriteInFile(entries, f,i);
    }
    else{
        while(!entries[i].empty()){
           
            WriteInFile(entries, f,i);
            ++i;
        }
    }
    f<<"-"<<std::endl;
}

void UpdateField(std::vector<std::string> query){
    std::string filename = query[1] + ".txt";
    if(!query[1].empty() && files.find(filename) != files.end()){
        
        std::pair< std::string,std::string> pair = FindFieldAndValue1(query);//returns conditional field and value
        std::pair< std::string,std::string> field_and_value = FindFieldForUpdate(query);//returns field and value that need to change
        std::vector<std::map<std::string,std::string>> entries = ParseEntries(filename);
       
        for (auto & entry : entries) {
            if (entry.find(pair.first)->second == pair.second) {
                entry[field_and_value.first] = field_and_value.second;
                Update(entries,field_and_value,filename);
            }
        }
    }
    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
}


void DeleteInfo(std::vector<std::string> query){
    std::string filename = query[1] + ".txt";
    if(!query[1].empty() && files.find(filename) != files.end()){
        std::pair< std::string,std::string> pair = FindFieldAndValue(query);//returns conditional field and value
        std::vector<std::map<std::string,std::string>> entries = ParseEntries(filename);
        for(int i=0;i<entries.size();++i){
            if(entries[i].find(pair.first)->second == pair.second){
                entries.erase(entries.begin() + i);
                Delete(entries,pair,filename);
                std::cout<<"Deleted"<<std::endl;
            }
            
        }
    }
    else{
        std::cout<<"Query is wrong "<<std::endl;
    }
}


void parse(std::vector<std::string>  query){
      
    if(query[0] == CREATE){
        CreateFile(query);
    }

    if(query[0] == INSERT){
        InsertInFile(query);
    }

    if(query[0] == READ){
        ReadFromFile(query);
    }
    
    if(query[0]==UPDATE){
        UpdateField(query);
    }

    if(query[0]==DROP){
       DropFile(query);
    }

    if(query[0]==DELETE){
        DeleteInfo(query);
    }

}

int main(){

    while(true){
        std::vector<std::string> query;
        while(std::cin){
            std::string line;
            std::cin >> line;
            query.push_back(line);
            if(std::cin.get() == '\n'){
                parse(query);
                break;
            }
               
        }
      
    }

    return 0;
}
