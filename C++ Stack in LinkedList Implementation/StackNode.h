/*
 * StackNode.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Tony Nguyen
 */

#ifndef STACKNODE_H_
#define STACKNODE_H_

struct StackNode
{
    // Pointer to the next node.
    StackNode* next;
    // Data that is in the node.
    int data;
};

#endif /* STACKNODE_H_ */
