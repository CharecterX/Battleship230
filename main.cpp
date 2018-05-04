#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

// ---- Prototypes ------------------------------------------------------------------------------------------------------
void Display(char Board[][10], int SIZE);
void CreateBoard(char Board[][10], int SIZE);
void Shipplacement(char Board[][10], int SIZE, int playerNum);
void ShipPlacementAI(char Board[][10], int SIZE);
void displayMenu();
void DisplayBattleship();
int charToInt(char);
bool loadGame(char board1[][10], char board2[][10], char boardGuess1[][10], char boardGuess2[][10], int size, int &);
void saveGame(char board1[][10], char board2[][10], char boardGuess1[][10], char boardGuess2[][10], int size, int);
void playGame(char BoardP1[][10], char BoardP2[][10], char BoardGuessP1[][10], char BoardGuessP2[][10], int SIZE, int);
void playGameVai(char BoardP1[][10], char BoardP2[][10], char BoardGuessP1[][10], char BoardGuessP2[][10], int SIZE);
// -----------------------------------------------------------------------------------------------------------------------

// -- Pure Abstract Class Declaration ----------------------------------------------
class GeneralShipPlacement
{
	// protected member variables
protected:
	int xposition1;
	int xposition2;
	string yposition;
public:
	// pure virtural member funtions 
	virtual void SetxpositionAircraft(char Board[][10], int SIZE) = 0;
	virtual void SetypositionAircraft(char Board[][10], int SIZE) = 0;
	virtual void SetxpositionBattleship(char Board[][10], int SIZE) = 0;
	virtual void SetypositionBattleship(char Board[][10], int SIZE) = 0;
	virtual void SetxpositionCruiser(char Board[][10]) = 0;
	virtual void setypositionCruiser(char Board[][10], int SIZE) = 0;
	virtual void SetxpositionSubmarine(char Board[][10]) = 0;
	virtual void SetypositionSubmarine(char Board[][10], int SIZE) = 0;
	virtual void SetxpositionDestroyer(char Board[][10]) = 0;
	virtual void SetypositionDestroyer(char Board[][10], int SIZE) = 0;
};
// ---------------------------------------------------------------------------------

// -- Ship Placement Class : inherits General Ship Placement -----------------------
class ShipPlacement : public GeneralShipPlacement
{
public:
	// virtual funtion overidders 
	virtual void SetxpositionAircraft(char Board[][10], int SIZE);
	virtual void SetypositionAircraft(char Board[][10], int SIZE);
	virtual void SetxpositionBattleship(char Board[][10], int SIZE);
	virtual void SetypositionBattleship(char Board[][10], int SIZE);
	virtual void SetxpositionCruiser(char Board[][10]);
	virtual void setypositionCruiser(char Board[][10], int SIZE);
	virtual void SetxpositionSubmarine(char Board[][10]);
	virtual void SetypositionSubmarine(char Board[][10], int SIZE);
	virtual void SetxpositionDestroyer(char Board[][10]);
	virtual void SetypositionDestroyer(char Board[][10], int SIZE);
};
// ---------------------------------------------------------------------------------

// -- Battleship AI class : inherits General ship Placement Class --------------------------
class Battleshipai : public GeneralShipPlacement
{
public:
	string generateDirection();
	
	virtual void SetxpositionAircraft(char Board[][10], int SIZE);
	virtual void SetypositionAircraft(char Board[][10], int SIZE);
	virtual void SetxpositionBattleship(char Board[][10], int SIZE);
	virtual void SetypositionBattleship(char Board[][10], int SIZE);
	virtual void SetxpositionCruiser(char Board[][10]);
	virtual void setypositionCruiser(char Board[][10], int SIZE);
	virtual void SetxpositionSubmarine(char Board[][10]);
	virtual void SetypositionSubmarine(char Board[][10], int SIZE);
	virtual void SetxpositionDestroyer(char Board[][10]);
	virtual void SetypositionDestroyer(char Board[][10], int SIZE);
};
// ---------------------------------------------------------------------------------

