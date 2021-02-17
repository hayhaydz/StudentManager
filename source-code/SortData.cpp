#include "SortData.h"

void SortData::sortData(std::vector<Student>& students, int longestNameLength, int averagePercentage) {
	studentsC = students;
	this->longestNameLength = longestNameLength;
	this->averagePercentage = averagePercentage;
	switch (menu.sortMenu()) {
		case 0:
			break;
		case 1:
			sortAcsending();
			break;
		case 2:
			sortDescending();
			break;
		case 3:
			sortAZ();
			break;
	}
}

void SortData::sortAcsending() {
	std::sort(studentsC.begin(), studentsC.end());
	viewData.outputData(studentsC, longestNameLength, averagePercentage);
}

void SortData::sortDescending() {
	std::sort(studentsC.begin(), studentsC.end(), std::greater<Student>());
	viewData.outputData(studentsC, longestNameLength, averagePercentage);
}

void SortData::sortAZ() {
	//https://stackoverflow.com/questions/16894700/c-custom-compare-function-for-stdsort
	std::sort(
		studentsC.begin(),
		studentsC.end(),
		[](const auto& lhs, const auto& rhs) {
			return lhs.name < rhs.name;
		}
	);
	viewData.outputData(studentsC, longestNameLength, averagePercentage);
}