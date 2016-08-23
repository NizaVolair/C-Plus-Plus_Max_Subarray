/*********************************************************************
** Program Filename: MaxSubarrayEnumeration.hpp
** Author: Group 8 - Niza Volair, Sarah Hashem, Matt Palmer
** Date: 07/06/16
** Description: These functions solve the max subarray problem through
**              simple enumeration and improved enumeration 
** Input: An array
** Output: The max sum of all possible subarrays
*********************************************************************/
#include <fstream>
#ifndef MAX_SUBARRAY_ENUMERATION_H
#define MAX_SUBARRAY_ENUMERATION_H

// Function prototypes
int maxSubarrayEnumeration(int inputArray[], int inputArrayLength, std::ofstream &file);
int maxSubarrayEnumerationImproved(int inputArray[], int inputArrayLength, std::ofstream &file);

#endif