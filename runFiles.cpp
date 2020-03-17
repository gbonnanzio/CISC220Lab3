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
	/*
	cout<<"Hip"<<endl;
	char charArray[5];
	makeBoard2(charArray,0,5);
	for(int i = 0; i<5; i++){
		cout<< charArray[i];
	}
	*/
	char myArray[5] = {'c','a','f','e','b'};
	rxSelectionSort1(myArray,5,0);
	for(int i = 0; i<5; i++){
		cout <<myArray[i];
	}
	return 0;
}



