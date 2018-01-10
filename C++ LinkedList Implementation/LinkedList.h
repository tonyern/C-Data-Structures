/*
 * LinkedList.h
 *
 *  Created on: Jan 9, 2018
 *      Author: Tony
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"

class LinkedList
{
private:
    int length;
    Node* start;
public:
    LinkedList();
    void makeEmpty();
    bool isFull() const;
    int getLength() const;
    void insertItem(int item);
    void deleteItem(int item);
    void show();
    ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
