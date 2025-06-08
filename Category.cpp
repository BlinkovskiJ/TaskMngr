#include "Category.hpp"

Category::Category(String^ name, int id)
{
	this->name = name;
	this->id = id;
}

String^ Category::getName()
{
	return name;
}

void Category::setID(int id)
{
	this->id = id;
}

int Category::getID()
{
	return id;
}
