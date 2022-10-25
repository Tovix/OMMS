#pragma once
#include "customer.h"
#include "ArrList.cpp"
#include <iostream>
using namespace std;
class customer_list
{
	ArrList<customer> customers;
public:
	void addCustomer();
	int checkUser(string, string);
};