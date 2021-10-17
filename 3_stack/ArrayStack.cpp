// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file Stack.cpp */

#include <cassert>      // For assert
#include "ArrayStack.h" // Header file

// constructor
template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}

// destructor
template <class ItemType>
ArrayStack<ItemType>::~ArrayStack()
{
    delete[] items;
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
    if (top < MAX_STACK - 1)
    {
        top++;
        items[top] = newEntry;
        result = true;
    }
    return result;
}

// pop()
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
template <class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    assert(!isEmpty());
    return items[top];
}
