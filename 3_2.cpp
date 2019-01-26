#include <iostream>
#include <math.h>
using namespace std;

#define eps 0.00001

double function1(double x, double y)
{
	return sin(x + y) - 1.2*x - 0.2;
}

double function2(double x, double y)
{
	return x*x + y*y - 1;
}

double func1dx(double x, double y)
{
	return cos(x + y) - 1.2;
}

double func1dy(double x, double y)
{
	return cos(x + y);
}

double func2dx(double x, double y)
{
	return 2 * x;
}

double func2dy(double x, double y)
{
	return 2 * y;
}

void ober_matr(double a[2][2])
{
	double det, aa;
	det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
	aa = a[0][0];
	a[0][0] = a[1][1] / det;
	a[1][1] = aa / det;
	aa = a[0][1];
	a[0][1] = -a[0][1] / det;
	a[1][0] = -a[1][0] / det;
}

void nuton(double x, double y)
{
	int i = 1;
	double a[2][2], dx, dy, b[2], norm;
	do
	{
		a[0][0] = func1dx(x, y);
		a[0][1] = func1dy(x, y);
		a[1][0] = func2dx(x, y);
		a[1][1] = func2dy(x, y);
		ober_matr(a);
		dx = -a[0][0] * function1(x, y) + -a[0][1] * function2(x, y);
		dy = -a[1][0] * function1(x, y) + -a[1][1] * function2(x, y);
		x = x + dx;
		y = y + dy;
		b[0] = function1(x, y);
		b[1] = function2(x, y);
		norm = sqrt(b[0] * b[0] + b[1] * b[1]);
		i++;
	} while (norm >= eps);
	cout <<"X = "<<  x << endl <<"Y = "<< y << endl;
	cout <<"Количество итераций = "<< i << endl;

	cout<< "Проверка : \n" << function1(x,y) << endl << function2(x,y) << endl;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	double x, y;
	cout << "Начальное приближение x: ";
	cin >> x;
	cout << "Начальное приближение  y: ";
	cin >> y;
	nuton(x, y);
	cout << endl;
	return 0;
}