// ================ MAIN =================================================================================
int main()
{
	const int SIZE = 10; // constant size for boards
						 // --- four 2D arrays for play boards -------
	char BoardP1[SIZE][SIZE];
	char BoardP2[SIZE][SIZE];
	char BoardGuessP1[SIZE][SIZE];
	char BoardGuessP2[SIZE][SIZE];
	// -------------------------------------------
	int choice; // int for menu choice
	int currentPlayerTurn; // int for tracking whoes turn it is

	while (true)
	{
		currentPlayerTurn = 1; // sets turn back to 1 for replay
		DisplayBattleship();  // display title card
		displayMenu();        // display menu
		cin >> choice;
		// error catching 
		while (choice < 1 || choice > 4)
		{
			cout << "You have made an Invalid choice Please try again" << endl;
			cin >> choice;
		}

		if (choice == 1) // choice 1 plays vs. AI
		{
			// fills all boards with blank values
			CreateBoard(BoardP1, SIZE);
			CreateBoard(BoardGuessP1, SIZE);
			CreateBoard(BoardP2, SIZE);
			CreateBoard(BoardGuessP2, SIZE);
			Shipplacement(BoardP1, SIZE, 1); // ship placement for player 1
			ShipPlacementAI(BoardP2, SIZE);  // ship placement for computer
			playGameVai(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE);  // Plays the game 
			system("PAUSE");
			system("cls");
		}
		else if (choice == 2) // choice 2 plays 2 player 
		{
			cout << "You have chosen 2-Player mode " << endl;
			cout << "Creating the Board" << endl;
			// fills all boards with blank values
			CreateBoard(BoardP1, SIZE);
			CreateBoard(BoardGuessP1, SIZE);
			CreateBoard(BoardP2, SIZE);
			CreateBoard(BoardGuessP2, SIZE);
			Shipplacement(BoardP1, SIZE, 1); // ship placement for player 1
			Shipplacement(BoardP2, SIZE, 2); // ship placement for player 2
			playGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, currentPlayerTurn);  // PLays the game 
			system("PAUSE");
			system("cls");
		}
		else if (choice == 3) // choice 3 loads a saved game
		{
			// checks if load game was succesfull 
			if (loadGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, currentPlayerTurn) == true)
			{
				// if so, plays the game 
				if (currentPlayerTurn == 0)
					playGameVai(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE);
				else
					playGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, currentPlayerTurn);
				
				system("PAUSE");
				system("cls");
			}
			else // if not returns to menu
			{
				system("PAUSE");
				system("cls");
			}
		}
		else if (choice == 4) // choice 4 exits the program 
		{
			cout << "Goodbye.\n";
			system("pause");
			return 0;
		}
	}

	system("pause");
	return 0;
}
// =======================================================================================================

