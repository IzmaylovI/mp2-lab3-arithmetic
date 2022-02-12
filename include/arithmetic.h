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
<<<<<<< HEAD
	bool isV;
public:
	lexeme(){}
	lexeme(double m_value);
=======
	string parameter;
	bool isV;
	bool isPa;
public:
	lexeme(){}
	lexeme(double m_value);
	//lexeme(char m_parameter);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
	lexeme(string a);
	~lexeme(){}
	double getValue() { return value; }
	double getValue() const{ return value; }
	string getOp() { return operation; }
	string getOp()const { return operation; }
<<<<<<< HEAD
	bool isValue() { return isV; }
	bool isValue() const{ return isV; }
=======
	string getParameter() { return parameter; }
	string getParameter() const{ return parameter; }
	bool isValue() { return isV; }
	bool isValue() const{ return isV; }
	bool isParameter() { return isPa; }
	bool isParameter() const{ return isPa; }
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
	void operator=(double x);
	void operator=(string x);
	void operator=(lexeme x);
	bool operator==(const lexeme& x) const;
<<<<<<< HEAD
=======
	friend ostream& operator<<(ostream& out, lexeme& lex);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
};


class arithmetic
{
private:
	map<string, int> rang = { {"+", 2}, {"-", 2}, {"/", 3}, {"*", 3}, {"(", 1}, {")", 0}, {"un-",4} };
<<<<<<< HEAD
public:
	double arithmetic::tokenizing_and_polish_notation(string& a);
	int check(lexeme* array, int kol);
	double calculate(lexeme* arrt, int kol);
};
#endif // ! _ARITHMETIC_H_
=======
	int counteer = 0;
public:
	vector<lexeme> arithmetic::tokenizing(string& a);
	int check(vector<lexeme> array, int kol);
	lexeme* arithmetic::polish_notation(vector<lexeme> arrt);
	double calculate(lexeme* arrt, int kol);
	int getCounteer() { return counteer; }
};
#endif // ! _ARITHMETIC_H_
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
