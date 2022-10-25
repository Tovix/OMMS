#include "cart.h"
#include "productList.h"

/*addToCart: function is responisable for adding an item from the product list to cart list 
it asks for the name of the product and it's quanity and if the conditions are met the product
is added to the cart*/

void cart::addToCart(productList p)
{
	string itemName;
	int quantity;
	int flag = 0;
	p.display(p.returnProductList(), 0, " ", " ");
	cout << "Enter the name of the product you want to add to your cart:" << endl;
	cin.ignore();
	getline(cin, itemName);
	for(int i = 0; i < cart_list.size(); i++)
	{
		if (cart_list[i].getName() == itemName) 
		{
			cout << "item is already in your cart!" << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 0) 
	{
		cout << "Enter the quantity of the product you want to add to your cart:" << endl;
		cin >> quantity;
		products item = p.returnProduct(itemName, quantity);
		if (item.getName() == itemName)
		{
			cart_list.push_back(item);
			cout << "Product Added Successfully" << endl;
		}
	}
}

/*displayCart: a for loop itering the cart list displaying the products and their info*/

void cart::displayCart()
{
	if (cart_list.size() != 0) 
	{
		for (int i = 0; i < cart_list.size(); i++)
		{
			cout << "ID assigned to the product:" << endl;
			cout << cart_list[i].getID() << endl;
			cout << "product's Name:" << endl;
			cout << cart_list[i].getName() << endl;
			cout << "product's price:" << endl;
			cout << cart_list[i].getPrice() << endl;
			cout << "product's category:" << endl;
			cout << cart_list[i].getCategory() << endl;
			cout << "seller's ID assigned to the product:" << endl;
			cout << cart_list[i].getSellerID() << endl;
			cout << "Quantity:" << endl;
			cout << cart_list[i].getOrderQuantity() << endl;
			cout << "###################################################" << endl;
		}
	}
	else
	{
		cout << "Cart is Empty !" << endl;
	}
}


void cart::removeFromCart(string itemName, productList p)
{
	cout << "pass" << endl;
}

/*checkout: function which calculates the price of all products in the cart and asks
the customer to rate the product*/

void cart::checkout(productList& p)
{
	float price = 0;
	char answer;
	float r;
	
	if(cart_list.empty())
	{
		cout << "cart is empty" << endl;
	}
	else
	{
		for (int i = 0; i < cart_list.size(); i++)
		{
			price += (cart_list[i].getPrice() * cart_list[i].getOrderQuantity());
		}
		cout << "Total price : " << price << "L.E" << endl;
		cout << "Confirm Order ? (y/n) " << endl;
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Order confirmed, please check our other products" << endl;
			for (int i = 0; i < cart_list.size(); i++)
			{
				
				cout << "rate the product: " << cart_list[i].getName() << " [ your rate / 5 ]:" << endl;
				cout << "###################################################" << endl;
				cin >> r;
				if (r > 5)
				{
					cout << "Wrong rate [max.5 // min.1]" << endl;
					cout << "try again and re enter your vote" << endl;
					r = 0;
					cin >> r;
				}
					
				for (int j = 0; j < p.returnProductList().size(); j++)
				{
					if (p.returnProductList()[j].getName() == cart_list[i].getName())
					{
						p.returnProductList()[j].setRates(r);
					}
				}
			}

			cart_list.clear();
		}
	}

}

