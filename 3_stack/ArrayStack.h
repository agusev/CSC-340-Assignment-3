// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file ArrayStack.h */

#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
#include <cassert>

const int MAX_STACK = 6;

template <class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
    ItemType items[MAX_STACK];
    int top;

public:
    ArrayStack();
    ~ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType &newEntry);
    bool pop();
    ItemType peek() const;
};

// constructor
template <class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
    std::cout << "\033[32m\n*************************** ArrayStack CREATED ***************************\n\n\033[0m";
}

// destructor
template <class ItemType>
ArrayStack<ItemType>::~ArrayStack()
{
    while (!isEmpty())
    {
        pop();
    }
    std::cout << "\033[31m\n*************************** ArrayStack DELETED ***************************\n\n\033[0m";
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

#endif