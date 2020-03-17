/*
 * problem0and1.cpp
 *
 *  Created on: Mar 16, 2020
 *      Author: gbonn
 */

#include "problem0and1.h"

void rxSelectionSort1(char arr[], int len, int indx){
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
  if(len-indx!=0){
    if(arr[indx]<arr[smllstIndx]){
        smllstIndx = indx;
    }
    indx++;
    smllstIndx = rxSelectionSort2(arr,len,indx,smllstIndx);
  }
  return smllstIndx;
}
