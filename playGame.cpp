/*
 * playGame.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */

#include "playGame.h"
#include "createGame.h"

int ckrow(char arr[],char p,int size, int it, int *ct){
	/* function takes the current array of a row, a char representing
	 * the current player an integer size for size of board,
	 * an int iterator and a running score
	 * returns the number of pieces belonging to that player
	 * in that row
	 */
	if(it<size){
		if(arr[it]==p){
			*ct++;
		}
		it++;
		ckrow(arr,p,size,it,ct);
	}
	else{
		return *ct;
	}
}

char ckwin(GameBoard *game,int ct,int finScore){
	/* function takes the gameboard and an integer
	 * counter and determines who has
	 * the higher score of the two players
	 * returns nothing but prints the winner
	 */
	char oppPiece;
	if(game->p == 'X'){
		oppPiece = 'O';
	}
	else{
		oppPiece = 'X';
	}

	if(ct<game->size){
		finScore = finScore + ckrow(game->board[ct],game->p,game->size,0,0);
		ct++;
		ckwin(game,ct,finScore);
	}
	else{
		int otherScore = (game->size)^(2)-finScore;
		if(finScore > otherScore){
			cout << "Player "<< game->p <<"wins!"<<endl;
			return game->p;
		}
		else if(otherScore > finScore){
			cout<< "Player " << oppPiece<< " wins!"<<endl;
			return oppPiece;
		}
		else{
			cout<< "It's a tie!"<<endl;
			return 'T';
		}
	}
}

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
	if(x<game->size && x>=0 && y<game->size && y>=0){
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
	else{
		return 0;
	}
}
void flipping(int x, int y, int xd,int yd, GameBoard *game){
	/* this function actually flips the pieces on the board
	 * once it has been determined that flipping in that
	 * direction occurs
	 * returns nothing
	 */
	char oppPiece;
	if(game->p == 'X'){
		oppPiece = 'O';
	}
	else{
		oppPiece = 'X';
	}
	if(game->board[x][y]==oppPiece){
		game->board[x][y] = game->p;
		flipping(x+xd,y+yd,xd,yd,game);
	}
}

int figureoutflipping(int x, int y, GameBoard *game){
	/* function starts at (x,y) and looks in all 8 directions
	 * to see which pieces are flipped in a single direction
	 * it then flips those pieces
	 */
	int ct = 0;
	int one = shouldweflip(x, y, -1, -1, game, ct);
	if(one>0){
		flipping(x,y,-1,-1,game);
	}

	int two = shouldweflip(x, y, -1,  0, game, ct);
	if(two>0){
		flipping(x,y,-1,0,game);
	}

	int three = shouldweflip(x, y, -1,  1, game, ct);
	if(three>0){
		flipping(x,y,-1,1,game);
	}

	int four = shouldweflip(x, y,  0,  1, game, ct);
	if(four>0){
		flipping(x,y,0,1,game);
	}

	int five = shouldweflip(x, y,  1,  1, game, ct);
	if(five>0){
		flipping(x,y,1,1,game);
	}

	int six = shouldweflip(x, y,  1,  0, game, ct);
	if(six>0){
		flipping(x,y,1,0,game);
	}

	int seven = shouldweflip(x, y,  1, -1, game, ct);
	if(seven>0){
		flipping(x,y,1,-1,game);
	}

	int eight = shouldweflip(x, y,  0, -1, game, ct);
	if(eight>0){
		flipping(x,y,0,-1,game);
	}
	return (one + two + three + four + five + six + seven + eight);
}

bool placepieceperson(GameBoard *game){
	int pickedX;
	int pickedY;
	cout << "Pick X Coordinate:";
	cin >> pickedX;
	if(pickedX<0 || pickedX>=game->size){
		cout<< "You have forfeited the turn";
		return false;
	}
	cout << "Pick Y Coordinate:";
	cin>>pickedY;
	if(pickedY < 0 || pickedY >= game->size){
		cout << "You have forfeited the turn";
		return false;
	}
	if(game->board[pickedX][pickedY] != '-'){
		cout<< "You have forfeited the turn";
		return false;
	}
	if(figureoutflipping(pickedX,pickedY,game)==0){
		cout<< "You have forfeited the turn";
		return false;
	}
	else{
		return true;
	}
}

