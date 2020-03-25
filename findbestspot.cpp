/*
 * findbestspot.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: nsamu
 */
#include "playGame.cpp"
#include "createGame.h"


int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct){
	if(currx + 1 == game-> size){
			return oldct;
	}
	findbestspoty(currx, curry, bestx, besty, game, oldct);
	findbestspot(currx + 1, curry, bestx, besty, game, oldct);

}
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
	int ct = 0;
	if(game->board[currx][curry] == 'X' || game->board[currx][curry] == 'O'){
		return oldct;
	}
	shouldweflip(currx, curry, -1, -1, game, ct);
	shouldweflip(currx, curry, -1,  0, game, ct);
	shouldweflip(currx, curry, -1,  1, game, ct);
	shouldweflip(currx, curry,  0,  1, game, ct);
	shouldweflip(currx, curry,  1,  1, game, ct);
	shouldweflip(currx, curry,  1,  0, game, ct);
	shouldweflip(currx, curry,  1, -1, game, ct);
	shouldweflip(currx, curry,  0, -1, game, ct);
	if(ct >= oldct){
		bestx = currx;
		besty = curry;
		oldct = ct;
	}
	if(curry + 1 == game-> size){
		return oldct;
	}
	findbestspoty(currx, curry + 1, bestx, besty, game, oldct);
}

bool compplacepiece(GameBoard *game){
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

