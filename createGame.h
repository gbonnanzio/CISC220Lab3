/*
 * createGame.h
 *
 * Geoffrey Bonnanzio and Nick Samulewicz
 *
 * functions in this file are related to making and printing the board
 * defining the GameBoard struct and keeping track of the pieces played
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
void getSize(int &size);
void printRow(char arr[], int size,int ct, bool flag);
void printBoard(GameBoard *game, int ct);
int rowCount(char arr[], int size, int it, int dashes);
void updateCount(GameBoard *game, int ct,int &boardCount);

#endif /* CREATEGAME_H_ */
