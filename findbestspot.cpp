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
		cout << "test 2" << endl;
			return oldct;
	}
	oldct = findbestspoty(currx, curry, bestx, besty, game, oldct);
	findbestspot(currx + 1, curry, bestx, besty, game, oldct);

}
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
	int ct = 0;
	if(curry == game-> size){
			return oldct;
	}
	if(!(game->board[currx][curry] == 'X' || game->board[currx][curry] == 'O')){
		ct = shouldweflip(currx, curry, -1, -1, game, ct);
		ct = shouldweflip(currx, curry, -1,  0, game, ct);
		ct = shouldweflip(currx, curry, -1,  1, game, ct);
		ct = shouldweflip(currx, curry,  0,  1, game, ct);
		ct = shouldweflip(currx, curry,  1,  1, game, ct);
		ct = shouldweflip(currx, curry,  1,  0, game, ct);
		ct = shouldweflip(currx, curry,  1, -1, game, ct);
		ct = shouldweflip(currx, curry,  0, -1, game, ct);
		cout << ct << endl;
		if(ct >= oldct){
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

