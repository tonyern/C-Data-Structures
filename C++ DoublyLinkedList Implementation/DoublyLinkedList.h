/*
 * DoublyLinkedList.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Tony Nguyen
 *      Version: 1.01
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
    void insertItem(int item, int positionIndex);
    void insertAll(int *array, int size);
    void deleteItem(int item);
    void forwardShow();
    void reverseShow();
    void searchNumber(int searchItem);
    int peek();
    int peekLast();
    int poll();
    int pollLast();
    ~DoublyLinkedList();
};

#endif /* DOUBLYLINKEDLIST_H_ */
