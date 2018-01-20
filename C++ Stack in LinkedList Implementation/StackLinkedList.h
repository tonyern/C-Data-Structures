/*
 * StackLinkedList.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Tony Nguyen
 */

#ifndef STACKLINKEDLIST_H_
#define STACKLINKEDLIST_H_
#include "StackNode.h"

class StackLinkedList
{
private:
    StackNode* head;
    int length;
public:
    StackLinkedList();
    void push(int item);
    int pop();
    int peek();
    bool empty();
    int getLength();
    void search(int searchNumber);
    void forwardShow();
    void makeEmpty();
    ~StackLinkedList();
};

#endif /* STACKLINKEDLIST_H_ */
