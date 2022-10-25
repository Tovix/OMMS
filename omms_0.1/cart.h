#pragma once
#include<vector>
#include <string>
#include <iostream>
#include "productList.h"
using namespace std;
class cart
{
	vector<products> cart_list;
public:
	void addToCart(productList);
	void displayCart();
	void removeFromCart(string, productList);
	void checkout(productList&);
	

};

