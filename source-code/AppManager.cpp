#include "AppManager.h"

AppManager::AppManager() {
	// declaring variables inital values
	appState = true;
	location = Locations::MAIN;
	longestNameLength = 0;
	averagePercentage = 0;
	manageData.loadData(students, longestNameLength, averagePercentage);
	appLoop();
}

void AppManager::appLoop() {
	while (appState) {
		// clearing the screen before displaying the main menu
		system("cls");
		switch (menu.mainMenu()) {
			case 0:
				appState = false;
				break;
			case 1:
				location = Locations::VIEW;
				viewData.outputData(students, longestNameLength, averagePercentage);
				break;
			case 2:
				location = Locations::SORT;
				sortData.sortData(students, longestNameLength, averagePercentage);
				break;
			case 3:
				location = Locations::SEARCH;
				searchData.searchData(students, longestNameLength);
				break;
			case 4:
				location = Locations::EDIT;
				manageData.managingData(students);
				// sleeping for a second to ensure that data is correctly altered before re-loading the data
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				manageData.loadData(students, longestNameLength, averagePercentage);
				break;
		}
	}
}