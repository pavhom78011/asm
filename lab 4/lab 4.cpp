#include <iostream>
using namespace std;
void str()
{
	cout << '\n' << "Если у числа в 2 с/с убрать все нули:";
}
void str2()
{
	cout << '\n' << "Если поменять 0 и 1 местами:" << endl;
}
void str3()
{
	cout << '\n' << "Инверсия:";
}
void print(int a)
{
	cout << a;
}
void space()
{
	cout << '\n';
}
void printing(int a)
{
	cout << '\n' << a << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int n{};
	cout << "Введите число:";
	cin >> n;
	int massiv[32]{};
	cout << "Число в 2 с.с.:" << endl;
	_asm
	{
		mov esi, 1
		mov ebx, 2
		mov eax, n
		xor ecx,ecx

		starting:
		imul esi
		idiv ebx
		mov[massiv + 4 * ecx], edx
		inc ecx
		cmp eax, 1
		jge starting
		mov ecx, 32

		printingif:
		mov ebx, [massiv + 4 * (ecx - 4)]
		push ecx
		push ebx
		call print
		pop ebx
		pop ecx
		loop printingif

		call str
		call space
		mov eax, n
		mov ebx, 2
		reverseif:
		imul esi
		idiv ebx
		cmp edx, 1
		je printif
		cmp eax, 1
		jge reverseif
		jmp inverting

		printif:
		push ecx
		push eax
		push edx
		call print
		pop edx
		pop eax
		pop ecx
		cmp eax, 1
		jge reverseif

		call str2
		mov ecx, 32
		inverting:
		mov eax, [massiv + 4 * (ecx - 4)]
		dec ecx
		cmp eax,1
		je something
		mov eax, 1
		push ecx
		push eax
		call print
		pop eax
		pop ecx
		cmp ecx,0
		jg inverting
		jmp notif

		something:
		mov eax,0
		push ecx
	    push eax
		call print
		pop eax
		pop ecx
		cmp ecx, 0
		jg inverting

		notif:
		mov eax, n
		not eax
		push eax
		call str3
		call printing
		pop eax

		endif:
		nop
	}
}