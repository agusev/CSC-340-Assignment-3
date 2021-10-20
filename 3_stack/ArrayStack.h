// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file ArrayStack.h */

#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
#include <cassert>
using namespace std;

// default arraySize
int arraySize = 6;

template <class ItemType>
class ArrayStack : public StackInterface<ItemType>
{

private:
    ItemType *items;
    int top;

public:
    ArrayStack();
    ~ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType &newEntry);
    bool pop();

    ItemType peek() const;
};

// default constructor
template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
    items = new ItemType[arraySize];
}

// destructor
template <class ItemType>
ArrayStack<ItemType>::~ArrayStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// isEmpty()
template <class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}

// push
template <class ItemType>
bool ArrayStack<ItemType>::push(const ItemType &newEntry)
{
    bool result = false;
    top++;

    // resize array
    if (!(top < arraySize))
    {
        ItemType *oldArray = items;
        items = new ItemType[2 * arraySize];
        for (int index = 0; index < arraySize; index++)
        {
            items[index] = oldArray[index];
        }
        delete[] oldArray;
        arraySize *= 2;
    } // end if

    if (top < arraySize)
    {
        items[top] = newEntry;
        result = true;
    }

    return result;
}

// pop
template <class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }
    return result;
}

// peek()
// returns the top element from the stack
template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{

    assert(!isEmpty());
    return items[top];
}

#endif