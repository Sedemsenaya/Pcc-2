//
// Created by Colli on 7/27/2023.
//

#include "taskList.h"
#include <iostream>
#include <cstring>
#include "fstream"
using namespace std;

TaskList::TaskList() : count(0), size(10)
{
    tasks = new Task[size];
}

TaskList::~TaskList()
{
    if(tasks)
    {
        delete [] tasks;
        tasks = nullptr;
    }
}

bool TaskList::loadTasks(char *fileName)
{
    ifstream inFile(fileName);
    char tempName[51];
    bool result = false, stillRoom = true;
    Task task;
    if(inFile.is_open())
    {
        do {
            if(count >= 51)
            {
                cout << "Array is full.\n";
                stillRoom = false;
            }
            else
            {
                inFile.getline(tempName, 51);
                task.setName(tempName);
                addTask(task);
            }
            inFile.peek();
        } while(!inFile.eof() && stillRoom);
        result = true;
    }
    inFile.close();
    return result;
}


void TaskList::addTask(Task & task)
{
    //check if size ==  cap
    //If yes, then grow the array
    if(size == count)
    {
        growList();
    }
    //!!!!! Assignment operator overloaded-So, ok to copy
    tasks[count++] = task;
}

//adds to capacity of list when full
void TaskList::growList()
{
    size += 10;
    Task *tempTask= new Task[size];
    for (int i = 0; i < size; i++)
    {
        //assignment operator overloaded
        tempTask[i] = tasks[i];
    }

    delete[] tasks;
    tasks = tempTask;
    tempTask = NULL;
}

void TaskList::print()
{
    sortTasksAlphabetically();
    for (int i = 0; i < count; i++) {
        cout << i + 1<<" " << tasks[i].getName()<<endl;
    }
}
void TaskList::sortTasksAlphabetically() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(tasks[j].getName(), tasks[j + 1].getName()) > 0) {
                // Swap tasks[j] and tasks[j+1]
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int TaskList::readInt(char prompt[])
{
    int temp = 0;
    cout << prompt;
    cin >> temp;
    //data validation
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input!! Please try again!!";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

//removes a song  from the list
void TaskList::removeTask()
{
    int delIndex = 0;
    delIndex = readInt("Please enter index of song to delete:");
    if(delIndex < count)
    {
        for(int i = delIndex; i < count; i++)
        {
            tasks[i-1] = tasks[i];
        }
    }
    count--;
}
