/*
 * findbestspot.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: nsamu
 */


//int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct);
//int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct);

int *currcount = 0;
int *newx = 0;
int *newy = 0;

int findbestspot(int currx, int curry,int &bestx,int &besty,GameBoard *game,int oldct){


}
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
	shouldweflip(currx, curry, -1, -1, &game, ct);
	shouldweflip(currx, curry, -1,  0, &game, ct);
	shouldweflip(currx, curry, -1,  1, &game, ct);
	shouldweflip(currx, curry,  0,  1, &game, ct);
	shouldweflip(currx, curry,  1,  1, &game, ct);
	shouldweflip(currx, curry,  1,  0, &game, ct);
	&currcount += ct;
	shouldweflip(currx, curry,  1, -1, &game, ct);
	&currcount += ct;
	shouldweflip(currx, curry,  0, -1, &game, ct);
	&currcount += ct;

}







/*
int findbestspoty(int currx, int curry, int &bestx, int &besty, GameBoard *game, int oldct){
	&newx = currx;
	&newy = curry;
	if(game(currx)(curry) == '-'){
		if(game(currx-1)(curry) == 'O'){
			&currcount++;

			findbestspoty(currx-1,curry, *bestx, *besty, &game, oldct);
		}
		if(game(currx-1)(curry) == 'X'){
			if(&currcount > oldct){
				oldct = &currcount;
				&bestx = currx;
				&besty = curry;
			}

	}
}
*/



