#pragma once
#include <vector>
#include <cmath>

class ime /*c00*/
{
private:
	std::vector<unsigned long long int> m_s0; /*c01*/

	unsigned long long int m_powmod(unsigned long long int base, unsigned long long int expo, unsigned long long int devisor) const; //tested, range: root(base, devisor), max(expo)

	double m_log(const double& base, const double& antilog) const; //tested, range: max(base, antilog)
	
	bool m_sn_se_int(unsigned long long int sn_index, const unsigned long long int& integer) const;//tested range: sn_index < m_s0.size(), max(integer, m_s0)

	unsigned long long int m_pow(const unsigned long long int& base, const unsigned long long int& expo) const; //tested, range pow < max;

	unsigned long long int m_sn(const unsigned long long int& sn_index) const; //tested, range: sn < max

	unsigned long long int m_mod(unsigned long long int n, const unsigned long long int& y) const; /*c5*/

public:

	ime(std::vector<unsigned long long int> expo_list); /*c2*/

	unsigned long long int mod(unsigned long long int devisor);	/*c3*/

	unsigned long long int operator%(unsigned long long int devisor); /*c4*/

};