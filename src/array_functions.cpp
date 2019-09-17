/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
//#include <iostream>
#include <fstream>
#include <sstream>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"


using namespace constants;
using namespace std;

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry {
	string word = "";
	int number_occurences = 0;
};

//TODO add a global array of entry structs (global to this file)
static entry dictionary[MAX_WORDS];
//TODO add variable to keep track of next available slot in array
unsigned int dictionary_sz = 0;

//TODO define all functions from header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

//zero out array that tracks words and their occurrences
void clearArray() {
	return;
}

//how many unique words are in array
int getArraySize() {
	return dictionary_sz;
}

//get data at a particular location
string getArrayWordAt(int i) {
	return dictionary[i].word;
}

int getArrayWord_NumbOccur_At(int i) {
	return dictionary[i].number_occurences;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(fstream &myfstream) {
	if (!myfstream.is_open())
		return FAIL;
	string line = "";
	while (getline(myfstream, line)) {
		// reading in
		processLine(line);
	}
	//myfstream.close();
	closeFile(myfstream);
	return SUCCESS;
}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(string &myString) {
	stringstream ss(myString);
	string tempToken;
	while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}
	return;
}

/*Keep track of how many times each token seen*/
void processToken(string &token) {

	return;
}

/*if you are debugging the file must be in the project parent directory
 in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream &myfile, const std::string &myFileName,
		std::ios_base::openmode mode) {
	const string str = myFileName.c_str();
	//myfile.open(myFileName, mode);
	myfile.open(str, mode);
	return myfile.is_open();
}

/*iff myfile is open then close it*/
void closeFile(std::fstream &myfile) {
	return myfile.close();
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
