/*
 * Item.h
 *
 *  Created on: May 2, 2020
 *      Author: mehulwilliams
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>

using namespace std;

class Item {
public:
	Item();
	Item(string n, string b, float p, int a, string c);
	//Item(const Item &other);

	//setters
	void setName(string n);
	void setBrand(string b);
	void setPrice(float p);
	void setAmount(int a);
	void setCategory(string c);

	//getters
	string getName();
	string getBrand();
	float getPrice();
	int getAmount();
	string getCategory();

	friend ostream& operator<<(ostream& ost, const Item &c);
	friend istream& operator>>(istream &in, Item &i);
	void operator =(Item c);


private:
	string name;
	string brand;
	float price;
	int amount;
	string category;
};

#endif /* ITEM_H_ */
