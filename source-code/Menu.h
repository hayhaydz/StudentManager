#ifndef MENU_H
#define MENU_H

#include <iostream>

	// This class handles the management and displaying of any menus displayed within the program. It will return an integer based on the menu item that was selected. It contains it's own function for handling user input.

#pragma once
class Menu {
	public:
		Menu();
		int mainMenu();
		int sortMenu();
		int searchMenu();
		int editMenu();
		int updateMenu();
		int editChoiceMenu();

	private:
		void getInput(int minValue, int maxValue);

		int input;
};
#endif