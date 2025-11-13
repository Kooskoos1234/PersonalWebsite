#include "primaryNums.h"
#include "arrayManipulation.h"

bool isPrime(std::vector<big>& primeList, big num)
{
	if (sqrt(num) <= primeList[primeList.size() - 1])
	{
		for (int i = 0; primeList[i] <= sqrt(num); i++)
		{
			if (num % primeList[i] == 0)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		std::cout << "PRIME LIST IS NOT LONG ENOUGH TO CHECK IF THIS IS A PRIME NUMBER.\n";
		return false;
	}
}

int primeNumGenerator(std::vector<big>& primeList, int totalIterations, bool runOnce)
{
	//counter for number of primes added in this execution
	int primesAdded = 0;
	//counter for iterations; used to determine when the program should ask about termination
	big curIteration = 0;

	//iterates through numbers, starting at the number one greater than the last prime number stored, and checks if it is a prime number. 
	//If it is, adds it to primes. Every countBeforeTermination iterations, ask the user whether or not to stop the program. 
	for (big i = primeList[primeList.size() - 1] + 1; i < ULLONG_MAX; i++)
	{
		if (isPrime(primeList, i))
		{
			primeList.push_back(i);
			primesAdded++;
		}
		if ((curIteration != 0 && curIteration % totalIterations == 0))
		{
			if (runOnce) {
				break;
			}
			std::cout << "kill script? Enter Y for yes, anything else for no. ";
			std::string answer;
			std::cin >> answer;
			if ((answer == "y" || answer == "Y"))
			{
				break;
			}
			else
			{
				std::cout << "Please enter the amount of iterations you would like to run before being prompted again. ";
				std::cin >> curIteration;
			}
		}
		curIteration++;
	}
	return primesAdded;
}

std::vector<big> primeFactors(std::vector<big>& primeList, big n)
{
	std::vector<big> result = {};
	while (!isPrime(primeList, n))
	{
		for (int i = 0; i < primeList.size() - 1; i++)
		{
			if (n % primeList[i] == 0)
			{
				result.push_back(primeList[i]);
				n /= primeList[i];
			}
		}
	}
	if(n != 1)
		result.push_back(n);
	std::sort(result.begin(), result.end());
	return result;
}
