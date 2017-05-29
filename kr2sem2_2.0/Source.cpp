#include <iostream> 
#include<fstream>

using namespace std;

void enterArr(int* arr, int n);
void printArr(int* arr, int n);
void newArrT(int* arr1, int* arr2, int n, int i);
void newArrF(int* arr1, int* arr2, int n, int i);
int* readFile(char* fileName);
void createFile(char* fileName, int n);
int contentsFile(char*);
int* initArray(char* fileName, int n);
bool primeNumber(int n);

int main()
{

	char* fileName = "text.txt";
	int n;
	cout << "kol-vo elementov" << endl;
	cin >> n;
	createFile(fileName, n);
	int* arr1 = initArray(fileName, n);
	int* arr2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (primeNumber(arr1[i]))
			newArrT(arr1, arr2, n, i);
		else
			newArrF(arr1, arr2, n, i);
	}

	cout << endl;
	cout << "Arr2 =";
	printArr(arr2, n);
	cout <<endl;
	system("pause");
	return 0;
}

int contentsFile(char* fileName)
{
	ifstream in(fileName); // פאיכמגûי גגמה
	if (!in.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		exit(1);
	}
	int count = 0, term;
	while (!in.eof())
	{
		in >> term;
		cout << term;
		count++;
	}
	in.close();
	return count;
}
int* initArray(char* fileName, int n)
{
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		in >> arr[i];
		cout << arr[i] << "  ";
	}
	in.close();
	return arr;
}
int* readFile(char* fileName) {
	ifstream streamIn(fileName);

	if (!streamIn.is_open()) {
		cout << "can not open file to write" << endl;
		exit(1);
	}

	int size = 0, *t;
	streamIn >> size;
	t = new int[size];
	for (int i = 0; i < size; i++)
		streamIn >> t[i];

	streamIn.close();
	return t;
}
void createFile(char* fileName, int n) 
{
	ofstream streamOut(fileName);// פאיכמגûי גûגמה

	if (!streamOut.is_open()) {
		cout << "can not open file to write" << endl;
		exit(1);
	}

	int temp = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (flag) 
		{
			flag = false;
			streamOut  << " ";
		}
		cout << "Input temp: ";
		cin >> temp;
		streamOut << " " << temp<<endl;
	}

	streamOut.close();;
}
void enterArr(int* arr, int n)
{
	cout << "Array " << endl;
	for (int i = 0; i < n; i++)
		cin >> *(arr + i);
}
void printArr(int* arr, int n)
{
	for (int* p = arr; p < arr + n; p++)
	{
		cout << " " << *p;
	}
}
void newArrT(int* arr1, int* arr2, int n, int i)
{
	
		*(arr2 + i) = *(arr1 + i);
			cout << endl << *(arr2 + i) <<"-prime" ;

}
void newArrF(int* arr1, int* arr2, int n, int i)
{

	*(arr2 + i) = *(arr1 + i);
	cout << endl << *(arr2 + i) <<"- not prime" ;

}
bool primeNumber(int n)
{
	int n1 = n;
	bool o = false;
	for (int i = 2; i <= (n1 / 2); i++)
	{
		if (n1 % i == 0)
		{
			o = true;
			break;
		}
	}
	if (o == true) return false;
	else return true;
}