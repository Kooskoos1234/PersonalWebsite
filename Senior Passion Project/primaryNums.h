#ifndef primaryNums_H
#define primaryNums_H

typedef unsigned long long int big;

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

/*
FUNCTIONAL.At least seemingly, initially.I hope.Maybe.Probably.Send help.Please.
note: not a working template at the moment, because the typecast is STRICTLY LONG LONG INTS. (bigs). if i find a typecast function i'll use it :3
*/
template <typename T> std::vector<T> readCSV(std::fstream* stream)
{
	stream->seekp(0);
	//initializes this vector; it will be returned at the end of the function.
	std::vector<T> valueArray;
	//checks if the stream has a file open; if so, continue; otherwise, tell the user as such and abort the function
	if (!stream->is_open())
	{
		std::cout << "failed to open file" << '\n';
		return { 0 };
	}
	else
	{
		//stores the entire file the stream is linked to as one string
		std::string file;
		*stream >> file;

		//parses the large string read prior as individual string elements in a vector
		std::vector<std::string> strElements;
		long long int elementCount = 1;
		strElements.push_back("");
		long long int n = 0;
		for (int i = 0; i < file.size(); i++)
		{
			if (file[i] == ',')
			{
				strElements.push_back("");
				n++;
			}
			else
				strElements[n].push_back(file[i]);
		}

		//converts the string elements of the above vector into long long ints
		for (int i = 0; i < strElements.size(); i++) {
			valueArray.push_back(std::stol(strElements[i]));
		}
	}
	return valueArray;
}

/*
FUNCTIONAL.At least seemingly, initially.I hope.Maybe.Probably.Send help.Please.
note: this IS a functional template, however reads will not work if data contains a comma(as in some strings), would need to be updated to write literals in ""
*/
template <typename T> void writeCSV(std::fstream* stream, std::vector<T> vec)
{
	if (!stream->is_open())
		std::cout << "failed to open file" << '\n';
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			*stream << vec[i] << (i == vec.size() - 1 ? "" : ",");
		}
	}
}

/*
enter a list of prime numbers, and a number.If the largest number in the list is less than the square root of the provided number,
checks if the provided number is prime and returns the result as a boolean.Otherwise, prints a message and returns false.
*/
bool isPrime(std::vector<big>& primeList, big num);

/*
generates a list of prime numbers, between the last number provided in primeList, and that number + totalIterations.
This can be used to generate any list for each all new numbers are succeeding numbers that are not divisible by any numbers in the provided list.
This use, however, is not particularly useful; it's intended to generate prime numbers.
*/
int primeNumGenerator(std::vector<big>& primeList, int totalIterations, bool runOnce);

/*
Gets the prime factors of a number less than or equal to primeList[primeList.size() - 1] ^ 2
The domain of the function is x <= primeList[primeList.size()-1]^2
*/
std::vector<big> primeFactors(std::vector<big>& primeList, big n);

#endif