#ifndef SEARCHDATA_H
#define SEARCHDATA_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "Student.h"
#include "Menu.h"

	// This class handles the searching of data. By either a students number or name. These functions are also shared by the ManageData class that uses the search for selecting students to delete or edit.

#pragma once
class SearchData {
	public:
		void searchData(std::vector<Student> &students, int longestNameLength);
		Student searchNumber(std::vector<Student>& students, int longestNameLength, bool outsideSource);
		Student searchName(std::vector<Student>& students, int longestNameLength, bool outsideSource);

	private:
		void displayResults(Student student);

		std::vector<Student> studentsC;
		std::vector<Student>::iterator studentResult;
		Student defaultStudent;
		int longestNameLength;
		Menu menu;
		int numberInput;
		std::string nameInput;
		bool searchError;
		bool resultsFound;
};
#endif