#include <iostream>
#include <vector>
#include <cmath>

class ime
{
private:
	std::vector<int> m_s0;
	
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

	bool m_sn_bigeq_y(size_t n_start, int o)/*not approved*/ const
	{
		// sn >= o
		double o_log = o;
		for (size_t n = n_start; n < m_s0.size(); o_log = m_log(m_s0[n], o_log), n++)
		{
			if (m_s0[n] >= (int)o_log + 1)
			{
				return true;
			}
		}
		return false;
	}

	int m_mod(const int& y, size_t n)/*not approved*/ const
	{
		if (m_sn_bigeq_y(n + 1, y) == false)
		{
			int mw_iteratior = 1;
			for (size_t n_iterator = m_s0.size() - 1; n_iterator >= n; n_iterator--)
			{
			//not finished
			}

		}

		bool* t_register = new bool[y];
		memset(t_register, false, y);

		int td = 1;
		int d = 0;
		while (true)
		{
			td = (td * m_s0[n]) % y;
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
					to = (to * m_s0[n]) % y;
					o++;

					if (to == td)
					{
						int l = d - o;
						int  mw = m_mod(l, n++);
						//mw -> tw
					}
				}

			}
		}
	}

public:

	ime(std::vector<int> expo_list)
		: m_s0(expo_list){}
	
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