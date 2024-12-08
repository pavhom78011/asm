//Условие:Ввести координаты трех точек на плоскости. Если они могут быть вершинами равностороннего треугольника, то вычислить его площадь.
/*
Тесты:
Координаты первой точки(дробные числа вводить минимум с точностью до сотых):
x1:0
y1:0
Координаты второй точки(дробные числа вводить минимум с точностью до сотых):
x2:2
y2:0
Координаты третьей точки(дробные числа вводить минимум с точностью до сотых):
x3:1
y3:1.73
Площадь(C++):1.73205
Площадь(Assembler):1.73205


Координаты первой точки(дробные числа вводить минимум с точностью до сотых):
x1:5
y1:0
Координаты второй точки(дробные числа вводить минимум с точностью до сотых):
x2:20
y2:0
Координаты третьей точки(дробные числа вводить минимум с точностью до сотых):
x3:12.50
y3:12.99
Площадь(C++):97.4279
Площадь(Assembler):97.4278


Координаты первой точки(дробные числа вводить минимум с точностью до сотых):
x1:100
y1:0
Координаты второй точки(дробные числа вводить минимум с точностью до сотых):
x2:300
y2:0
Координаты третьей точки(дробные числа вводить минимум с точностью до сотых):
x3:200
y3:173.20
Площадь(C++):17320.5
Площадь(Assembler):17320.5


Координаты первой точки(дробные числа вводить минимум с точностью до сотых):
x1:7
y1:-1
Координаты второй точки(дробные числа вводить минимум с точностью до сотых):
x2:3
y2:99
Координаты третьей точки(дробные числа вводить минимум с точностью до сотых):
x3:7
y3:4.86
Площадь(C++):Треугольник не равносторонний
Assembler:Треугольник не равносторонний
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Координаты первой точки(дробные числа вводить минимум с точностью до сотых):" << endl;
	float x1{}, y1{}, x2{}, y2{}, x3{}, y3{};
	cout << "x1:";
	cin >> x1;
	cout << "y1:";
	cin >> y1;
	cout << "Координаты второй точки(дробные числа вводить минимум с точностью до сотых):" << endl;
	cout << "x2:";
	cin >> x2;
	cout << "y2:";
	cin >> y2;
	cout << "Координаты третьей точки(дробные числа вводить минимум с точностью до сотых):" << endl;
	cout << "x3:";
	cin >> x3;
	cout << "y3:";
	cin >> y3;
	float a{}, b{}, c{}, square{};//стороны треугольника и площадь
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	if ((a <= b + 0.01 and a >= b - 0.01) && (b <= c + 0.01 and b >= c - 0.01) && (a <= c + 0.01 and a >= c - 0.01))
	{
		square = (a * a * sqrt(3)) / 4;
		cout << "Площадь(C++):" << square << endl;
	}
	else
	{
		cout << "Площадь(C++):Треугольник не равносторонний" << endl;
	}
	a = 0;
	b = 0;
	c = 0;
	square = 0;
	float squareofthree = 1.73205;//корень из 3 для вычисления площади 
	float something = 0.01;
	float d = 4;
	_asm
	{
		fld x1
		fld x2
		fsubp st(1), st(0)
		fmul st(0), st(0)
		fld y1
		fld y2
		fsubp st(1), st(0)
		fmul st(0), st(0)
		faddp st(1), st(0)
		fsqrt
		fstp a//вычислили и поместили значение в переменную а(первая сторона)
		fld x2
		fld x3
		fsubp st(1), st(0)
		fmul st(0), st(0)
		fld y2
		fld y3
		fsubp st(1), st(0)
		fmul st(0), st(0)
		faddp st(1), st(0)
		fsqrt
		fstp b//вычислили и поместили значение в переменную b(вторая сторона)
		fld x3
		fld x1
		fsubp st(1), st(0)
		fmul st(0), st(0)
		fld y3
		fld y1
		fsubp st(1), st(0)
		fmul st(0), st(0)
		faddp st(1), st(0)
		fsqrt
		fstp c//вычислили и поместили значение в переменную c(третья сторона)
		fld a
		fld something
		faddp st(1), st(0)
		fld b
    	fcomip st(0), st(1)
		jb some1
		jmp endif
		some1:
		fld b
		fld something
		faddp st(1), st(0)
		fld a
		fcomip st(0), st(1)
		jb secondcheck
		jmp endif
		secondcheck:
		fld b
		fld something
		faddp st(1), st(0)
		fld c
		fcomip st(0), st(1)
		jb some2
		jmp endif
		some2:
		fld c
		fld something
		faddp st(1), st(0)
		fld b
		fcomip st(0), st(1)
		jb thirdcheck
		jmp endif
		thirdcheck:
		fld c
		fld something
		faddp st(1), st(0)
		fld a
		fcomip st(0), st(1)
		jb some3
		jmp endif
		some3:
		fld a
		faddp st(1), st(0)
		fld c
		fcomip st(0), st(1)
		jb result
		jmp endif
		result:
		fld a
		fld a
		fmulp st(1), st(0)
		fld squareofthree
		fmulp st(1), st(0)
		fld d
		fdivp st(1), st(0)
		fstp square
		jmp endifok
		endif:
		mov b, 1
		jmp endofasm
		endifok:
		mov b, 0
		endofasm:
		nop
	}
	if (b == 0)
	{
		cout << "Площадь(Assembler):" << square;
	}
	else
	{
		cout << "Assembler:Треугольник не равносторонний" << endl;
	}
}