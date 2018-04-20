


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void Display(char Board[][10], int SIZE);
void CreateBoard(char Board[][10], int SIZE);
void Shipplacement(char Board[][10], int SIZE);
void Shipplacement2(char Board[][10], int SIZE);
void displayMenu();
void DisplayBattleship();
int charToInt(char);

class ShipPlacement
{

private:
	int xposition1;
	int xposition2;
	string yposition;
public:

	void SetxpositionAircraft (char Board[][10], int SIZE)
	{
		char temp;
		cout << "where would you like to place your Aircraft Carrier?  enter Ex. 5 5" << endl;
		cin >> temp >> xposition2;
		xposition1 = charToInt(temp);

		while (xposition1 < 0 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
			cin >> temp >> xposition2;
			xposition1 = charToInt(temp);
		}

		

	}

	void SetypositionAircraft(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		while((yposition == "North" || yposition == "north" || yposition == "N") && xposition1 <4 )
		{
			cout << "The Aircraft carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while ((yposition == "East" || yposition == "east" || yposition == "E") && xposition2 > 6)
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
			cout << "Due to unforseen consequences The ship as erred off course due to bad directions " << endl;
		}
		
	}

	void SetxpositionBattleship(char Board[][10], int SIZE)
	{
		char temp;
		cout << "where would you like to place your Battleship?  enter Ex. 5 5" << endl;
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

	void SetypositionBattleship(char Board[][10], int SIZE) 
	{
		cout << "Where do you want the Battleship to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation the north south east and west for empty tiles
		
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E"|| yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <4; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
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
				Board[xposition1 -i ][xposition2] = 'B';
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

	void SetxpositionCruiser(char Board[][10])
	{
		char temp;
		cout << "where would you like to place your Cruiser?  enter Ex. 5 5" << endl;
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

	void setypositionCruiser(char Board[][10], int SIZE) // three size
	{
		cout << "Where do you want the Cruiser to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A'|| Board[xposition1][xposition2 + i] == 'B')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
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



	void SetxpositionSubmarine(char Board[][10])
	{
		char temp;
		cout << "where would you like to place your Submarine?  enter Ex. 5 5" << endl;
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

	void SetypositionSubmarine(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Submarine to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' ||Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
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
		while ((yposition == "West" || yposition == "west" || yposition == "w" )&& xposition2 < 3)
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

	void SetxpositionDestroyer(char Board[][10])
	{
		char temp;
		cout << "where would you like to place your Destroyer?  enter Ex. 5 5" << endl;
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

	void SetypositionDestroyer(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Destroyer to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently there is a ship there" << endl;
					cin >> yposition;
				}
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
};

int main()
{
	
	const int SIZE = 10;
	char BoardP1[SIZE][SIZE];
	char BoardP2[SIZE][SIZE];
	char BoardGuessP1[SIZE][SIZE];
	char BoardGuessP2[SIZE][SIZE];
	int choice;
	
	DisplayBattleship();
	displayMenu();
	cin >> choice;

	if (choice == 2)
	{
		cout << "You have chosen 2-Player mode " << endl;
		cout << "Creating the Board" << endl;
		CreateBoard(BoardP1, SIZE);
		CreateBoard(BoardGuessP1, SIZE);
		CreateBoard(BoardP2, SIZE);
		CreateBoard(BoardGuessP2, SIZE);
		Shipplacement(BoardP1, SIZE);
		Shipplacement2(BoardP2, SIZE);
		while (true)
		{
			int position1, position2;
			bool flag = false;
			cout << "Player 1 take your shot" << endl;
			Display(BoardGuessP1, SIZE);
			Display(BoardP1, SIZE);
			cout << "Please enter the coordinates of where you wish to fire" << endl;
			cin >> position1 >> position2;
			while (position1 > 10 || position2 > 10 || position1 < 1 || position2 < 1)
			{
				cout << "Invalid coordinates to fire please input a correct scope of attack" << endl;
				cin >> position1 >> position2;
			}

			if (BoardP2[position1][position2] != '~')
			{
				cout << "You have hit an enemy ship uploading to table" << endl;
				BoardGuessP1[position1][position2] = 'X';
				BoardP2[position1][position2] = 'X';
			}
			else
			{
				cout << "You have missed" << endl;
				BoardGuessP1[position1][position2] = 'O';
				BoardP2[position1][position2] = 'O';
			}

			cout << "Player 2 take your shot" << endl;
			
			Display(BoardGuessP2, SIZE);
			Display(BoardP2, SIZE);
			cout << "Please enter the coordinates of where you wish to fire" << endl;
			cin >> position1 >> position2;
			while (position1 > 10 || position2 > 10 || position1 < 1 || position2 < 1)
			{
				cout << "Invalid coordinates to fire please input a correct scope of attack" << endl;
				cin >> position1 >> position2;
			}

			if (BoardP1[position1][position2] != '~')
			{
				cout << "You have hit an enemy ship uploading to table" << endl;
				BoardGuessP2[position1][position2] = 'X';
				BoardP1[position1][position2] = 'X';
			}
			else
			{
				cout << "You have missed" << endl;
				BoardGuessP1[position1][position2] = 'O';
				BoardP1[position1][position2] = 'O';
			}
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (BoardP1[i][j] != '~' || BoardP1[i][j] != 'X' || BoardP1[i][j] != 'O')
					{
						flag = false;
					}
					else
					{
						flag = true;
						cout << "Winner is player 2" << endl;
					}

					if (BoardP2[i][j] != '~' || BoardP1[i][j] != 'X' || BoardP1[i][j] != 'O')
					{
						flag = false;
					}
					else
					{
						flag = true;
						cout << "Winner is player 1" << endl;
					}
				}
				
			}

			if (flag = true)
			{
				break;
			}

		}
	}
	else if (choice == 1)
	{

	}
	else if (choice == 3)
	{
		system("pause");
		return 0;

	}
	else
	{
		cout << "You have made an Invalid choice Please try again" << endl;
		cin >> choice;
		while (choice < 1 || choice > 3)
		{
			cout << "Invalid" << endl;
			cin >> choice;
		}
	}

	system("pause");
	return 0;
 }

void Display(char Board[][10], int SIZE)
{
	char Alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','H','I', 'J' };
	cout << setw(7) << " ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(8) << i;
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(8) <<Alphabet[i];// up and down
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(6) <<"|" << Board[i][j] << "|";
		}
		cout << endl;
	}
}

void CreateBoard(char Board[][10], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Board[i][j] = '~';
		}
	}


}

void Shipplacement(char Board[][10], int SIZE)
{
	ShipPlacement Battleship;
	Display(Board, SIZE);
	cout << "PLAYER 1 PLACE YOUR SHIPS" << endl;
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
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	Display(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	Display(Board, SIZE);
	cout << "Submarine has been deployed" << endl;
	system("pause");
	system("cls");
	
	DisplayBattleship();


}

void Shipplacement2(char Board[][10], int SIZE)
{
	ShipPlacement Battleship;
	Display(Board, SIZE);
	cout << "PLAYER 2 PLACE YOUR SHIPS" << endl;
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
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	Display(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	Display(Board, SIZE);
	cout << "Submarine has been deployed" << endl;
	system("pause");
	system("cls");
	DisplayBattleship();
}

void DisplayBattleship()
{
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
	cout << "                                                               Welcome to the game Battleship " << endl;
	cout << "                                                               1. 1- Player vs AI" << endl;
	cout << "                                                               2. 2-Player" << endl;
	cout << "                                                               3. Exit" << endl;
}

int charToInt(char x)
{
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
	}
}
