#include <iostream>
#include "arithmetic.h"
#include "stack.h"

using namespace std;

//Повторное вычисление этого выражения
//Если имеются переменные, то им можно присвоить другие значения 
void povtornoe_vychyslenie_vyrazhenia(lexeme* polish)
{
	arithmetic vr;
	cout << vr.calculate(polish, vr.getCounteer());
}

lexeme* new_calculating()
{
	cout << " Введите выражение без пробелов, которые нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);
	lexeme* polish = vr.polish_notation(tok);
	cout << vr.calculate(polish, vr.getCounteer());

	return polish;
}
void tokenizing()
{
	cout << " Введите выражение без пробелов, которые нужно разбить на лексемы" << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);
	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i] << " ";
	}
	cout << "\n\n";


}

void tokenizng_and_polish_notation()
{
	cout << " Введите выражение без пробелов, которые нужно разбить на лексемыи перевести в постфиксную запись" << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);
	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i] << " ";
	}

	lexeme* polish = vr.polish_notation(tok);
	for (int i = 0; i < vr.getCounteer(); i++)
	{
		cout << polish[i] << " ";
	}
}

void how_it_works()
{
	cout << " Введите выражение без пробелов, которые нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);

	cout << "1) Выражение разбивается на отдельные лексемы" << endl;
	cout << "   Введенное выражение состоит из следующих лексем: " << endl;
	
	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i];
	}
	cout << "\n\n";

	lexeme* polish = vr.polish_notation(tok);

	cout << "2) Программа переводит выражение в обратную польскую(постфиксную) запись";
	cout << "   Постфиксная запись имеет следующий вид: " << endl;
	
	for (int i = 0; i < vr.getCounteer(); i++)
	{
		cout << polish[i] << " ";
	}
	cout << "\n\n";
	
	cout << "3) Присвавивание значений переменным(если они есть) и вычисление результата" << endl;
	cout << "\n\n";
	cout << vr.calculate(polish, vr.getCounteer());
}

void main_interface()
{
	cout << " Выберите, что Вы хотите сделать" << "\n\n";
	cout << "1) Демонстрация работы программы" << endl;
	cout << "2) Вычисление выражения" << endl;
	cout << "3) Разбиение выражения на лексемы" << endl;
	cout << "4) Разбиение выражения на лексемы и перевод в обратную польскую запись " << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "\t\t" <<  "-----------------------------------------------------" << endl;;
	cout << "\t\t" <<  "| Программа для вычисления арифметических вырыжаний |" << endl;
	cout << "\t\t"  << "-----------------------------------------------------";
	cout << "\n\n\n\n";
	
	main_interface();
	int p;
	cout << "\n";
	cout << "  ";
	cin >> p;
	cout << "\n";

	switch (p)
	{
	case 1:
		how_it_works();
		break;

	case 2:
		new_calculating();
		break;
	case 3:
		tokenizing();
		break;
	case 4: 
		tokenizng_and_polish_notation();
		break;
	}
}

