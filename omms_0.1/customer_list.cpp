#include"customer_list.h"
#include"customer.h"
using namespace std;

/*addCustomer: function which takes info a certain customer 
and add it to the customer list*/

void customer_list::addCustomer() 
{
	int id;
	string name;
	string address;
	int phone_num;
	string email;
	string password;
	cout << "Customer Registration:" << endl;
	cout << "Fill the Following Data to submit your customer info:" << endl;
	cout << "###################################################" << endl;
	cout << "Please Enter your ID:" << endl;
	cin >> id;
	cout << "Enter Your Name:" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your Phone Number:" << endl;
	cin >> phone_num;
	cout << "Enter your password:" << endl;
	cin.ignore();
	getline(cin, password);
	cout << "Enter Your Address:" << endl;
	cin.ignore();
	getline(cin, address);
	cout << "Enter your Email:" << endl;
	cin.ignore();
	getline(cin, email);
	customer c1 = customer(id, name, address, phone_num, email, password);
	customers.Append(c1);
	cout << "Customer Added Successfully!" << endl;
	cout << "###################################################" << endl;


}

/*checkUser: function created to check for the username and password and compare them 
to the ones found in the list if found return 0 if not return -1*/

int customer_list::checkUser(string usr, string password)
{
	for(int i = 0; i < customers.Length(); i ++)
	{
		if((customers.At(i).getName() == usr) && (customers.At(i).getpassword() == password))
		{
			return 0;
			break;
		}
	}
	return -1;
}




