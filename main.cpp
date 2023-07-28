#include <iostream>
#include "task.h"
#include "taskList.h"

using namespace std;

int main() {
    TaskList taskList;
    Task task;

    taskList.loadTasks("tasks.txt");
    taskList.print();
    taskList.removeTask();
    taskList.print();

    return 0;
}
