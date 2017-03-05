#include <iostream>

using namespace std;

double* AllocateMemory(int);
void DisplayArray(double*, int);
void RandArray(double*, int);
void IntegerArray(double*, int);
void BinaryInteger(double*, int);
float AB(double*, int, int, int, int);
void addElement(double*, double, int);
int countOne(double *, int, int);
void bubbleSort(double *, int);


int main()
{

	int n, length = 0;
	cout << "Plese, enter length of array " << endl;
	while (true)
	{
		cin >> n;
		if (n > 0) break;
		else cout << "Please enter positive size of array" << endl;
	}

	double *arr = AllocateMemory(n);
	RandArray(arr, n);
	IntegerArray(arr, n);
	DisplayArray(arr, n);
	//BinaryInteger(arr, length);
	int a;
	cout << "Enter a(one): ";
	cin >> a;
	int b;
	cout << "Enter b(zero): ";
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		if (!(AB(arr, n, i, a, b)))
		{
			length++;

		}
	}
	double *arr1 = AllocateMemory(length);
    int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(AB(arr, n, i, a, b)))
		{
			addElement(arr1, arr[i], pos);
			pos++;
		}
	}
	DisplayArray(arr1, length);
	bubbleSort(arr1, length);
	BinaryInteger(arr1, length);
	DisplayArray(arr1, length);
	system("pause");
}

double* AllocateMemory(int n)
{
	double* arr = new double[n];
	for (double* p = arr; p < arr + n; p++)
		*p = 0;
	return arr;
}

void RandArray(double *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
}

void DisplayArray(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}

void IntegerArray(double* arr, int size)
{
	for (int i=0; i <= size ; i++)
	{
		arr[i] = (int)arr[i];
	}
}

void BinaryInteger(double* arr1, int size)
{
	for (int i = 0; i <= size; i++)
	{
		int n;
		int p = 0;
		n = arr1[i];
		arr1[i] = 0;
		while (n)
		{
			arr1[i] += (n % 2) * pow(10, p);
			n = n / 2;
			p++;
		}
	}
}

float AB(double* arr, int size, int  i, int a, int b)
{
	int countOne=0, countZero=0;
	double mod;
	int temp = (int)arr[i];
	while (temp)
	{
		mod = temp % 2;
		if (mod)
			countOne++;
		else
			countZero++;
		temp = temp / 2;
	}
	if (countOne == a && countZero == b)
		return true;
	else
		return false;
}
int countOne(double *arr1, int n, int i)
{
	int countOne = 0, mod;
	int temp = (int)arr1[i];
		while (temp)
		{
			mod =temp % 2;
			if (mod)
				countOne++;
			temp = temp / 2;

		}
	return countOne;
}
void bubbleSort(double* arr1, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (countOne(arr1, n, i) > countOne(arr1, n, j) )
			{
				double k = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = k;
			}
		}
	}

}
void addElement(double* arr1, double el, int pos)
{
	arr1[pos] = el;
}