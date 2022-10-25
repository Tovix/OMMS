#include"customer.h"
using namespace std;

customer::customer()
{

}

customer::customer(int id, string name, string address,
	int phone_num, string email, string password) 
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone_num = phone_num;
	this->email = email;
	this->password = password;
}

string customer::getName()
{
	return name;
}

string customer::getpassword()
{
	return password;
}
