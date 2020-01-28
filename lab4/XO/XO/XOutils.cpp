#include "pch.h"
#include <iostream>
#include "XOutils.h"
#include <ctime>
#include <algorithm>


XO::Game initGame(char userChar) {
	//system("CLS");
	srand(unsigned(time(0)));
	XO::Game gm;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gm.board[i][j] = '.';
		}
	}
	gm.isUserTurn = rand() % 2;
	gm.userChar = userChar;
	gm.botChar = (userChar=='O'?'X':'O');
	gm.status = XO::PLAY;
	return gm;
}

void updateDisplay(const XO::Game game) {
	system("CLS");
	std::cout << game.playerScore << "  -  " << game.botScore << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "  1 2 3" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << ' ';
		for (int j = 0; j < 3; j++) {
			std::cout << game.board[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}


bool boardEmpty(XO::Game* game) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] != '.') return false;
		}
	}
	return true;
}

bool checkWinMoves(XO::Game* game, char Char) {
	int rows[3] = {};
	int cols[3] = {};
	int diags[2] = {};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] == Char) rows[i]++;
		}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (game->board[j][i] == Char) cols[i]++;
		}
	for (int i = 0; i < 3; i++) {
		if (game->board[i][i] == Char) diags[0]++;
	}
	for (int i = 0; i < 3; i++)
		if (game->board[2 - i][i] == Char) diags[1]++;

	if (diags[0] == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][i] == '.') {
				game->board[i][i] = game->botChar;
				return true;
			}
		}
	}

	if (diags[1] == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[2 - i][i] == '.') {
				game->board[2 - i][i] = game->botChar;
				return true;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (rows[i] == 2) {
			for (int j = 0; j < 3; j++) {
				if (game->board[i][j] == '.') {
					game->board[i][j] = game->botChar;
					return true;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (cols[i] == 2) {
			for (int j = 0; j < 3; j++) {
				if (game->board[j][i] == '.') {
					game->board[j][i] = game->botChar;
					return true;
				}
			}
		}
	}
	return false;
}

bool won(XO::Game* game, char c);
bool draw(XO::Game* game);

int minimax(char board[3][3], int depth, bool isMaximizing) {

	if (won(game, game->botChar)) {
		return 1;
	}
	else if (won(game, game->userChar)) {
		return -1;
	}
	else if (draw(game)){
		return 0;
	}
	

	if (isMaximizing) {
		bool first = true;
		int bestScore = -INFINITY;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (game->board[i][j] == '.') {
					game->board[i][j] == game->botChar;
					int score = minimax(game, depth + 1, false);
					game->board[i][j] == '.';
					if (first) bestScore = score;
					else bestScore = std::max(score, bestScore);
					first = false;
				}
			}
		}
		return bestScore;
	} else {
		bool first = true;
		int bestScore = INFINITY;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (game->board[i][j] == '.') {
					game->board[i][j] == game->botChar;
					int score = minimax(game, depth + 1, true);
					game->board[i][j] == '.';
					if (first) bestScore = score;
					else bestScore = std::min(score, bestScore);
					first = false;
				}
			}
		}
		return bestScore;
	}
}

void botTurn(XO::Game* game) {

	if (boardEmpty(game)) {
		game->board[1][1] = game->botChar;
		return;
	}

	if (!checkWinMoves(game, game->botChar)) {
		if (!checkWinMoves(game, game->userChar)){
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (game->board[i][j] == '.') {
						game->board[i][j] = game->botChar;
							return;
					}
				}
			}
		}
	}
	
	/*int move[] = { 0,0 };
	int bestScore = -INFINITY;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] == '.') {
				game->board[i][j] = game->botChar;
				int score = minimax(game->board, 0, true);
				game->board[i][j] = '.';
				if (score > bestScore) {
					bestScore = score;
					move[0] = i; move[1] = j;
				}
			}
		}
	}
	game->board[move[0]][move[1]] = game->botChar;*/
	return;
}

void userTurn(XO::Game* game) {
	int row, col;
	while (1) {
		std::cin >> col >> row;
		col--; row--;
		if (game->board[row][col] == '.' && row >= 0 && row <= 2 && col >= 0 && col <= 2) {
			game->board[row][col] = game->userChar;
			break;
		}
		else {
			std::cout << "������� ���������� ���������� �����!" << std::endl;
		}
	}
}

bool won(XO::Game* game, char c) {
	int a = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] == c) a++;
			if (a == 3) return true;
		}
		a = 0;
	}
	a = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->board[j][i] == c) a++;
			if (a == 3) return true;
		}
		a = 0;
	}
	a = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[i][i] == c) a++;
		if (a == 3) return true;
	}
	a = 0;
	for (int i = 0; i < 3; i++) {
		if (game->board[2 - i][i] == c) a++;
		if (a == 3) {
			return true;
		}
	}
	return false;
}



bool draw(XO::Game* game) {
	bool full = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] == '.') full = false;
		}
	}
	return (full && !won(game, game->userChar) && !won(game, game->botChar));
}



bool quit() {
	char a = 0;
	while (1) {
		std::cout << "��� ���? (1 - ��, 2 - ���): ";
		std::cin >> a;
		switch (a) {
		case '1': return false;
		case '2': return true;
		}
	}
}

void restart(XO::Game* game) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game->board[i][j] = '.';
		}
	}
	updateDisplay(*game);
	game->status = XO::PLAY;
}

bool updateGame(XO::Game* game) {
	if (won(game, game->userChar)) {
		game->status = XO::USER_WIN;
		std::cout << "�� ��������!" << std::endl;
		game->playerScore++;
		if (quit()) return true;
		restart(game);
	}
	if (won(game, game->botChar)) {
		game->status = XO::BOT_WIN;
		std::cout << "�� ���������!" << std::endl;
		game->botScore++;
		if(quit()) return true;
		restart(game);
	}
	if (draw(game)) {
		game->status = XO::NOT_WIN;
		std::cout << "�����!" << std::endl;
		if(quit()) return true;
		restart(game);
	}
	if (game->isUserTurn) {
		userTurn(game);
		game->isUserTurn = false;
	}
	else {
		botTurn(game);
		game->isUserTurn = true;
	}
	return false;
}