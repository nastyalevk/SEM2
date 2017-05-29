#pragma once

const int N = 20;
const int M = 5;
class Movie
{
public:
	Movie();
	~Movie();

	void SetName(char*);
	void SetProducerName(char*);
	void SetProducerSurname(char*);
	void SetYear(int);
	void SetCountry(char*);
	void SetCost(int);
	void SetIncome(int);
	void SetProfit(int);
	void SetMovie(char*, char*, char*, int, char*, int, int, int);

	void DisplayMovie();


	char* GetName();
	char* GetProducerName();
	char* GetProducerSurname();
	int   GetYear();
	char* GetCountry();
	int   GetCost();
	int   GetIncome();
	int   GetProfit();


private:
	char Name[N], ProducerName[N], ProducerSurname[N], Country[N];
	int YearN, CostN, IncomeN, ProfitN;

};