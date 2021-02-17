#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "Student.h"
#include "ManageData.h"
#include "Menu.h"
#include "ViewData.h"
#include "SortData.h"
#include "SearchData.h"

	/*This class is the root class for all subsequent classes. It handles these classes and directs the program towards which necessary class needs to be called. It has it's own continuously running loop to ensure that the program never stops until the user asks it to.
	The calling of subsequent classes is determined by a switch statement that gets its value from the menu class.*/

#pragma once
class AppManager {
	public:
		AppManager();

	private:
		void appLoop();

		std::vector<Student> students;
		ManageData manageData;
		int longestNameLength;
		int averagePercentage;
		bool appState;
		enum class Locations { MAIN, VIEW, SORT, SEARCH, EDIT};
		Locations location;
		Menu menu;
		ViewData viewData;
		SortData sortData;
		SearchData searchData;
};
#endif