// CSC340
// Assignment 3.2
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

#include "TicTacToe.h"

// Defaut constructor
TicTacToe::TicTacToe()
{
   cout << BLE << "The game has started: \n"
        << NC << endl;
}

/**
 * This function prints the board and
 * takes users' moves
 */
void TicTacToe::makeMove()
{
   printBoard();

   while (true)
   {
      if (xoMove('X'))
      {
         break;
      }
      else if (xoMove('O'))
      {
         break;
      }
   }
}

/**
 * Outputs current states of the board
 */
void TicTacToe::printBoard() const
{
   cout << "    0   1   2  " << endl
        << endl;

   for (int row = 0; row < 3; ++row)
   {
      cout << row << "   ";
      for (int col = 0; col < 3; ++col)
      {
         if (col == 1)
         {
            cout << YLW << " | " << NC;
         }

         if (board[row][col] == 1)
         {
            cout << CYN << "X" << NC;
         }
         else if (board[row][col] == -1)
         {
            cout << BLE << "O" << NC;
         }
         else
         {
            cout << ' ';
         }
         if (col == 1)
         {
            cout << YLW << " | " << NC;
         }
      }
      if (row == 0 || row == 1)
      {
         cout << "\n"
              << YLW
              << "   ––– ––– ––– " << NC;
      }
      cout << endl;
   }
}

/**
 * validates that user's move in the Board range and
 * position is empty
 */
bool TicTacToe::validMove(int row, int col) const
{
   if ((row >= 0) && (row < 3) &&
       (col >= 0) && (col < 3) &&
       (board[row][col] == 0))
   {
      return true;
   }

   return false;
}

/**
 * checks the game status of the game according to the user's valid input
 */
TicTacToe::Status TicTacToe::gameStatus() const
{
   int sum = 0;
   bool hasMoves = false;

   for (int i = 0; i < 3; i++)
   {
      sum = board[i][0] + board[i][1] + board[i][2];
      if (sum == 3 || sum == -3)
      {
         return WIN;
      }
      else
      {
         sum = 0;
      }
   }

   for (int j = 0; j < 3; j++)
   {
      sum = board[0][j] + board[1][j] + board[2][j];
      if (sum == 3 || sum == -3)
      {
         return WIN;
      }
      else
      {
         sum = 0;
      }
   }

   sum = board[0][0] + board[1][1] + board[2][2];

   if (sum == 3 || sum == -3)
   {
      return WIN;
   }

   sum = board[0][2] + board[1][1] + board[2][0];
   if (sum == 3 || sum == -3)
   {
      return WIN;
   }

   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
         if (board[row][col] == 0)
         {
            hasMoves = true;
         }
      }
   }

   if (!hasMoves)
   {
      return DRAW;
   }

   return CONTINUE;
}

/**
 * handles user's move
 * @return false if the game continues
 * @return true if the game is over
 */
bool TicTacToe::xoMove(int symbol)
{
   int row = -1;
   int col = -1;

   cout << endl;
   while (!validMove(row, col))
   {
      cout << YLW << "Player ";

      if (static_cast<char>(symbol) == 'X')
      {
         cout << CYN << static_cast<char>(symbol) << NC;
      }
      else
      {
         cout << BLE << static_cast<char>(symbol) << NC;
      }

      cout << YLW << " enter move: " << NC << endl;

      cin >> row >> col;

      cin.clear();
      cin.ignore(1000, '\n');

      cout << endl;
   }

   if (static_cast<char>(symbol) == 'X')
   {
      board[row][col] = 1;
   }
   else if (static_cast<char>(symbol) == 'O')
   {
      board[row][col] = -1;
   }
   printBoard();
   Status xoStatus = gameStatus();

   if (xoStatus == WIN)
   {
      cout << endl;
      cout << GRN << "Player " << static_cast<char>(symbol) << " WINS!" << NC << endl;
      cout << endl;

      return true;
   }
   else if (xoStatus == DRAW)
   {
      cout << endl;
      cout << RED << "Game is a DRAW." << NC << endl;
      cout << endl;

      return true;
   }
   else
      return false;
}