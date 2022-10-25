#include "admin.h"
#include <iostream>
using namespace std;

admin::admin()
{
	forbidden_items = {"alcohol", "weapon", "tabacoo", "drugs", "cat", "dog", "fruits", "vegatables"};
}

vector<string> admin::returnItemList()
{
	return forbidden_items;
}
