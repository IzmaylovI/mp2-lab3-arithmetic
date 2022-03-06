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
	lexeme(char a);
	lexeme(double m_value);
	lexeme(string a);
	~lexeme(){}
	double getValue() { return value; }
	double getValue() const{ return value; }
	string getOp() { return operation; }
	string getOp()const { return operation; }
	bool isValue() { return isV; }
	bool isValue() const{ return isV; }
	string getParameter() { return parameter; }
	string getParameter() const { return parameter; }
	bool isParameter() { return isPa; }
	bool isParameter()const { return isPa; }
	void operator=(double x);
	void operator=(string x);
	void operator=(lexeme x);
	bool operator==(const lexeme& x) const;
	friend ostream& operator<<(ostream& out, lexeme& lex);
};


class arithmetic
{
private:
	//int counteer = 0;
public:
    map<string, int> rang = { {"+", 2}, {"-", 2}, {"/", 3}, {"*", 3}, {"(", 1}, {")", 0}, {"un-",4} };
	double tokenizing_and_polish_notation(string& a);
	int check(vector<lexeme> array, int kol);
	vector<lexeme> polish_notation(vector<lexeme> array);
	//double arithmetic::tokenizing_and_polish_notation(string& a);
	double calculate(vector<lexeme> arrt);
	//int getCounteer() { return counteer; }
	vector<lexeme> tokenizing(string a);
};
#endif // ! _ARITHMETIC_H_
