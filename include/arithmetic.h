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
	bool isV;
public:
	lexeme(){}
	lexeme(double m_value);
	lexeme(string a);
	~lexeme(){}
	double getValue() { return value; }
	double getValue() const{ return value; }
	string getOp() { return operation; }
	string getOp()const { return operation; }
	bool isValue() { return isV; }
	bool isValue() const{ return isV; }
	void operator=(double x);
	void operator=(string x);
	void operator=(lexeme x);
	bool operator==(const lexeme& x) const;
};


class arithmetic
{
private:
	map<string, int> rang = { {"+", 2}, {"-", 2}, {"/", 3}, {"*", 3}, {"(", 1}, {")", 0}, {"un-",4} };
public:
	double arithmetic::tokenizing_and_polish_notation(string& a);
	int check(lexeme* array, int kol);
	double calculate(lexeme* arrt, int kol);
};
#endif // ! _ARITHMETIC_H_