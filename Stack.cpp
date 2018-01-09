# C-Data-Structures
Just implementation of data structures in C++.

/*
 * Stack.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Tony
 */

#include <iostream>
#include "Stack.h"
using namespace std;

/**
 * Constructor that takes in a user-specified size and creates the stack.
 */
Stack::Stack(int size)
{
    this->size = size;
    this->top = -1;
    stack = new int[size];
}

/**
 * This method adds item to the stack.
 */
void Stack::push(int item)
{
    // Making sure the stack is not full so it doesn't overflow.
    if (!full())
    {
        // Increasing top and set it to the stack.
        top++;
        stack[top] = item;
    }
}

/**
 * This method removes item from the stack.
 */
int Stack::pop()
{
    // Checks if the stack is not empty.
    if (!empty())
    {
        // We remove the number but removing the index.
        return stack[top--];
    } else {
        return -1;
    }
}

/**
 * This method checks if top is equal to its original set value of -1 in constructor. If so then stack is empty.
 */
bool Stack::empty()
{
    return (top == -1);
}

/**
 * This method checks if the top and size equal. If they do then we can't add anymore because stack is full.
 */
bool Stack::full()
{
    return (top == size);
}

/**
 * This method returns the value on the top most stack but does not remove it.
 */
int Stack::peek()
{
    return stack[top];
}

/**
 * This method looks for the index a specified number is located on the stack from 0 to specified size.
 */
void Stack::search(int searchNumber)
{
    // Loop through the stack.
    for (int i = 0; i < size; i++)
    {
        // If we find the corresponding value.
        if (stack[i] == searchNumber)
        {
            // Print out this message.
            cout << searchNumber << " is located at " << i << " index." << endl;
        }
    }
}
