#pragma once
#include <string>
using namespace std;
class seller
{
public:
	int ID;
	string Name, Email;
	string password;
public:
	seller();
	string getName();
	string getPassword();
};