#include <iostream>
#include "arithmetic.h"
#include "stack.h"

using namespace std;

void main_interface();


void povtornoe_vychyslenie_vyrazhenia(vector<lexeme> polish)
{
	arithmetic vr;
	cout << vr.calculate(polish);

	cout << "\n\n";

	cout << " 1) Посчитать это выражение еще раз " << endl;
	cout << " 2) Вернуться в главное меню" << endl;
	cout << " 3) Выйти из программы" << endl;

	int p;
	cout << "  ";
	cin >> p;
	cout << "\n";


	switch (p)
	{
	case 1:
		povtornoe_vychyslenie_vyrazhenia(polish);
		break;
	case 2:
		main_interface();
		break;
	case 3:
		break;
	}
}



void new_calculating()
{
	cout << " Введите выражение без пробелов, которое нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	
	vector<lexeme> tok = vr.tokenizing(h);
	vector<lexeme> polish = vr.polish_notation(tok);
	vr.check(tok, tok.size());
	cout << vr.calculate(polish);

	cout << "\n\n";

	cout << " 1) Посчитать это выражение еще раз " << endl;
	cout << " 2) Вернуться в главное меню" << endl;
	cout << " 3) Выйти из программы" << endl;

	int p;
	cout << "  ";
	cin >> p;
	cout << "\n";


	switch (p)
	{
	case 1:
		povtornoe_vychyslenie_vyrazhenia(polish);
		break;
	case 2:
		main_interface();
		break;
	case 3:
		break;
	}
}


void tokenizing()
{
	cout << " Введите выражение без пробелов, которое нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);

	cout << "1) Выражение разбивается на отдельные лексемы" << endl;
	cout << "   Введенное выражение состоит из следующих лексем " << endl;

	
	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i] << " ";
	}
	cout << "\n\n";
}

void tokenizng_and_polish_notation()
{
	cout << " Введите выражение без пробелов, которое нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);
	
	cout << "1) Выражение разбивается на отдельные лексемы" << endl;
	cout << "   Введенное выражение состоит из следующих лексем " << endl;


	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i] << " ";
	}
	cout << "\n\n";

	cout << "2) Программа переводит выражение в обратную польскую(постфиксную) запись " << endl;
	cout << "   Постфиксная запись имеет следующий вид: " << endl;

	vector<lexeme> polish = vr.polish_notation(tok);

	for (int i = 0; i < polish.size(); i++)
	{
		cout << polish[i] << ' ';
	}

	cout << "\n\n";
}


void how_it_works()
{
	cout << " Введите выражение без пробелов, которое нужно вычислить " << endl;
	cout << " Переменные вводите без коэффициентов " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	vector<lexeme> tok = vr.tokenizing(h);

	
	cout << "1) Выражение разбивается на отдельные лексемы" << endl;
	cout << "   Введенное выражение состоит из следующих лексем " << endl;

	for (int i = 0; i < tok.size(); i++)
	{
		cout << tok[i] << ' ';
	}

	cout << "\n\n";
	
	cout << vr.check(tok, tok.size());

	cout << "2) Выражение проверяется на корректность:\n\n";
	cout << "3) Программа переводит выражение в обратную польскую(постфиксную) запись " << endl;
	cout << "   Постфиксная запись имеет следующий вид: " << endl;
	

	vector<lexeme> polish = vr.polish_notation(tok);
	
	for (int i = 0; i < polish.size(); i++)
	{
		cout << polish[i] << ' ';
	}

	cout << "\n\n";
	cout << "4) Присваивание значений перменным(если они есть) и вычисление результата " << endl;

	cout << vr.calculate(polish);
	
	cout << "\n\n";

	cout << " 1) Посчитать это выражение еще раз " << endl;
	cout << " 2) Вернуться в главное меню" << endl;
	cout << " 3) Выйти из прграммы" << endl;

	int p;
	cout << "  ";
	cin >> p;
	cout << "\n";


	switch (p)
	{
	case 1:
		povtornoe_vychyslenie_vyrazhenia(polish);
		break;
	case 2:
		main_interface();
		break;
	case 3:
		break;
	}
}

void main_interface()
{
	cout << " Выберите, что Вы хотите сделать" << "\n\n";
	cout << "1) Демонстрация работы программы" << endl;
	cout << "2) Вычисление выражения" << endl;
	cout << "3) Разбиение выражения на лексемы" << endl;
	cout << "4) Разбиение выражения на лексемы и перевод в обраиную польскую запись " << endl;

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


int main()
{

	cout << "\n\n";
	setlocale(LC_ALL, "Rus");
	cout << "\t\t" << "-----------------------------------------------------" << endl;;
	cout << "\t\t" << "| Программа для вычисления арифметических выражений |" << endl;
	cout << "\t\t" << "-----------------------------------------------------";
	cout << "\n\n\n\n";

	main_interface();
}
