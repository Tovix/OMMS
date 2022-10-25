#pragma once
#include <string>
#include <iostream>
using namespace std;

class customer
{
	int id;
	string name;
	string address;
	int phone_num;
	string email;
	string password;
public:
	customer();
	customer(int, string, string, int, string, string);
	string getName();
	string getpassword();
};