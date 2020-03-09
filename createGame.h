/*
 * createGame.h
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */

#ifndef CREATEGAME_H_
#define CREATEGAME_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct GameBoard {
	char **board; // the othello board
	int size; //for the size of the board (it's a square, so size is one dimension)
	char p; //for current player ('X' or 'O')
	int totalct; // for number of used squares (so that when the board is full, the game stops)
};


//functions
void makeBoard(GameBoard *game, int ct, bool flag);
void makeBoard2(char arr[], int ct, int size);

#endif /* CREATEGAME_H_ */
