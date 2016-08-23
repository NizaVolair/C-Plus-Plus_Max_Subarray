/*********************************************************************
** Program Filename: 	MaxSubarrayRec.cpp
** Author: 					Group 8 - Niza Volair, Sarah Hashem, Matt 
**								Palmer
** Date:						07/05/16
** Description:			This program recursively solves the max 
**								subarray problem
** Input:					An array
** Output:					The max sum of all possible subarrays
*********************************************************************/




#ifndef MAX_SUBARRAY_REC_H
#define MAX_SUBARRAY_REC_H

#include <math.h>
#include <fstream>


// Function prototypes
int maxSubarrayRec(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength, std::ofstream &file);
int maxPrefix(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength);
int maxSuffix(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength);

#endif