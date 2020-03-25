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
		if(finScore > ((game->size)^2)-finScore){
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

/*bool compPlacePiece(GameBoard *game){
	 function to help computer figure out what spot will result in the most
	 * pieces being flipped. Returns true if pieces were flipped sucessfully
	 * and false if the player/computer forfeits their turn


	int playedX = 0;
	int playedY = 0;
	if(game->p == 'X'){
		char oppPiece = 'O';
	}
	else{
		char oppPiece = 'X';
	}
	findBestSpot(0,0,playedX,playedY,game,0);

	return true;
}

int findBestSpot(int currX, int currY, int &bestX, int &bestY, GameBoard *game, int oldCt){
	 checks all (x,y) spots and finds best spot to place piece on
	 * the board. if two spots are tied it will randomly pick one.
	 * oldCt represents how many pieces will be switched if bestX and Y is used
	 * The return will be ??

	if(oldCt < findBestSpotY())

	return 0;
}

int findBestSpotY(int currX, int currY, int &bestX, int &bestY, GameBoard *game, int oldCt){
	 this function will check each direction to see how many pieces would
	 * be switched if placed here

	if(game->board[currX][currY] == game->p){
		if(game->board[currX+1][currY]==)
	}
}*/

int shouldweflip(int x, int y, int xd, int yd, GameBoard *game,int ct){
	/* this function takes the current x and y, the direction we are
	 * looking at, the GameBoard, and the count of how many pieces will be
	 * flipped.
	 * returns the count
	 */
	char oppPiece;
	if(game->p == 'X'){
		oppPiece = 'O';
	}
	else{
		oppPiece = 'X';
	}
	if(game->board[x][y]==oppPiece){
		ct++;
		shouldweflip(x+xd,y+yd,xd,yd,game,ct);
	}
	else if(game->board[x][y]==game->p){
		return ct;
	}
	else{
		return 0;
	}
}
void flipping(int x, int y, int xd,int yd, GameBoard *game, int ct){

}
int figureoutflipping(int x, int y, int xd, int yd, GameBoard *game){

}

