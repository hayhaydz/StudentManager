#ifndef VIEWDATA_H
#define VIEWDATA_H

#include <iostream>
#include <vector>

#include "Student.h" 

	// This class handles the displaying of student data. It has no functionality other than to display what has been passed to it.

#pragma once
class ViewData {
	public:
		void outputData(std::vector<Student> &students, int longestNameLength, int averagePercentage);

	private:

};
#endif