#include "SearchData.h"

void SearchData::searchData(std::vector<Student> &students, int longestNameLength) {
	studentsC = students;
	this->longestNameLength = longestNameLength;
	searchError = false;
	resultsFound = false;
	nameInput = "";
	numberInput = 0;

	switch (menu.searchMenu()) {
		case 0:
			break;
		case 1:
			searchNumber(students, longestNameLength, false);
			break;
		case 2:
			searchName(students, longestNameLength, false);
			break;
	}
}

Student SearchData::searchNumber(std::vector<Student>& students, int longestNameLength, bool outsideSource) {
	system("cls");
	studentsC = students;
	this->longestNameLength = longestNameLength;
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Search student records >> Student number" << std::endl;
	std::cout << "============================================\n" << std::endl;
	std::cout << "Please enter the students number: ";
	std::cin >> numberInput;
	while (std::cin.fail() || numberInput < 1000 || numberInput > 9999) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid input. Please try again." << std::endl;
		std::cout << "Please enter the students number: ";
		std::cin >> numberInput;
	}

	//https://stackoverflow.com/questions/15517991/search-a-vector-of-objects-by-object-attribute
	int numberInput = this->numberInput;
	// finding the first result based on the number entered
	studentResult = std::find_if(
		studentsC.begin(), 
		studentsC.end(),
		[&numberInput](const Student& obj) {
			return obj.number == numberInput; 
		}
	);

	if (studentResult != studentsC.end()) {
		int studentPosition = std::distance(studentsC.begin(), studentResult);
		displayResults(studentsC[studentPosition]);
		defaultStudent = studentsC[studentPosition];
		if (outsideSource) {
			return defaultStudent;
		}
	}
	else {
		std::cout << "No results were found" << std::endl;
		defaultStudent.error = true;
		searchError = true;
	}

	if (!outsideSource) {
		system("pause");
		if (searchError) {
			searchData(studentsC, longestNameLength);
		}
		else {
			numberInput = NULL;
		}
	}

	return defaultStudent;
}

Student SearchData::searchName(std::vector<Student>& students, int longestNameLength, bool outsideSource) {
	system("cls");
	studentsC = students;
	this->longestNameLength = longestNameLength;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Search student records >> Student name" << std::endl;
	std::cout << "============================================\n" << std::endl;
	std::cout << "Please enter the students name: ";
	std::getline(std::cin, nameInput);
	while (nameInput.length() < 2 || nameInput.length() > 30) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid input. Please try again." << std::endl;
		std::cout << "Please enter the students name: ";
		std::getline(std::cin, nameInput);
	}
	transform(nameInput.begin(), nameInput.end(), nameInput.begin(), ::tolower);

	// finding the best matched result based on the string entered
	for (auto student : studentsC) {
		std::string name = student.name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		std::regex r("\\b" + nameInput + "\\b");
		std::smatch m;
		if (std::regex_search(name, m, r)) {
			defaultStudent = student;
			displayResults(defaultStudent);
			resultsFound = true;
			if (outsideSource) {
				return defaultStudent;
			}
		}
	}

	if (!resultsFound) {
		std::cout << "No results were found" << std::endl;
		defaultStudent.error = true;
		searchError = true;
	}

	if (!outsideSource) {
		system("pause");
		if (searchError) {
			searchData(studentsC, longestNameLength);
		}
		else {
			nameInput = "";
		}
	}
	return defaultStudent;
}

void SearchData::displayResults(Student student) {
	system("cls");
	std::cout << "==================================================" << std::endl;
	std::cout << "Menu >> Search student records >> Results Found:" << std::endl;
	std::cout << "==================================================\n" << std::endl;
	std::cout << "Number\tName\t";
	for (int i = 0; i < longestNameLength; i++) {
		std::cout << " ";
	}
	std::cout << "Total coursework mark\tExam mark\tOverall percentage (%)\tGrade" << std::endl;
	std::cout << student.number << "\t" << student.name;
	for (int i = 0; i < longestNameLength - student.name.length(); i++) {
		std::cout << " ";
	}
	std::cout << "\t" << student.courseMarksTotal << "                     \t" << student.examMark << "         \t" << student.overallPercentage << "                  \t" << student.grade << std::endl;
	std::cout << std::endl;
}