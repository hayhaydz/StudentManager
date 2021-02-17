#include "Menu.h"

Menu::Menu() {
	input = NULL;
}

int Menu::mainMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. View all student records" << std::endl;
	std::cout << "2. Sort records" << std::endl;
	std::cout << "3. Search student records" << std::endl;
	std::cout << "4. Edit student record data" << std::endl;
	std::cout << "0. Exit program" << std::endl;
	getInput(0,4);

	return input;
}

int Menu::sortMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Sort records" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. Total marks ascending" << std::endl;
	std::cout << "2. Total marks descending" << std::endl;
	std::cout << "3. Student name A - Z" << std::endl;
	std::cout << "0. Return home" << std::endl;
	getInput(0,3);

	return input;
}

int Menu::searchMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Search student records" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. Student number" << std::endl;
	std::cout << "2. Student name" << std::endl;
	std::cout << "0. Return home" << std::endl;
	getInput(0,2);

	return input;
}

int Menu::editMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Edit student record data" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. Add a student record" << std::endl;
	std::cout << "2. Delete a student record" << std::endl;
	std::cout << "3. Update a student record" << std::endl;
	std::cout << "0. Return home" << std::endl;
	getInput(0,3);

	return input;
}

int Menu::updateMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Edit student record data >> Update" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. Name" << std::endl;
	std::cout << "2. Coursework marks" << std::endl;
	std::cout << "3. Examination mark" << std::endl;
	std::cout << "0. Return home" << std::endl;
	getInput(0,3);

	return input;
}

int Menu::editChoiceMenu() {
	system("cls");
	std::cout << "============================================" << std::endl;
	std::cout << "Menu >> Edit student record data >> Remove/Update" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "1. Student number" << std::endl;
	std::cout << "2. Student name" << std::endl;
	std::cout << "0. Return home" << std::endl;
	getInput(0,2);

	return input;
}

void Menu::getInput(int minValue, int maxValue) {
	std::cout << "Please enter a number: ";
	std::cin >> input;
	while (std::cin.fail() || input < minValue || input > maxValue) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid input. Please try again." << std::endl;
		std::cout << "Please enter a number: ";
		std::cin >> input;
	}
}