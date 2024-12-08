//Условие:Дан A=(ai) ,  i=1..n,  (n<=10), массив  и число b. Переставить  числа  в массиве  таким  образом, чтобы сначала шли  элементы,
//меньшие или равные b, а лишь затем большие b.
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
void print(int a)
{
	cout << a << '\t';
}
void some()
{
	cout << '\n' << "Отсортированный массив с b:" << '\n';
}
void sortmassiv()
{
	cout << "Отсортированный массив:" << endl;
}
void printb()
{
	cout << "b" << '\t';
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(0)));
	cout << "Введите количество элементов(от 1 до 10):";
	int n, b;
	cin >> n;
	while (n < 1 || n>10)
	{
		cout << "Неправильный ввод." << "\n";
		cout << "Введите количество элементов(от 1 до 10):";
		n = 0;
		cin >> n;
	}
	cout << "Введите b:";
	cin >> b;
	int* massiv = new int[n];
	for (int i = 0; i < n; ++i)
	{
		massiv[i] = rand() % 100;
	}
	cout << "Массив случайных чисел(в диапозоне от 1 до 100):" << '\n';
	for (int i = 0; i < n; ++i)
	{
		cout << massiv[i] << " ";
	}
	cout << '\n';
	int something{};
	_asm
	{
		call sortmassiv
		mov eax,massiv
		mov ebx,0
		mov ecx,n
		mov something,ecx
		dec ecx

		startofasm:
		mov eax, massiv
		mov ebx, 0
		mov ecx, n
		dec ecx

		starting:
		dec ecx
		mov edi, [eax + 4 * ebx]
		mov esi, [eax + 4 * ebx + 4]
		cmp edi,esi
		jg beginning
		inc ebx
		cmp ecx, 1
		jge starting
		jmp repeat

		beginning:
		xchg edi, esi
		mov[eax + ebx * 4], edi
		mov[eax + ebx * 4 + 4], esi
		inc ebx
		cmp ecx, 1
		jl repeat
		jmp starting

		repeat:
		dec something
		cmp something,0
		jge startofasm
		jmp somethingif

		somethingif:
		mov ebx,0
		mov eax, massiv

		printing:
        mov edx, [eax + ebx * 4]
		push eax
		push ebx
		push edx
		call print
		pop edx
		pop ebx
		pop eax
		inc ebx
		cmp ebx, n
		jge print2
		jmp printing

		print2:
		call some
		mov ebx, 0
		mov eax, massiv
		mov something,1

		somethingif2:
		cmp ebx, n
		jge endofasm
		mov edx, [eax + ebx * 4]
		cmp b, edx
		jge printiflessorgreater
		cmp something,0
		jne printifb
		cmp b, edx
		jle printiflessorgreater

		printiflessorgreater:
		push eax
		push ebx
		push edx
		call print
		pop edx
		pop ebx
		pop eax
		inc ebx
		jmp somethingif2

		printifb:
		dec something
		push eax
		push ebx
		push edx
		call printb
		pop edx
		pop ebx
		pop eax
		push eax
		push ebx
		push edx
		call print
		pop edx
		pop ebx
		pop eax
		inc ebx
		jmp somethingif2

		endofasm:
		nop
	}
}