/*
 * createGame.cpp
 *
 *  files relating to the creation of the board
 *
 */

#include "createGame.h"



void makeBoard2(char arr[], int ct, int size){
	if(size > 0){
		arr[size-1] = '-';
		size--;
		makeBoard2(arr,ct,size);
	}
}
void makeBoard(GameBoard *game, int ct, bool flag){
	if(!flag){
		game->board = new char*[game->size];
		//game->board[]
	}
}
