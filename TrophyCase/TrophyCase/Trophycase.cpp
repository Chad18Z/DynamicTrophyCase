#include "Trophycase.h"
#include <iostream>

using namespace std;

// Initialize Default constructor to safe values
Trophycase::Trophycase()
{	
	m_count = new int(0);
	m_size = new int(5);
	Trophies = new Trophy*[5];
}
// return the total number of trophies in the case
int Trophycase::GetNumberOfTrophies()
{
	return *m_count;
}
// returns the size of the trophycase
int Trophycase::GetSizeOfTrophycase()
{
	return *m_size;
}
// Adds a new trophy to the trophycase
void Trophycase::AddTrophy(Trophy& trophy)
{
	// trophycase is full!
	if (*m_count >= *m_size)
	{		
		Trophy* tempArray = new Trophy[(*m_size) * 2]; // new array will be double the size of the original

		// fill the new array with the contents of the original
		for (int i = 0; i < *m_size; i++)
		{
			tempArray[i] = *Trophies[i];
		}
		*m_size *= 2; // double the size of the trophycase
		delete[] Trophies;
		Trophies = &tempArray;

		delete [] tempArray;
		tempArray = NULL;
	}

	// increment the counter
	m_count = new int(*m_count + 1);

	// add new trophy to the array
	Trophies[*m_count - 1] = new Trophy(trophy);
}
// return the trophy at this index
Trophy& Trophycase::GetTrophy(int index)
{
	return *Trophies[index];
}

// destructor
Trophycase::~Trophycase()
{
	delete[] Trophies;
	Trophies = NULL;
}
// delete the trophy at this index
void Trophycase::DeleteTrophy(int index)
{
	// decrement the number of trophies in the case
	*m_count--;

	// assign last trophy in array to the deleted trophy's position
	Trophies[index] = Trophies[*m_count];
}
// overload insertion operator
ostream& operator<< (ostream& sout, const Trophycase& trophycase)
{
	for (int i = 0; i < *trophycase.m_count; i++)
	{
		sout << *trophycase.Trophies[i];
	}
	return sout;
}
// Copy constructor
Trophycase::Trophycase(Trophycase& trophycaseToCopy)
{
	for (int i = 0; i < *trophycaseToCopy.m_size; i++)
	{
		Trophies[i] = new Trophy(trophycaseToCopy.GetTrophy(i));
	}
}
// assignment operator
Trophycase& Trophycase::operator= (const Trophycase& trophycaseToCopy)
{
	for (int i = 0; i < *trophycaseToCopy.m_count; i++)
	{
		*Trophies[i] = *trophycaseToCopy.Trophies[i];
	}
	return *this;
}