// --- Funtion implimenation -----------------------------------------------------------------------------------------------------
void Display(char Board[][10], int SIZE)
{
	char Alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','H','I', 'J' }; // array for coordinate letters
	cout << "   ";
	// prints numbers at top-----------
	cout << "       ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << "   ";
	}
	//----------------------------------
	cout << "\n        -----------------------------------------" << endl;

	// ptrints board with letters along the side --------------------------------
	for (int i = 0; i < SIZE; i++)
	{
		cout << "     " << Alphabet[i] << "  ";// up and down
		for (int j = 0; j < SIZE; j++)
		{
			cout << "| " << Board[i][j] << " ";
		}
		cout << "|";
		cout << endl;
		cout << "        -----------------------------------------" << endl;
	}
	//-----------------------------------------------------------------------------
}
void CreateBoard(char Board[][10], int SIZE)
{
	// Fills the board with spaces
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Board[i][j] = ' ';
		}
	}


}
void Shipplacement(char Board[][10], int SIZE, int playerNum)
{
	// creates object for player one ship placement
	ShipPlacement Battleship;
	// displays board for reference
	Display(Board, SIZE);
	// calls all member fuctions in Ship Placement class to set ships ---------
	cout << "PLAYER " << playerNum << " PLACE YOUR SHIPS" << endl;
	Battleship.SetxpositionAircraft(Board, SIZE);
	Battleship.SetypositionAircraft(Board, SIZE);
	Display(Board, SIZE);
	cout << "Aircraft Carrier has been placed" << endl;
	Battleship.SetxpositionBattleship(Board, SIZE);
	Battleship.SetypositionBattleship(Board, SIZE);
	Display(Board, SIZE);
	cout << "Battleship has been placed" << endl;
	Battleship.SetxpositionCruiser(Board);
	Battleship.setypositionCruiser(Board, SIZE);
	Display(Board, SIZE);
	cout << "Cruiser has been placed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	Display(Board, SIZE);
	cout << "Submarine has been deployed" << endl;
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	Display(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	// --------------------------------------------------------------------------
	system("pause");
	system("cls");
	DisplayBattleship();
}
void ShipPlacementAI(char Board[][10], int SIZE)
{
	// creates object for ship placement
	Battleshipai Battleship;
	// calls all member fuctions in Ship Placement class to set ships ---------
	cout << "COMPUTER IS PLACING SHIPS" << endl;
	Battleship.SetxpositionAircraft(Board, SIZE);
	Battleship.SetypositionAircraft(Board, SIZE);
	cout << "Aircraft Carrier has been placed" << endl;
	Battleship.SetxpositionBattleship(Board, SIZE);
	Battleship.SetypositionBattleship(Board, SIZE);
	cout << "Battleship has been placed" << endl;
	Battleship.SetxpositionCruiser(Board);
	Battleship.setypositionCruiser(Board, SIZE);
	cout << "Cruiser has been placed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	cout << "Submarine has been deployed" << endl;
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	cout << "COMPUTER SHIPS ARE IN PLACE" << endl;
	// --------------------------------------------------------------------------
	system("pause");
	system("cls");
	DisplayBattleship();
}
void DisplayBattleship()
{
	// prints title card because it looks cool
	cout << "BBBBBBBBBBBBBBBBB                             tttt               tttt          lllllll                                     hhhhhhh               iiii                     " << endl;
	cout << "B::::::::::::::::B                         ttt:::t            ttt:::t          l:::::l                                     h:::::h              i::::i                    " << endl;
	cout << "B::::::BBBBBB:::::B                        t:::::t            t:::::t          l:::::l                                     h:::::h               iiii                     " << endl;
	cout << "BB:::::B     B:::::B                       t:::::t            t:::::t          l:::::l                                     h:::::h                                        " << endl;
	cout << "  B::::B     B:::::B  aaaaaaaaaaaaa  ttttttt:::::tttttttttttttt:::::ttttttt     l::::l     eeeeeeeeeeee        ssssssssss   h::::h hhhhh       iiiiiiippppp   ppppppppp   " << endl;
	cout << "  B::::B     B:::::B  a::::::::::::a t:::::::::::::::::tt:::::::::::::::::t     l::::l   ee::::::::::::ee    ss::::::::::s  h::::hh:::::hhh    i:::::ip::::ppp:::::::::p  " << endl;
	cout << "  B::::BBBBBB:::::B   aaaaaaaaa:::::at:::::::::::::::::tt:::::::::::::::::t     l::::l  e::::::eeeee:::::eess:::::::::::::s h::::::::::::::hh   i::::ip:::::::::::::::::p " << endl;
	cout << "  B:::::::::::::BB             a::::atttttt:::::::tttttttttttt:::::::tttttt     l::::l e::::::e     e:::::es::::::ssss:::::sh:::::::hhh::::::h  i::::ipp::::::ppppp::::::p" << endl;
	cout << "  B::::BBBBBB:::::B     aaaaaaa:::::a      t:::::t            t:::::t           l::::l e:::::::eeeee::::::e s:::::s  ssssss h::::::h   h::::::h i::::i p:::::p     p:::::p" << endl;
	cout << "  B::::B     B:::::B  aa::::::::::::a      t:::::t            t:::::t           l::::l e:::::::::::::::::e    s::::::s      h:::::h     h:::::h i::::i p:::::p     p:::::p" << endl;
	cout << "  B::::B     B:::::B a::::aaaa::::::a      t:::::t            t:::::t           l::::l e::::::eeeeeeeeeee        s::::::s   h:::::h     h:::::h i::::i p:::::p     p:::::p" << endl;
	cout << "  B::::B     B:::::Ba::::a    a:::::a      t:::::t    tttttt  t:::::t    tttttt l::::l e:::::::e           ssssss   s:::::s h:::::h     h:::::h i::::i p:::::p    p::::::p" << endl;
	cout << "BB:::::BBBBBB::::::Ba::::a    a:::::a      t::::::tttt:::::t  t::::::tttt:::::tl::::::le::::::::e          s:::::ssss::::::sh:::::h     h:::::hi::::::ip:::::ppppp:::::::p" << endl;
	cout << "B:::::::::::::::::B a:::::aaaa::::::a      tt::::::::::::::t  tt::::::::::::::tl::::::l e::::::::eeeeeeee  s::::::::::::::s h:::::h     h:::::hi::::::ip::::::::::::::::p " << endl;
	cout << "B::::::::::::::::B   a::::::::::aa:::a       tt:::::::::::tt    tt:::::::::::ttl::::::l  ee:::::::::::::e   s:::::::::::ss  h:::::h     h:::::hi::::::ip::::::::::::::pp  " << endl;
	cout << "BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaa         ttttttttttt        ttttttttttt  llllllll    eeeeeeeeeeeeee    sssssssssss    hhhhhhh     hhhhhhhiiiiiiiip::::::pppppppp    " << endl;
	cout << "                                                                                                                                                       p:::::p            " << endl;
	cout << "                                                                                                                                                       p:::::p            " << endl;
	cout << "                                                                                                                                                      p:::::::p           " << endl;
	cout << "                                                                                                                                                      p:::::::p           " << endl;
	cout << "                                                                                                                                                      p:::::::p           " << endl;
	cout << "                                                                                                                                                      ppppppppp           " << endl;
}
void displayMenu()
{
	// displays menu options for user
	cout << "                                                               Welcome to the game Battleship " << endl;
	cout << "                                                               1. 1- Player vs AI" << endl;
	cout << "                                                               2. 2-Player" << endl;
	cout << "                                                               3. Load Game" << endl;
	cout << "                                                               4. Exit" << endl;
}
int charToInt(char x)
{
	// switches a character and converts to n integer
	switch (x)
	{
	case 'a':
	case 'A':
		return 0;
		break;
	case 'b':
	case 'B':
		return 1;
		break;
	case 'c':
	case 'C':
		return 2;
		break;
	case 'd':
	case 'D':
		return 3;
		break;
	case 'e':
	case 'E':
		return 4;
		break;
	case 'f':
	case 'F':
		return 5;
		break;
	case 'g':
	case 'G':
		return 6;
		break;
	case 'h':
	case 'H':
		return 7;
		break;
	case 'i':
	case 'I':
		return 8;
		break;
	case 'j':
	case 'J':
		return 9;
		break;
		// returns a number for proper placement of ship and shots
	}
}
void saveGame(char  board1[][10], char board2[][10], char boardGuess1[][10], char boardGuess2[][10], int size, int playerTurn)
{
	// accepts a board stat and saves the game

	ofstream outfile; 	// creates outfile object

	string saveName; // variable for save file name

					 // user enters save file name
	cout << "Enter name for save file (No spaces or special characters): ";
	cin.ignore();
	getline(cin, saveName);

	// converts save file name to alphbetical characters only
	for (int i = 0; i < saveName.length(); i++)
	{
		if (!isalpha(saveName[i]))
		{
			saveName[i] = '\b';
		}
	}

	// checks if user added .txt to the end of save file name
	if (saveName.find(".txt") > saveName.length())
	{
		saveName += ".txt"; // adds .txt if not
	}

	outfile.open(saveName); // opens save file 

							// loops through all boards and saves contents to save file
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board1[i][j] == ' ')
				outfile << '\b';
			else
				outfile << board1[i][j];

			if (board2[i][j] == ' ')
				outfile << '\b';
			else
				outfile << board2[i][j];

			if (boardGuess1[i][j] == ' ')
				outfile << '\b';
			else
				outfile << boardGuess1[i][j];

			if (boardGuess2[i][j] == ' ')
				outfile << '\b';
			else
				outfile << boardGuess2[i][j];
		}
	}

	outfile << playerTurn;

	cout << "Gave Saved." << endl;
	cout << "Please enter the coordinates of where you wish to fire or enter 'x' to save" << endl;

	outfile.close(); // closes file
}
bool loadGame(char  board1[][10], char board2[][10], char boardGuess1[][10], char boardGuess2[][10], int size, int &playerTurn)
{
	ifstream infile; // creates infile object

	string loadName; // variable for load file name

					 // user enters name of file they wish to load
	cout << "Enter the name of the game file you wish to load: ";
	cin.clear();
	cin >> loadName;

	// checks if user specified .txt
	if (loadName.find(".txt") > loadName.length())
	{
		loadName += ".txt"; // adds .txt if not
	}

	infile.open(loadName); // opens load file

	if (!infile) // checks for file open error
	{
		cout << "Save file does not exist." << endl;
		infile.close();
		return false; // returns false to indcate the load failed
	}

	// loops though all elements saved in load file
	for (int i = 0; i < size; i++)
	{
		// fills all boards with those respective elements
		for (int j = 0; j < size; j++)
		{
			infile >> board1[i][j];
			if (board1[i][j] == '\b')
				board1[i][j] = ' ';

			infile >> board2[i][j];
			if (board2[i][j] == '\b')
				board2[i][j] = ' ';

			infile >> boardGuess1[i][j];
			if (boardGuess1[i][j] == '\b')
				boardGuess1[i][j] = ' ';

			infile >> boardGuess2[i][j];
			if (boardGuess2[i][j] == '\b')
				boardGuess2[i][j] = ' ';
		}
	}

	infile >> playerTurn;

	infile.close(); // closes file 
	return true; // return true when load is completed
}
void playGame(char BoardP1[][10], char BoardP2[][10], char BoardGuessP1[][10], char BoardGuessP2[][10], int SIZE, int playerTurn)
{
	while (true)
	{
		// variables for input and couter for win condition 
		char temp;
		int position1, position2, counter;

		if (playerTurn == 1)
		{
			// PLAYER ONE'S TURN -------------------------------------------------------------------------
			cout << "Player 1 take your shot" << endl;
			// display boards
			Display(BoardGuessP1, SIZE);
			Display(BoardP1, SIZE);
			cout << "Please enter the coordinates of where you wish to fire or enter 'x' to save" << endl;
			// gets y coordinate
			cin >> temp;
			// if input x save game
			while (temp == 'x' || temp == 'X')
			{
				saveGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, playerTurn);
				cin >> temp;
			}
			// get x coordinate
			cin >> position2;
			position1 = charToInt(temp);
			//error catching
			while (position1 > 10 || position2 > 10 || position1 < 0 || position2 < 0 || BoardP2[position1][position2] == 'X' || BoardP2[position1][position2] == 'O')
			{
				cout << "Invalid coordinates to fire please input a correct scope of attack" << endl;
				cin >> temp >> position2;
				position1 = charToInt(temp);
			}
			// hit / miss checks
			if (BoardP2[position1][position2] != ' ')
			{
				system("cls");
				cout << "You have hit an enemy ship uploading to table" << endl;
				BoardGuessP1[position1][position2] = 'X';
				BoardP2[position1][position2] = 'X';
				system("PAUSE");
			}
			else
			{
				system("cls");
				cout << "You have missed" << endl;
				BoardGuessP1[position1][position2] = 'O';
				BoardP2[position1][position2] = 'O';
				system("PAUSE");
			}

			// Check for win ------------------------------------------------------------------
			counter = 0;
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (BoardP2[i][j] != ' ' && BoardP2[i][j] != 'X' && BoardP2[i][j] != 'O')
					{
						counter++;
					}
				}
			}
			if (counter == 0)
			{
				cout << endl << endl << "PLAYER ONE WINS!" << endl << endl;
				break;
			}
			playerTurn = 2; // sets player turn to 2 after player 1 is done
		}
		//-----------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------------------

		// PLAYER TWO'S TURN --------------------------------------------------------------------------------------
		cout << "Player 2 take your shot" << endl;
		// display boards
		Display(BoardGuessP2, SIZE);
		Display(BoardP2, SIZE);
		cout << "Please enter the coordinates of where you wish to fire or enter 'x' to save" << endl;
		// get y coordinate
		cin >> temp;
		// if input x save game
		while (temp == 'x' || temp == 'X')
		{
			saveGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, playerTurn);
			cin >> temp;
		}
		// get x coordinate
		cin >> position2;
		position1 = charToInt(temp);
		// error catching
		while (position1 > 10 || position2 > 10 || position1 < 0 || position2 < 0 || BoardP1[position1][position2] == 'X' || BoardP1[position1][position2] == 'O')
		{
			cout << "Invalid coordinates to fire please input a correct scope of attack" << endl;
			cin >> temp >> position2;
			position1 = charToInt(temp);
		}
		// hit/ miss checks
		if (BoardP1[position1][position2] != ' ')
		{
			system("cls");
			cout << "You have hit an enemy ship uploading to table" << endl;
			BoardGuessP2[position1][position2] = 'X';
			BoardP1[position1][position2] = 'X';
			system("PAUSE");
		}
		else
		{
			system("cls");
			cout << "You have missed" << endl;
			BoardGuessP2[position1][position2] = 'O';
			BoardP1[position1][position2] = 'O';
			system("PAUSE");
		}
		// Check for win ------------------------------------------------------------------
		counter = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (BoardP1[i][j] != ' ' && BoardP1[i][j] != 'X' && BoardP1[i][j] != 'O')
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			cout << endl << endl << "PLAYER TWO WINS!" << endl << endl;
			break;
		}
		playerTurn = 1; // sets player turn to 1 after player 2 is done
						//-----------------------------------------------------------------------------------
						// --------------------------------------------------------------------------------------------------------
	}
}
void playGameVai(char BoardP1[][10], char BoardP2[][10], char BoardGuessP1[][10], char BoardGuessP2[][10], int SIZE)
{
	srand(time(0));
	while (true)
	{
		// variables for input and couter for win condition 
		char temp;
		int position1, position2, counter;

			// PLAYER ONE'S TURN -------------------------------------------------------------------------
			cout << "Player 1 take your shot" << endl;
			// display boards
			Display(BoardGuessP1, SIZE);
			Display(BoardP1, SIZE);
			cout << "Please enter the coordinates of where you wish to fire or enter 'x' to save" << endl;
			// gets y coordinate
			cin >> temp;
			// if input x save game
			while (temp == 'x' || temp == 'X')
			{
				saveGame(BoardP1, BoardP2, BoardGuessP1, BoardGuessP2, SIZE, 0);
				cin >> temp;
			}
			// get x coordinate
			cin >> position2;
			position1 = charToInt(temp);
			//error catching
			while (position1 > 10 || position2 > 10 || position1 < 0 || position2 < 0 || BoardP2[position1][position2] == 'X' || BoardP2[position1][position2] == 'O')
			{
				cout << "Invalid coordinates to fire please input a correct scope of attack" << endl;
				cin >> temp >> position2;
				position1 = charToInt(temp);
			}
			// hit / miss checks
			if (BoardP2[position1][position2] != ' ')
			{
				system("cls");
				cout << "You have hit an enemy ship uploading to table" << endl;
				BoardGuessP1[position1][position2] = 'X';
				BoardP2[position1][position2] = 'X';
				system("PAUSE");
			}
			else
			{
				system("cls");
				cout << "You have missed" << endl;
				BoardGuessP1[position1][position2] = 'O';
				BoardP2[position1][position2] = 'O';
				system("PAUSE");
			}

			// Check for win ------------------------------------------------------------------
			counter = 0;
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (BoardP2[i][j] != ' ' && BoardP2[i][j] != 'X' && BoardP2[i][j] != 'O')
					{
						counter++;
					}
				}
			}
			if (counter == 0)
			{
				cout << endl << endl << "PLAYER ONE WINS!" << endl << endl;
				break;
			}
		
		//-----------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------------------

		// COMPUTER'S TURN --------------------------------------------------------------------------------------
		// get x and y coordinate
		position2 = rand() % 10;
		position1 = rand() % 10;
		// error catching
		while (position1 > 10 || position2 > 10 || position1 < 0 || position2 < 0 || BoardP1[position1][position2] == 'X' || BoardP1[position1][position2] == 'O')
		{
			position2 = rand() % 10;
			position1 = rand() % 10;
		}
		// hit/ miss checks
		if (BoardP1[position1][position2] != ' ')
		{
			system("cls");
			cout << "You have been hit! uploading to table." << endl;
			BoardGuessP2[position1][position2] = 'X';
			BoardP1[position1][position2] = 'X';
			system("PAUSE");
		}
		else
		{
			system("cls");
			cout << "The enemy missed" << endl;
			BoardGuessP2[position1][position2] = 'O';
			BoardP1[position1][position2] = 'O';
			system("PAUSE");
		}
		// Check for win ------------------------------------------------------------------
		counter = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (BoardP1[i][j] != ' ' && BoardP1[i][j] != 'X' && BoardP1[i][j] != 'O')
				{
					counter++;
				}
			}
		}
		if (counter == 0)
		{
			cout << endl << endl << "THE ENEMY HAS WON!" << endl << endl;
			break;
		}
		//-----------------------------------------------------------------------------------
		// --------------------------------------------------------------------------------------------------------
	}
}
// --------------------------------------------------------------------------------------------------------------------------------


