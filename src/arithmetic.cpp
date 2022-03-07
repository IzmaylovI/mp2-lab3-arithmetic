#include "arithmetic.h"

lexeme::lexeme(char a)
	: isV(false)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')')
	{
		isPa = false;
		operation = a;
	}
	else
	{
		isPa = true;
		parameter = a;
	}
}
lexeme::lexeme(double m_value)
	: value(m_value)
	, isV(true)
	, isPa(false)
{}

lexeme::lexeme(string a)
	: isV(false)
{
	if (a == "+" || a == "-" || a == "*" || a == "/" || a == "(" || a == ")" || a == "un-")
	{
		isPa = false;
		operation = a;
	}
	else
	{
		isPa = true;
		parameter = a;
	}
}


void lexeme::operator=(double x)
{
	value = x;
	isV = true;
	isPa = false;
}

void lexeme::operator=(string x)
{
	isV = false;

	if (x == "+" || x == "-" || x == "*" || x == "/" || x == "(" || x == ")")
	{
		isPa = false;
		parameter = x;
	}
	else
	{
		isPa = true;
		operation = x;
	}
}

void lexeme::operator=(lexeme x)
{
	if (x.isValue())
	{
		value = x.value;
		isV = true;
		isPa = false;
	}
	else if(x.isParameter())
	{
		isV = false;
		isPa = true;
		parameter = x.parameter;
	}
	else
	{
		isV = false;
		isPa = false;
		operation = x.operation;
	}
}
bool  lexeme::operator==(const lexeme& x) const
{
	bool flag = 1;
	
	if (isValue())
	{
		if (x.isValue())
		{
			if (getValue() != x.getValue())
			{
				flag = 0;
			}
		}
		else
		{
			flag = 0;
		}
	}
	else
	{
		if (getOp() != x.getOp())
		{
			flag = 0;
		}
	}
	return flag;
}
ostream& operator<<(ostream& out, lexeme& lex)
{
	if (lex.isValue())
	{
		out << lex.getValue();
	}
	else if (lex.isParameter())
	{
		out << lex.getParameter();
	}
	else
	{
		out << lex.getOp();
	}

	return out;
}

