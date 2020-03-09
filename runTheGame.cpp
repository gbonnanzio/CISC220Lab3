/*
 * runTheGame.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: gbonn
 */
#include "playGame.h"
#include "createGame.h"

int main(){
	cout<<"Hip"<<endl;
	char charArray[5];
	makeBoard2(charArray,0,5);
	for(int i = 0; i<5; i++){
		cout<< charArray[i];
	}
	return 0;
}



