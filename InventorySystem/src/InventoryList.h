/*
 * InventoryList.h
 *
 *  Created on: May 2, 2020
 *      Author: mehulwilliams
 */

#ifndef INVENTORYLIST_H_
#define INVENTORYLIST_H_
#include "Item.h"

class InventoryList {
public:
	InventoryList();
	InventoryList(int max);
	void load(string file);
	virtual ~InventoryList();
	void increaseSize(int newMaxSize);
	friend ostream& operator <<(ostream &ost, const InventoryList &c);

	Item getHigh();
	Item getLow();

	void sortByPrice();
	void sortByAmount();
	void sortByCategory();
	void sortByName();
	void sortByBrand();
	float calculateAve();
	void equals(Item &i, Item &p);
	bool mycomp(string a, string b);
	void findHighLow();

	Item high;
	Item low;

private:
	Item *data;
	int maxsize;
	int length;
};

#endif /* INVENTORYLIST_H_ */
