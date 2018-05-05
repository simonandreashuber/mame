#include <iostream>
#include "mane.h"


unsigned long long int powmod(unsigned long long  base, unsigned long long int expo, unsigned long long int devisor) //testing
{
	base %= devisor;
	unsigned long long int result = 1;

	while (expo > 0) {
		if (expo & 1)
		{
			result = (result * base) % devisor;
		}
		base = (base * base) % devisor;
		expo >>= 1;
	}

	return result;

	/*
	Schneier, Bruce (1996). Applied Cryptography: Protocols, Algorithms, and Source Code in C, Second Edition (2nd ed.). Wiley. ISBN 978-0-471-11709-4.
	*/
}

bool primetest_bruteforce(unsigned long long int integer)
{

	if (integer % 2 == 0)
	{
		return false;
	}

	if (integer % 3 == 0)
	{
		return false;
	}

	unsigned long long int i = 5;
	while (i*i <= integer)
	{
		if (integer % i == 0 || integer % (i + 2) == 0)
		{
			return false;
		}
		i = i + 6;
	}

	return true;

	/*
	neg:
	bad for huge numbers
	poss:
	simple
	not probabilistic
	*/
}

int main()
{
	//testing
	std::vector<unsigned long long int> test_expo_list = { 10,10,10,10,10,10,10,10,10,10 };
	std::vector<unsigned long long int> test_expo_list_fermat = { 10,10,10,10,10,10,10,10,10 };
	ime test_ime(test_expo_list);
	ime test_ime_fermat(test_expo_list_fermat);


	std::cout << ((test_ime % 1807) + 23) % 1807 << std::endl;

	for (unsigned long long int i = 13; i < 10000000; i++)
	{
		if (primetest_bruteforce(i))
		{
			if (((test_ime % i) + 23)  % i == 0) /* raw */
			{
				std::cout << i << std::endl;
			}
			if ((powmod(10, test_ime_fermat % (i - 1), i) + 23) % i == 0) /* fermat */
			{
				std::cout << i << std::endl;
				/*
				unsigned long long int i_pow = i * i;
				unsigned long long int pow = 2;
				while (((test_ime % i_pow) + 23) % i_pow == 0)
				{
					i_pow = i_pow * i;
					pow++;
				}
				pow--;
				std::cout << "power: " << pow << std::endl;
				*/
			}
		}
	}

	//testing 

	system("pause");
}