/*//============================================================================
 * 		File:		array_functions.cpp
 *  	Created: 	Sep 16, 2019
 *  	LModified:	17 Sept 2k19
 *      Author: 	wchang 00960978
 *      Prof:		K. Perkins @ CNU.edu
 *		Assignment:	cs327 P2
 *		Desc:
 *			File IO functions to read files,
 *			parse words followed by their count,
 *			and write to a file from a couple of sorting methods.
 *
 *		Notes:
 *			Parser and sorter are case insensitive.
 *      	Glad I took cs420
 *      	InsertionSort algorithm is adapted from
 *      	Intro to Design and Analysis of Algorithms 2ed by A. Levitin
 *///============================================================================
#include <string.h>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"

using namespace constants;
using namespace std;

struct entry {
	string word = "";
	int number_occurences = 0;
};

static entry dictionary[MAX_WORDS];
unsigned int dictionary_size = 0;

//zero out array that tracks words and their occurrences
void clearArray() {
	for (unsigned int i = 0; i < dictionary_size; i++) {
		dictionary[i].number_occurences = 0;
		dictionary[i].word = "";
	}
	dictionary_size = 0;
	return;
}

//how many unique words are in array
int getArraySize() {
	return dictionary_size;
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
		return false;
	string line = "";

	while (getline(myfstream, line)) {
		processLine(line);
	}
	closeFile(myfstream);
	return true;
}

/*take 1 line and extract all the tokens from it
 feed each token to processToken for recording*/
void processLine(string &myString) {
	stringstream ss(myString);
	string tempToken = "";

	while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken);
	}
	return;
}

/*Keep track of how many times each token seen*/
void processToken(string &token) {
	bool exists_in_dict = false;

	strip_unwanted_chars(token);
	for (unsigned int i = 0; i < dictionary_size; i++) {
		if (strcasecmp(token.c_str(), dictionary[i].word.c_str()) == 0) {
			++dictionary[i].number_occurences;
			exists_in_dict = true;
		}
	}
	if (!exists_in_dict && token != "") {
		if (dictionary_size == MAX_WORDS)
			return; // ideally send an error code, no_more_dictionary_space
		dictionary[dictionary_size].word = token;
		++dictionary[dictionary_size].number_occurences;
		++dictionary_size;
	}
	return;
}

/*if you are debugging the file must be in the project parent directory
 in this case Project2 with the .project and .cProject files*/
bool openFile(fstream &myfile, const string &myFileName, ios_base::openmode mode) {
	myfile.open(myFileName.c_str(), mode);
	return myfile.is_open();
}

/*iff myfile is open then close it*/
void closeFile(fstream &myfile) {
	return myfile.close();
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const string &outputfilename) {
	fstream fout;

	if (!openFile(fout, outputfilename, ios_base::out))
		return FAIL_FILE_DID_NOT_OPEN;
	if (dictionary_size == 0)
		return FAIL_NO_ARRAY_DATA;

	for (unsigned int i = 0; i < dictionary_size; i++) {
		fout << dictionary[i].word << " " << dictionary[i].number_occurences << "\n";
	}
	closeFile(fout);
	return SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(sortOrder so) {
	entry v;
	int j = 0;

	switch (so) {
	case NONE:
		break;
	case ASCENDING:
		// InsertionSort
		for (unsigned int i = 1; i < dictionary_size; i++) {
			v = dictionary[i];
			j = i - 1;
			while (j >= 0 && strcasecmp(dictionary[j].word.c_str(), v.word.c_str()) > 0) {
				dictionary[j + 1] = dictionary[j];
				--j;
			}
			dictionary[j + 1] = v;
		}
		break;
	case DESCENDING:
		// InsertionSort
		for (unsigned int i = 1; i < dictionary_size; i++) {
			v = dictionary[i];
			j = i - 1;
			while (j >= 0 && strcasecmp(dictionary[j].word.c_str(), v.word.c_str()) > 0) {
				dictionary[j + 1] = dictionary[j];
				--j;
			}
			dictionary[j + 1] = v;
		}
		break;
	case NUMBER_OCCURRENCES:
		// InsertionSort
		for (unsigned int i = 1; i < dictionary_size; i++) {
			v = dictionary[i];
			j = i - 1;
			while (j >= 0 && dictionary[j].number_occurences < v.number_occurences) {
				dictionary[j + 1] = dictionary[j];
				--j;
			}
			dictionary[j + 1] = v;
		}
		break;
	default:
		break;
	}
	return;
}
