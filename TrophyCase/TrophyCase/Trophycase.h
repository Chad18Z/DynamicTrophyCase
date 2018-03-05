#ifndef TROPHYCASE_H
#define TROPHYCASE_H

#include <iostream>
#include <string>
#include "Trophy.h"

using namespace std;


class Trophycase
{
public:
	Trophycase();
	~Trophycase();
	Trophycase(Trophycase& trophycaseToCopy);
	void AddTrophy(Trophy& trophy); // copy contructor
	int GetNumberOfTrophies();
	int GetSizeOfTrophycase();
	Trophy& GetTrophy(int index);
	void DeleteTrophy(int index);
	friend ostream& operator<< (ostream& sout, const Trophycase& trophycase);
	Trophycase& operator= (const Trophycase& trophy);

private:
	Trophy** Trophies;
	int* m_size; // size of the case
	int* m_count; // number of trophies in case
};

#endif


