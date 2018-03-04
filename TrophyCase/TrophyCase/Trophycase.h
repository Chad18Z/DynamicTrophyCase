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
	void AddTrophy(Trophy& trophy);
	int GetNumberOfTrophies();
	int GetSizeOfTrophycase();
	Trophy& GetTrophy(int index);
	void DeleteTrophy(int index);

private:
	Trophy* Trophies;
	int m_size; // holds the trophy's level
	int m_count; // holds the trophy's color
};

#endif


