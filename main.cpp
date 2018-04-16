


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ShipPlacement
{

private:
	int xposition1;
	int xposition2;
	string yposition;
public:

	void SetxpositionAircraft (char Board[][10], int SIZE)
	{
		cout << "where would you like to place your Aircraft Carrier?  enter Ex. 5 5" << endl;
		cin >> xposition1 >> xposition2;

		while (xposition1 < 1 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
			cin >> xposition1 >> xposition2;
		}



	}

	void SetypositionAircraft(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		while(yposition == "North" || yposition == "north" || yposition == "N" && xposition1 < 5)
		{
			cout << "The Aircraft carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "East" || yposition == "east" || yposition == "E" && xposition2 > 5)
		{
			cout << "The Aircraft carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "South" || yposition == "south" || yposition == "south" && xposition1 > 5)
		{
			cout << "The Aircraft carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "West" || yposition == "west" || yposition == "w" && xposition2 < 5)
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
		else if (yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i < 5; i++)
			{
				Board[xposition1 + i][xposition2] = 'A';
			}
		}
		
	}

	void SetxpositionBattleship(char Board[][10], int SIZE)
	{
		cout << "where would you like to place your Battleship?  enter Ex. 5 5" << endl;
		cin >> xposition1 >> xposition2;
		while (Board[xposition1][xposition2] == 'A')
		{
			cout << "Spot is already taken by the Aircraft Carrier please deploy elsewhere" << endl;
			cin >> xposition1 >> xposition2;
		}

		while (xposition1 < 1 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
			cin >> xposition1 >> xposition2;
		}


	}

	void SetypositionBattleship(char Board[][10], int SIZE) 
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation the north south east and west for empty tiles
		
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E"|| yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <4; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1 + i][xposition2] == 'A')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
			}
		}


		//end of the validation/////////////////////////////////////////////////////////////////////////// of the directions


		//Validation for the squares
		while (yposition == "North" || yposition == "north" || yposition == "N" && xposition1 < 4)
		{
			cout << "The Battleship carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "East" || yposition == "east" || yposition == "E" && xposition2 > 6)
		{
			cout << "The Battleship carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "South" || yposition == "south" || yposition == "south" && xposition1 > 6)
		{
			cout << "The Battleship carrier will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "West" || yposition == "west" || yposition == "w" && xposition2 < 4)
		{
			cout << "The Battleship carrier will not fit within the tiles" << endl;
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
		cout << "where would you like to place your Battleship?  enter Ex. 5 5" << endl;
		cin >> xposition1 >> xposition2;
		while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B')
		{
			cout << "Spot is already taken by the Aircraft Carrier or the Battleship please deploy elsewhere" << endl;
			cin >> xposition1 >> xposition2;
		}

		while (xposition1 < 1 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
			cin >> xposition1 >> xposition2;
		}

	}

	void setypositionCruiser(char Board[][10], int SIZE) // three size
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A'|| Board[xposition1][xposition2 + i] == 'B')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
			}
		}
		//Validation for the squares
		while (yposition == "North" || yposition == "north" || yposition == "N" && xposition1 < 3)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "East" || yposition == "east" || yposition == "E" && xposition2 > 7)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "South" || yposition == "south" || yposition == "south" && xposition1 > 7)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "West" || yposition == "west" || yposition == "w" && xposition2 < 3)
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
		cout << "where would you like to place your Submarine?  enter Ex. 5 5" << endl;
		cin >> xposition1 >> xposition2;
		while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C')
		{
			cout << "Spot is already taken by the Aircraft Carrier or the Battleship or the Cruiser please deploy elsewhere" << endl;
			cin >> xposition1 >> xposition2;
		}

		while (xposition1 < 1 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the aircraft carrier is 5 pegs long try again" << endl;
			cin >> xposition1 >> xposition2;
		}

	}

	void SetypositionSubmarine(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' ||Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
			}
		}
		//Validation for the squares
		while (yposition == "North" || yposition == "north" || yposition == "N" && xposition1 < 3)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "East" || yposition == "east" || yposition == "E" && xposition2 > 7)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "South" || yposition == "south" || yposition == "south" && xposition1 > 7)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "West" || yposition == "west" || yposition == "w" && xposition2 < 3)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
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
		cout << "where would you like to place your Destroyer?  enter Ex. 5 5" << endl;
		cin >> xposition1 >> xposition2;
		while (Board[xposition1][xposition2] == 'S' || Board[xposition1][xposition2] == 'B' || Board[xposition1][xposition2] == 'C' || Board[xposition1][xposition2] == 'S')
		{
			cout << "Spot is already taken by the Aircraft Carrier or the Battleship or the Cruiser or the Submarine please deploy elsewhere" << endl;
			cin >> xposition1 >> xposition2;
		}

		while (xposition1 < 1 || xposition1 > 10)
		{
			cout << "Invalid grid for the placed ship, the Destroyer is 2 pegs long try again" << endl;
			cin >> xposition1 >> xposition2;
		}

	}

	void SetypositionDestroyer(char Board[][10], int SIZE)
	{
		cout << "Where do you want the Aircraft Carrier to face North, East, South, or West" << endl;
		cin >> yposition;
		//validation for the cruiser and ship placements////////////////////////////////////////////////////////////////////
		if (yposition == "North" || yposition == "north" || yposition == "N" || yposition == "East" || yposition == "east" || yposition == "E" || yposition == "West" || yposition == "west" || yposition == "w" || yposition == "South" || yposition == "south" || yposition == "south")
		{
			for (int i = 0; i <3; i++)
			{
				if (Board[xposition1 - i][xposition2] == 'A' || Board[xposition1 - i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 + i] == 'A' || Board[xposition1][xposition2 + i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1][xposition2 - i] == 'A' || Board[xposition1][xposition2 - i] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
				if (Board[xposition1 + i][xposition2] == 'A' || Board[xposition1 + i][xposition2] == 'B' || Board[xposition1 - i][xposition2] == 'C' || Board[xposition1 - i][xposition2] == 'S')
				{
					cout << "Invalid Deployment currently the Aircraft Carrier is there" << endl;
					cin >> yposition;
				}
			}
		}
		//Validation for the squares
		while (yposition == "North" || yposition == "north" || yposition == "N" && xposition1 < 2)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "East" || yposition == "east" || yposition == "E" && xposition2 > 8)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "South" || yposition == "south" || yposition == "south" && xposition1 > 8)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
			cin >> yposition;
		}
		while (yposition == "West" || yposition == "west" || yposition == "w" && xposition2 < 2)
		{
			cout << "The Cruiser will not fit within the tiles" << endl;
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


void Display(char Board[][10], int SIZE);
void CreateBoard(char Board[][10], int SIZE);
void Shipplacement(char Board[][10], int SIZE);
void Shipplacement2(char Board[][10], int SIZE);

int main()
{
	
	const int SIZE = 10;
	char BoardP1[SIZE][SIZE];
	char BoardP2[SIZE][SIZE];
	char BoardGuessP1[SIZE][SIZE];
	char BoardGuessP2[SIZE][SIZE];
	int choice;
	cout << "Welcome to the game Battleship " << endl;
	cout << "1. 2-Player" << endl;
	cout << "2. vs AI" << endl;
	cout << "3. Exit" << endl;
	cin >> choice;

	if (choice == 1)
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
			cout << "Player 1 take your shot" << endl;
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

			}
			else
			{
				cout << "You have missed" << endl;
				BoardGuessP1[position1][position2] = 'O';
			}
		}
	}
	else if (choice == 2)
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
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(8) << Board[i][j];
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
	cout << "Player 1 place your ships" << endl;
	Battleship.SetxpositionAircraft(Board, SIZE);
	Battleship.SetypositionAircraft(Board, SIZE);
	cout << "Aircraft Carrier has been placed" << endl;
	Battleship.SetxpositionBattleship(Board, SIZE);
	Battleship.SetypositionBattleship(Board, SIZE);
	cout << "Battleship has been placed" << endl;
	Battleship.SetxpositionCruiser(Board);
	Battleship.setypositionCruiser(Board, SIZE);
	cout << "Cruiser has been placed" << endl;
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	cout << "Submarine has been deployed" << endl;



}

void Shipplacement2(char Board[][10], int SIZE)
{
	ShipPlacement Battleship;
	cout << "Player 2 place your ships" << endl;
	Battleship.SetxpositionAircraft(Board, SIZE);
	Battleship.SetypositionAircraft(Board, SIZE);
	cout << "Aircraft Carrier has been placed" << endl;
	Battleship.SetxpositionBattleship(Board, SIZE);
	Battleship.SetypositionBattleship(Board, SIZE);
	cout << "Battleship has been placed" << endl;
	Battleship.SetxpositionCruiser(Board);
	Battleship.setypositionCruiser(Board, SIZE);
	cout << "Cruiser has been placed" << endl;
	Battleship.SetxpositionDestroyer(Board);
	Battleship.SetypositionDestroyer(Board, SIZE);
	cout << "Destroyer has been deployed" << endl;
	Battleship.SetxpositionSubmarine(Board);
	Battleship.SetypositionSubmarine(Board, SIZE);
	cout << "Submarine has been deployed" << endl;
}
