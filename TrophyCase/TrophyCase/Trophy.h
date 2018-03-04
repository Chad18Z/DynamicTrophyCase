#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>

using namespace std;

// This is an enumeration of the three Trophy colors
enum Color { BRONZE, SILVER, GOLD };

class Trophy
{
public:
	Trophy();
	Trophy(string& name, int level, Color& color);
	string GetName();
	string ColorToString(Color& color);
	int GetLevel();
	Color GetColor();
	void SetColor(Color color);
	void SetName(string& name);
	void SetLevel(int level);
	void Print();


private:
	string m_name; // holds the trophy's name
	int m_level; // holds the trophy's level
	Color m_color; // holds the trophy's color
};

#endif
