#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double e = pow(10, -6.0); // эпсилон, точность вычислений

double f(double x) // вычисление функции
{
	return 3 * x - 4 * log(x) - 5;
}

double func(double a, double b)
{
	double c = (a + b) / 2.0;

	if (fabs(f(a) - f(b)) < e)
		return c;
	
	if (f(a) * f(c) <= 0)
		return func(a, c);
	else
		return func(c, b);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b; // переменные начала и конца отрезка, в котором находится корень

	cout << "Введите значения начала и конца отрезка: ";
	cin >> a >> b;

	cout << "Корень уравнения - " << func(a, b) << endl;
	return 0;
}

