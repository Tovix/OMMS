#include <iostream>
using namespace std;
#include "seller_list.h"
#include "customer_list.h"
#include "productList.h"
#include "cart.h"
int main()
{
	/*The normal program flow creating objects from the classes and using them for the project purposes*/

	vector<products> p;
	productList p_list(p);
	seller_list s_list = seller_list();
	customer_list c_list = customer_list();
	cart cart_list = cart();
	
	int choice = 0;
	cout << "Online MarketPlace Management System: [OMMS_0.1]" << endl;
	cout << "#######################################################" << endl;
	while(choice != 3)
	{
		cout << "1 - Login" << endl;
		cout << "2 - Register" << endl;
		cout << "3 - quit" << endl;
		cout << "#######################################################" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;
		cout << "#######################################################" << endl;
		if(choice == 1)
		{
			string usr, password;
			int account_flag = 0;
			cout << "Enter your username:" << endl;
			cin.ignore();
			getline(cin, usr);
			cout << "Enter your Password:" << endl;
			getline(cin, password);
			cout << "#######################################################" << endl;
			int check_cust = c_list.checkUser(usr, password);
			int check_sell = s_list.checkUser(usr, password);
			if(check_cust == 0)
			{
				int inner_choice_2 = 0;
				while(inner_choice_2 != 5)
				{
					cout << "Welcome, " << usr << endl;
					cout << "you have cutomer privileges:" << endl;
					cout << "#######################################################" << endl;
					cout << "1 - display all products" << endl;
					cout << "2 - add product to cart" << endl;
					cout << "3 - display cart" << endl;
					cout << "4 - checkout" << endl;
					cout << "5 - Logout" << endl;
					cout << "#######################################################" << endl;
					cout << "Enter your choice:" << endl;
					cin >> inner_choice_2;
					if(inner_choice_2 == 1)
					{
						p_list.display_product();
					}
					else if(inner_choice_2 ==2)
					{
						cart_list.addToCart(p_list);
					}
					else if(inner_choice_2 == 3)
					{
						cart_list.displayCart();
					}
					else if(inner_choice_2 == 4)
					{
						cart_list.checkout(p_list);
					}

				}
			}
			else if(check_cust == -1)
			{
				if(check_sell == 0)
				{
					int inner_choice_3 = 0;
					while (inner_choice_3 != 2) 
					{
						cout << "Welcome, " << usr << endl;
						cout << "you have seller privileges:" << endl;
						cout << "#######################################################" << endl;
						cout << "1 - add your products" << endl;
						cout << "2 - Logout" << endl;
						cout << "#######################################################" << endl;
						cout << "Enter your choice:" << endl;
						cin >> inner_choice_3;
						if(inner_choice_3 == 1)
						{
							p_list.add_product();
						}
					}
				}
				else
				{
					cout << "Wrong username/password\nTry again later." << endl;
				}
			}
			else
			{
				cout << "Wrong username/password\nTry again later." << endl;
			}
			
		}
		else if(choice == 2)
		{
			int inner_choice_1 = 0;
			cout << "1 - Register as Seller" << endl;
			cout << "2 - Register as customer" << endl;
			cout << "#######################################################" << endl;
			cout << "Enter your choice:" << endl;
			cin >> inner_choice_1;
			if(inner_choice_1 == 1)
			{
				cout << "Seller Registration" << endl;
				cout << "Fill the Following Data to submit your Seller Info:" << endl;
				cout << "###################################################" << endl;
				s_list.add_seller_account();
			}
			else if(inner_choice_1 == 2)
			{
				c_list.addCustomer();
			}
			else
			{
				cout << "wrong choice" << endl;
			}
		}



	}

	system("pause");
}