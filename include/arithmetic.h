#ifndef  _ARITHMETIC_H_
#define _ARITHMETIC_H_
#include <iostream>
#include <cmath>
#include "stack.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

//template<typename ValType>
class lexeme{
private:
	double value;
	string operation;
	string parameter;
	bool isV;
	bool isPa;
public:
	lexeme(){}
	lexeme(double m_value);
	//lexeme(char m_parameter);
	lexeme(string a);
	~lexeme(){}
	double getValue() { return value; }
	double getValue() const{ return value; }
	string getOp() { return operation; }
	string getOp()const { return operation; }
	string getParameter() { return parameter; }
	string getParameter() const{ return parameter; }
	bool isValue() { return isV; }
	bool isValue() const{ return isV; }
	bool isParameter() { return isPa; }
	bool isParameter() const{ return isPa; }
	void operator=(double x);
	void operator=(string x);
	void operator=(lexeme x);
	bool operator==(const lexeme& x) const;
	friend ostream& operator<<(ostream& out, lexeme& lex);
};


class arithmetic
{
private:
	map<string, int> rang = { {"+", 2}, {"-", 2}, {"/", 3}, {"*", 3}, {"(", 1}, {")", 0}, {"un-",4} };
	int counteer = 0;
public:
	vector<lexeme> arithmetic::tokenizing(string& a);
	int check(vector<lexeme> array, int kol);
	lexeme* arithmetic::polish_notation(vector<lexeme> arrt);
	double calculate(lexeme* arrt, int kol);
	int getCounteer() { return counteer; }
};
#endif // ! _ARITHMETIC_H_
