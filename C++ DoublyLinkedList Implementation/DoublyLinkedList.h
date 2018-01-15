/*
 * DoublyLinkedList.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Tony
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_
#include "DoublyNode.h"

class DoublyLinkedList
{
private:
    int length;
    DoublyNode* start;
    DoublyNode* end;
public:
    DoublyLinkedList();
    void makeEmpty();
    bool isFull() const;
    int getLength() const;
    void insertItem(int item);
    void deleteItem(int item);
    void forwardShow();
    void reverseShow();
    void searchNumber(int searchItem);
    ~DoublyLinkedList();
};

#endif /* DOUBLYLINKEDLIST_H_ */
