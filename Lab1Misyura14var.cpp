#include <iostream>
#include <math.h>
using namespace std;

void _1z()
{
	double x1, x2, x3, y1, y2, y3, xmed12, xmed23, xmed31, ymed12, ymed23, ymed31, med1, med2, med3;
	setlocale(LC_ALL, "Russian");
	cout << "Введите x-координаты точек через пробел" << endl;
	scanf_s("%g %g %g", &x1, &x2, &x3);
	cout << "Введите y-координаты точек через пробел" << endl;
	scanf_s("%g %g %g", &y1, &y2, &y3);
	xmed12 = (x1 + x2) / 2;
	xmed23 = (x2 + x3) / 2;
	xmed31 = (x3 + x1) / 2;
	ymed12 = (y1 + y2) / 2;
	ymed23 = (y2 + y3) / 2;
	ymed31 = (y3 + y1) / 2;
	med1 = sqrt(((xmed12 - x3) * (xmed12 - x3)) + ((ymed12 - y3) * (ymed12 - y3)));
	med2 = sqrt(((xmed23 - x1) * (xmed23 - x1)) + ((ymed23 - y1) * (ymed23 - y1)));
	med3 = sqrt(((xmed31 - x2) * (xmed31 - x2)) + ((ymed31 - y2) * (ymed31 - y2))) ;
	cout << "Длины медиан:" << med1 << " " << med2 << " " << med3 << endl;
}

void _2z()
{
	double x, y;
	setlocale(LC_ALL, "Russian");
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Введите y" << endl;
	cin >> y;
	if (x < 0 && y < 0)
	{
		x = abs(x);
		y = abs(y);
	}
	else if (x < 0 || y < 0)
	{
		x = 1.5 * x;
		y = 1.5 * y;
	}
	else if (x > 2 && x < 0.5 && y>2 && y < 0.5)
	{
		x = x * 0.1;
		y = y * 0.1;
	}
	cout << "x=" << x << " y=" << y << endl;
}

void main()
{
	int x;
	setlocale(LC_ALL, "Russian");
	cout << "Выберите номер задания" << endl;
	cin >> x;
	if (x==1)
	{
		_1z();
	}
	else if (x==2)
	{
		_2z();
	}
	else
		cout << "некорректный номер задачи" << endl;
}