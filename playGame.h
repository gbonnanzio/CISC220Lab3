/*
 * playGame.h
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */

#ifndef PLAYGAME_H_
#define PLAYGAME_H_

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "createGame.h"

//function declarationskou
int ckrow(char arr[],char p,int size, int ct, int score);
void ckwin(GameBoard *game,int ct,int finScore);
int shouldweflip(int x, int y, int xd, int yd, GameBoard *game,int ct);

#endif /* PLAYGAME_H_ */
