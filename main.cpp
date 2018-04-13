#include <iostream>
#include <iomanip>


using namespace std;
void Display(char Board[][10], int SIZE);
void CreateBoard(char Board[][10], int SIZE);

int main()
{
	const int SIZE = 10;
	char BoardP1[SIZE][SIZE];
	char BoardP2[SIZE][SIZE];
	int choice;
	cout << "Welcome to the game Battleship " << endl;
	cout << "1. 2-Player" << endl;
	cout << "2. vs AI" << endl;
	cout << "3. Exit" << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "You have chosen 2-Player mode " << endl;
		CreateBoard(BoardP1, SIZE);
		CreateBoard(BoardP2, SIZE);

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
void CreateBoard(int Board[][10], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Board[i][j] = '~';
		}
	}
}

void CreateBoard(char Board[][10], int SIZE)
{



}