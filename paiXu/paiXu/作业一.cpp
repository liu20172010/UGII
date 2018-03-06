#include <iostream>

using namespace std;



int main()
{
	int a[] = { 21, 52, 13, 69, 58, 43, 22, 15, 8 ,2,2,2,2,1};
	cout << "ÅÅÐòÇ°£º";
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;


	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{

			if (a[i]>a[j])
			{
				a[i] = a[i] ^ a[j];
				a[j] = a[i] ^ a[j];
				a[i] = a[i] ^ a[j];
			}		
		}

	}

	cout << "ÅÅÐòºó£º";
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << "  " ;
	}
	system("pause");
	return 0;
}