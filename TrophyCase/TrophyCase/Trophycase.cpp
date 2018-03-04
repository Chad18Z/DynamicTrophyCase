#include "Trophycase.h"
#include <iostream>

using namespace std;

// Initialize Default constructor to safe values
Trophycase::Trophycase()
{	
	m_count = 0;
	m_size = 5;
	Trophies = new Trophy[m_size];
}
// return the total number of trophies in the case
int Trophycase::GetNumberOfTrophies()
{
	return m_count;
}
// returns the size of the trophycase
int Trophycase::GetSizeOfTrophycase()
{
	return m_size;
}
// Adds a new trophy to the trophycase
void Trophycase::AddTrophy(Trophy& trophy)
{
	// trophycase is full!
	if (m_count >= m_size)
	{		
		Trophy* tempArray = new Trophy[m_size * 2]; // new array will be double the size of the original

		// fill the new array with the contents of the original
		for (int i = 0; i < m_size; i++)
		{
			tempArray[i] = Trophies[i];
		}
		m_size *= 2; // double the size of the trophycase
		delete[] Trophies;
		Trophies = tempArray;

		delete [] tempArray;
		tempArray = NULL;
	}

	// increment the counter
	m_count++;

	// add new trophy to the array
	Trophies[m_count-1] = trophy;
}
// return the trophy at this index
Trophy& Trophycase::GetTrophy(int index)
{
	return Trophies[index];
}

// destructor
Trophycase::~Trophycase()
{
	delete [] Trophies;
	Trophies = NULL;
}
// delete the trophy at this index
void Trophycase::DeleteTrophy(int index)
{
	// decrement the number of trophies in the case
	m_count--;

	// assign last trophy in array to the deleted trophy's position
	Trophies[index] = Trophies[m_count];
}





