/*
 * findbestspot.cpp
 *
 * Geoffrey Bonnanzio and Nick Samulewicz
 *
 * files related to finding the best spot to flip for the computer
 * and the computer placing the piece
 */
#include "playGame.h"
#include "createGame.h"


int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct){
	/* checks all x and y positions on the board and finds the best spot to
	* place a piece on the board. If two spots are tied, my game randomly chooses between them.
	* Uses findbestspoty as a helper function
	*/
	if(currx == game-> size){
			return oldct;
	}
	oldct = findbestspoty(currx, curry, bestx, besty, game, oldct);
	return findbestspot(currx + 1, curry, bestx, besty, game, oldct);

}
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
	/* This is the helper function for findbestspot – for each row in the board. Checks
	 *each direction to see how many pieces would be flipped if a piece is placed here. It went through the entire row,
	 *updating the best x location and the best y location and the best count (the oldct) if the current xy square resulted
	 *in more flips than any previous square (if it tied with the previous best square, it picked randomly
	 *between the two).
	 */
	int ct = 0;
	if(curry == game-> size){
			return oldct;
	}
	if(!(game->board[currx][curry] == 'X' || game->board[currx][curry] == 'O')){
		int one = shouldweflip(currx, curry, -1, -1, game, ct);
		int two = shouldweflip(currx, curry, -1,  0, game, ct);
		int three = shouldweflip(currx, curry, -1,  1, game, ct);
		int four = shouldweflip(currx, curry,  0,  1, game, ct);
		int five = shouldweflip(currx, curry,  1,  1, game, ct);
		int six = shouldweflip(currx, curry,  1,  0, game, ct);
		int seven = shouldweflip(currx, curry,  1, -1, game, ct);
		int eight = shouldweflip(currx, curry,  0, -1, game, ct);
		ct = one + two + three + four + five + six + seven + eight;
		if(ct > oldct){
			bestx = currx;
			besty = curry;
			oldct = ct;
		}
		if(ct == oldct && rand()%2 == 0){
			bestx = currx;
			besty = curry;
			oldct = ct;
		}
	}
	findbestspoty(currx, curry + 1, bestx, besty, game, oldct);
}

bool compplacepiece(GameBoard *game){
	/* This function is used for when the computer is playing as one (or both) of the players. It determines
	* the location on the board where, if it places its piece, the most other pieces will be flipped. It is not
	* terribly intelligent – it just picks randomly among the squares in which the most pieces will be flipped.
	* It calls the function findbestspot to find the best x and y location on the board that
	* will flip the most pieces. If there are no spots on the board that flip pieces, the function prints
	* out that the player forfeits their turn and returns false. Otherwise, it calls figureoutflipping to
	* flip the legal pieces on the board after placing the game piece at location x y It returns true if
	* a piece was placed successfully, and false if there was nowhere to place a piece that would result
	* in flipping.
	**/

	int compBestX = 0;
	int compBestY = 0;
	int oldct = findbestspot(0, 0, compBestX, compBestY, game, 0);
	if(oldct == 0){
		cout << "There are no moves. The computer forfeits their turn." << endl;
		return false;
	}
	else{
		figureoutflipping(compBestX, compBestY, game);
		return true;
	}
}

