//
// Created by Colli on 7/27/2023.
//

#ifndef MEMCHECK_1_TASK_H
#define MEMCHECK_1_TASK_H


class Task {
    char * name;

public:
    Task();
    Task(char *);
    ~Task();

    void setName(char *);
    char * getName();

    Task(const Task&);
    const Task& operator= (const Task&);

};


#endif //MEMCHECK_1_TASK_H
