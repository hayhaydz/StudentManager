#include "ViewData.h"

void ViewData::outputData(std::vector<Student>& students, int longestNameLength, int averagePercentage) {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> View data" << std::endl;
	std::cout << "============================================\n" << std::endl;
	std::cout << "Number\tName\t";
	for (int i = 0; i < longestNameLength; i++) {
		std::cout << " ";
	}
	std::cout << "Total coursework mark\tExam mark\tOverall percentage (%)\tGrade"<<std::endl;
	for (auto student : students) {
		std::cout << student.number << "\t" << student.name;
		for (int i = 0; i < longestNameLength - student.name.length(); i++) {
			std::cout << " ";
		}
		std::cout << "\t" << student.courseMarksTotal << "                     \t" << student.examMark << "         \t" << student.overallPercentage << "                  \t" << student.grade << std::endl;
	}
	std::cout << "\n\nThere is " << students.size();
	if (students.size() < 2) {
		std::cout << " student";
	}
	else {
		std::cout << " students";
	}
	std::cout << " in the class. With an average percentage of " << averagePercentage << "%\n" << std::endl;
	system("pause");
}