/*
 * createGame.cpp
 *
 *  files relating to the creation of the board
 *
 */

#include "createGame.h"



void makeBoard2(char arr[], int ct, int size){
	/* function takes a character array (each element in a row)
	 * an int ct that is not used and an int size representing the size of
	 * the board. Function places a '-' in each element of the array
	 * returns nothing
	 */
    if(size > 0){
        arr[size-1] = '-';
        size--;
        makeBoard2(arr,ct,size);
    }
}

void makeBoard(GameBoard *game, int ct, bool flag){
	/* function takes a pointer to a GameBoard, an int ct and a boolean flag
	 * flag = true if the board needs to be created for the first time
	 * function creates the game board and places the first starting pieces
	 * returns nothing
	 */
    if(flag){
        game->board = new char*[game->size];
        makeBoard(game,ct,false);
    }
    else{
      if(ct<game->size){
        game->board[ct] = new char[game->size];
        makeBoard2(game->board[ct],0,game->size);
        ct++;
        makeBoard(game,ct,false);
      }
    }
    if(ct==game->size){
      game->board[((game->size)/2)-1][((game->size)/2)-1] = 'X';
      game->board[(game->size)/2][((game->size)/2)-1] = 'O';
      game->board[((game->size)/2)-1][(game->size)/2] = 'O';
      game->board[(game->size)/2][(game->size)/2] = 'X';
    }
}

void getSize(int &size){
	/* Function takes a reference to an int
		 * and generates a random even number between 6 and 16
		 * returns nothing
		 */
		size = rand()%11 + 6;
		if(size%2!=0){
			size++;
	}
}


void printRow(char arr[], int size,int ct, bool flag){
	/* function takes an array of chars representing a single row
	 * the size of the array, a ct (indx), and a flag indicating if it is
	 * the preliminary row (true)
	 * prints out each element of the array and creates a new line after
	 *  the last element is printed
	 * returns nothing
	 */
	if(flag){
		if(ct<size){
			if(ct == 0){
				cout << "*\t";
			}
			cout<<ct<< "\t";
			ct++;
			printRow(arr,size,ct,flag);
		}
		else{
			cout<<endl;
		}
	}
	else{
		if(ct<size){
			cout<< arr[ct]<< "\t";
			ct++;
			printRow(arr,size,ct,flag);
		}
		else{
			cout<<endl;
		}
	}
}
void printBoard(GameBoard *game, int ct){
	if(ct == 0){
		printRow(game->board[ct],game->size,0,true);
	}
	else{
		cout << ct-1 << "\t";
		printRow(game->board[ct-1],game->size,0,false);
	}
	ct++;
	if(ct<=game->size){
		printBoard(game,ct);
	}
}

int rowCount(char arr[], int size, int it, int &rowCounts){
	if(it<size){
		if(arr[it]=='-'){
			rowCounts++;
		}
		it++;
		rowCount(arr,size,it,rowCounts);
	}
	else{
		return rowCounts;
	}
}

void updateCount(GameBoard *game, int ct,int &boardCount){
	if(ct<game->size){
		int counter = 0;
		int val = rowCount(game->board[ct],game->size,0,counter);
		boardCount = boardCount + val;
		ct++;
		updateCount(game,ct,boardCount);
	}
	else{
		game->totalct = (game->size)^2 -boardCount;
	}
}
