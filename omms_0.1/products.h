#pragma once
#include <iostream>
#include <vector>
using namespace std;

class products
{
	int id;
	float price;
	int seller_id;
	int quantity;
	int order_quantity;
	vector <float> rates;
	

public:
	string name;
	string category;
	float rate;
	
	products();
	products(int, string, float, string, int, int);
	int getID();
	string getName();
	float getPrice();
	string getCategory();
	int getSellerID();
	int getQuantity();
	int getOrderQuantity();
	void setOrderQuantity(int);
	void setQuantity(int);
	float getRate();
	void setRates(float);


};
