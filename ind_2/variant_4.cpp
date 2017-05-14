#include<iostream>
#include<math.h>


using namespace std;

double** AllocateMemory(int n, int*arr);
double Sinus(double x, double eps);
double AddEll_1(int i, int j, int e, double eps);
double AddEll_2(int i, int j, int e);
double** FillMatrix_1(double n, double eps, double e);
double** FillMatrix_2(double n, double eps, double e);
void DisplayArray(double* a, int n);
void DisplayMatrix(double**matrix, int n);

int main()
{

	int n;
	cout << "Plese, enter size of matrix: " << endl;
	while (true)
	{
		cin >> n;
		if (n > 1) break;
		else cout << "Plese, enter size of matrix: " << endl;
	}
	double eps;
	cout << "Plese, enter accuracy: " << endl;
	while (true)
	{
		cin >> eps;
		if (eps > 0 && eps < 1 ) break;
		else cout << "Plese, enter accuracy: " << endl;
	}
	double e = exp(1);
	double **matrix_1S = FillMatrix_1(n, eps, e);
	cout << "Matrix 1"<< endl;
	DisplayMatrix(matrix_1S, n);
	cout << endl;
	double **matrix_2 = FillMatrix_2(n, eps, e);
	cout << "Matrix 2"<< endl;
	DisplayMatrix(matrix_2, n);
	system("pause");
	return 0;
}


double** AllocateMemory(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

double Sinus(double x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term *= (-1) * x * x / (2 * i * (2 * i + 1));
	}
	return sum;
}

double AddEll_1(int i, int j, int e, double eps)
{
	if (i == j)
		return (i + j)*pow(e, i + j) / Sinus((double)(2 * i), eps) + 4;
	else return i - j;
}

double AddEll_2(int i, int j, int e)
{
	if (i == j)
		return (i + j)*pow(e, i + j) / (sin(2 * i) + 4);
	else return i - j;
}

double** FillMatrix_1(double n, double eps, double e)
{
	double** matrix = AllocateMemory(n);
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		matrix[i][j] = AddEll_1(i, j, e, eps);
return matrix;
}

double** FillMatrix_2(double n, double eps, double e)
{
	double** matrix = AllocateMemory(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = AddEll_2(i, j, e);
	return matrix;
}

void DisplayArray(double* a, int n)
{
	for (double* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}

void DisplayMatrix(double**matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		DisplayArray(matrix[i], n);
		cout << endl;
	}
}

