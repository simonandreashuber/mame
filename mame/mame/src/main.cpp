#include <iostream>
#include <vector>
#include <cmath>

class ime
{
private:
	std::vector<int> m_expo_list;
	
	int m_powmod(int base,int expo,int devisor) const
	{
		base %= devisor;
		int result = 1;

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

	double m_log(double base, double antilogarithm) const
	{
		return log(antilogarithm) / log(base);
	}

	int m_mod(const int& y, size_t expo_stage) const
	{
		/*check if sn+1 >= y >= o
		double  y_comp = y;
		for (size_t expo_stage_comp = expo_stage + 1; expo_stage_comp < m_expo_list.size(); expo_stage_comp++, y_comp = m_log(m_expo_list[expo_stage_comp], y_comp))
		{
			if (m_expo_list[expo_stage_comp] >= (int)y_comp + 1)
			{
				return powmod();
			}
		}
		*/

		bool* t_register = new bool[y];
		memset(t_register, false, y);

		int td = 1;
		int d = 0;
		while (true)
		{
			td = (td * m_expo_list[expo_stage]) % y;
			d++;

			if (t_register[td] == false)
			{
				t_register[td] = true;
			}
			else
			{
				delete[] t_register;

				int to = 1;
				int o = 0;
				while (true)
				{
					to = (to * m_expo_list[expo_stage]) % y;
					o++;

					if (to == td)
					{
						int l = d - o;
						int  mw = m_mod(l, expo_stage++);
						//mw -> tw
					}
				}

			}
		}
	}

public:

	ime(std::vector<int> expo_list)
		: m_expo_list(expo_list){}
	
	int mod(const int& devisor) const
	{
		return m_mod(devisor, 0);
	}

	int operator%(const int& devisor) const
	{
		//return m_mod(devisor, 0);
		return 42;
	}
};

int powmod(int base, int expo, int devisor) //testing
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

int main()
{
	//testing 
	int test_int = 13;
	int test_int_fermat = 12;
	std::vector<int> test_expo_list = {2,2,2,2};
	std::vector<int> test_expo_list_fermat = {2,2,2};
	ime test_ime(test_expo_list);
	ime test_ime_fermat(test_expo_list_fermat);

	std::cout << test_ime % test_int <<  std::endl;
	std::cout << powmod(2, test_ime_fermat % test_int_fermat, test_int) << std::endl;



	/*
	this is how the code should be useable:

	ime big_number({2,4,56,7,43,8}); //2^4^56^7^43^8
	int small_number = 756;
	int smaller_number = big_number % small_number;
	
	*/
	system("pause");

}