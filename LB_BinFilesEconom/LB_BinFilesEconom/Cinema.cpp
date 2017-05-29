#include <iostream>
#include "Movie.h"

using namespace std;

Movie InitMovie();
Movie* InitArray(int);
void DisplayArray(Movie*, int);
void EnterArray(int*, int);
void SortFirstName(Movie*, int);
void Swap(Movie&, Movie&);

int main()
{
	int n;
	cout << "Enter the number of Movies:";
	cin >> n;
	system("cls");
	Movie* Movie = InitArray(n);
	if (!Movie)
	{
		cout << "Dynamic array doesn't exist!" << endl;
		system("pause");
		return 0;
	}
	cout << "The list of Movies : " << endl;
	DisplayArray(Movie, n);



	cout << "The sorting list of Movies:" << endl;;
	SortFirstName(Movie, n);
	DisplayArray(Movie, n);
	delete[] Movie;
	system("pause");
	return 0;
}

Movie InitMovie()
{
	char SetName[N] = "", SetProducerName[N] = "", SetProducerSurname[N] = "", SetCountry[N] = "";
	cout << "Enter the name of the Movie: " << endl;
	cin.ignore();
	cin.get(SetName, N, '\n');
	cout << "Enter the Producer Name: " << endl;
	cin.ignore();
	cin.get(SetProducerName, N, '\n');
	cout << "Enter the Producer Surname: " << endl;
	cin.ignore();
	cin.get(SetProducerSurname, N, '\n');
	cout << "Enter Ñountry : " << endl;
	cin.ignore();
	cin.get(SetCountry, N, '\n');

	int SetYear, SetCost, SetIncome, SetProfit;
	cout << "Enter the Year: " << endl;
	cin >> SetYear;
	cout << "Enter the Cost: " << endl;
	cin >> SetCost;
	cout << "Enter the Income: " << endl;
	cin >> SetIncome;
	cout << "Enter the Profit: " << endl;
	cin >> SetProfit;



	Movie Movie;
	Movie.SetMovie(SetName, SetProducerName, SetProducerSurname, SetYear, SetCountry, SetCost, SetIncome, SetProfit);
	return Movie;
}

Movie* InitArray(int n)
{
	Movie* array = new Movie[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the information about " << (i + 1) << "  Movie\n" << endl;
		array[i] = InitMovie();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

void DisplayArray(Movie* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayMovie();
	cout << endl;
}

void SortFirstName(Movie* array, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(array[j].GetName(), array[j - 1].GetName()) < 0)
				Swap(array[j], array[j - 1]);
}

void Swap(Movie &a, Movie &b)
{
	Movie t = a;
	a = b;
	b = t;
}