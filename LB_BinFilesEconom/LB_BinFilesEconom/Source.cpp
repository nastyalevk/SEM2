#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie()
{

}

Movie::~Movie()
{

}

void Movie::SetName(char* s)
{
	strcpy(Name, s);
}

void Movie::SetProducerName(char* s)
{
	strcpy(ProducerName, s);
}

void Movie::SetProducerSurname(char* s)
{
	strcpy(ProducerSurname, s);
}

void Movie::SetYear(int YearN)
{
	this->YearN = YearN;
}

void Movie::SetCountry(char* s)
{
	strcpy(Country, s);
}

void Movie::SetCost(int CostN)
{
	this->CostN = CostN;
}

void Movie::SetIncome(int IncomeN)
{
	this->IncomeN = IncomeN;
}

void Movie::SetProfit(int ProfitN)
{
	this->ProfitN = ProfitN;
} 
void  Movie::SetMovie(char* s1, char* s2, char* s3, int n1, char* s4, int n2, int n3, int n4)
{
	SetName(s1);
	SetProducerName(s2);
	SetProducerSurname(s3);
	SetYear(n1);
	SetCountry(s4);
	SetCost(n2);
	SetIncome(n3);
	SetProfit(n4);
}


char* Movie::GetName()
{
	return Name;
}
char* Movie::GetProducerName()
{
	return ProducerName;
}
char* Movie::GetProducerSurname()
{
	return ProducerSurname;
}
int Movie::GetYear()
{
	return YearN;
}
char* Movie::GetCountry()
{
	return Country;
}
int Movie::GetCost()
{
	return CostN;
}
int Movie::GetIncome()
{
	return IncomeN;
}
int Movie::GetProfit()
{
	return ProfitN;
}


void  Movie::DisplayMovie()
{
	cout << endl << Name << ": " << ProducerName <<" " << ProducerSurname;
	cout.precision(3);
	cout << "Year: "<<YearN << "  , \t" << "Country: " << Country << "  , \t" << "Cost: " << CostN << "  , \t" << "Income: " << IncomeN << "  , \t" << "Profit: " << ProfitN << "  . \t";

}