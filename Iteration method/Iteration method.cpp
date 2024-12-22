#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double e = pow(10, -6.0); // эпсилон, точность вычислений

double g(double x) // вычисление итерационной функции
{
	return (4 * log(x) + 5) / 3;
}

void func(double x1, double x0, double (*g)(double)) // функция поиска корня
{
	while (abs(x1 - x0) >= e) // пока не будет достигнута точност вычислений 
	{
		x0 = x1;
		x1 = g(x0);
		cout << "x0 = " << x0 << "; x1 = " << x1 << endl;
	}
	cout << "Корень уравнения - " << x1 << endl;
}

double g1(double x) // вычисление первой производной функции
{
	return 4 / (3 * x);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b; // переменные начала и конца отрезка, в котором находится корень
	double x0, x1; // переменные, которые будут хранить значеня приближения к корню

	cout << "Введите значения начала и конца отрезка: ";
	cin >> a >> b;

	if (abs(g1(a)) < 1) // определяем с какой стороны подходить
		x0 = a;
	else
		x0 = b;

	x1 = g(x0); // находим x1 от начального значения x0

	cout << "x0 = " << x0 << "; x1 = " << x1 << endl;

	func(x1, x0, g);

	return 0;
}




