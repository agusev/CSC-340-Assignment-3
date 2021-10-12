// CSC340
// Assignment 3.1
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

/**
 * This program determines whether a string is palindrome or not, 
 * considering only alphanumeric characters and ignoring cases. 
 * 
 * to compile:
 * g++ AleksandrGusev-Assignment-03_1.cpp -Wall -Werror -Wextra
 * or
 * g++ AleksandrGusev-Assignment-03_1.cpp -Wall -Werror -Wextra
 * or to test
 * g++ AleksandrGusev-Assignment-03_1.cpp ---test
 * then
 * ./a.out
*/

#include <iostream>
#include <string>
using namespace std;

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
					   "A slut nixesy sex in Tulsa.",
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

bool ispalindrome(string str)
{
	if (str.length() == 0)
	{
		return false;
	}
	if (str.length() == 1)
	{
		return true;
	}

	int start = 0;
	int end = str.length() - 1;
	while (start < end)
	{
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}

	return true;
}

void start(string input)
{
	bool res = false;

	cout << "\nInput: s = \"" << input << "\"" << endl;

	input = normalizeString(input);
	res = ispalindrome(input);

	cout << "Output: " << boolalpha << res << endl;
	if (input.length() == 0)
	{
		cout << "Explanation: \033[31mEMPTY STRING \033[0m";
	}
	else
	{
		cout << "Explanation: \"" << input << "\" ";
	}

	if (res)
	{
		cout << "\033[32mis a palindrome.\033[0m" << endl;
		cout << "\033[5;2;32m";

		for (int i = 0; i <= (int)input.length() + 35; i++)
		{
			cout << "*";
		}
		cout << "\033[0m" << endl;
	}
	else
	{
		cout << "\033[31mis not a palindrome.\033[0m" << endl;
		cout << "\033[5;2;31m";

		for (int i = 0; i <= (int)input.length() + 35; i++)
		{
			cout << "*";
		}
		cout << "\033[0m" << endl;
	}
}

int main(int ac, char **av)
{

	if (ac == 2 && strcmp(av[1], "--test") == 0)
	{
		int i = 0;
		while (i++ < (int)(sizeof(test_arr) / sizeof(test_arr[0])))
		{
			cout << "\033[34mTest string #" << i + 1 << "\033[0m";

			start(test_arr[i]);
			cout << endl;
		}
	}
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

		start(input);
	}

	return 0;
}
