#pragma once
#include <vector>
#include <cmath>

class ime
{
private:
	std::vector<unsigned long long int> m_s0;

	
	unsigned long long int m_powmod(unsigned long long int base, unsigned long long int expo, unsigned long long int devisor) const; //tested, range: root(base, devisor), max(expo)

	double m_log(double base, double antilog) const; //tested, range: max(base, antilog)
	
	bool m_sn_soe_int(unsigned long long int sn_index, unsigned long long int integer) const;//tested range: sn_index < m_s0.size(), max(integer, m_s0)

	unsigned long long int m_pow(unsigned long long int base, unsigned long long int expo) const; //tested, range pow < max;

	unsigned long long int m_sn(unsigned long long int sn_index) const; //tested, range: sn < max

	unsigned long long int m_mod(unsigned long long int n, unsigned long long int y) const;

public:

	ime(std::vector<unsigned long long int> expo_list);

	unsigned long long int mod(unsigned long long int devisor);

	unsigned long long int operator%(unsigned long long int devisor);

};