// ----- Ship Placement Class Member function implimentation ------------------------
void ShipPlacement::SetxpositionAircraft(char Board[][10], int SIZE)
{
	char temp;
	cout << "Where would you like to place your Aircraft Carrier (Takes 5 space)?  enter Ex. A 5" << endl;
	cin >> temp >> xposition2;
	xposition1 = charToInt(temp);
	cin.ignore(1);
	while (xposition1 < 0 || xposition1 > 10)
	{
		cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}
}
void ShipPlacement::SetypositionAircraft(char Board[][10], int SIZE)
{
	cout << "Where do you want the Aircraft Carrier to face North, East, South, or West (Takes 5 spaces)" << endl;
	cin >> yposition;
	while (((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 <4) ||
		((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 6) ||
		((yposition == "South" || yposition == "south" || yposition == "S") && xposition1 > 5) ||
		((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 4))
	{
		cout << "The Aircraft carrier will not fit within the tiles" << endl;
		cin >> yposition;
	}
	/*	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 6)
	{
	cout << "The Aircraft carrier will not fit within the tiles" << endl;
	cin >> yposition;
	}
	while ((yposition == "South" || yposition == "south" || yposition == "S") && xposition1 > 5)
	{
	cout << "The Aircraft carrier will not fit within the tiles" << endl;
	cin >> yposition;
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 4)
	{
	cout << "The Aircraft carrier will not fit within the tiles" << endl;
	cin >> yposition;
	}*/
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1 - i][xposition2] = 'A';

		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1][xposition2 + i] = 'A';

		}
	}
	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1][xposition2 - i] = 'A';

		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1 + i][xposition2] = 'A';

		}
	}
	else
	{
		cout << "Due to unforseen consequences The ship as erred off course due to bad directions " << endl;
	}

}
void ShipPlacement::SetxpositionBattleship(char Board[][10], int SIZE)
{
	char temp;
	cout << "where would you like to place your Battleship (Takes 4 spaces)?  enter Ex. A 5" << endl;
	cin >> temp >> xposition2;
	xposition1 = charToInt(temp);
	while (Board[xposition1][xposition2] == 'A')
	{
		cout << "Spot is already taken by the Battleship please deploy elsewhere" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		cout << "Invalid grid for the placed ship" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}


}
void ShipPlacement::SetypositionBattleship(char Board[][10], int SIZE)
{
	cout << "Where do you want the Battleship to face North, East, South, or West (Takes 4 spaces)" << endl;
	cin >> yposition;
	//validation the north south east and west for empty tiles

	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "s")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <4; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1][xposition2 + i] == 'A')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}


		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1][xposition2 - i] == 'A')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1 + i][xposition2] == 'A')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}

	//end of the validation/////////////////////////////////////////////////////////////////////////// of the directions


	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		cout << "The Battleship will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 >7)
	{
		cout << "The Battleship will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		cout << "The Battleship will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		cout << "The Battleship will not fit within the tiles" << endl;
		cin >> yposition;
	}

	//setting the squares to be the ships
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <4; i++)
		{
			Board[xposition1 - i][xposition2] = 'B';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1][xposition2 + i] = 'B';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1][xposition2 - i] = 'B';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1 + i][xposition2] = 'B';
		}
	}
}
void ShipPlacement::SetxpositionCruiser(char Board[][10])
{
	char temp;
	cout << "where would you like to place your Cruiser (Takes 3 spaces)?  enter Ex. A 5" << endl;
	cin >> temp >> xposition2;
	xposition1 = charToInt(temp);
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B')
	{
		cout << "Spot is already taken by the Aircraft Carrier or the Battleship please deploy elsewhere" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		cout << "Invalid grid for the placed ship" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

}
void ShipPlacement::setypositionCruiser(char Board[][10], int SIZE) // three size
{
	cout << "Where do you want the Cruiser to face North, East, South, or West (Takes 3 Spaces)" << endl;
	cin >> yposition;
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{

			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{


			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i < 3; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}

	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		cout << "The Cruiser will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 7)
	{
		cout << "The Cruiser will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		cout << "The Cruiser will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		cout << "The Cruiser will not fit within the tiles" << endl;
		cin >> yposition;
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			Board[xposition1 - i][xposition2] = 'C';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 + i] = 'C';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 - i] = 'C';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1 + i][xposition2] = 'C';
		}
	}

}
void ShipPlacement::SetxpositionSubmarine(char Board[][10])
{
	char temp;
	cout << "where would you like to place your Submarine (Takes 3 spaces)?  enter Ex. A 5" << endl;
	cin >> temp >> xposition2;
	xposition1 = charToInt(temp);
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C')
	{
		cout << "Spot is already taken by the Aircraft Carrier or the Battleship or the Cruiser please deploy elsewhere" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

}
void ShipPlacement::SetypositionSubmarine(char Board[][10], int SIZE)
{
	cout << "Where do you want the Submarine to face North, East, South, or West (Takes 3 spaces)" << endl;
	cin >> yposition;
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		cout << "The Submarine will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 7)
	{
		cout << "The Submarine will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		cout << "The Submarine will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		cout << "The Submarine will not fit within the tiles" << endl;
		cin >> yposition;
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			Board[xposition1 - i][xposition2] = 'S';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 + i] = 'S';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 - i] = 'S';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1 + i][xposition2] = 'S';
		}
	}

}
void ShipPlacement::SetxpositionDestroyer(char Board[][10])
{
	char temp;
	cout << "where would you like to place your Destroyer? (Takes 2 spaces)  enter Ex. A 5" << endl;
	cin >> temp >> xposition2;
	xposition1 = charToInt(temp);
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C' || Board[xposition1][xposition2] == 'S')
	{
		cout << "Spot is already taken by the Aircraft Carrier or the Battleship or the Cruiser or the Submarine please deploy elsewhere" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		cout << "Invalid grid for the placed ship, the Destroyer is 2 pegs long try again" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);
	}

}
void ShipPlacement::SetypositionDestroyer(char Board[][10], int SIZE)
{
	cout << "Where do you want the Destroyer to face North, East, South, or West (Takes 2 spaces)" << endl;
	cin >> yposition;
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <2; i++)
		{

			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "S")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				cout << "Invalid Deployment currently there is a ship there" << endl;
				cin >> yposition;
			}
		}
	}
	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 1)
	{
		cout << "The Destroyer will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 8)
	{
		cout << "The Destoyer will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 8)
	{
		cout << "The Destoyer will not fit within the tiles" << endl;
		cin >> yposition;
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 1)
	{
		cout << "The Destoyer will not fit within the tiles" << endl;
		cin >> yposition;
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <2; i++)
		{
			Board[xposition1 - i][xposition2] = 'D';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 2; i++)
		{
			Board[xposition1][xposition2 + i] = 'D';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <2; i++)
		{
			Board[xposition1][xposition2 - i] = 'D';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 2; i++)
		{
			Board[xposition1 + i][xposition2] = 'D';
		}
	}


}
// ----------------------------------------------------------------------------------

