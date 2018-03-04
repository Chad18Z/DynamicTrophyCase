#include "Trophy.h"
#include "Trophycase.h"
#include <iostream>

using namespace std;

// Declare function prototypes
void DisplayWelcomeMessage();
void DisplayGoodbyeMessage();
void ExitApplication();
string GetString(string);
int GetShiftValue(string);
void AddNewTrophy();
void CopyTrophy();
void DeleteTrophy();
void RenameTrophy();
void ChangeLevelTrophy();
void ChangeColorTrophy();
void PrintTrophies();
void PrintMenu();
int FindIndexOfTrophy(string&);

Trophycase* Trophies = new Trophycase(); // declare a trophycase

// Entry point for the application
int main()
{
	
	int inputFromUser; // Initialize variable to hold user input

	DisplayWelcomeMessage(); // Show the welcome message
							 // Main loop of the application
	do
	{
		inputFromUser = 0;
		PrintMenu();	// Display the menu

		cin >> inputFromUser; // Get input from the user

		switch (inputFromUser)
		{
		case 1:
			AddNewTrophy(); // User chooses to add a trophy
			break;
		case 2:
			CopyTrophy(); // User chooses to copy a trophy
			break;
		case 3:
			DeleteTrophy(); // User chooses to delete a trophy
			break;
		case 4:
			RenameTrophy(); // User chooses to rename a trophy
			break;
		case 5:
			ChangeLevelTrophy(); // User chooses to change the level of a trophy
			break;
		case 6:
			ChangeColorTrophy(); // User chooses to change the color of a trophy
			break;
		case 7:
			PrintTrophies(); // User chooses to print all of the trophies
			break;
		case 8:
			ExitApplication(); // User chooses to exit application
			break;
		}

	} while (inputFromUser != 8);

	return 0;
}
// This function displays the welcome message
void DisplayWelcomeMessage()
{
	cout << "Welcome to the Trophy application! With this application" << endl
		<< "you can manage Trophies! To do this" << endl
		<< "select one the options from the menu." << endl << endl;
}

// This function displays the main menu
void PrintMenu()
{
	cout << "********************************************************************************" << endl
		<< "* Please select an option:" << endl
		<< "* 1 - Add a new Trophy" << endl
		<< "* 2 - Copy a Trophy" << endl
		<< "* 3 - Delete a Trophy" << endl
		<< "* 4 - Rename a Trophy" << endl
		<< "* 5 - Change the level of a Trophy" << endl
		<< "* 6 - Change the color of a Trophy" << endl
		<< "* 7 - Print all the Trophies" << endl
		<< "* 8 - Exit the program" << endl
		<< "********************************************************************************" << endl;
}
// This function displays the goodbye message
void DisplayGoodbyeMessage()
{
	cout << "Thanks for using our application." << endl
		<< "Please hit ENTER to exit" << endl;
}
// This function exits the application
void ExitApplication()
{
	DisplayGoodbyeMessage();
	int userInput; // Variable to hold user input
	cin >> userInput; // Get input from user
	exit(0); // Exit application
}

// Get an integer value from the user
int GetShiftValue(string message)
{

	int userInput; // Declare variable to hold input from the user
	do
	{
		cout << endl << message << endl; // Display prompt to the user
		cin >> userInput; // Get input from user

	} while (userInput < 1 || userInput > 50); // Check to be sure the user enters valid integers
	return userInput;
}
// Gets a string of characters from the user
string GetString(string message)
{
	char userInput[50];
	cout << endl << message << endl; // Display prompt to the user	
	cin.ignore();
	cin.clear();
	cin.get(userInput, 50); // get input from user
	return userInput;
}

// Adds a new trophy to the array
void AddNewTrophy()
{
	string trophyName = GetString("Please enter the trophy's name: ");
	int trophyLevel = GetShiftValue("Please enter the trophy's level: ");
	Color trophyColor;
	string tempColor = "";
	do
	{
		string tempColor = GetString("Please enter the trophy's color  BRONZE, SILVER, or GOLD (case sensitive): ");
		if (tempColor == "GOLD")
		{
			trophyColor = GOLD;
			tempColor = "";
		}
		else if (tempColor == "BRONZE")
		{
			trophyColor = BRONZE;
			tempColor = "";
		}
		else if (tempColor == "SILVER")
		{
			trophyColor = SILVER;
			tempColor = "";
		}
		else { tempColor = " "; }
	} while (tempColor != "");


	Trophy newTrophy(trophyName, trophyLevel, trophyColor); // instantiate new trophy
	Trophies->AddTrophy(newTrophy);
	cout << "New trophy added" << endl;
}

