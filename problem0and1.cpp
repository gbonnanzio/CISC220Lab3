/*
 * problem0and1.cpp
 *
 *  Created on: Mar 16, 2020
 *      Author: gbonn
 */

#include "problem0and1.h"

int func(int k){
	if(k<=2){
		return 1;
	}
	return (func(k-1)+func(k-2));
}
