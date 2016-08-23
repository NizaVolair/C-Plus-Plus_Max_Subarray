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

#include <cmath>
#include <iostream>
#include <fstream>
#include "MaxSubarrayRec.hpp"


// Function implementations
/*********************************************************************
** Function: 			maxSubarrayRec
** Description:		This function finds the maximum sum of any 
							consecutive subarray
** Parameters: 		int array, start array index, end array index, 
**							array's length
** Pre-Conditions:	Array initialized, indices are valid
** Post-Conditions:	Subarray sum returned
*********************************************************************/
int maxSubarrayRec(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength, std::ofstream &file){
	int midIndex = 0;
	int leftSum, rightSum, middleSum;
	
	// Base case
	if(endIndex - startIndex == 0){
		return inputArray[startIndex];
	}
	// Recursive case
	else{
		// Calculate the middle index of the array
		midIndex = (endIndex - startIndex + 1) / 2 + startIndex;
		
		// Recursively find the max subarray sum
		leftSum = maxSubarrayRec(inputArray, 
			startIndex, 
			(midIndex - 1), 
			(midIndex - startIndex), file);
			
		rightSum = maxSubarrayRec(inputArray, 
			midIndex, 
			endIndex, 
			(endIndex + 1 - midIndex), file);
			
		middleSum = maxSuffix(inputArray, 
			startIndex, 
			(midIndex - 1), 
			(midIndex - startIndex)) + 
			maxPrefix(inputArray, 
			midIndex, 
			endIndex, 
			(endIndex + 1 - midIndex));
		/* 
		 * Combine the results of the recursive calls by finding
		 * the greatest sum returned by the functions
		 */
		if(leftSum >= rightSum && leftSum >= middleSum){
			// Output to file
			file << "Recursive: " << leftSum << std::endl;
			return leftSum;
		}
		else if(rightSum >= leftSum && rightSum >= middleSum){
			// Output to file
			file << "Recursive: " << rightSum << std::endl;			
			return rightSum;
		}
		else {
			// Output to file
			file << "Recursive: " << middleSum << std::endl;
			return middleSum;
		}
	}
}

/*********************************************************************
** Function: 			maxPrefix
** Description:		This function finds the maximum sum of subarrays
							starting from the last element of the array
** Parameters: 		int array, start array index, end array index, 
**							array's length
** Pre-Conditions:	Array initialized, indices are valid
** Post-Conditions:	Subarray sum returned
*********************************************************************/
int maxPrefix(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength){
	int index, sum;
	if(inputArrayLength == 1){
		return inputArray[startIndex];
	}
	else if(inputArray[startIndex] < 0){
		return 0;
	}
	else{
		// Initialize the loop variables to default values
		index = startIndex;
		sum = inputArray[index];
		
		/*
		 * Loop through the array and add each element until
		 * the maximum sum is found
		 */
		while(index + 1 <= endIndex){
			if(inputArray[index + 1] + sum > sum){
				// Add the next element's value to the sum
				sum += inputArray[index + 1];
				index++;
			}
			else{
				// The next element lowers sum, exit loop
				break;
			}
		}
		// Return the max sum found
		return sum;	
	}
}

/*********************************************************************
** Function: 			maxSuffix
** Description:		This function finds the maximum sum of subarrays
							starting from the first element of the array
** Parameters: 		int array, start array index, end array index, 
**							array's length
** Pre-Conditions:	Array initialized, indices are valid
** Post-Conditions:	Subarray sum returned
*********************************************************************/
int maxSuffix(int inputArray[], unsigned int startIndex, 
	unsigned int endIndex, int inputArrayLength){
	int index, sum;
	if(inputArrayLength == 1){
		return inputArray[startIndex];
	}
	else if(inputArray[endIndex] < 0){
		return 0;
	}
	else{
		// Initialize the loop variables to default values
		index = endIndex;
		sum = inputArray[index];
		
		/*
		 * Loop through the array and add each element until
		 * the maximum sum is found
		 */
		while(index - 1 >= startIndex){
			if(inputArray[index - 1] + sum > sum){
				// Add the next element's value to the sum
				sum += inputArray[index - 1];
				index--;
			}
			else{
				// The next element lowers sum, exit loop
				break;
			}
		}
		// Return the max sum found
		return sum;	
	}
}