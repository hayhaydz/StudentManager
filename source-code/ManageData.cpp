#include "ManageData.h"

ManageData::ManageData() {
	i = 0;
	counter = 0;
	totalPercentage = 0;
	nameInput = "";
	courseMarks.fill(0);
	numInput = 0;
	resultsFound = false;
	noDelete = false;
	searchError = false;
	addError = false;
}

void ManageData::managingData(std::vector<Student>& students) {
	studentsC = students;

	switch (menu.editMenu()) {
		case 0:
			break;
		case 1:
			addData(students);
			break;
		case 2:
			deleteData(students);
			break;
		case 3:
			editData(students);
			break;
	}
}

void ManageData::loadData(std::vector<Student>& students, int &longestNameLength, int &averagePercentage) {
	i = 0;
	totalPercentage = 0;
	defaultStudent.clear();
	students.clear();
	readFile.open("studentMarks.txt");
	for (std::string line; getline(readFile, line);) {
		if (i != 0) {
			counter = 0;
			std::stringstream ss(line);
			while (ss.good()) {
				counter++;
				getline(ss, substr, ',');
				switch (counter) {
					case 1:
						defaultStudent.number = std::stoi(substr);
						break;
					case 2:
						defaultStudent.name = substr;
						break;
					case 3:
						defaultStudent.courseMarks.at(0) = std::stoi(substr);
						break;
					case 4:
						defaultStudent.courseMarks.at(1) = std::stoi(substr);
						break;
					case 5:
						defaultStudent.courseMarks.at(2) = std::stoi(substr);
						break;
					case 6:
						defaultStudent.examMark = std::stoi(substr);
						break;
				}
			}

			// Calculate independent data
			if (defaultStudent.name.length() > longestNameLength) {
				longestNameLength = defaultStudent.name.length();
			}
			for (int mark : defaultStudent.courseMarks) {
				defaultStudent.courseMarksTotal += mark;
			}
			defaultStudent.totalMarks = defaultStudent.courseMarksTotal + defaultStudent.examMark;
			defaultStudent.overallPercentage = (static_cast<double>(defaultStudent.totalMarks) / 160) * 100;
			switch (defaultStudent.overallPercentage/10) {
				case 10:
				case 9:
				case 8:
				case 7:
					defaultStudent.grade = 'A';
					break;
				case 6:
					defaultStudent.grade = 'B';
					break;
				case 5:
					defaultStudent.grade = 'C';
					break;
				case 4:
					defaultStudent.grade = 'D';
					break;
				default:
					defaultStudent.grade = 'F';
					break;
			}

			totalPercentage += defaultStudent.overallPercentage;

			students.push_back(defaultStudent);
			defaultStudent.clear();
		}
		else {
			i++;
		}
	}
	averagePercentage = totalPercentage / students.size();
	this->longestNameLength = longestNameLength;
	readFile.close();
}

void ManageData::addData(std::vector<Student>& students) {
	system("cls");
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "Please enter your new students full name: ";
	std::getline(std::cin, nameInput);
	std::string localName = nameInput;
	transform(localName.begin(), localName.end(), localName.begin(), ::tolower);
	// checking that a user doesn't already exist with the name entered
	auto it = find_if(students.begin(), students.end(), [&localName](const Student& obj) {
		std::string name = obj.name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		return name == localName; 
	});
	if (it != students.end()) {
		addError = true;
	}
	while (nameInput.length() < 2 || nameInput.length() > 30 || !stringValidation(nameInput) || addError) {
		if (addError) {
			std::cout << "Name already exists please try again." << std::endl;
		}
		else {
			std::cout << "Invalid input. Please try again." << std::endl;
		}
		std::cout << "Please enter your new students full name: ";
		std::getline(std::cin, nameInput);
		localName = nameInput;
		transform(localName.begin(), localName.end(), localName.begin(), ::tolower);
		auto it = find_if(students.begin(), students.end(), [&localName](const Student& obj) {
			std::string name = obj.name;
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			return name == localName;
		});
		if (it != students.end()) {
			addError = true;
		}
		else {
			addError = false;
		}
		//std::cin.clear();
		//std::cin.ignore(256, '\n');
	}
	std::cout << "Please enter your new students first coursemark (0 - 20): ";
	std::cin >> courseMarks[0];
	minMaxValidation(courseMarks[0], 0, 20, "Please enter your new students first coursemark (0 - 20): ");
	std::cout << "Please enter your new students second coursemark (0 - 20): ";
	std::cin >> courseMarks[1];
	minMaxValidation(courseMarks[1], 0, 20, "Please enter your new students first coursemark (0 - 20): ");
	std::cout << "Please enter your new students first coursemark (0 - 20): ";
	std::cin >> courseMarks[2];
	minMaxValidation(courseMarks[2], 0, 20, "Please enter your new students third coursemark (0 - 20): ");
	std::cout << "Please enter your new students exam mark (0 - 100): ";
	std::cin >> numInput;
	minMaxValidation(numInput, 0, 100, "Please enter your new students exam mark (0 - 100): ");
	defaultStudent.name = nameInput;
	defaultStudent.courseMarks = courseMarks;
	defaultStudent.examMark = numInput;
	// creating a random student number
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1000, 9999);
	numInput = dist(rng);
	for (auto student : students) {
		while (student.number == numInput) {
			numInput = dist(rng);
		}
	}
	defaultStudent.number = numInput;
	students.push_back(defaultStudent);
	updateData(students);
	defaultStudent.clear();
	std::cout << "New student has been added sucessfully!" << std::endl;
	system("pause");
}

