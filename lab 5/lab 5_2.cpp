//Условие:Задана  последовательность   A=(ai),  i=1..n, n<=100. Найти элемент,
//который повторяется наибольшее количество  раз и количество его повторений.
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
void some()
{
	cout << "элементы,которые повторяются наибольшее количество раз или элемент, который повторяется наибольшее количество  раз:" << endl;
}
void numberofrep(int a)
{
	cout << '\n' << "Количество повторений:" << a;
}
void print(int a)
{
	cout << a << '\t';
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(0)));
	int n;
	cout << "Введите n(количество элементов массива(от 1 до 100)):";
	cin >> n;
	while (n < 1 or n>100)
	{
		cout << "Неправильный ввод." << "\n";
		cout << "Введите n(количество элементов массива(от 1 до 100)):";
		n = 0;
		cin >> n;
	}
	int* array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = (rand() % 40) + 1;
		cout << array[i] << "\t";
		if (i % 10 == 9)
		{
			cout << "\n";
		}
	}
	int array2[100]{};
	int array3[100]{};
	int max{};
	_asm
	{
		call some
		mov edx,array
		mov ebx,0
		mov esi,0
		
		starting:
		mov eax, [array2 + esi * 4]	
		cmp [edx + ebx * 4], eax
		je equalif
		cmp eax,0
		je zeroif
		inc esi
		cmp ebx,n
		jl starting
		jmp something

		equalif:
		inc [array3 + esi * 4]
		mov eax, [edx + ebx * 4]
		mov [array2 + esi * 4], eax
		xor esi, esi
		inc ebx
		jmp starting

		zeroif:
		mov eax, [edx + ebx * 4]
        mov [array2 + esi * 4], eax
		inc [array3 + esi * 4]
		inc ebx
		mov esi,0
		jmp starting

		something:
		xor ebx, ebx
		xor edx,edx

		maxelement:
		mov eax, [array3 + ebx * 4]
		cmp max,eax
		jl moving
		inc ebx
		cmp ebx,n
		jg whatprint
		jmp maxelement
		
		moving:
		mov eax, [array3 + ebx * 4]
		mov max, eax
		inc ebx
		cmp ebx, n
		jg printing
		jmp maxelement

		whatprint:
		mov eax, [array3 + edx * 4]
		cmp max, eax
		je printing
		inc edx
		cmp edx, n
		jg endif
		jmp whatprint

		printing:
		mov ecx, [array2 + edx * 4]
		push edx
		push ecx
		call print
		pop ecx
		pop edx
		inc edx
		cmp edx, n
		jg endif
		jmp whatprint

		endif:
		push max
		call numberofrep
		pop max
	}
}