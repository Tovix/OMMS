#pragma once
#include "seller.h"

class seller_list
{
public:
	int num_of_accou, list_size;

	seller* seller_arr;

public:
	seller_list();
	void add_seller_account();
	int cin_ID();//used in add_account function only
	string cin_name();//used in add_seller_account function only 
	string cin_email();//used in add_seller_account function only 
	string cin_password();//used in add_seller_account function only 
	int checkUser(string, string);
	void expand_list();
	~seller_list();
};

