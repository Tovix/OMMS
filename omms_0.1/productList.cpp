#include "productList.h"
#include "products.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*creating constructor in this form to be able to pass the product list to the cart list by reference*/

productList::productList(vector<products>& vec) : products_list(vec)
{

}

/*add_product: used to take info and add the products to the product list and checks 
if the product sold is illegal or not before adding it the list*/

void productList::add_product()
{
	string name, category;
	float price;
	int id, seller_id;
	int quantity;
	int flag = 0;
	admin a1;
	products p1 = products();
	cout << "Product Submission" << endl;
	cout << "Fill the Following Data to submit your product:" << endl;
	cout << "###################################################" << endl;
	cout << "Enter the product's ID:" << endl;
	cin >> id;
	cout << "Enter the product's Name:" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter the product's price:" << endl;
	cin >> price;
	cout << "Enter the product's category:" << endl;
	cin.ignore();
	getline(cin, category);
	cout << "Enter the seller's ID assigned to your account:" << endl;
	cin >> seller_id;
	cout << "Enter the quanity of the product you are selling:" << endl;
	cin >> quantity;
	cout << "Admin checking if the product is legal to be shown on the system ............." << endl;
	cout << "###################################################" << endl;
	for(int i = 0 ; i < a1.returnItemList().size(); i++)
	{
		if(a1.returnItemList()[i] == name)
		{
			cout << "illegal item found cannot sell this kind of this product: " << a1.returnItemList()[i] << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0) 
	{
		p1 = products(id, name, price, category, seller_id, quantity);
		products_list.push_back(p1);
		cout << "Product added successfully!" << endl;
		cout << "###################################################" << endl;
	}
}

/*display_product: display the products with different methods*/

void productList::display_product()
{
	int choice;
	cout << "Displaying All Products:" << endl;
	cout << "###################################################" << endl;
	cout << "1) display all products" << endl;
	cout << "2) display all products sorted by category" << endl;
	cout << "3) display all products sorted by name" << endl;
	cout << "4) search products by category" << endl;
	cout << "5) searh products by name" << endl;
	cout << "6) display all orders sorted by ratings" << endl;
	cout << "###################################################" << endl;
	cout << "Enter your choice:" << endl;
	cin >> choice;

	if (choice == 1) 
	{

		
		display(products_list, 0, " ", " ");
	}
	else if (choice == 2)
	{
		vector<products> prod_cat;
		prod_cat = products_list;
		sort(prod_cat.begin(),
			prod_cat.end(),
			[](const products& p1, const products& p2) { return p1.category < p2.category; });

		display(prod_cat, 0, " ", " ");
		
	}

	else if (choice == 3)
	{
		vector<products> prod_name;
		prod_name = products_list;
		sort(prod_name.begin(),
			prod_name.end(),
			[](const products& p1, const products& p2) { return p1.name < p2.name; });

		display(prod_name, 0, " ", " ");

	}

	else if (choice == 4)
	{
		string c;
		cout << "###################################################" << endl;
		cout << "Enter the category you are looking for:" << endl;
		cin.ignore();
		getline(cin, c);
		display(products_list, 1, c, " ");
	}

	else if (choice == 5)
	{
		string n;
		cout << "###################################################" << endl;
		cout << "Enter the name of the product you are looking for:" << endl;
		cin.ignore();
		getline(cin, n);
		display(products_list, 2, " ", n);
	}

	else if (choice == 6)
	{
		vector<products> prod_rate;
		prod_rate = products_list;
		sort(prod_rate.begin(),
			prod_rate.end(),
			[](const products& p1, const products& p2) { return p1.rate > p2.rate; });

		display(prod_rate, 0, " ", " ");
	}

	else
	{
		cout << "option not found" << endl;
	}
}

/*rerturnProduct: return product if it's name equal to the parameter
and it's quantity is greater than or equal to the ordered quanity
and decreases this amount from the stock*/

products productList::returnProduct(string name, int quantity)
{
	products p1;
	int flag_q = 0;
	int flag_n = 0;
	for(int i = 0; i < products_list.size(); i++)
	{
		
		if(products_list[i].getName() == name)
		{
			flag_n = 1;
			if (products_list[i].getQuantity() >= quantity) 
			{
				products_list[i].setOrderQuantity(quantity);
				products_list[i].setQuantity(products_list[i].getQuantity() - quantity);
				return products_list[i];
				flag_q = 1;
			}
		}
		
	}
	if(flag_n == 0)
	{
		cout << "the product is not available" << endl;
	}
	if(flag_q == 0)
	{
		cout << "the product amount in the stock is insufficient" << endl;
	}
	return p1;
}

/*returnProductName: return the product name from the product list if
it's name is equal to the argument*/

string productList::returnProductName(string name)
{
	products p1;
	for (int i = 0; i < products_list.size(); i++)
	{

		if (products_list[i].getName() == name)
		{
			return products_list[i].getName();
			break;
			
		}
	}
	return "";
}

/*display: link with display_products function as a way to decrease duplicate code*/

void productList::display(vector<products> list, int option, string category, string name)
{
	int flag = 0;
	for(int i = 0; i < list.size(); i++)
	{
		
		if(option == 1)
		{
			if(list[i].getCategory() == category)
			{
				cout << "Category found !" << endl;
				cout << "###################################################" << endl;
				flag = 1;
			}
		}
		else if (option == 2)
		{
			if (list[i].getName() == name)
			{
				cout << "product found !" << endl;
				cout << "###################################################" << endl;
				flag = 1;
			}
			
		}
		

		cout << "ID assigned to the product:" << endl;
		cout << list[i].getID() << endl;
		cout << "product's Name:" << endl;
		cout << list[i].getName() << endl;
		cout << "product's price:" << endl;
		cout << list[i].getPrice() << " L.E" <<endl;
		cout << "product's category:" << endl;
		cout << list[i].getCategory() << endl;
		cout << "Number of products available in stock:" << endl;
		cout << list[i].getQuantity() << " Piece(s) " <<endl;
		cout << "Rating (postive)/(negative):" << endl;
		cout << list[i].getRate() <<" %" << " ||  "<< 100 - list[i].getRate() <<" %" <<endl;
		cout << "seller's ID assigned to the product:" << endl;
		cout << list[i].getSellerID() << endl;
		cout << "###################################################" << endl;

	}

	if (option != 0)
	{
		if (flag == 0)
		{
			cout << "product not found" << endl;
		}


	}
}

/*returnProductList: return the productsList*/

vector<products>& productList::returnProductList()
{
	return products_list;
}

