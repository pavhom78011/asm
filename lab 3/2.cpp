//Найти все меньшие N натуральные числа, которые при возведении в квадрат дают палиндром. 
#include <iostream>
using namespace std;
void print(int a)
{
	cout << a << endl;
}
void main()
{
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите число N:";
	cin >> N;
	int n(1);
	int ost[20]{};
	_asm
	{
		numbers:
		mov eax,n
		mov edi,1//перед делением
		mov esi,10//для остатков
		mov ebx,0//индексы массива
		imul n
		mov edx,n
		cmp edx,N
		jl ostatki
		jmp endasm

		ostatki:
		imul edi
		idiv esi
		mov [ost+ebx*4],edx
		inc ebx
		cmp eax,0
		jg ostatki
		mov ecx,20
		mov ebx, 0

		palindrom:
		mov edx, [ost + ebx * 4]
		add eax,edx
		cmp [ost + (ebx+1) * 4],1
		jl compare
		imul esi
		inc ebx
		loop palindrom

		compare:
		mov ecx,n
		xchg eax,ecx
		imul n
		cmp eax,ecx
		je printif
		inc n
		jmp numbers

		printif:
		push n
		call print
		pop n
		inc n
		jmp numbers

		endasm:
		nop
	}
}