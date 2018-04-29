#include <iostream>
#include <vector>

class ime
{
private:
	std::vector<int> m_expo_list;

public:

	ime(std::vector<int> expo_list)
		: m_expo_list(expo_list)
	{}



};





int main()
{
	std::vector<int> test_vector = { 1,2,3 };
	ime test(test_vector);

	/*
	this is how the code should be useable:

	ime big_number({2,4,56,7,43,8}); //2^4^56^7^43^8
	int small_number = 756;
	int smaller_number = big_number % small_number;
	
	*/


}