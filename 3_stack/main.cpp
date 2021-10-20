// CSC340
// Assignment 3.3
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/** @file main.cpp */

#include <iostream>
#include <string>
#include <sstream>

#include "ArrayStack.h"
using namespace std;

// Array for testing isPalindrome
string test_arr[41] = {"Sunny Cove",
                       "Willow Cove",
                       "Golden Cove",
                       "Ocean Cove",
                       "A but tuba.",
                       "A car, a man, a maraca.",
                       "A dog, a plan, a canal: pagoda.",
                       "A dog! sA panic in a pagoda!",
                       "A lad named E. Mandala",
                       "A man, a plan, a canal: Panama.",
                       "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                       "A new ordfer began, a more Roman age bred Rowena.",
                       "A nut for fa jar of tuna.",
                       "A Santa at gNasa.",
                       "A Santa dog lived as a devil God at NASA.",
                       "A tin mug forh a jar of gum, Nita.",
                       "A Toyota! Race fast, safe car! A Toyota!",
                       "A Toyota’s a Tjoyota.",
                       "Able was I ere I saw Elba.",
                       "Acrobats stab osrca.",
                       "Aerate pet area.",
                       "Ah, Satan seess Natasha!",
                       "Aibohphobia (fear of palindromes)",
                       "Air an arisa.",
                       "Al lets Della call Ed Stella.",
                       "alula",
                       "Amen icy cinema.",
                       "Amore, Roma.",
                       "Amy, must Is jujitsu my ma?",
                       "Ana",
                       "Animal loots foliated detail of stool lamina.",
                       "Anna",
                       "Anne, rI vote more cars race Rome to Vienna.",
                       "Are Mac ‘n’ Oliver ever evil on camera?",
                       "Are we rnot drawn onward to new era?",
                       "Are we not drawn onward, we few, drawn onward to new era?",
                       "Are we n5ot pure? “No sir!” Panama’s moody Noriega brags. “It is garbage!” Irony dooms a man; a prisoner up to new era.",
                       "Art, name6 no tub time. Emit but one mantra",
                       "As I pee, sir, I see Pisa!",
                       "Avid div7a."};

// Array for testing Revrse function
string test_arr_reverse[8] = {
    "Sunny Cove",
    "A car a man a maraca",
    "dog  plan canal pagoda",
    "A lad named E Mandala",
    "A nut for jar of tuna",
    "A Santa at Nasa",
    "A Santa dog lived at NASA",
    "Race fast safe car",
};

// keep only alphanunerical values in the string
string normalizeString(string str)
{
    string string;

    for (int i = 0; i <= (int)str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            string += (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + 32) : str[i];
        }
    }
    return string;
}

// returns true if the string is palindrome
// otherwise returns false
bool isPalindrome(string s)
{
    if (s.size() == 0)
    {
        return false;
    }
    if (s.size() == 1)
    {
        return true;
    }
    string str = normalizeString(s);
    int length = str.size();

    StackInterface<char> *stack1 = new ArrayStack<char>();
    StackInterface<char> *stack2 = new ArrayStack<char>();

    for (int i = 0; i < length; i++)
    {
        stack1->push(str[i]);
        stack2->push(str[length - i - 1]);
    }

    for (int i = 0; i < length; i++)
    {
        if (stack1->peek() != stack2->peek())
        {
            delete stack1;
            delete stack2;
            return false;
        }
    }

    delete stack1;
    delete stack2;

    return true;
}

int main(int ac, char **av)
{

    // testing isPalindrome function
    if (ac == 2 && strcmp(av[1], "--palindrome") == 0)
    {
        int i = 0;
        while (i <= (int)(sizeof(test_arr) / sizeof(test_arr[0])))
        {
            cout << "\033[34mTest string #" << i + 1 << "\033[0m" << endl;

            if (isPalindrome(test_arr[i]))
            {
                cout << "Explanation: \"" << test_arr[i] << "\" ";
                cout << "\033[32mis a palindrome.\033[0m" << endl;
            }
            else
            {
                cout << "Explanation: \"" << test_arr[i] << "\" ";
                cout << "\033[31mis not a palindrome.\033[0m" << endl;
            }
            cout << endl;
            i++;
        }
    } // end if

    // testing the reverse string with user's input
    else if (ac == 2 && strcmp(av[1], "--reverse") == 0)
    {

        const char *prompt = "Enter a string: ";
        string input;
        StackInterface<string> *stack = new ArrayStack<string>();
        string str;

        cout << prompt << endl;
        while (!cin)
        {
            cout << prompt << endl;
        }
        getline(cin, input);

        if (input.length() == 0)
        {
            cout << "\033[32mYour string is EMPTY! " << endl;
            return 0;
        }

        istringstream streamStr(input);

        cout << "\033[32mYour string is: " << endl;

        while (streamStr.good())
        {
            streamStr >> str;
            stack->push(str);
            cout << stack->peek() << " ";
        }
        cout << "\033[0m" << endl;

        cout << "\033[34mThe reverse string is: " << endl;

        while (!stack->isEmpty())
        {
            cout << stack->peek() << " ";
            stack->pop();
        }
        cout << "\033[0m" << endl;
        cout << endl;
        delete stack;
    } // end if

    // testing the reverse string with preset array
    else if (ac == 2 && strcmp(av[1], "--reverse-test") == 0)
    {
        StackInterface<string> *stack = new ArrayStack<string>();
        string str;

        int i = 0;

        while (i < (int)(sizeof(test_arr_reverse) / sizeof(test_arr_reverse[0])))
        {
            istringstream streamStr(test_arr_reverse[i]);

            cout << "\033[32mTest string #" << i + 1 << " is: " << endl;

            while (!streamStr.eof())
            {
                streamStr >> str;
                stack->push(str);

                cout << stack->peek() << " ";
            }
            cout << "\033[0m" << endl;

            cout << "\033[34mThe reverse string is: " << endl;

            while (!stack->isEmpty())
            {
                cout << stack->peek() << " ";
                stack->pop();
            }
            cout << "\033[0m" << endl;
            cout << endl;

            i++;
        }
        delete stack;
    } // if

    // otherwise testing isPalindrome with user's input
    else
    {
        const char *prompt = "Enter a string: ";
        string input;

        cout << prompt << endl;
        while (!cin)
        {
            cout << prompt << endl;
        }
        getline(cin, input);

        if (isPalindrome(input))
        {
            cout << "Explanation: \"" << input << "\" ";
            cout << "\033[32mis a palindrome.\033[0m" << endl;
        }
        else
        {
            cout << "Explanation: \"" << input << "\" ";
            cout << "\033[31mis not a palindrome.\033[0m" << endl;
        }
    }

    return 0;
}