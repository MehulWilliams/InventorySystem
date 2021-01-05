/*
 * Item.cpp
 *
 *  Created on: May 2, 2020
 *      Author: mehulwilliams
 */

#include "Item.h"

Item::Item() {
	setName("undefined");
	brand = "undefined";
	price = -1;
	amount = -1;
	category = "undefined";
}

Item::Item(string n, string b, float p, int a, string c) {
	setName("undefined");
	brand = b;
	price = p;
	amount = a;
	category = c;
}

void Item::setName(string n) {
	name = n;
}
void Item::setBrand(string b) {
	brand = b;
}
void Item::setPrice(float p) {
	price = p;
}
void Item::setAmount(int a) {
	amount = a;
}
void Item::setCategory(string c) {
	category = c;
}
string Item::getName() {
	return name;
}
string Item::getBrand() {
	return brand;
}
float Item::getPrice() {
	return price;
}
int Item::getAmount() {
	return amount;
}
string Item::getCategory() {
	return category;
}

istream& operator>>(istream &in, Item &i) {
	string Nname;
	string Nbrand;
	float Nprice;
	int Namount;
	string Ncategory;

	in >> Nname >> Nbrand >> Nprice >> Namount >> Ncategory;

	i.setName(Nname);
	i.setBrand(Nbrand);
	i.setPrice(Nprice);
	i.setAmount(Namount);
	i.setCategory(Ncategory);

	return in;
}

ostream& operator <<(ostream &ost, const Item &c) {
	ost << "Name: " << c.name;
	ost << "		Brand: " << c.brand;
	ost << "		Price: " << c.price;
	ost << "		Amount: " << c.amount;
	ost << "		Category: " << c.category;
	return ost;
}

void Item::operator =(Item c) {
	/*
	 name = c.getName();
	 brand = c.getBrand();
	 price = c.getPrice();
	 amount = c.getAmount();
	 category = c.getCategory();
	 */

	c.setName(getName());
	c.setBrand(getName());
	c.setPrice(getPrice());
	c.setAmount(getAmount());
	c.setCategory(getName());
}


