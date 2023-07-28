//
// Created by Colli on 7/27/2023.
//

#include <cstring>
#include "task.h"

using namespace std;

void Task::setName(char * nameArg)
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
    name = new char[strlen(nameArg)+1];
    strcpy(name, nameArg);
}

char *Task::getName() { return name; }

Task::Task()
{
    name = nullptr;
}

Task::~Task() { delete[] name;}

Task::Task(char *nameArg)
{
    name = new char[51];
    strcpy(name, nameArg);
}
Task::Task(const Task & other)
{
    name = nullptr;
    *this = other;
}

const Task &Task::operator=(const Task & other)
{
    if(this == &other)
        return *this;
    else
    {
        this->setName(other.name);
        return *this;
    }
}

