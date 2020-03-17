/*
 * runTheGame.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */
#include "playGame.h"
#include "createGame.h"
#include "problem0and1.h"

int main(){

	GameBoard *testGame = new GameBoard;
	testGame -> size = 6;
	testGame ->totalct = 0;
	makeBoard(testGame, 0, true);
	printBoard(testGame,0);
	/* test problem 1
	char myArray[5] = {'c','a','f','e','b'};
	rxSelectionSort1(myArray,5,0);
	for(int i = 0; i<5; i++){
		cout <<myArray[i];
	}
	*/
	return 0;
}



