//
// Created by Colli on 7/27/2023.
//

#ifndef MEMCHECK_1_TASKLIST_H
#define MEMCHECK_1_TASKLIST_H
#include "task.h"

class TaskList {
    int count;
    int size;
    Task *tasks;
public:
    TaskList();
    ~TaskList();
    bool loadTasks(char fileName[]);
    void resize();
    void addTask(Task &);
    void growList();
    void print();
    void sortTasksAlphabetically();
    void removeTask();
    int readInt( char []);
};


#endif //MEMCHECK_1_TASKLIST_H
