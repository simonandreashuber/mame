#include "mane.h"

//private
unsigned long long int ime::m_powmod(unsigned long long int base, unsigned long long int expo, unsigned long long int devisor) const /*c20*/ /*base^expo mod devisor*/
{

	base %= devisor;
	unsigned long long int result = 1;

	while (expo > 0) {
		if (expo & 1) /*c21*/
		{
			result = (result * base) % devisor;
		}
		base = (base * base) % devisor; /*c22*/
		expo >>= 1;
	}

	return result;

	/*
	Schneier, Bruce (1996). Applied Cryptography: Protocols, Algorithms, and Source Code in C, Second Edition (2nd ed.). Wiley. ISBN 978-0-471-11709-4.
	*/
}

double ime::m_log(const double& base, const double& antilog) const /*c9*/
{
	//log with custom base
	double ret_log = log(antilog) / log(base);
	return ret_log;
}

bool ime::m_sn_se_int(unsigned long long int sn_index, const unsigned long long int& integer) const /*c10*/
{
	//sn <= interger
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

unsigned long long int ime::m_pow(const unsigned long long int& base,const unsigned long long int& expo) const /*c11*/
{
	unsigned long long int power = 1;
	for (unsigned long long int i = 0; i < expo; i++)
	{
		power = power * base;
	}
	return power;
}

unsigned long long int ime::m_sn(const unsigned long long int& sn_index) const /*c12*/
{
	unsigned long long int sn = 1;
	for (unsigned long long int n = m_s0.size() - 1; n > sn_index; n--)
	{
		sn = m_pow(m_s0[n], sn);
	}
	sn = m_pow(m_s0[sn_index], sn); /* avoid n overflow (unsigned, so no neg numbers) */
	return sn;
}

unsigned long long int ime::m_mod(unsigned long long int n, const unsigned long long int& y) const /*c5*/
{
	//if y == 0 then: integer = 0 mod 1
	if (y == 1) /*c6*/
	{
		return 0;
	}

	//if sn = smax
	if (n == m_s0.size() - 1) /*c7*/
	{
		return m_s0[n] % y;
	}

	//if sn+1 =< y
	if (m_sn_se_int(n + 1, y)) /*c8*/
	{
		return m_powmod(m_s0[n], m_sn(n + 1), y + 100); /*c13*/ //the 100 are just for savety, bacause of rounding errors
	}

	//d and td
	bool* t_register = new bool[y]; /*c15*/
	memset(t_register, 0, y);

	unsigned long long int d = 0;
	unsigned long long int td = 1;
	while (true)
	{
		if (t_register[td] == 0) /*c16*/
		{
			t_register[td] = 1;
		}
		else
		{
			delete[] t_register;
			break;
		}
		d++;
		td = (td * m_s0[n]) % y;
	}
	
	//o
	unsigned long long int o = 0;
	unsigned long long int to = 1;
	while (true)
	{
		if (to == td) /*c14*/
		{
			break;
		}

		o++;
		to = (to * m_s0[n]) % y;
	}
	
	//l
	unsigned long long int l = d - o;
	unsigned long long int mo = o % l;

	//recursion
	unsigned long long int mw = m_mod(n + 1, l);

	//mw -> tw
	unsigned long long int w;

	if (mw >= mo) /*c17*/
	{
		w = o + mw - mo; /*c18*/
	}
	else
	{
		w = d + mw - mo; /*c19*/
	}

	unsigned long long int tw = m_powmod(m_s0[n], w, y);

	return tw;
	
}

//public
ime::ime(std::vector<unsigned long long int> expo_list) /*c2*/
	: m_s0(expo_list) {}

unsigned long long int ime::mod(unsigned long long int devisor) /*c3*/
{
	return m_mod(0, devisor);
}

unsigned long long int ime::operator%(unsigned long long int devisor) /*c4*/
{
	return m_mod(0, devisor);
}
