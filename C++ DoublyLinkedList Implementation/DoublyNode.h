/*
 * DoublyNode.h
 *
 *  Created on: Jan 12, 2018
 *      Author: Tony
 */

#ifndef DOUBLYNODE_H_
#define DOUBLYNODE_H_

struct DoublyNode
{
    // Integer stored in the node.
    int data;
    // Pointer that points to the previous node.
    DoublyNode* previous;
    // Pointer that points to the next node.
    DoublyNode* next;
};

#endif /* DOUBLYNODE_H_ */
