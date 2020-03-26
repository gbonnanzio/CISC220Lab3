/*
 * findbestspot.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: nsamu
 */
#include "playGame.h"
#include "createGame.h"


int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct){
	if(currx == game-> size){
			return oldct;
	}
	oldct = findbestspoty(currx, curry, bestx, besty, game, oldct);
	return findbestspot(currx + 1, curry, bestx, besty, game, oldct);

}
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
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
	int compBestX = 0;
	int compBestY = 0;
	int oldct = findbestspot(0, 0, compBestX, compBestY, game, 0);
	cout << oldct << endl;
	if(oldct == 0){
		cout << "There are no moves. The computer forfeits their turn." << endl;
		return false;
	}
	else{
		figureoutflipping(compBestX, compBestY, game);
		return true;
	}
}

