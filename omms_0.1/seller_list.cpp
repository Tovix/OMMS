#include "seller_list.h"
#include "seller.h"
#include <iostream>

using namespace std;

seller_list::seller_list()
{
	num_of_accou = 0;
	list_size = 0;
	seller_arr = 0;
	seller_arr = new seller[list_size];

}

/*add_seller_account: adds the seller data to the seller list*/

void seller_list::add_seller_account()
{

	expand_list();

	seller_arr[list_size - 1].Name = cin_name();
	seller_arr[list_size - 1].password = cin_password();
	seller_arr[list_size - 1].ID = cin_ID();
	seller_arr[list_size - 1].Email = cin_email();
	cout << "###################################################" << endl;
	cout << "Seller Data had been stored successfully" << endl;
	cout << "###################################################" << endl;
	num_of_accou++;

}

/*cin_ID:append the seller id to the seller list */

int seller_list::cin_ID()
{
	int id;
	bool was_taken = true;
	while (was_taken == true)
	{
		cout << "Enter the ID:" << endl;
		cin >> id;
		for (int i = 0; i < list_size; i++)
		{
			if (id == seller_arr[i].ID)
			{
				cout << "This ID was taken try again! --> " << endl;
				was_taken = true;
				break;
			}
			else
				was_taken = false;
		}
		if (id < 0)
		{
			cout << "Please add a positive number";
			was_taken = true;  //  start  from the begining of loop  
		}
	}
	return id;

}

/*cin_name:append the seller name to the seller list */

string seller_list::cin_name()
{
	string name;
	bool  was_taken = true;
	while (was_taken == true)
	{
		cout << "Enter the username: " << endl;
		cin >> name;
		for (int i = 0; i < list_size; i++)
		{
			if (name == seller_arr[i].Name)
			{
				cout << "This name was taken try again! --> " << endl;;
				was_taken = true;
				break;
			}
			else
				was_taken = false;
		}
	}
	return string(name);
}

/*cin_email:append the seller email to the seller list */

string seller_list::cin_email()
{

	string e_mail;

	bool  was_taken = true;
	while (was_taken == true)
	{
		cout << "Enter the email: "<<endl;
		cin >> e_mail;
		for (int i = 0; i < list_size; i++)
		{

			if (e_mail == seller_arr[i].Email)
			{
				cout << "This E-mail was taken try again! -->" << endl;
				was_taken = true;
				break;

			}
			else
				was_taken = false;
		}
	}
	return string(e_mail);
}

/*cin_password:append the seller password to the seller list */

string seller_list::cin_password()
{
	string password;
	cout << "Enter the password: " << endl;;
	cin >> password;
	return string(password);
}

/*checkUser: function created to check for the username and password and compare them
to the ones found in the list if found return 0 if not return -1*/

int seller_list::checkUser(string usr, string password)
{
	for(int i = 0; i < list_size; i++)
	{
		if((seller_arr[i].getName() == usr) && (seller_arr[i].getPassword() == password))
		{
			return 0;
			break;
		}
	}
	return -1;
}


/*expand_list: expands the seller list */

void seller_list::expand_list()
{
	list_size++;
	seller* arr = new seller[list_size];
	if (list_size != 1) {
		for (int i = 0; i < list_size - 1; i++)
		{
			arr[i] = seller_arr[i];

		}
	}
	delete[] seller_arr;
	seller_arr = arr;
}

seller_list::~seller_list()
{
	delete[] seller_arr;
}
