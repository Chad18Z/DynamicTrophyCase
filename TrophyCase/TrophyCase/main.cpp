#include "Trophy.h"
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
int FindIndexOfTrophy(string);

Trophy* Trophies[10]; // array to hold trophies
int numberOfTrophies; // number of trophies created by the user

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


	Trophy* newTrophy = new Trophy(trophyName, trophyLevel, trophyColor); // instantiate new trophy
	Trophies[numberOfTrophies] = newTrophy; // add new trophy to array
	numberOfTrophies++; // increment number of trophies that user has created
	cout << "New trophy added" << endl;
}

// Copies one trophy's information to a new trophy
void CopyTrophy()
{
	string trophyName = GetString("Please enter the trophy's name that you want to copy: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	Trophy* newTrophy = new Trophy(*Trophies[indexOfTrophy]);
	Trophies[numberOfTrophies] = newTrophy; // add new trophy to array
	numberOfTrophies++; // increment number of trophies that user has created
}

// Remove a trohpy from the array.....also frees the memory
void DeleteTrophy()
{
	string trophyName = GetString("Please enter the trophy's name that you want to delete: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	numberOfTrophies--; // decrement counter
	Trophies[indexOfTrophy] = Trophies[numberOfTrophies]; // assign last trophy in array to the deleted trophy's position
	delete Trophies[numberOfTrophies + 1]; // for every new we need a delete
	Trophies[numberOfTrophies] = NULL; // free memory
	cout << endl << "Trophy deleted." << endl;
}
// Change a trophy's name
void RenameTrophy()
{
	string trophyName = GetString("Please enter the trophy's name that you want to rename: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	string NewName = GetString("Please enter the trophy's new name: ");
	Trophies[indexOfTrophy]->SetName(NewName);
	cout << endl << "Name Changed to: " << NewName << endl;
}
// Change a trophy's level
void ChangeLevelTrophy()
{
	string trophyName = GetString("Please enter the trophy's name that you want to relevel: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	int trophyLevel = GetShiftValue("Please enter the trophy's level: ");
	Trophies[indexOfTrophy]->SetLevel(trophyLevel);
	cout << endl << "Trophy's level changed" << endl;
}
// Change a trophy's color
void ChangeColorTrophy()
{
	string trophyName = GetString("Please enter the trophy's name which you want to change the color: ");
	int indexOfTrophy = FindIndexOfTrophy(trophyName);
	Color trophyColor = GOLD;
	string tempColor = "";
	do
	{
		string tempColor = GetString("Please enter the trophy's color  BRONZE, SILVER, or GOLD (case sensitive): ");
		if (tempColor == "GOLD")
		{
			Trophies[indexOfTrophy]->SetColor(GOLD);
			tempColor = "";
		}
		else if (tempColor == "BRONZE")
		{
			Trophies[indexOfTrophy]->SetColor(BRONZE);
			tempColor = "";
		}
		else if (tempColor == "SILVER")
		{
			Trophies[indexOfTrophy]->SetColor(SILVER);
			tempColor = "";
		}
	} while (tempColor != "");
}
// Displays all of the existing trophies to the screen
void PrintTrophies()
{
	cout << "All existing trophies." << endl << endl;
	for (int i = 0; i < numberOfTrophies; i++)
	{
		Trophies[i]->Print();
	}

}
// this method find the index of the trophy. Assuming they all have unique names.
int FindIndexOfTrophy(string testString)
{
	int index = 0;
	for (int i = 0; i < numberOfTrophies; i++)
	{
		if (Trophies[i]->GetName() == testString)
		{
			index = i;
		}
	}
	return index;
}
















