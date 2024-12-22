#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double e = pow(10, -6.0); // эпсилон, точность вычислений

double f(double x) // вычисление функции
{
	return 3 * x - 4 * log(x) - 5;
}

void func(double a, double b, double (*f)(double))
{
	double c; // переменная середины отрезка

	do
	{
		c = (a + b) / 2.0;
		if (f(a) * f(c) <= 0) // проверка на наличие корня в отрезке [a;c]
			b = c; // если корень есть, то новый конец отрезка = c
		else
			a = c; // иначе c = новое начало отрезка

		cout << "Отрезок [" << a << ';' << b << ']' << endl;
	} while (abs(a - b) >= e); // пока не будет достигнута точност вычислений 

	cout << "Корень уравнения - " << c << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b; // переменные начала и конца отрезка, в котором находится корень

	cout << "Введите значения начала и конца отрезка: ";
	cin >> a >> b;

	func(b, a, f);

	return 0;
}

