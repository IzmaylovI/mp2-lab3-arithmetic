#include "arithmetic.h"
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef

#define _CALCULATOR_

lexeme::lexeme(double m_value)
	: value(m_value)
	, isV(true)
<<<<<<< HEAD
{}

lexeme::lexeme(string a)
	: operation(a)
	, isV(false)
{}
=======
	, isPa(false)
{}

/*
lexeme:: lexeme(char m_parameter)
	: isV(false)
	, isPa(true)
	, parameter(m_parameter)
{}
*/

lexeme::lexeme(string a)
	: isV(false)
{
	if (a == "+" || a == "-" || a == "/" || a == "*" || a == "un-" || a == "(" || a == ")")
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
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef

void lexeme::operator=(double x)
{
	value = x;
	isV = true;
<<<<<<< HEAD
=======
	isPa = false;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
}

void lexeme::operator=(string x)
{
<<<<<<< HEAD
	operation = x;
	isV = false;
}

=======
	if (x == "+" || x == "-" || x == "/" || x == "*" || x == "un-" || x == ")" || x == "(")
	{
		isPa = false;
		isV = false;
		operation = x;
	}
	else
	{
		isPa = true;
		isV = false;
		parameter = x;
	}
}


>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
void lexeme::operator=(lexeme x)
{
	if (x.isValue())
	{
		value = x.value;
		isV = true;
<<<<<<< HEAD
	}
	else
	{
		operation = x.operation;
		isV = false;
	}
}
=======
		isPa = false;
	}
	else
	{
		if (x.isParameter())
		{
			parameter = x.parameter;
			isV = false;
			isPa = true;
		}
		else
		{
			operation = x.operation;
			isV = false;
			isPa = false;
		}
	}
}



>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
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
<<<<<<< HEAD
		if (getOp() != x.getOp())
		{
			flag = 0;
=======
		if (x.isParameter())
		{
			if (getParameter() != x.getParameter())
				flag = 0;
		}
		else
		{
			if (getOp() != x.getOp())
				flag = 0;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
		}
	}
	return flag;
}

