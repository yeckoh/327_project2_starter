/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include "constants.h"
using namespace constants;
using namespace std;

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry {
	string word;
	int number_occurences;
};
//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!




//zero out array that tracks words and their occurrences
void clearArray() {

	return;
}

//how many unique words are in array
int getArraySize() {

	return FAIL;
}

//get data at a particular location
string getArrayWordAt(int i) {

	return "";
}

int getArrayWord_NumbOccur_At(int i) {

	return FAIL;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream) {

	return FAIL;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString) {

	return;
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {

	return;
}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in) {

	return FAIL;
}

/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile) {

	return;
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename) {

	return FAIL;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {

	return;
}
