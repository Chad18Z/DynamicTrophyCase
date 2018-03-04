#include "Trophy.h"
#include <iostream>

using namespace std;

// Initialize Default constructor to safe values
Trophy::Trophy()
{
	m_level = new int (0);
	m_name = new string("");
	m_color = new Color(GOLD);
}
// Constructor for three parameters
Trophy::Trophy(string& name, int level, Color& color)
{
	m_level = new int(level);
	m_name = new string(name);
	m_color = new Color(color);
}
// destructor
Trophy::~Trophy()
{
	delete m_level;
	m_level = NULL;
	delete m_name;
	m_name = NULL;
	delete m_color;
	m_color = NULL;
}

// Copy constructor
Trophy::Trophy(Trophy& trophyToCopy)
{
	m_name = new string(*trophyToCopy.m_name);
	m_color = new Color(*trophyToCopy.m_color);
	m_level = new int(*trophyToCopy.m_level);
}
// assignment operator
Trophy& Trophy::operator= (const Trophy& trophy)
{
	m_name = new string(*trophy.m_name);
	m_color = new Color(*trophy.m_color);
	m_level = new int(*trophy.m_level);
	return *this;
}

// returns the name of the trophy
string Trophy::GetName()
{
	return *m_name;
}
// returns the level of the trophy
int Trophy::GetLevel()
{
	return *m_level;
}
// returns the color of the trophy
Color Trophy::GetColor()
{
	return *m_color;
}
// property to change name of the trophy
void Trophy::SetName(string& name)
{
	*m_name = name;
}
// property to change the level of the trophy
void Trophy::SetLevel(int level)
{
	*m_level = level;
}
// property to change the color of the trophy
void Trophy::SetColor(Color color)
{
	*m_color = color;
}
// print the trophy's information to the screen
void Trophy::Print()
{
	cout << "[ " << *m_name << " : ";
	cout << *m_level << " : ";
	cout << ColorToString(*m_color) << " ]" << endl;
}
// this function converts a Color value to a string
string Trophy::ColorToString(Color& color)
{
	switch (color)
	{
	case 0:
		return "BRONZE";
		break;
	case 1:
		return "SILVER";
		break;
	case 2:
		return "GOLD";
		break;
	default:
		return "ERROR";
		break;
	}

	return "";
}
