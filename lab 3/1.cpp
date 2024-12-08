//Найти количество повторений каждой цифры  у заданного натурального числа (не используя массивов).	(Не использовать массив).
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	unsigned int N;
	cout << "Введите натуральное число:";
	cin >> N;
	int n1{}, n2{}, n3{}, n4{}, n5{}, n6{}, n7{}, n8{}, n9{}, n0{}, numberofdigits{};
	_asm
	{
		mov eax,N
		mov ebx,10
		mov esi, 1
		beginning:
		inc numberofdigits
		imul esi
		idiv ebx
		cmp eax,1
		jge beginning
		mov eax, N
		mov ecx,numberofdigits
		something:
		imul esi
		idiv ebx
		cmp edx,1
		je ostatok1
		cmp edx, 2
		je ostatok2
		cmp edx, 3
		je ostatok3
		cmp edx, 4
		je ostatok4
		cmp edx, 5
		je ostatok5
		cmp edx, 6
		je ostatok6
		cmp edx, 7
		je ostatok7
		cmp edx, 8
		je ostatok8
		cmp edx, 9
		je ostatok9
		cmp edx, 0
		je ostatok0
		ostatok9:
		inc n9
		jmp endasm
	    ostatok8:
		inc n8
		jmp endasm
	    ostatok7:
		inc n7
		jmp endasm
	    ostatok6:
        inc n6
		jmp endasm
	    ostatok5:
		inc n5
		jmp endasm
	    ostatok4:
		inc n4
		jmp endasm
	    ostatok3:
		inc n3
		jmp endasm
	    ostatok2:
		inc n2
		jmp endasm
	    ostatok1:
		inc n1
		jmp endasm
	    ostatok0:
		inc n0
	    endasm:
		nop
	    loop something
	}
	cout << "Количество повторений цифры 1:" << n1 << endl;
	cout << "Количество повторений цифры 2:" << n2 << endl;
	cout << "Количество повторений цифры 3:" << n3 << endl;
	cout << "Количество повторений цифры 4:" << n4 << endl;
	cout << "Количество повторений цифры 5:" << n5 << endl;
	cout << "Количество повторений цифры 6:" << n6 << endl;
	cout << "Количество повторений цифры 7:" << n7 << endl;
	cout << "Количество повторений цифры 8:" << n8 << endl;
	cout << "Количество повторений цифры 9:" << n9 << endl;
	cout << "Количество повторений цифры 0:" << n0 << endl;
}