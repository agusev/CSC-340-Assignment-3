// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file ArrayStack.h */

#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
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
#include "ArrayStack.cpp"
#endif