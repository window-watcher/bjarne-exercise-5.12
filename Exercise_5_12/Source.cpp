/*
	Project:Exercise 5.12
	By: Adrian Rodriguez
	Date:9/3/20
	Objective: 
	Create the game Bulls & Cows
	User guess the correct combination to win
	If user's guess is a correct number in the correct slot then user gets a bull
	If user's guess is a correct number NOT in the correct slot then user gets a cow

	Version 1.1

	Change log
	version 1.1 : Improved code structure.

*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }
int check_for_bulls(vector<int>player_board, vector<int>game_board,int size) {
	int bulls = 0;
	for (int i = 0; i < size; ++i) {
		if (player_board[i] == game_board[i]) { ++bulls; }
		}
	return bulls;
}
int check_for_cows(vector<int>player_board, vector<int>game_board, int size) {
	int cows = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) { 
			if (player_board[i] == game_board[j]) { ++cows; } 
		}	
	}
	return cows;
}

void bull_and_cows() {
	bool game = true;
	vector<int> board(4);
	int board_size = board.size(); // created to ensure game board and player's board match.
	board[0] = 6;
	board[1] = 9;
	board[2] = 4;
	board[3] = 2;

	//Prompt user on game
	cout << "Welcome to Bulls & Cows!\nEnter " << board_size << " numbers between 0 and 9 \n";
	while (game == true) {
		int bulls = 0, cows = 0;
		vector<int> digits(board_size);

		for (int i = 0; i < board_size; ++i) {cin >> digits[i];}//user enters his guesses

		bulls = check_for_bulls(digits, board, board_size);
		cows = check_for_cows(digits, board, board_size);
		cows = cows - bulls;

		if (bulls == board_size) { game = false; cout << "Your number of bulls is : " << bulls << "\nYOU WIN!\n"; }
		else { cout << "Your number of bulls is : " << bulls << "\n Your number of cows is : " << cows << endl; }

	}
}
int main() {
	try {
		bull_and_cows();
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
	keep_window_open();//wait for a character to be enter
	return 0;
}