#pragma once

#include "taskMngrBaseObject.hpp"

using namespace System;

ref class Category : taskMngrBaseObject
{
private:
	String^ name;
	int id;

public:
	Category(String^ name, int id);
	String^ getName();
	void setID(int id);

	int getID();
};


