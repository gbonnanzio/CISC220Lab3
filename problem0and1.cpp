/*
 * problem0and1.cpp
 *
 * Geoffrey Bonnanzio and Nick Samulewicz
 *
 * problems related to question 1 of the lab
 */

#include "problem0and1.h"

void rxSelectionSort1(char arr[], int len, int indx){
	/* this function takes a character array, representing the
	 * list to be sorted, as well as the length of the list
	 * and the current index of the array
	 * this function sorts the char array from smallest to largest
	 * returns nothing
	 */
    if(len-indx != 0){
        int smllstIndx = indx;
        int innerLoopSmallestIndex = rxSelectionSort2(arr,len,indx+1,smllstIndx);
        char tmp = arr[innerLoopSmallestIndex];
        arr[innerLoopSmallestIndex] = arr[indx];
        arr[indx]=tmp;
        indx++;
        rxSelectionSort1(arr,len,indx);
    }
}
int rxSelectionSort2(char arr[],int len, int indx,int smllstIndx){
	/* this function is the helper function to rxSlectionSort1 and
	 * works by finding the next smallest character in the array that it is
	 * passed and returning the index so that it can be switched
	 * this function takes the char array to be sorted, the length of the array, the index
	 * that it is currently on and the former index that holds the current index of the smallest
	 * element
	 */
  if(len-indx!=0){
    if(arr[indx]<arr[smllstIndx]){
        smllstIndx = indx;
    }
    indx++;
    smllstIndx = rxSelectionSort2(arr,len,indx,smllstIndx);
  }
  return smllstIndx;
}
