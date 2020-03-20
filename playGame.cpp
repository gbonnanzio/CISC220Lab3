/*
 * playGame.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */

#include "playGame.h"
#include "createGame.h"

int ckrow(char arr[],char p,int size, int ct, int score){
	/* function takes the current array of a row, a char representing
	 * the current player an integer size for size of board,
	 * an int iterator and a running score
	 * returns the number of pieces belonging to that player
	 * in that row
	 */
	if(ct<size){
		if(arr[ct]==p){
			score++;
		}
		ct++;
		ckrow(arr,p,size,ct,score);
	}
	else{
		return score;
	}
}

void ckwin(GameBoard *game,int ct,int finScore){
	/* function takes the gameboard and an integer
	 * counter and determines who has
	 * the higher score of the two players
	 * returns nothing but prints the winner
	 */
	if(ct<game->size){
		finScore = finScore + ckrow(game->board[ct],game->p,game->size,0,0);
		ct++;
		ckwin(game,ct,finScore);
	}
	else{
		if(finScore > (game->size)^2-finScore){
			cout << "Player "<< game->p <<"wins!"<<endl;
		}
		else if(game->p == 'X'){
			cout<< "Player O wins!"<<endl;
		}
		else if(game->p == 'O'){
			cout<< "Player X wins!"<<endl;
		}
		else{
			cout<< "It's a tie!"<<endl;
		}
	}
}

bool compPlacePiece(GameBoard *game){
	/* function to help computer figure out what spot will result in the most
	 * pieces being flipped. Returns true if pieces were flipped sucessfully
	 * and false if the player/computer forfeits their turn
	 */

	int playedX = 0;
	int playedY = 0;
	char oppPiece = 'N';
	if(game->p == 'X'){
		oppPiece = 'O';
	}
	else{
		oppPiece = 'X';
	}
	findBestSpot(0,0,playedX,playedY,game);

	return true;
}

int findBestSpot(int currX, int currY, int &bestX, int &bestY, GameBoard *game, int oldCt){
	/* checks all (x,y) spots and finds best spot to place piece on
	 * the board. if two spots are tied it will randomly pick one.
	 * oldCt represents how many pieces will be flipped if bestX and Y is used
	 * The return will be ??
	 */

	return 0;
}

int findbestspoty(int currX, int currY, int &bestX, int &bestY, GameBoard *game, int oldCt){
	/* this function will check each direction to see how many pieces would
	 * be flipped if placed here
	 */
	if(game->board[currX][currY] == game->p){
		if(game->board[currX+1][currY]==)
	}
}


