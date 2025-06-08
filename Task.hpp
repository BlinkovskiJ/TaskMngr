#pragma once

#include "taskMngrBaseObject.hpp"

using namespace System;

public enum class TaskStatus { Process, Finished, Delayed };

ref class Task : taskMngrBaseObject
{
private:
	String^ taskName;
	String^ taskDesc;
	DateTime deadLineAt;
	TaskStatus currentStatus = TaskStatus::Delayed;
	int categoryID;

public:
	Task(String^ name, String^ desc, DateTime deadline, TaskStatus status, int catID);
	Task();

	void setDeadLine(DateTime deadLine);
	void setStatus(int statusIndex);
	void setName(String^ taskName);
	void setDesc(String^ taskDesc);
	void setCategoryID(int id);

	String^ getName();
	String^ getDesc();
	DateTime getDeadLine();
	TaskStatus getStatus();
	int getCategoryID();
};

