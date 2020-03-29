/*
 * playGame.h4
 *
 */

#ifndef PLAYGAME_H_
#define PLAYGAME_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

#include "createGame.h"

//function declaration
int ckrow(char arr[],char p,int size, int it, int &ct);
char ckwin(GameBoard *game,int ct,int &finScore);
int shouldweflip(int x, int y, int xd, int yd, GameBoard *game,int ct);
void flipping(int x, int y, int xd,int yd, GameBoard *game);
int figureoutflipping(int x, int y, GameBoard *game);
bool placepieceperson(GameBoard *game);

int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct);
int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct);
bool compplacepiece(GameBoard *game);


#endif /* PLAYGAME_H_ */
