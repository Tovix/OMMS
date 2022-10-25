#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class admin
{
	vector<string> forbidden_items;
public:
	admin();
	vector<string> returnItemList();
};

