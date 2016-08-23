/*********************************************************************
** Program Filename: MaxSubarrayLinear.cpp
** Author: Group 8 - Niza Volair, Sara Hashem, Matt Palmer
** Date: 07/09/16
** Description: This function solves the max subarray problem through
**              a nonrecursive linear time algorithm 
** Input: An array
** Output: Max sum of subarray and associated subarray
** Sources Cited: https://en.wikipedia.org/wiki/Maximum_subarray_problem
*********************************************************************/
#include "MaxSubarrayLinear.hpp"
#include <iostream>
#include <fstream>

// Function implementation
/*********************************************************************
** Function: 		maxSubarrayLinear
** Description:		This function solves the max subarray problem through
**              	a nonrecursive linear time algorithm 
** Parameters: 		int array, array's length, file pointer
** Pre-Conditions:	Array initializaed with at least 1 positive int, file
					open for writing
** Post-Conditions:	Max sum returned, subarray and max sum printed to
					standard output and output file
*********************************************************************/
int maxSubarrayLinear(int inputArray[], int inputArrayLength, std::ofstream &file){
	// Initialize current and max sum with first array element
	int curMaxSum = inputArray[0];
	int maxSum = inputArray[0];

	// Initiliaze left and right index positions with first position
	int left = 0;
	int right = 0;

	// Initiliaze start and end indices of subarray with first position
	int start = 0;
	int end = 0;

	// Loop through array
	for(int i = 1; i < inputArrayLength; i++){
		// If current max sum is less than current element
		if((curMaxSum + inputArray[i]) < inputArray[i]){
			// Increment index positions
			left = i;
			right = i;

			// Set current max sum to current element
			curMaxSum = inputArray[i];
		}

		// Otherwise,
		else{
			// Increment within possible subarray
			right = i;

			// Accumulate current max sum with current element
			curMaxSum += inputArray[i];
		}

		// Compare current and max sum, swap if necessary
		if(curMaxSum > maxSum){
			maxSum = curMaxSum;

			// Update subarray indices
			start = left;
			end = right;
		}
	}


	// Print to standard output
	std::cout << "[";

	for(int i = start; i <= end; i++){
		std::cout << inputArray[i];
		if(i < end){
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
	std::cout << maxSum << std::endl;


	// Print to output file
	file << "[";

	for(int i = start; i <= end; i++){
		file << inputArray[i];
		if(i < end){
			file << ", ";
		}
	}

	file << "]" << std::endl;
	file << "Linear: " << maxSum << std::endl << std::endl;


	// Return max sum of subarray
	return maxSum;
}
