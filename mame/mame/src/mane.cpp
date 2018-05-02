#include "mane.h"

//private
//private 0 depend
unsigned long long int ime::m_powmod(unsigned long long int base, unsigned long long int expo, unsigned long long int devisor)
{
	unsigned long long int base_mod = base % devisor;
	unsigned long long int general_prod = 1;

	while (expo > 0)
	{
		unsigned long long int partial_prod = base_mod;
		unsigned long long int power_subtrahend = 1;

		while (expo >= power_subtrahend << 1)
		{
			partial_prod = (partial_prod*partial_prod) % devisor;
			power_subtrahend = power_subtrahend << 1;
		}
		general_prod = (partial_prod*general_prod) % devisor;
		expo = expo - power_subtrahend;
	}

	return general_prod;
}

double ime::m_log(double base, double antilog)
{
	double ret_log = log(antilog) / log(base);
	return ret_log;
}

unsigned long long int ime::m_pow(unsigned long long int base, unsigned long long int expo)
{
	unsigned long long int power = 1;
	for (unsigned long long int i = 0; i < expo; i++)
	{
		power = power * base;
	}
	return power;
}

//private 1 depend
bool ime::m_ime_soe_int(unsigned long long int sn_index, unsigned long long int integer)
{
	double int_log = integer;
	while (sn_index < m_s0.size())
	{
		if ((double)m_s0[sn_index] > int_log)
		{
			return false;
		}
		int_log = m_log(m_s0[sn_index], int_log);
		sn_index++;
	}
	return true;
}

unsigned long long int ime::m_sn(unsigned long long int sn_index)
{
	unsigned long long int sn = 1;
	for (unsigned long long int n = m_s0.size() - 1; n > sn_index; n--)
	{
		sn = m_pow(m_s0[n], sn);
	}
	sn = m_pow(m_s0[sn_index], sn); // avoid unsigned overflow/neg. numbers
	return sn;
}

//private multible depend
unsigned long long int ime::m_mw_tw(unsigned long long int n, unsigned long long int mw, unsigned long long int o, unsigned long long int d, unsigned long long int l, unsigned long long int y)
{
	for (unsigned long long int w = o; w < d; w++)
	{
		if (mw == w % l)
		{
			unsigned long long int tw = m_powmod(m_s0[n], w, y);
			return tw;
		}
	}
}

unsigned long long int ime::m_d(unsigned long long int n, unsigned long long int y)
{
	if (y == 1)
	{
		return 1;
	}

	bool* t_register = new bool[y];
	memset(t_register, 0, y);

	unsigned long long int d = 0;
	unsigned long long int td = 1;
	while (true)
	{
		if (t_register[td] == 0)
		{
			t_register[td] = 1;
		}
		else
		{
			delete[] t_register;
			return d;
		}
		d++;
		td = (td * m_s0[n]) % y;
	}
}

unsigned long long int ime::m_td(unsigned long long int n, unsigned long long int y)
{
	bool* t_register = new bool[y];
	memset(t_register, 0, y);

	unsigned long long int d = 0;
	unsigned long long int td = 1;
	while (true)
	{
		if (t_register[td] == 0)
		{
			t_register[td] = 1;
		}
		else
		{
			delete[] t_register;
			return td;
		}
		d++;
		td = (td * m_s0[n]) % y;
	}
}

unsigned long long int ime::m_o(unsigned long long int n, unsigned long long int y, unsigned long long int td)
{

	unsigned long long int o = 0;
	unsigned long long int to = 1;
	while (true)
	{
		if (to == td)
		{
			return o;
		}

		o++;
		to = (to * m_s0[n]) % y;
	}
}

//main
unsigned long long int ime::m_mod(unsigned long long int n, unsigned long long int y)
{
	//error: n > n_max
	if (n > m_s0.size() - 1)
	{
		std::cout << "n > n_max" << std::endl;
		return 0;
	}
	//if sn = smax
	if (n == m_s0.size() - 1)
	{
		return m_s0[n] % y;
	}

	//if y == 0 then integer = 0 mod 1
	if (y == 1)
	{
		return 0;
	}


	//if sn+1 =< y
	if (m_ime_soe_int(n + 1, y))
	{
		return m_powmod(m_s0[n], m_sn(n + 1), y);
	}

	unsigned long long int d = m_d(n, y);
	unsigned long long int td = m_td(n, y);
	unsigned long long int o = m_o(n, y, td);
	unsigned long long int l = d - o;

	unsigned long long int mw = m_mod(n + 1, l);

	unsigned long long int tw = m_mw_tw(n, mw, o, d, l, y);

	return tw;

}

//public
ime::ime(std::vector<unsigned long long int> expo_list)
	: m_s0(expo_list) {}

unsigned long long int ime::mod(unsigned long long int devisor)
{
	return m_mod(0, devisor);
}

unsigned long long int ime::operator%(unsigned long long int devisor)
{
	return m_mod(0, devisor);
}