void ManageData::deleteData(std::vector<Student>& students) {
	system("cls");
	numInput = menu.editChoiceMenu();
	if (numInput == 1) {
		defaultStudent = searchData.searchNumber(students, longestNameLength, true);
	}
	else if (numInput == 2) {
		defaultStudent = searchData.searchName(students, longestNameLength, true);
	}
	else {
		searchError = true;
		noDelete = true;
	}

	for (int i = 0; i < studentsC.size(); i++) {
		if (studentsC[i].number == defaultStudent.number) {
			studentPosition = i;
		}
	}

	if (!searchError) {
		//std::cin.clear();
		//std::cin.ignore(256, '\n');
		std::cout << "Are you sure that you want to delete this students data? (Y/N): ";
		std::cin >> charInput;
		charInput = tolower(charInput);
		while (charInput != 'y' && charInput != 'n') {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid input. Please try again." << std::endl;
			std::cout << "Are you sure that you want to delete this students data? (Y/N): ";
			std::cin >> charInput;
			charInput = tolower(charInput);
		}

		if (charInput == 'y') {
			students.erase(students.begin()+studentPosition);
			updateData(students);
			std::cout << "Student has been deleted sucessfully!" << std::endl;
		}
		else {
			noDelete = true;
		}
	}

	if (!noDelete) {
		system("pause");
	}
	resultsFound = false;
	noDelete = false;
	searchError = false;
}

