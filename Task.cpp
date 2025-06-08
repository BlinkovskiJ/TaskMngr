#include "Task.hpp"

Task::Task(String^ name, String^ desc, DateTime deadline, TaskStatus status, int catID)
{
	taskName = name;
	taskDesc = desc;
	deadLineAt = deadline;
	currentStatus = status;
	categoryID = catID;
	MarkNew();
}

Task::Task()
{
	MarkNew();
}

void Task::setDeadLine(DateTime deadLine)
{
	deadLineAt = deadLine;
	MarkModified();
}

void Task::setStatus(int statusIndex)
{
	currentStatus = static_cast<TaskStatus>(statusIndex);
	MarkModified();
}

void Task::setName(String^ taskName)
{
	this->taskName = taskName;
	MarkModified();
}

void Task::setDesc(String^ taskDesc)
{
	this->taskDesc = taskDesc;
	MarkModified();
}

void Task::setCategoryID(int id)
{
	categoryID = id;
	MarkModified();
}

String^ Task::getName()
{
	return taskName;
}

String^ Task::getDesc()
{
	return taskDesc;
}

DateTime Task::getDeadLine()
{
	return deadLineAt;
}

TaskStatus Task::getStatus()
{
	return currentStatus;
}

int Task::getCategoryID()
{
	return categoryID;
}
