#include "Trophy.h"
#include <iostream>

using namespace std;

// Initialize Default constructor to safe values
Trophy::Trophy()
{
	m_level = 0;
	m_name = "";
	m_color = GOLD;
}
// Constructor for three parameters
Trophy::Trophy(string& name, int level, Color& color)
{
	m_level = level;
	m_name = name;
	m_color = color;
}

// returns the name of the trophy
string Trophy::GetName()
{
	return m_name;
}
// returns the level of the trophy
int Trophy::GetLevel()
{
	return m_level;
}
// returns the color of the trophy
Color Trophy::GetColor()
{
	return m_color;
}
// property to change name of the trophy
void Trophy::SetName(string& name)
{
	m_name = name;
}
// property to change the level of the trophy
void Trophy::SetLevel(int level)
{
	m_level = level;
}
// property to change the color of the trophy
void Trophy::SetColor(Color color)
{
	m_color = color;
}
// print the trophy's information to the screen
void Trophy::Print()
{
	cout << "[ " << m_name << " : ";
	cout << m_level << " : ";
	cout << ColorToString(m_color) << " ]" << endl;
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