// ----- Battle Ship AI class member fucntion implimentation ------------------------
string Battleshipai::generateDirection()
{
	switch (rand() % 4)
	{
	case 0: 
		return "North";
		break;
	case 1:
		return "East";
		break;
	case 2:
		return "South";
		break;
	case 3:
		return "West";
		break;
	}
}

void Battleshipai::SetxpositionAircraft(char Board[][10], int SIZE)
{
	srand(time(0));
	xposition2 = rand() % 10;
	xposition1 = rand() % 10;
	cin.ignore(1);
	while (xposition1 < 0 || xposition1 > 10)
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}
}
void Battleshipai::SetypositionAircraft(char Board[][10], int SIZE)
{
	srand(time(0));
	yposition = generateDirection();
	while (((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 <4) ||
		((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 6) ||
		((yposition == "South" || yposition == "south" || yposition == "S") && xposition1 > 5) ||
		((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 4))
	{
		cout << "The Aircraft carrier will not fit within the tiles" << endl;
		yposition = generateDirection();
	}
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1 - i][xposition2] = 'A';

		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1][xposition2 + i] = 'A';

		}
	}
	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1][xposition2 - i] = 'A';

		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i < 5; i++)
		{
			Board[xposition1 + i][xposition2] = 'A';

		}
	}
	else
	{
		cout << "The Ship failed to place, Thats lucky for you\n";
	}
}
void Battleshipai::SetxpositionBattleship(char Board[][10], int SIZE)
{
	srand(time(0));
	xposition2 = rand() % 10;
	xposition1 = rand() % 10;
	while (Board[xposition1][xposition2] == 'A')
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}

}
void Battleshipai::SetypositionBattleship(char Board[][10], int SIZE)
{
	srand(time(0));
	yposition = generateDirection();
	//validation the north south east and west for empty tiles

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <4; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1][xposition2 + i] == 'A')
			{
				yposition = generateDirection();
			}


		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1][xposition2 - i] == 'A')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i <4; i++)
		{

			if (Board[xposition1 + i][xposition2] == 'A')
			{
				yposition = generateDirection();
			}
		}
	}

	//end of the validation/////////////////////////////////////////////////////////////////////////// of the directions


	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		yposition = generateDirection();
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 >7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		yposition = generateDirection();
	}

	//setting the squares to be the ships
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <4; i++)
		{
			Board[xposition1 - i][xposition2] = 'B';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1][xposition2 + i] = 'B';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1][xposition2 - i] = 'B';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 4; i++)
		{
			Board[xposition1 + i][xposition2] = 'B';
		}
	}
}
void Battleshipai::SetxpositionCruiser(char Board[][10])
{
	srand(time(0));
	xposition2 = rand() % 10;
	xposition1 = rand() % 10;
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B')
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}
}
void Battleshipai::setypositionCruiser(char Board[][10], int SIZE)
{
	srand(time(0));
	yposition = generateDirection();
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{

			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{


			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "s")
	{
		for (int i = 0; i < 3; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B')
			{
				yposition = generateDirection();
			}
		}
	}

	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		yposition = generateDirection();
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		yposition = generateDirection();
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			Board[xposition1 - i][xposition2] = 'C';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 + i] = 'C';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 - i] = 'C';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1 + i][xposition2] = 'C';
		}
	}
}
void Battleshipai::SetxpositionSubmarine(char Board[][10])
{
	srand(time(0));
	xposition2 = rand() % 10;
	xposition1 = rand() % 10;
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C')
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}
}
void Battleshipai::SetypositionSubmarine(char Board[][10], int SIZE)
{
	srand(time(0));
	yposition = generateDirection();
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				yposition = generateDirection();
			}
		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				yposition = generateDirection();
			}
		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				yposition = generateDirection();
			}
		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i <3; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C')
			{
				yposition = generateDirection();
			}
		}
	}
	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 3)
	{
		yposition = generateDirection();
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 7)
	{
		yposition = generateDirection();
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 3)
	{
		yposition = generateDirection();
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <3; i++)
		{
			Board[xposition1 - i][xposition2] = 'S';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 + i] = 'S';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1][xposition2 - i] = 'S';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 3; i++)
		{
			Board[xposition1 + i][xposition2] = 'S';
		}
	}
}
void Battleshipai::SetxpositionDestroyer(char Board[][10])
{
	srand(time(0));
	xposition2 = rand() % 10;
	xposition1 = rand() % 10;
	while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C' || Board[xposition1][xposition2] == 'S')
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}

	while (xposition1 < 0 || xposition1 > 10)
	{
		xposition2 = rand() % 10;
		xposition1 = rand() % 10;
	}
}
void Battleshipai::SetypositionDestroyer(char Board[][10], int SIZE)
{
	srand(time(0));
	yposition = generateDirection();
	//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
	//if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				yposition = generateDirection();
			}
		}
	}
	if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <2; i++)
		{

			if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				yposition = generateDirection();
			}

		}
	}
	if (yposition == "South" || yposition == "south" || yposition == "S")
	{
		for (int i = 0; i <2; i++)
		{
			if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
			{
				yposition = generateDirection();
			}
		}
	}
	//Validation for the squares
	while ((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 < 1)
	{
		yposition = generateDirection();
	}
	while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 8)
	{
		yposition = generateDirection();
	}
	while ((yposition == "South" || yposition == "south" || yposition == "south") && xposition1 > 8)
	{
		yposition = generateDirection();
	}
	while ((yposition == "West" || yposition == "west" || yposition == "w") && xposition2 < 1)
	{
		yposition = generateDirection();
	}

	if (yposition == "North" || yposition == "north" || yposition == "N")
	{
		for (int i = 0; i <2; i++)
		{
			Board[xposition1 - i][xposition2] = 'D';
		}
	}
	else if (yposition == "East" || yposition == "east" || yposition == "E")
	{
		for (int i = 0; i < 2; i++)
		{
			Board[xposition1][xposition2 + i] = 'D';
		}
	}

	else if (yposition == "West" || yposition == "west" || yposition == "w")
	{
		for (int i = 0; i <2; i++)
		{
			Board[xposition1][xposition2 - i] = 'D';
		}
	}
	else if (yposition == "South" || yposition == "south" || yposition == "south")
	{
		for (int i = 0; i < 2; i++)
		{
			Board[xposition1 + i][xposition2] = 'D';
		}
	}
}
// ----------------------------------------------------------------------------------