void ManageData::editData(std::vector<Student>& students) {
	system("cls");
	numInput = menu.editChoiceMenu();
	if (numInput == 1) {
		defaultStudent = searchData.searchNumber(students, longestNameLength, true);
	}
	else if (numInput == 2) {
		defaultStudent = searchData.searchName(students, longestNameLength, true);
	}
	else {
		searchError = true;
		noDelete = true;
	}

	if (defaultStudent.error) {
		searchError = true;
	}

	if (!searchError) {
		//std::cin.clear();
		//std::cin.ignore(256, '\n');
		for (int i = 0; i < studentsC.size(); i++) {
			if (studentsC[i].number == defaultStudent.number) {
				studentPosition = i;
			}
		}
		std::cout << "Are you sure that you want to edit this students data? (Y/N): ";
		std::cin >> charInput;
		charInput = tolower(charInput);
		while (charInput != 'y' && charInput != 'n') {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid input. Please try again." << std::endl;
			std::cout << "Are you sure that you want to delete this students data? (Y/N): ";
			std::cin >> charInput;
			charInput = tolower(charInput);
		}

		if (charInput == 'y') {
			numInput = menu.updateMenu();
			if (numInput == 1) {
				system("cls");
				std::cout << "Student Name: " << defaultStudent.name << std::endl;
				std::cout<<std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Please enter your students new full name: ";
				std::getline(std::cin, nameInput);
				std::string localName = nameInput;
				transform(localName.begin(), localName.end(), localName.begin(), ::tolower);
				std::string outsideName = defaultStudent.name;
				transform(outsideName.begin(), outsideName.end(), outsideName.begin(), ::tolower);
				if (localName != outsideName) {
					auto it = find_if(students.begin(), students.end(), [&localName](const Student& obj) {
						std::string name = obj.name;
						transform(name.begin(), name.end(), name.begin(), ::tolower);
						return name == localName;
						});
					if (it != students.end()) {
						addError = true;
					}
				}
				while (nameInput.length() < 2 || nameInput.length() > 30 || !stringValidation(nameInput) || addError) {
					if (addError) {
						std::cout << "Name already exists please try again." << std::endl;
					}
					else {
						std::cout << "Invalid input. Please try again." << std::endl;
					}
					std::cout << "Please enter your new students full name: ";
					std::getline(std::cin, nameInput);
					localName = nameInput;
					transform(localName.begin(), localName.end(), localName.begin(), ::tolower);
					if (localName != outsideName) {
						auto it = find_if(students.begin(), students.end(), [&localName](const Student& obj) {
							std::string name = obj.name;
							transform(name.begin(), name.end(), name.begin(), ::tolower);
							return name == localName;
						});
						if (it != students.end()) {
							addError = true;
						}
						else {
							addError = false;
						}
					}
					else {
						addError = false;
					}
				}

				students[studentPosition].name = nameInput;
				updateData(students);
				std::cout << "New data has been updated sucessfully!" << std::endl;
			}
			else if (numInput == 2) {
				system("cls");
				std::cout << "Student Coursemarks: " << defaultStudent.courseMarks[0] << " " << defaultStudent.courseMarks[1] << " " << defaultStudent.courseMarks[2] << std::endl;
				std::cout << std::endl;
				std::cout << "Please enter your new students first coursemark (0 - 20): ";
				std::cin >> courseMarks[0];
				minMaxValidation(courseMarks[0], 0, 20, "Please enter your new students first coursemark (0 - 20): ");
				std::cout << "Please enter your new students second coursemark (0 - 20): ";
				std::cin >> courseMarks[1];
				minMaxValidation(courseMarks[1], 0, 20, "Please enter your new students first coursemark (0 - 20): ");
				std::cout << "Please enter your new students first coursemark (0 - 20): ";
				std::cin >> courseMarks[2];
				minMaxValidation(courseMarks[2], 0, 20, "Please enter your new students third coursemark (0 - 20): ");

				students[studentPosition].courseMarks = courseMarks;
				updateData(students);
				std::cout << "New data has been updated sucessfully!" << std::endl;
			}
			else if (numInput == 3) {
				system("cls");
				std::cout << "Student Exame mark: " << defaultStudent.examMark << std::endl;
				std::cout << std::endl;
				std::cout << "Please enter your new students exam mark (0 - 100): ";
				std::cin >> numInput;
				minMaxValidation(numInput, 0, 100, "Please enter your new students exam mark (0 - 100): ");

				students[studentPosition].examMark = numInput;
				updateData(students);
				std::cout << "New data has been updated sucessfully!" << std::endl;
			}
			else {
				searchError = true;
				noDelete = true;
			}
		}
		else {
			noDelete = true;
		}
	}

	if (!noDelete) {
		system("pause");
	}
	resultsFound = false;
	noDelete = false;
	searchError = false;
}

void ManageData::updateData(std::vector<Student>& students) {
	// re-writing student data
	writeFile.open("studentMarks.txt");
		writeFile << students.size() << std::endl;
		for (auto student : students) {
			writeFile << student.number << "," << student.name << "," << student.courseMarks[0] << "," << student.courseMarks[1] << "," << student.courseMarks[2] << "," << student.examMark << std::endl;
		}
	writeFile.close();
}

void ManageData::minMaxValidation(int &value, int min, int max, std::string msg) {
	while (std::cin.fail() || value < min || value > max) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid input. Please try again." << std::endl;
		std::cout << msg;
		std::cin >> value;
	}
}

//https://stackoverflow.com/questions/52303608/validate-string-input-in-c-for-letters-and-spaces-only
bool ManageData::stringValidation(std::string s) {
	// function to check that a string does not contain any characters that are either numbers or special characters
	for (auto c : s) {
		if (!isalpha(c) && !isspace(c))
			return false;
	}

	return true;
}