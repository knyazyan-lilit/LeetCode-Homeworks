#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>


struct VarDec {
	std::string name;
	int value = 0;
};

enum NewType {
	INT,
	string,
	
};

struct Typedetect {
	void * value;
	NewType typ;
};

class Interpreter {

private:
	VarDec obj;
	std::unordered_map <std::string, Typedetect> vars;
	std::unordered_map <std::string, struct VarDec> decmap;

public:
	bool is_number(const std::string& s);
	void VariableDecl(std::string* str) ;
	Typedetect Sum(std::string* str, int k);
	Typedetect Subtract(std::string* str, int k);
	Typedetect Multiplication(std::string* str, int k);
	Typedetect QuotientDivision(std::string* str, int k);
	Typedetect RemainderDivision(std::string* str, int k);
	void  Assignment(std::string* str) ;
	Typedetect Stosum(std::string* str);
	Typedetect Stosub(std::string* str);
	Typedetect Stomul(std::string* str);
	Typedetect Stoquot(std::string* str);
	Typedetect Storem(std::string* str);
	Typedetect Inc(std::string* str);
	Typedetect Dec(std::string* str);
	void Printel(std::string* str, int k);
	void Helper2(std::string* str,std::fstream& f);
   	void If_Complement1(std::string* str, std::fstream& f);
	void If_Complement2(std::string* str,std::fstream& f);
	void If_Complement3(std::string* str, std::fstream& f);
	void If_Complement4(std::string* str, std::fstream& f);
	void If_Complement5(std::string* str, std::fstream& f);
	void If_Complement6(std::string* str, std::fstream& f);
	void Ifststemant(std::string* str, std::fstream& f) ;
	void Loop(std::string* str, std::fstream& f);
    void Checking(std::string* str, int k, std::fstream& f);
	void Parser();

};




