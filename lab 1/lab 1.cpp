//Y=(-x^3/3+7*a+x^3-2)/(3x^2Цb/7a+b)
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int x, a, b, c, d;
	int ed = 1;
	cout << "¬ведите x:";
	cin >> x;
	cout << "¬ведите a:";
	cin >> a;
	cout << "¬ведите b:";
	cin >> b;
	c = ((-x * x * x) / 3 + 7 * a + x * x * x - 2) / (3 * x * x - b / (7 * a) + b);
	cout << "C++=" << c << endl;
	c = 0;
	_asm
	{
		mov eax, x
		imul ed
		imul x
		imul x
		mov ebx,-1
		imul ebx
		mov ebx, 3
		imul ed
		idiv ebx
		mov ecx, eax
		mov eax, 7
		mov ebx, a
		imul ebx
		add ecx, eax
		mov eax, x
		imul x
		imul x
		add ecx, eax
		mov ebx, 2
		sub ecx, ebx
		mov c, ecx//c-перва€ скобка
		mov eax, 3
		mov ebx, x
		imul ebx
		imul ebx
		mov d, eax//d=3x^2
		mov ebx, a
		mov ecx, 7
		mov eax, b
		imul ed
		idiv ebx
		imul ed
		idiv ecx
		sub d, eax
		mov eax, b
		add d,eax//d-втора€ скобка
		mov eax, c
		imul ed
		idiv d
		mov d, eax//d-значение выражени€
	}
	cout << "Assembler=" << d << endl;
}