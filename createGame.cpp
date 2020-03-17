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
    if(flag){
        game->board = new char*[game->size];
        makeBoard(game,ct,false);
    }
    else{
      if(ct<game->size){
        game->board[ct] = new char[game->size];
        makeBoard2(game->board[ct],0,game->size);
        ct++;
        makeBoard(game,ct,false);
      }
    }
    if(ct==game->size){
      game->board[((game->size)/2)-1][((game->size)/2)-1] = 'X';
      game->board[(game->size)/2][((game->size)/2)-1] = 'O';
      game->board[((game->size)/2)-1][(game->size)/2] = 'O';
      game->board[(game->size)/2][(game->size)/2] = 'X';
    }
}

void getSize(int &size){
	/* Function takes a reference to an int
		 * and generates a random even number between 6 and 16
		 * returns nothing.
		 */
		size = rand()%11 + 6;
		if(size%2!=0){
			size++;
	}
}
