#ifndef SORTDATA_H
#define SORTDATA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "Student.h"
#include "Menu.h"
#include "ViewData.h"

	// This class handles the sorting of data. There are three methods of sorting. Sorting by ascending grades, descending grades and A-Z by student name.

#pragma once
class SortData {
	public:
		void sortData(std::vector<Student>& students, int longestNameLength, int averagePercentage);

	private:
		void sortAcsending();
		void sortDescending();
		void sortAZ();

		Menu menu;
		std::vector<Student> studentsC;
		ViewData viewData;
		int longestNameLength;
		int averagePercentage;
};
#endif