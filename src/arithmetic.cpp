#include "arithmetic.h"

#define _CALCULATOR_

lexeme::lexeme(double m_value)
	: value(m_value)
	, isV(true)
{}

lexeme::lexeme(string a)
	: operation(a)
	, isV(false)
{}

void lexeme::operator=(double x)
{
	value = x;
	isV = true;
}

void lexeme::operator=(string x)
{
	operation = x;
	isV = false;
}

void lexeme::operator=(lexeme x)
{
	if (x.isValue())
	{
		value = x.value;
		isV = true;
	}
	else
	{
		operation = x.operation;
		isV = false;
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

double arithmetic::tokenizing_and_polish_notation(string& a)
{
	// разбиваем выражение на лексемы 
	int i = 0, j = 0;
	int count = 0;   //количество лексем
	double temp, x, d;
	lexeme array[1000];
	while (a[j] != '\0')
	{
		if (a[j] >= '0' && a[j] <= '9')
		{
			x = 0;
			d = 10;

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

			array[i] = x;
			count++;
			i++;
<<<<<<< HEAD
			if (a[j] != '\0' && (a[j] >= 'a' && a[j] <= 'z' || a[j] >= 'A' && a[j] <= 'Z'))
			{
				array[i++] = "*";
				count++;
			}
=======
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
		}

		else if (a[j] == '+')
		{
			array[i] = "+";
			i++;
			j++;
			count++;
		}
		else if (a[j] == '*')
		{
			array[i] = "*";
			i++;
			j++;
			count++;
		}
		else if (a[j] == '/')
		{
			array[i] = "/";
			i++;
			j++;
			count++;
		}
		else if (a[j] == '-')
		{
			if ((!array[i - 1].isValue()) && array[i - 1].getOp() != ")" || j == 0)
			{
				array[i++] = "un-";
				j++;
				count++;
			}
			else {
				array[i] = "-";
				i++;
				j++;
				count++;
			}
		}
		else if (a[j] == '(')
		{
			if (j != 0 && array[i].isValue())
			{
				array[i++] = "*";
				count++;
			}
			array[i] = "(";
			i++;
			j++;
			count++;
		}
		else if (a[j] == ')')
		{
			array[i] = ")";
			i++;
			j++;
			count++;
			if (a[j] != '\0' && (a[j] >= '0' && a[j] <= '9' || a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z'))
			{
				array[i++] = "*";
				count++;
			}
		}
		else if (a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z')
		{
			double curr;
			cout << "Введите значение " << a[j] << endl;
			cin >> curr;
			/*
			if (i != 0 && !arr[i].isV)
			{
				arr[i++] = "*";
				count++;
			}
			*/

			array[i] = curr;
			count++;
			i++;
			j++;

			while (a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z')
			{
				array[i] = "*";
				i++;
				count++;
				cout << "Введите значение " << a[j] << endl;
				cin >> curr;
				array[i] = curr;
				count++;
				i++;
				j++;
			}
		}
		else
		{
			cout << "Введен некорректный символ: " << a[j] << endl;
			throw exception("Введен некорректный символ");
		}
	}


	/*
	cout << "\n\n\n\n";
	for (int k = 0; k < count; k++)
	{
		if (array[k].isValue())
<<<<<<< HEAD
			cout << array[k].getValue() << endl;
=======
			cout << array[k].getV() << endl;
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
		else
			cout << array[k].getOp() << endl;
	}
	cout << "\n\n\n\n\n";
	*/

	if (check(array, count) == 0)
	{
		int count2 = count; // count2 будет равен количеству лексем без учета скобок


		//обратная польская запись 
		lexeme* array2 = new lexeme[count]{};
		Stack<lexeme> st;
		int l = 0;

		for (int k = 0; k < count; k++)
		{
			if (array[k].isValue())
			{
				//cout << arr[k].getValue() << endl;
				array2[l] = array[k];
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
					if (array[k].getOp() == ")")
					{
						count2--;
					}
					while (!st.isEmpty() && rang[array[k].getOp()] <= rang[st.peek().getOp()])
					{
						if (rang[st.peek().getOp()] == 1)
						{
							st.pop();
							count2--;
							break;
						}
						else
						{
							array2[l] = st.pop();
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
			array2[l] = st.pop();
			l++;
		}

<<<<<<< HEAD
		
=======
		/*
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
		cout << "Обратная польская запись выражения:" << endl;
		for (int k = 0; k < count2; k++)
		{
			if (array2[k].isValue())
				cout << array2[k].getValue() << " ";
			else
				cout << array2[k].getOp() << " ";
		}
		cout << "\n\n\n";

		cout << "Результат вычисления: " << endl;
<<<<<<< HEAD
		
=======
		*/
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
		double result = calculate(array2, count2);
		return result;
	}
	else
	{
	throw exception("Error in the expresion!");
	}


}

int arithmetic::check(lexeme* array, int kol)
{
	int count_of_errors = 0;
	int count_of_brackets = 0;
	for (int i = 0; i < kol; i++)
	{
		if (array[i].isValue())
		{
			if (i != kol - 1 && (array[i + 1].getOp() == "un-" || array[i + 1].isValue()))
			{
				cout << "После числа стоит небинарный оператор" << endl;
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
			else if (array[i].getOp() == "(" && (array[i + 1].getOp() == "+" || array[i + 1].getOp() == "-" || array[i + 1].getOp() == "/" || array->getOp() == "*"))
			{
				cout << "После ( стоит недопустимый бинарный оператор" << endl;
				count_of_errors++;
			}
<<<<<<< HEAD
			else if (i != kol - 1 && array[i].getOp() != ")" && !array[i + 1].isValue() && array[i + 1].getOp() != "un-" && array[i + 1].getOp() != "(" && array[i + 1].getOp() != ")")
			{
				count_of_errors++;
			}
			else if (i != kol - 1 && array[i].getOp() == ")" && array[i + 1].getOp() == "un-" && array[i + 1].isValue())
=======
			else if (i != kol - 1 && (!array[i + 1].isValue()) && array[i + 1].getOp() != "un-")
			{
				count_of_errors++;
			}
			else if (i == kol - 1 && array->getOp() != ")")
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
			{
				count_of_errors++;
			}
		}
<<<<<<< HEAD

		if (count_of_brackets != 0)
		{
			cout << "Количество открывающихся скобок не равно количеству закрывающихся";
			count_of_errors++;
		}
		return count_of_errors;
	}
=======
	}
		
	if (count_of_brackets != 0)
	{
		cout << "Количество открывающихся скобок не равно количеству закрывающихся";
		count_of_errors++;
	}
	return count_of_errors;
>>>>>>> cdf2b31cd9bd876f6e3828f405f2f1e7e3bad5d9
}

double arithmetic::calculate(lexeme* arrt, int kol)
{
	Stack<lexeme> s;
	lexeme t;
	double x1, x2;
	for (int i = 0; i < kol; i++)
	{
		if (arrt[i].isValue())
		{
			s.push(arrt[i]);
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
