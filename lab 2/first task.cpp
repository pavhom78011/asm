//Условие:
/*
y = -x ^ 2 + 1, если x <= -4.
y = sqrt(x + 12), если - 4 < x < 4.
y = tg(x), если 4 <= x < 6.
y = x ^ 2, если x >= 6.
*/
//Идея:для вычисления тангенса используем функцию tg на С++.
/*
Тесты:
Введите х:-8
y = -x * x + 1
C++:-63
Assembler:-63

Введите х:3
y = sqrt(x + 12)
C++:3.87298
Assembler:4

Введите х:5
y = tan (x)
C++:-3.38052
Assembler:-3

Введите х:11
y = x * x
C++:121
Assembler:121
*/
#include <iostream>
#include <cmath>
using namespace std;
int tg(int a)
{
	a = tan(a);
	return a;
}
int main()
{
	setlocale(LC_ALL, "rus");
	float x{}, y{};
	int n{}, m{};
	cout << "Введите х:";
	cin >> x;
	if (x <= -4)
	{
		y = -x * x + 1;
		cout << "y = -x * x + 1" << endl;
	}
	else if (x > -4 && x < 4)
	{
		y = sqrt(x + 12);
		cout << "y = sqrt(x + 12)" << endl;
	}
	else if (x >= 4 and x < 6)
	{
		y = tan(x);
		cout << "y = tan (x)" << endl;
	}
	else
	{
		y = x * x;
		cout << "y = x * x" << endl;
	}
	cout << "C++:" << y << endl;
	n = static_cast<int>(x);
	_asm
	{
		mov eax,n
		cmp eax,-4
		jle firstif
		cmp eax,4
		jl secondif
		cmp eax,6
		jl thirdif
		cmp eax,6
		jge endif
		firstif:
		mov eax, -1
		imul n
		imul n
		inc eax
		mov m,eax
		jmp endofprogramm
		secondif:
		add eax,12
		mov n,eax
		fild n
		fsqrt
		fistp m
		jmp endofprogramm
		thirdif:
		push eax
		call tg
		pop eax
		mov m,eax
	    jmp endofprogramm
		endif:
		imul n
		mov m,eax
		endofprogramm:
		nop
	}
	cout << "Assembler:" << m;
}