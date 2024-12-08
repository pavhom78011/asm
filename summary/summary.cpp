#include <iostream>
using namespace std;
extern "C" int _cdecl digitis(int);
extern "C" void _cdecl some(int,int[]);
extern "C" int _cdecl digits();
extern "C" int _cdecl printing();
void main()
{
	setlocale(LC_ALL, "rus");
	int x;
	cout << "Ведите x:";
	cin >> x;
	int n;
	cout << "Ведите n:";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "Число Y:";
	int Y = digitis(x);
	cout << Y << endl;

	int* b = new int [n] {};
	cout << "Массив b в начале:";
	for (int i = 0; i < n; ++i)
	{
		cout << b[i] << " ";
	}
	cout << '\n';
	some(n, a);
	cout << digits() << '\n';
	cout << "Массив b после(элементы меньшие Y и большие последнего элемента массива:" << '\n';
	for (int i = 0; i < n; ++i)
	{
		b[i] = printing();
		if (b[i] != -1)
		{
			cout << b[i] << "  ";
		}
		else
		{
			b[i] = 0;
		}
	}
}