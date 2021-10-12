// CSC340
// Assignment 3.2
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>
#include <iostream>
using namespace std;

//colors
#define NC "\e[0m"
#define RED "\e[5;31m"
#define GRN "\e[5;32m;"
#define YLW "\e[0;33m"
#define BLE "\e[34m"
#define CYN "\e[35m"

class TicTacToe
{

private:
   enum Status
   {
      WIN,
      DRAW,
      CONTINUE
   };
   std::array<std::array<int, 3>, 3> board;

public:
   TicTacToe();
   void makeMove();
   void printBoard() const;
   bool validMove(int, int) const;
   bool xoMove(int);
   Status gameStatus() const;
};

#endif
