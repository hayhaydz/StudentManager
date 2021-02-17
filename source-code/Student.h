#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <array>

	// This class handles the data required for a student. It has minimal code, the only code is to clear this objects values.

#pragma once
class Student {
	public:
		void clear();

		int number;
		std::string name;
		std::array<int, 3> courseMarks;
		int courseMarksTotal = 0;
		int examMark;
		int totalMarks;
		int overallPercentage;
		char grade;
		bool error;

		bool operator<(const Student& val) const {
			return totalMarks < val.totalMarks;
		}

		bool operator>(const Student& val) const {
			return totalMarks > val.totalMarks;
		}

	private:
};

#endif