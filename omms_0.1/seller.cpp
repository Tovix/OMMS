#include "seller.h"

seller::seller()
{
	ID = 0;
	Name = 'null';
	Email = 'null';
	password = 'null';
}

string seller::getName()
{
	return Name;
}

string seller::getPassword()
{
	return password;
}


