//============================================================================
// Name        : InventorySystem.cpp
// Author      : Mehul Williams
//============================================================================

#include <iostream>
#include "Item.h"
#include "InventoryList.h"
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

void mainMenu(InventoryList &Iv);
void sortingMenu(InventoryList &I);
void calcMenu();
int daynum;
InventoryList Day1;
InventoryList Day2;

int main() {
	string file1 = "Day1.txt";
	string file2 = "Day2.txt";
	Day1.load(file1);
	Day2.load(file2);

	cout
			<< "This program can be used to view and manipulate lists of inventory.\n";

	int dayChoice;
	cout << "Please enter a number for the day to view: ";
	cout << "\n1. Day 1";
	cout << "\n2. Day 2\n";
	cin >> dayChoice;
	if (dayChoice == 1) {
		daynum = 1;
		mainMenu(Day1);
	} else if (dayChoice == 2) {
		daynum = 2;
		mainMenu(Day2);
	}

}

void mainMenu(InventoryList &Iv) {
	int choice = 10;
	do {
		cout << "\nChoose an option:";
		cout << "\n1. Print Inventory";
		cout << "\n2. Enter Sorting Menu >>>";
		cout << "\n3. Enter Calculation/Comparison Menu >>>";
		cout << "\nEnter 0 to exit.";
		cout << "\nYour choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\nPrinting Inventory: \n";
			cout << Iv;
		}

		if (choice == 2) {
			cout << "\nEntering Sorting Menu: \n";
			sortingMenu(Iv);
		}

		if (choice == 3) {
			cout << "\nEntering Calculation/Comparison Menu: \n";
			calcMenu();
		}

	} while (choice != 0);

	cout << "Program ended." << endl;
}

void sortingMenu(InventoryList &I) {
	int choice = 10;
	do {
		cout << "\n1. Sort Inventory by Name";
		cout << "\n2. Sort Inventory by Brand";
		cout << "\n3. Sort Inventory by Price";
		cout << "\n4. Sort Inventory by Amount";
		cout << "\n5. Sort Inventory by Category";
		cout << "\nEnter 0 to return to Main Menu.";
		cout << "\nYour choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\n~~Sorting Inventory~~ \n";
			I.sortByName();
			cout << "\nSorted Inventory by Name: \n";
			cout << I;
		}

		if (choice == 2) {
			cout << "\n~~Sorting Inventory~~ \n";
			I.sortByBrand();
			cout << "\nSorted Inventory by Brand: \n";
			cout << I;
		}

		if (choice == 3) {
			cout << "\n~~Sorting Inventory~~ \n";
			I.sortByPrice();
			cout << "\nSorted Inventory by Price: \n";
			cout << I;
		}

		if (choice == 4) {
			cout << "\n~~Sorting Inventory~~ \n";
			I.sortByAmount();
			cout << "\nSorted Inventory by Amount: \n";
			cout << I;
		}

		if (choice == 5) {
			cout << "\n~~Sorting Inventory~~ \n";
			I.sortByCategory();
			cout << "\nSorted Inventory by Category: \n";
			cout << I;
		}

	} while (choice != 0);

}
void calcMenu() {
	float ave1 = Day1.calculateAve();
	float ave2 = Day2.calculateAve();

	int choice = 10;
	do {
		cout << "\n1. Calculate Average Price for Day 1";
		cout << "\n2. Calculate Average Price for Day 2";
		cout << "\n3. Compare Averages";
		cout << "\n4. Compare Highs and Lows";
		cout << "\nEnter 0 to return to Main Menu.";
		cout << "\nYour choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\n~~Calculating Average Price for Day 1~~\n";
			cout << "\nAverage of Day 1: ";
			printf("%.2f\n", ave1);
		}

		if (choice == 2) {
			cout << "\n~~Calculating Average Price for Day 2~~\n";
			cout << "\nAverage of Day 2: ";
			printf("%.2f\n", ave2);
		}

		if (choice == 3) {
			cout << "\n~~Comparing Average Prices~~ \n";
			printf("\nThe average price of Day 1 was %.2f", ave1);
			printf("\nThe average price of Day 2 was %.2f\n", ave2);
			if (ave1 > ave2)
				cout << "\nThe price went down for Day 2. \n";
			else
				cout << "The prices went up for Day 2. \n";
		}

		if (choice == 4) {
			cout << "\n~~Comparing Highs and Lows~~ \n";
			Day1.findHighLow();
			Day2.findHighLow();
			cout << "\nDay 1 lowest item was: " << Day1.low.getName() << " at $"
					<< Day1.low.getPrice();
			cout << "\nDay 2 lowest item was: " << Day2.low.getName() << " at $"
					<< Day2.low.getPrice();
			cout << "\nDay 1 highest item was: " << Day1.high.getName()
					<< " at $" << Day1.high.getPrice();
			cout << "\nDay 2 highest item was: " << Day2.high.getName()
					<< " at $" << Day2.high.getPrice() << endl;

			if (Day1.low.getPrice() > Day2.low.getPrice())
				cout
						<< "\nThe price of the lowest item went down for Day 2. ";
			else if (Day1.low.getPrice() == Day2.low.getPrice()) {
				cout
						<< "\nThe price of the lowest item stayed the same on Day 2";
			} else {
				cout << "\nThe price of the lowest item went up for Day 2.";
			}

			if (Day1.high.getPrice() > Day2.high.getPrice())
				cout
						<< "\nThe price of the highest item went down for Day 2. ";
			else if (Day1.high.getPrice() == Day2.high.getPrice()) {
				cout
						<< "\nThe price of the highest item stayed the same on Day 2";
			} else {
				cout << "\nThe price of the highest item went up for Day 2. ";
			}
			cout << endl;
		}


	} while (choice != 0);

}
