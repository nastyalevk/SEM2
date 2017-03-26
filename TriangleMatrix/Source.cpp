#include<iostream>

using namespace std;

int* AllocateMemory(int n);
int** AllocateMemory(int n, int*arr);
void FillArray(int* a, int n);
void FillMatrix(int**, int*, int);
void DisplayArray(int* a, int n);
void DisplayMatrix(int **matrix, int n, int *arr);
void Swapping(int **matrix, int n, int *arr);
void Swap(int*&a, int*&b);
void Swap(int&a, int&b);

int main()
{
	int n = 6;
	int *arr = AllocateMemory(n);
	FillArray(arr, n);
	DisplayArray(arr, n);
	cout << endl;
	int **matrix = AllocateMemory(n, arr);
	FillMatrix(matrix, arr, n);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	Swapping(matrix, n, arr);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	system("pause");
	return 0;
}

int** AllocateMemory(int n, int *arr)
{
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[arr[i]];
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = 1;

	}
	return matrix;
}

void FillMatrix(int**matrix, int*arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= arr[i]; j++)
			matrix[i][j] = 1;
}
int* AllocateMemory(int n)
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 1;
	return arr;
}

void FillArray(int* a, int n)
{
	int i = n;
	for (int* p = a; p < a + n; p++)
	{
		*p = i;
		i--;
	}
}

void DisplayArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}

void DisplayMatrix(int **matrix, int n, int *arr)
{
	for (int i = 0; i <n; i++)
	{
		if (arr[i] != n)
			for (int j = n - 1; j >= arr[i]; j--)
			{
				cout.width(5);
				cout << 0;
			}
		for (int j = 0; j< arr[i]; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


void Swapping(int **matrix, int n, int *arr)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(matrix[i], matrix[n - i - 1]);
		Swap(arr[i], arr[n - i - 1]);
	}
}
void Swap(int*&a, int*&b)
{
	int*t = a;
	a = b;
	b = t;
}
void Swap(int&a, int&b)
{
	int t = a;
	a = b;
	b = t;
}
