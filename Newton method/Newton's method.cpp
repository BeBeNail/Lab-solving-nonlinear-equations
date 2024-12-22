#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double e = pow(10, -6.0); // эпсилон, точность вычислений

double f(double x) // вычисление функции
{
	return 3 * x - 4 * log(x) - 5;
}

double f1(double x) // вычисление первой производной функции
{
	return 3 - (4 / x);
}

double f2(double x) // вычисление второй производной функции
{
	return 4 / pow(x, 2.0);
}

void func(double x1, double x0, double (*f)(double), double (*f1)(double)) // функция вычисления корня
{
	while (abs(x1 - x0) >= e) // пока не будет достигнута точност вычислений 
	{
		x0 = x1;
		x1 = x0 - (f(x0) / f1(x0));
		cout << "x0 = " << x0 << "; x1 = " << x1 << endl;
	}
	cout << "Корень уравнения - " << x1 << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b; // переменные начала и конца отрезка, в котором находится корень
	double x0, x1; // переменные, которые будут хранить значеня корня

	cout << "Введите значения начала и конца отрезка: ";
	cin >> a >> b;

	if (f(a) * f2(a) > 0) // определяем с какой стороны подходить
		x0 = a;
	else
		x0 = b;

	x1 = x0 - (f(x0) / f1(x0)); // находим x1 от начального значения x0

	cout << "x0 = " << x0 << "; x1 = " << x1 << endl;

	func(x1, x0, f, f1);

	return 0;
}



	