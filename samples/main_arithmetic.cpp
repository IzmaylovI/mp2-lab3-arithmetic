#include <iostream>
#include "arithmetic.h"
#include "stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << " ������� ��������� ��� ��������, ������� ����� ��������� " << endl;
	cout << " ���������� ������� ��� ������������� " << endl;
	cout << "\n\n";
	string h;
	arithmetic vr;
	cin >> h;
	cout << "\n\n";
	cout << "\t\t" << vr.tokenizing_and_polish_notation(h);

	cout << "\n\n";
}