<<<<<<< HEAD
double arithmetic::tokenizing_and_polish_notation(string& a)
{
	// ��������� ��������� �� ������� 
	int i = 0, j = 0;
	int count = 0;   //���������� ������
	double temp, x, d;
	lexeme array[1000];
=======
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

vector<lexeme> arithmetic::tokenizing(string& a)
{
	// разбиваем выражение на лексемы 
	int i = 0, j = 0;
	int count = 0;   //количество лексем
	double temp, x, d;
	lexeme array[1000];
	vector<lexeme> arrt;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
	while (a[j] != '\0')
	{
		if (a[j] >= '0' && a[j] <= '9')
		{
			x = 0;
			d = 10;
<<<<<<< HEAD
=======
			if (i != 0 && arrt[i - 1].isParameter())
			{
				lexeme z = "*";
				arrt.push_back(z);
				count++;
				i++;
			}
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef

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

<<<<<<< HEAD
			array[i] = x;
			count++;
			i++;
			if (a[j] != '\0' && (a[j] >= 'a' && a[j] <= 'z' || a[j] >= 'A' && a[j] <= 'Z'))
			{
				array[i++] = "*";
				count++;
=======
			//array[i] = x;
			lexeme z = x;
			arrt.push_back(z);
			count++;
			i++;
			if (a[j] != '\0' && (a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z'))
			{
				lexeme z = "*";
				arrt.push_back(z);
				count++;
				i++;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			}
		}

		else if (a[j] == '+')
		{
<<<<<<< HEAD
			array[i] = "+";
=======
			//array[i] = "+";
			lexeme z = "+";
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			i++;
			j++;
			count++;
		}
		else if (a[j] == '*')
		{
<<<<<<< HEAD
			array[i] = "*";
=======
			//array[i] = "*";
			lexeme z = "*";
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			i++;
			j++;
			count++;
		}
		else if (a[j] == '/')
		{
<<<<<<< HEAD
			array[i] = "/";
=======
			//array[i] = "/";
			lexeme z = "/";
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			i++;
			j++;
			count++;
		}
		else if (a[j] == '-')
		{
<<<<<<< HEAD
			if ((!array[i - 1].isValue()) && array[i - 1].getOp() != ")" || j == 0)
			{
				array[i++] = "un-";
=======
			//if ((!array[i - 1].isValue()) && array[i - 1].getOp() != ")" || j == 0)
			if (j == 0 || !arrt[i - 1].isValue() && !arrt[i - 1].isParameter() && arrt[i - 1].getOp() != ")")
			{
				//array[i++] = "un-";
				lexeme z = "un-";
				arrt.push_back(z);
				i++;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				j++;
				count++;
			}
			else {
<<<<<<< HEAD
				array[i] = "-";
=======
				//array[i] = "-";
				lexeme z = "-";
				arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				i++;
				j++;
				count++;
			}
		}
		else if (a[j] == '(')
		{
<<<<<<< HEAD
			if (j != 0 && array[i].isValue())
			{
				array[i++] = "*";
				count++;
			}
			array[i] = "(";
=======
			//if (j != 0 && array[i].isValue())
			if (j != 0 && (arrt[i - 1].isValue() || arrt[i - 1].isParameter()))
			{
				//array[i++] = "*";
				lexeme z = "*";
				arrt.push_back(z);
				i++;
				count++;
			}
			//array[i] = "(";
			lexeme z = "(";
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			i++;
			j++;
			count++;
		}
		else if (a[j] == ')')
		{
<<<<<<< HEAD
			array[i] = ")";
=======
			//array[i] = ")";
			lexeme z = ")";
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			i++;
			j++;
			count++;
			if (a[j] != '\0' && (a[j] >= '0' && a[j] <= '9' || a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z'))
			{
<<<<<<< HEAD
				array[i++] = "*";
=======
				//array[i++] = "*";
				lexeme z = "*";
				arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				count++;
			}
		}
		else if (a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z')
		{
<<<<<<< HEAD
			double curr;
			cout << "������� �������� " << a[j] << endl;
			cin >> curr;
=======
			//double curr;
			//cout << "Введите значение " << a[j] << endl;
			//cin >> curr;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			/*
			if (i != 0 && !arr[i].isV)
			{
				arr[i++] = "*";
				count++;
			}
			*/

<<<<<<< HEAD
			array[i] = curr;
=======
			//array[i] = curr;
			char tt = a[j];
			string zzz = "";
			zzz += tt;
			lexeme z = zzz;
			arrt.push_back(z);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			count++;
			i++;
			j++;

			while (a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z')
			{
<<<<<<< HEAD
				array[i] = "*";
				i++;
				count++;
				cout << "������� �������� " << a[j] << endl;
				cin >> curr;
				array[i] = curr;
				count++;
				i++;
				j++;
=======
				//array[i] = "*";
				string qq = "*";
				arrt.push_back(qq);
				i++;
				count++;
				char tt = a[j];
				//stringstream strStream;
				string zzz = "";
				zzz += tt;
				lexeme z = zzz;
				arrt.push_back(z);
				i++;
				j++;
				count++;
				//cout << "Введите значение " << a[j] << endl;
				//cin >> curr;
				//array[i] = curr;
				//cout << arrt[i].getParameter() << endl;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			}
		}
		else
		{
<<<<<<< HEAD
			cout << "������ ������������ ������: " << a[j] << endl;
			throw exception("������ ������������ ������");
		}
	}


	/*
	cout << "\n\n\n\n";
	for (int k = 0; k < count; k++)
	{
		if (array[k].isValue())
			cout << array[k].getValue() << endl;
		else
			cout << array[k].getOp() << endl;
	}
	cout << "\n\n\n\n\n";
	*/

	if (check(array, count) == 0)
	{
		int count2 = count; // count2 ����� ����� ���������� ������ ��� ����� ������


		//�������� �������� ������ 
		lexeme* array2 = new lexeme[count]{};
		Stack<lexeme> st;
		int l = 0;

		for (int k = 0; k < count; k++)
		{
			if (array[k].isValue())
			{
				//cout << arr[k].getValue() << endl;
				array2[l] = array[k];
=======
		    //cout << "Введен некорректный символ: " << a[j] << endl;
			//throw exception("Incorrect symbol");
			string zzzz = "";
			zzzz += a[j];
			lexeme z = zzzz;
			arrt.push_back(z);
			i++;
			j++;
		}

	}
	/*
		for (int u = 0; u < arrt.size(); u++)
		{
			cout << arrt[u] << " ";
		}
		*/
		
/*
	cout << "\n\n\n\n";
	check(arrt, arrt.size());
*/

	return arrt;
}

lexeme* arithmetic::polish_notation(vector<lexeme> arrt)
{
		int count2 = arrt.size(); // count2 будет равен количеству лексем без учета скобок

		//обратная польская запись 
		lexeme* array2 = new lexeme[count2]{};
		Stack<lexeme> st;
		int l = 0;
		vector<lexeme> result;

		for (int k = 0; k < arrt.size(); k++)
		{
			if (arrt[k].isValue() || arrt[k].isParameter())
			{
				//cout << arr[k].getValue() << endl;
				array2[l] = arrt[k];
				result.push_back(arrt[k]);
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				l++;
			}
			else
			{
				if (st.isEmpty())
				{
<<<<<<< HEAD
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
=======
					//string z = arrt[k].getOp();
					st.push(arrt[k]);
	
				}
				else
				{
				if (rang[arrt[k].getOp()] == 1)
				{
					st.push(arrt[k]);
				}
				else
				{
					if (arrt[k].getOp() == ")")
					{
						count2--;
					}
					if (arrt[k].getOp() == "un-" && st.peek().getOp() == "un-")
					{
						//result.push_back(st.peek());
						st.push(arrt[k].getOp());
						//k++;
					}
					else
					{
						while (!st.isEmpty() && rang[arrt[k].getOp()] <= rang[st.peek().getOp()])
						{

							if (rang[st.peek().getOp()] == 1)
							{
								st.pop();
								count2--;
								break;
							}
							else
							{
								result.push_back(st.peek());
								array2[l] = st.pop();
								l++;
							}
						}
						if (rang[arrt[k].getOp()] != 0)
						{

							st.push(arrt[k]);
						}
					}
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				}
				}
			}
		}

		while (!st.isEmpty())
		{
<<<<<<< HEAD
=======
			result.push_back(st.peek());
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
			array2[l] = st.pop();
			l++;
		}

<<<<<<< HEAD
		
		cout << "�������� �������� ������ ���������:" << endl;
		for (int k = 0; k < count2; k++)
		{
			if (array2[k].isValue())
				cout << array2[k].getValue() << " ";
			else
				cout << array2[k].getOp() << " ";
		}
		cout << "\n\n\n";

		cout << "��������� ����������: " << endl;
		
		double result = calculate(array2, count2);
		return result;
	}
	else
	{
	throw exception("Error in the expresion!");
	}


}

int arithmetic::check(lexeme* array, int kol)
=======
		/*
		for (int qqq = 0; qqq < result.size(); qqq++)
		{
			cout << result[qqq] << " ";
		}
		*/
		counteer = count2;
		return array2;
}

int arithmetic::check(vector<lexeme> array, int kol)
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
{
	int count_of_errors = 0;
	int count_of_brackets = 0;
	for (int i = 0; i < kol; i++)
	{
<<<<<<< HEAD
		if (array[i].isValue())
		{
			if (i != kol - 1 && (array[i + 1].getOp() == "un-" || array[i + 1].isValue()))
			{
				cout << "����� ����� ����� ���������� ��������" << endl;
=======
		if (array[i].isValue() || array[i].isParameter())
		{
			if (i != kol - 1 && (array[i + 1].getOp() == "un-" || array[i + 1].isValue() || array[i+1].isParameter()))
			{
				//cout << "После числа стоит небинарный оператор" << endl;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
				count_of_errors++;
			}
		}
		else {
<<<<<<< HEAD
=======
			if (count_of_brackets < 0)
			{
				throw exception("Некорректный ввод");
			}
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
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
<<<<<<< HEAD
				cout << "� ����� ��������� ����� ������������ ����" << endl;
				count_of_errors++;
			}
			else if (array[i].getOp() == "(" && (array[i + 1].getOp() == "+" || array[i + 1].getOp() == "-" || array[i + 1].getOp() == "/" || array->getOp() == "*"))
			{
				cout << "����� ( ����� ������������ �������� ��������" << endl;
				count_of_errors++;
			}
			else if (i != kol - 1 && array[i].getOp() != ")" && !array[i + 1].isValue() && array[i + 1].getOp() != "un-" && array[i + 1].getOp() != "(" && array[i + 1].getOp() != ")")
			{
				count_of_errors++;
			}
			else if (i != kol - 1 && array[i].getOp() == ")" && array[i + 1].getOp() == "un-" && array[i + 1].isValue())
			{
				count_of_errors++;
			}
		}

		if (count_of_brackets != 0)
		{
			cout << "���������� ������������� ������ �� ����� ���������� �������������";
			count_of_errors++;
		}
		return count_of_errors;
	}
=======
				//cout << "В конце выражения стоит недопустимый знак" << endl;
				throw exception("Некорректный ввод");
				count_of_errors++;
			}
			else if (array[i].getOp() == "(" && (array[i + 1].getOp() == "+" || array[i + 1].getOp() == "-" || array[i + 1].getOp() == "/" || array[i+1].getOp() == "*"))
			{
				//cout << "После ( стоит недопустимый бинарный оператор" << endl;
				throw exception("Некорректный ввод");
				count_of_errors++;
			}
			else if (i != kol - 1 && (!array[i + 1].isValue() && !array[i+1].isParameter()) && array[i + 1].getOp() != "un-")
			{
				throw exception("Некорректный ввод");
				count_of_errors++;
			}
			else if (i == kol - 1 && !array[i].isParameter() && !array[i].isValue() && array[i].getOp() != ")")
			{
				throw exception("Некорректный ввод");
				count_of_errors++;
			}
		}
		if (!array[i].isValue() && !array[i].isParameter() && (array[i].getOp() != "+" || array[i].getOp() != "/" || array[i].getOp() != "-" || array[i].getOp() != "*" || array[i].getOp() != "un-"))
		{
			throw exception("Недопустимый символ");
		}
	}
		
	if (count_of_brackets != 0)
	{
		throw exception("Некорректный ввод");
		//cout << "Количество открывающихся скобок не равно количеству закрывающихся";
		count_of_errors++;
	}
	return count_of_errors;
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
}

double arithmetic::calculate(lexeme* arrt, int kol)
{
	Stack<lexeme> s;
	lexeme t;
	double x1, x2;
	for (int i = 0; i < kol; i++)
	{
<<<<<<< HEAD
		if (arrt[i].isValue())
		{
			s.push(arrt[i]);
=======
		if (arrt[i].isValue() || arrt[i].isParameter()) {
			if (arrt[i].isValue())
			{
				s.push(arrt[i]);
			}
			if (arrt[i].isParameter())
			{
				cout << "Введите значение параметра " <<  arrt[i].getParameter() << endl;
				cin >> x1;
				s.push(x1);
			}
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
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
<<<<<<< HEAD
}
=======
}
>>>>>>> c434110eab1f41d6dfbe87f33a4bdfc0ac00ecef
