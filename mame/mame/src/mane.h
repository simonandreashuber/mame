#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class ime
{
public:
	std::vector<unsigned long long int> m_s0;

	//0 depend
	unsigned long long int m_powmod(unsigned long long int base, unsigned long long int expo, unsigned long long int devisor); //tested, range: root(base, devisor), max(expo)

	double m_log(double base, double antilog); //tested, range: max(base, antilog)

	unsigned long long int m_pow(unsigned long long int base, unsigned long long int expo); //tested, range pow < max;

	//1 depend
	bool m_ime_soe_int(unsigned long long int sn_index, unsigned long long int integer);//tested range: sn_index < m_s0.size(), max(integer, m_s0)

	unsigned long long int m_sn(unsigned long long int sn_index); //tested, range: sn < max

	//multible depend
	unsigned long long int m_mw_tw(unsigned long long int n, unsigned long long int mw, unsigned long long int o, unsigned long long int d, unsigned long long int l, unsigned long long int y); //tested, range: we use m_powmod so root

	unsigned long long int m_d(unsigned long long int n, unsigned long long int y);

	unsigned long long int m_td(unsigned long long int n, unsigned long long int y);

	unsigned long long int m_o(unsigned long long int n, unsigned long long int y, unsigned long long int td);

	//main
	unsigned long long int m_mod(unsigned long long int n, unsigned long long int y);



public:

	ime(std::vector<unsigned long long int> expo_list);

	unsigned long long int mod(unsigned long long int devisor);

	unsigned long long int operator%(unsigned long long int devisor);

};