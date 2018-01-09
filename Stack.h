/*
 * Stack.h
 *
 *  Created on: Jan 8, 2018
 *      Author: Tony
 */

#ifndef STACK_H_
#define STACK_H_

class Stack
{
private:
    int size;
    int top;
    int* stack;
public:
    Stack(int size);
    void push(int item);
    int pop();
    bool empty();
    bool full();
    int peek();
    void search(int searchNumber);
};

#endif /* STACK_H_ */