vector<lexeme> arithmetic::tokenizing(string a)
{
	int i = 0, j = 0;
	int count = 0;  
	double temp, x, d;

	vector<lexeme> arrt;
	
	while (a[j] != '\0')
	{
		if (a[j] != ' ')
		{
			if (a[j] >= '0' && a[j] <= '9')
			{
				x = 0;
				d = 10;

				if (i != 0 && arrt[i - 1].isParameter())
				{
					arrt.push_back('*');
					count++;
					i++;
				}
				while (a[j] >= '0' && a[j] <= '9')
				{
					temp = static_cast<double>(a[j] - '0');
					x = x * 10 + temp;
					j++;
				}
				if (a[j] == '.')
				{
					j++;

					while ((a[j] >= '0' && a[j] <= '9'))
					{
						temp = static_cast<double>(a[j] - '0');

						x += temp / d;
						j++;
						d *= 10;
					}
				}
				arrt.push_back(x);
				count++;
				i++;
			}

			else if (a[j] != '\0' && (a[j] >= 'a' && a[j] <= 'z' || a[j] >= 'A' && a[j] <= 'Z'))
			{
				if (i != 0 && arrt[i - 1].isValue())
				{

					arrt.push_back('*');
					i++;
					count++;
				}
				arrt.push_back(a[j]);
				count++;
				i++;
				j++;
			}
			else {
				if (a[j] == '+')
				{

					arrt.push_back('+');

					i++;
					j++;
					count++;
				}
				else if (a[j] == '*')
				{

					arrt.push_back('*');

					i++;
					j++;
					count++;
				}
				else if (a[j] == '/')
				{

					arrt.push_back('/');

					i++;
					j++;
					count++;
				}

				else if (a[j] == '-')
				{
					if (j == 0 || !arrt[i - 1].isValue() && !arrt[i - 1].isParameter() && arrt[i - 1].getOp() != ")")
					{

						lexeme z = "un-";
						arrt.push_back(z);           //???????????????????????????????

						i++;
						j++;
						count++;
					}
					else {

						arrt.push_back('-');
						i++;
						j++;
						count++;
					}

				}
				else if (a[j] == '(')
				{
					if (j != 0 && arrt[i - 1].isValue())
					{
						arrt.push_back('*');
						i++;
						count++;
					}
					if (j != 0 && (arrt[i - 1].isValue() || arrt[i - 1].isParameter()))
					{
						arrt.push_back('*');
						i++;
						count++;
					}

					arrt.push_back('(');
					i++;
					j++;
					count++;
				}
				else if (a[j] == ')')
				{

					arrt.push_back(')');
					i++;
					j++;
					count++;
					if (a[j] != '\0' && (a[j] >= '0' && a[j] <= '9' || a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z'))
					{
						arrt.push_back('*');
						i++;
						count++;
					}
				}
				else
				{
					arrt.push_back(a[j]);
					i++;
					j++;
				}
			}
		}
		else
		{
		    j++;
		}
	}
	
	return arrt;
}

int arithmetic::check(vector<lexeme> array, int kol)
{
	int count_of_errors = 0;
	int count_of_brackets = 0;

	for (int i = 0; i < kol; i++)
	{
		if (array[i].isValue() || array[i].isParameter())
		{
			if (i != kol - 1 && (array[i + 1].getOp() == "un-" || array[i + 1].isValue()))
			{
				cout << "После числа стоит небинарный оператор" << endl;
				count_of_errors++;
			}
			else if (array[i].isParameter() && array[i].getParameter() < "A" || (array[i].getParameter() > "Z" && array[i].getParameter() < "a") || array[i].getParameter() > "z")
			{
				cout << "  В Выражении присутствует недпустимый символ " << array[i].getParameter() << "\n\n";
				count_of_errors++;
			}
		}
		else {
			if (array[i].getOp() == "(")
			{
				count_of_brackets++;
			}
			if (array[i].getOp() == ")")
			{
				count_of_brackets--;
			}

			if (array[i].getOp() == "(" && i == kol - 1)
			{
				cout << "В конце выражения стоит недопустимый знак" << endl;
				count_of_errors++;
			}
			else if (array[i].getOp() == "(" && (array[i + 1].getOp() == "+" || array[i + 1].getOp() == "-" || array[i + 1].getOp() == "/" || array[i+1].getOp() == "*"))
			{
				cout << "После ( стоит недопустимый бинарный оператор" << endl;
				count_of_errors++;
			}
			else if (i != kol - 1 && array[i].getOp() == ")" && array[i + 1].getOp() == "un-" && array[i + 1].isValue())
			{
				count_of_errors++;
			}
			else if (i != kol - 1 && (array[i].getOp() != "un-" || array[i].getOp() != "(" || array[i].getOp() != ")") && (array[i + 1].getOp() != "un-" && array[i + 1].getOp() != "(" && array[i + 1].getOp() != ")") && !array[i+1].isValue() && !array[i+1].isParameter())
			{
				count_of_errors++;
			}
			else if (array[i].getOp() != "un-" && array[i].getOp() != "+" && array[i].getOp() != "-" && array[i].getOp() != "/" && array[i].getOp() != "*" && array[i].getOp() != "(" && array[i].getOp() != ")")
			{
				count_of_errors++;
			}
			else if (i == kol - 1 && array[i].getOp() != ")")
			{
				count_of_errors++;
			}
			else if (i == 0 && array[i].getOp() != "(" && array[i].getOp() != "un-")
			{
				count_of_errors++;
			}
			if (count_of_brackets < 0)
			{
				count_of_errors++;
			}
		}

	}
		if (count_of_brackets != 0)
		{
			cout << "Количество открывающихся скобок не равно количеству закрывающихся";
			count_of_errors++;
		}

		return count_of_errors;
}


vector<lexeme> arithmetic:: polish_notation(vector<lexeme> array)
{
	vector<lexeme> array2;
	
	Stack<lexeme> st;
	
	int l = 0;

	for (int k = 0; k < array.size(); k++)
	{
		if (array[k].isValue() || array[k].isParameter())
		{
			 array2.push_back(array[k]);
			
			l++;
		}
		else
		{
			if (st.isEmpty())
			{
				st.push(array[k]);
			}
			else
			{
				if (rang[array[k].getOp()] == 1)
				{
					st.push(array[k]);
				}
				else
				{
					while (!st.isEmpty() && rang[array[k].getOp()] <= rang[st.peek().getOp()])
					{
						if (rang[st.peek().getOp()] == 1)
						{
							st.pop();
							break;
						}
						else
						{
							array2.push_back(st.pop());
							l++;
						}
					}
					if (rang[array[k].getOp()] != 0)
					{
						st.push(array[k]);
					}
				}
			}
		}
	}

	while (!st.isEmpty())
	{
		 array2.push_back(st.pop());

		l++;
	}

	return array2;
}

double arithmetic::calculate(vector<lexeme> arrt)
{
	Stack<lexeme> s;
	lexeme t;
	double x1, x2;
	for (int i = 0; i < arrt.size(); i++)
	{
	
		if (arrt[i].isValue() || arrt[i].isParameter()) {
			if (arrt[i].isValue())
			{
				s.push(arrt[i]);
			}
			if (arrt[i].isParameter())
			{
				cout << "  Введите значение параметра " << arrt[i].getParameter() << "\n" << endl;
				cin >> x1;
				cout << "\n";
				s.push(x1);
			}
		}
		else
		{
			if (arrt[i].getOp() == "+")
			{
				x2 = s.pop().getValue();
				x1 = s.pop().getValue();
				t = x1 + x2;
			}
			if (arrt[i].getOp() == "-")
			{
				x2 = s.pop().getValue();
				x1 = s.pop().getValue();
				t = x1 - x2;
			}
			if (arrt[i].getOp() == "*")
			{
				x2 = s.pop().getValue();
				x1 = s.pop().getValue();
				t = x1 * x2;
			}
			if (arrt[i].getOp() == "/")
			{
				x2 = s.pop().getValue();
				x1 = s.pop().getValue();
				t = x1 / x2;
			}
			if (arrt[i].getOp() == "un-")
			{
				x2 = s.pop().getValue();
				t = -1 * x2;
			}
			s.push(t);
		}
	}

	return s.pop().getValue();
}
//#endif // ! _CALCULATOR_
