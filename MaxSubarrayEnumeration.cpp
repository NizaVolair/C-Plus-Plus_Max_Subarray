/*********************************************************************
** Program Filename: MaxSubarrayEnumeration.cpp
** Author: 			Group 8 - Niza Volair, Sarah Hashem, Matt Palmer
** Date: 			07/06/16
** Description: These functions solve the max subarray problem through
					simple enumeration and improved enumeration 
** Input: 		An array
** Output: 		The max sum of all possible subarrays
*********************************************************************/
#include "MaxSubarrayEnumeration.hpp"
#include <iostream>
#include <fstream>

// Function implementations
/*********************************************************************
** Function: 		maxSubarrayEnumeration
** Description:		This function finds the maximum sum of any 
						consecutive subarray with basic eumeration
** Parameters: 		int array and array's length
** Pre-Conditions:	Array initialized with at least 1 positive int
** Post-Conditions:	Subarray sum returned
*********************************************************************/
int maxSubarrayEnumeration(int inputArray[], int inputArrayLength, std::ofstream &file){
	// Create sum and tempSum variable to track totals
	int  tempSum, sum = 0;
	
	// Loop through each element in the array
	for(int i = 0; i < inputArrayLength; i++) {
		// Loop through all possible elements it could be paired with
		// This includes itself, since a subarray could be one element
		for (int j = i; j < inputArrayLength; j++){
			// Set temp value to 0 and add values between the elements
			tempSum = 0;
			for(int k = i; k <= j; k++){
				tempSum += k;
			}	
			//Keep any subarray sum greater than the current 
			if (tempSum > sum) {
				sum = tempSum;
			}
		}		
	}

	// Output to file
	file << "Enumeration: " << sum << std::endl;
	return sum;	
}

/*********************************************************************
** Function: maxSubarrayEnumerationImproved
** Description:		This function finds the maximum sum of any 
						consecutive subarray with improved enumeration
** Parameters: 		int array, array's length
** Pre-Conditions:	Array initialized with at least 1 positive int
** Post-Conditions:	Subarray sum returned
*********************************************************************/
int maxSubarrayEnumerationImproved(int inputArray[], int inputArrayLength, std::ofstream &file){
	// Create sum and tempSum variable to track totals
	int  tempSum, sum = 0;
	
	// Loop through each element in the array
	for(int i = 0; i < inputArrayLength; i++) {
		tempSum = 0;
		// Check all possible subarrays starting at current element
		for (int j = i; j < inputArrayLength; j++){
			tempSum += j;
				//Keep any subarray sum greater than the current 
				if (tempSum > sum) {
					sum = tempSum;
				}
		}		
	}

	// Output to file
	file << "Enumeration Improved: " << sum << std::endl;

	return sum;	
}