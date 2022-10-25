#include <string>
#include <iostream>
#include "products.h"
using namespace std;


products::products()
{

}

products::products(int i, string n, float pr, string cat, int s_id, int quant)
{
	id = i;
	name = n;
	price = pr;
	category = cat;
	seller_id = s_id;
	quantity = quant;
	if(rates.empty())
	{
		rate = 0;
	}
}



int products::getID()
{
	return id;
}

string products::getName()
{
	return name;
}

float products::getPrice()
{
	return price;
}

string products::getCategory()
{
	return category;
}

int products::getSellerID()
{
	return seller_id;
}

int products::getQuantity()
{
	return quantity;
}

void products::setQuantity(int quan)
{
	quantity = quan;
}

int products::getOrderQuantity()
{
	return order_quantity;
}

void products::setOrderQuantity(int quan)
{
	order_quantity = quan;
}



float products::getRate()
{
	return rate;
}

/*setRates: add the rate r and then does an
average calculation to return rate*/
void products::setRates(float r)
{
	rates.push_back(r);
	float sum = 0.0;
	float total = 0.0;
	for (int i = 0; i < rates.size(); i++)
	{
		sum += rates[i];
		total += 5.0;
	}
	rate = (sum / total) * 100;
	
}







