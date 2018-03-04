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
	friend ostream& operator<< (ostream& sout, const Trophycase& trophy);
	Trophycase& operator= (const Trophycase& trophy);

private:
	Trophy* Trophies = new Trophy[5];
	int* m_size; // holds the trophy's level
	int* m_count; // holds the trophy's color
};

#endif


