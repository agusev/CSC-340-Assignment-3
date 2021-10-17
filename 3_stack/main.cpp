// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file main.cpp */

#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;
int main()
{
    StackInterface<string> *stackPtr = new ArrayStack<string>();
    string anItem = "";
    cout << "Enter a string: ";
    cin >> anItem;
    stackPtr->push(anItem);

    return 0;
}