// Copies one trophy's information to a new trophy
void CopyTrophy()
{
	string trophyName = GetString("Please enter the trophy's name that you want to copy: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	Trophy newTrophy(Trophies->GetTrophy(indexOfTrophy));
	Trophies->AddTrophy(newTrophy); // add new trophy to array
}

// Remove a trohpy from the array.....also frees the memory
void DeleteTrophy()
{
	int indexOfTrophy;
	
	do 
	{
		string trophyName = GetString("Please enter the trophy's name that you want to delete: ");
		indexOfTrophy = FindIndexOfTrophy(trophyName);
	} while (indexOfTrophy == -1);
		
	Trophies->DeleteTrophy(indexOfTrophy);
	cout << endl << "Trophy deleted." << endl;
}
// Change a trophy's name
void RenameTrophy()
{
	int indexOfTrophy;
	do 
	{
		string trophyName = GetString("Please enter the trophy's name that you want to rename: ");
		indexOfTrophy = FindIndexOfTrophy(trophyName);
	} while (indexOfTrophy == -1);
	
	
	string NewName = GetString("Please enter the trophy's new name: ");
	Trophy& trophy = Trophies->GetTrophy(indexOfTrophy);
	trophy.SetName(NewName);
	cout << endl << "Name Changed to: " << NewName << endl;
}
// Change a trophy's level
void ChangeLevelTrophy()
{
	int indexOfTrophy;
	do 
	{
		string trophyName = GetString("Please enter the trophy's name that you want to relevel: ");
		indexOfTrophy = FindIndexOfTrophy(trophyName);
	} while (indexOfTrophy == -1);

	if (indexOfTrophy == -1)
	{
		cout << "Not a valid name";
		return;
	}
	int trophyLevel = GetShiftValue("Please enter the trophy's level: ");
	Trophy& trophy = Trophies->GetTrophy(indexOfTrophy);
	trophy.SetLevel(trophyLevel);
	cout << endl << "Trophy's level changed" << endl;
}
// Change a trophy's color
void ChangeColorTrophy()
{
	int indexOfTrophy;
	do
	{
		string trophyName = GetString("Please enter the trophy's name which you want to change the color: ");
		indexOfTrophy = FindIndexOfTrophy(trophyName);
	} while (indexOfTrophy == -1);

	Color trophyColor = GOLD;
	string tempColor = "";
	do
	{
		string tempColor = GetString("Please enter the trophy's color  BRONZE, SILVER, or GOLD (case sensitive): ");
		if (tempColor == "GOLD")
		{
			Trophy& newTrophy = Trophies->GetTrophy(indexOfTrophy);
			newTrophy.SetColor(GOLD);
			tempColor = "";
		}
		else if (tempColor == "BRONZE")
		{
			Trophy& newTrophy = Trophies->GetTrophy(indexOfTrophy);
			newTrophy.SetColor(BRONZE);
			tempColor = "";
		}
		else if (tempColor == "SILVER")
		{
			Trophy& newTrophy = Trophies->GetTrophy(indexOfTrophy);
			newTrophy.SetColor(SILVER);
			tempColor = "";
		}
	} while (tempColor != "");
}
// Displays all of the existing trophies to the screen
void PrintTrophies()
{
	cout << "All existing trophies." << endl << endl;
	for (int i = 0; i < Trophies->GetNumberOfTrophies(); i++)
	{
		Trophy& trophy = Trophies->GetTrophy(i);
		trophy.Print();
	}
}
// this method find the index of the trophy. Assuming they all have unique names.
int FindIndexOfTrophy(string& testString)
{
	int index = -1;
	for (int i = 0; i < Trophies->GetNumberOfTrophies(); i++)
	{
		string name = Trophies->GetTrophy(i).GetName();
		if (name.substr(0, name.find(' ')) == testString.substr(0, testString.find(' ')))
		{
			index = i;
		}
	}
	return index;
}
















