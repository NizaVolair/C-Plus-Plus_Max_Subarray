/*********************************************************************
** Program Filename: testIOMain.cpp
** Author: 			Group 8 - Niza Volair, Sara Hashem, Matt Palmer
** Date: 			07/06/16
** Description: Test main for maxSubarray functions using file I/O
** Input: 		None
** Output: 		Test Results from functions
*********************************************************************/
#include "MaxSubarrayEnumeration.hpp"
#include "MaxSubarrayRec.hpp"
#include "MaxSubarrayLinear.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(){
	// Create clock variable and double to track time
    std::clock_t start;
    double duration;

	// Initialize random number generator with time seed
	time_t seed;
	srand((unsigned) time(&seed));

	// Set up arrays
	std::vector<int> v;
	int testArray[100];
	
	// Set up file objects and parsers
	std::ifstream infile;
	std::ofstream outfile;
	std::string delim, line;

	// Open file for reading
	infile.open("MSS_TestProblems-1.txt");
	outfile.open("MSS_Results.txt");

	// Parse each line from file
	while(getline(getline(infile, delim, '['), line, ']')){
		std::stringstream linestream(line);
		std::string value;

		// Extract integer values from string
		while(getline(linestream, value, ',')){
			// Convert strings to integers (must compile with -std=c++11)
			v.push_back(stoi(value));

		}
			
		// Push vector elements to array
		std::cout << "Test Array" << std::endl;
		for(int i = 0; i < v.size(); i++){
		    testArray[i] = v[i];
		}
			
		// Push vector elements to array
		for(int i = 0; i < v.size(); i++){
		    std::cout << testArray[i] << ", ";
		}
		std::cout << std::endl << std::endl;

		// Initialize array length with vector size
		int testArrayLength = v.size();


		// Enumeration Test
		start = std::clock();
		int sum = 0;

		sum = maxSubarrayEnumeration(testArray, testArrayLength, outfile);
		
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

		std::cout << "Enumeration Test- Sum: " << sum << " Time: " << duration << std::endl << std::endl;

		
		// Enumeration Improved Test
		start = std::clock();
		sum = 0;

		sum = maxSubarrayEnumeration(testArray, testArrayLength, outfile);
		
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

		std::cout << "Enumeration Improve Test- Sum: " << sum << " Time: " << duration << std::endl << std::endl;


		// Recursive Test
		start = std::clock();
		sum = 0;

		sum = maxSubarrayRec(testArray, 0, 0, testArrayLength, outfile);
		
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

		std::cout << "Recursive Test- Sum: " << sum << " Time: " << duration << std::endl << std::endl;


		// Linear Test
		start = std::clock();
		sum = 0;

		sum = maxSubarrayLinear(testArray, testArrayLength, outfile);
		
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

		std::cout << "Linear Test- Sum: " << sum << " Time: " << duration << std::endl << std::endl;


		// Clear vector for next line (array) in file
		v.clear();
	}

	// Close files
	outfile.close();
	infile.close();


	return 0;
}
