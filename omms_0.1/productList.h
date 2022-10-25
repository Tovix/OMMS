#pragma once
#include "products.h"
#include <iostream>
#include <vector>
#include <string>
#include "admin.h"
class productList
{
	vector<products>& products_list;
public:
	productList(vector<products>&);
	void add_product();
	void display_product();
	products returnProduct(string, int);
	string returnProductName(string);
	void display(vector<products>, int, string, string);
	vector<products>& returnProductList();
};