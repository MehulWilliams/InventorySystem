/*
 * InventoryList.cpp
 *
 *  Created on: May 2, 2020
 *      Author: mehulwilliams
 */

#include "Item.h"
#include "InventoryList.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>

InventoryList::InventoryList() {
	maxsize = 50;
	length = 0;
	data = new Item[maxsize];
}

InventoryList::InventoryList(int max) {
	maxsize = max;
	length = -1; //iterator in load function sets it to one on first loop.
	data = new Item[maxsize];
}

InventoryList::~InventoryList() {
	delete[] data;
}

void InventoryList::increaseSize(int newMaxSize) {
	maxsize = newMaxSize;
	Item *temp = new Item[maxsize];

	for (int i = 0; i < length; i++) {
		temp[i] = data[i];
	}

	delete[] data;

	Item *data = new Item[maxsize];

	for (int i = 0; i < length; i++) {
		data[i] = temp[i];
	}

	delete[] temp;

}

ostream& operator <<(ostream &ost, const InventoryList &c) {
	for (int i = 0; i < c.length; i++) {
		ost << c.data[i] << endl;
	}
	return ost;
}

void InventoryList::load(string file) {
	length = 0;
	fstream fin;
	fin.open(file.c_str());
	if (fin.fail()) {
		cout << "File could not be opened\n";
	} else {
		cout << "File was opened\n";
	}
	int count = 0;

	string line;
	stringstream in;
	while (!fin.eof()) {

		fin >> data[count];
		length++;
		count++;
	}
	cout << "Data Loaded from " << file << "\n";
	fin.close();
	cout << "File was closed\n\n";
}
void InventoryList::sortByPrice() {
	Item temp;
	int smallest_index = 0;

	for (int i = 0; i < length - 1; i++) {
		smallest_index = i;
		for (int j = i + 1; j < length; j++) {
			if (data[j].getPrice() < data[smallest_index].getPrice()) {
				smallest_index = j;
			}
		}

		equals(temp, data[i]);
		equals(data[i], data[smallest_index]);
		equals(data[smallest_index], temp);

	}
}
void InventoryList::sortByAmount() {
	Item temp;
	int smallest_index = 0;

	for (int i = 0; i < length - 1; i++) {
		smallest_index = i;
		for (int j = i + 1; j < length; j++) {
			if (data[j].getAmount() < data[smallest_index].getAmount()) {
				smallest_index = j;
			}
		}

		equals(temp, data[i]);
		equals(data[i], data[smallest_index]);
		equals(data[smallest_index], temp);

	}
}
void InventoryList::sortByCategory() {
	Item temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length; j++) {
			if ((mycomp(data[j - 1].getCategory(), data[j].getCategory()))
					> 0) {
				equals(temp, data[j - 1]);
				equals(data[j - 1], data[j]);
				equals(data[j], temp);
			}
		}
	}
}
void InventoryList::sortByName() {
	Item temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length; j++) {
			if ((mycomp(data[j - 1].getName(), data[j].getName())) > 0) {
				equals(temp, data[j - 1]);
				equals(data[j - 1], data[j]);
				equals(data[j], temp);
			}
		}
	}
}
void InventoryList::sortByBrand() {
	Item temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length; j++) {
			if ((mycomp(data[j - 1].getBrand(), data[j].getBrand())) > 0) {
				equals(temp, data[j - 1]);
				equals(data[j - 1], data[j]);
				equals(data[j], temp);
			}
		}
	}
}

float InventoryList::calculateAve() {
	float total = 0;
	for (int i = 0; i < length; i++) {
		total = total + (data[i].getPrice());
	}
	return total / length;
}

void InventoryList::equals(Item &i, Item &p) {
	//i = p
	i.setName(p.getName());
	i.setBrand(p.getBrand());
	i.setPrice(p.getPrice());
	i.setAmount(p.getAmount());
	i.setCategory(p.getCategory());
}

bool InventoryList::mycomp(string a, string b) {
	return a > b;
}

void InventoryList::findHighLow() {
	sortByPrice();
	equals(high, data[length-1]);
	equals(low, data[0]);
}

Item InventoryList::getHigh() {
	return high;
}
Item InventoryList::getLow() {
	return low;
}
