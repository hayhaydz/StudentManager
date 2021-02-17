#ifndef MANAGEDATA_H
#define MANAGEDATA_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <array>
#include <regex>

#include "Student.h"
#include "Menu.h"
#include "SearchData.h"

	// This class handles anything that affects the data of the program such as loading, editing, deleting etc. 

#pragma once
class ManageData {
	public:
		ManageData();
		void managingData(std::vector<Student>& students);
		void loadData(std::vector<Student>& students, int &longestNameLength, int &averagePercentage);
		void addData(std::vector<Student>& students);
		void deleteData(std::vector<Student>& students);
		void editData(std::vector<Student>& students);
		void updateData(std::vector<Student>& students);
		void minMaxValidation(int &value, int min, int max, std::string msg);
		bool stringValidation(std::string s);

	private:
		Student defaultStudent;
		std::vector<Student> studentsC;
		std::vector<Student>::iterator studentResult;
		int studentPosition;
		Menu menu;
		SearchData searchData;

		std::ifstream readFile;
		std::ofstream writeFile;
		std::string substr;
		int i;
		int counter;
		int totalPercentage;

		std::string nameInput;
		std::array<int, 3> courseMarks;
		int numInput;
		char charInput;
		bool searchError;
		bool resultsFound;
		bool noDelete;
		bool addError;
		int longestNameLength;

};
#endif