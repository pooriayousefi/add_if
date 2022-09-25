
#include "add_if.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <stdexcept>

// entry point
auto main()->int
{
	try
	{
		// add test
		std::vector<int> data_1{ -1, 9, 0, 3, 4, 2, 2, 4, 5, -3, 0, -2 };
		auto sum_1{ add(data_1.begin(), data_1.end()) };
		auto evens_sum_1{ add_if(data_1.begin(), data_1.end(), [](auto val) { return ((val % 2) == 0); }) };
		auto odds_sum_1{ add_if(data_1.begin(), data_1.end(), [](const int & val)->bool { return ((val % 2) != 0); }) };
		auto positives_sum_1{ add_if(data_1.begin(), data_1.end(), [](auto& val) { return val > 0; }) };
		auto negatives_sum_1{ add_if(data_1.begin(), data_1.end(), [](auto & val) { return val < 0; }) };
		//auto strings_sum_1{ add_if(data_1.begin(), data_1.end(), [](auto & val) { return std::to_string(val); }) };
		std::cout
			<< "\n\tsum: " << sum_1
			<< "\n\tevens sum: " << evens_sum_1
			<< "\n\todds sum: " << odds_sum_1
			<< "\n\tpositives sum: " << positives_sum_1
			<< "\n\tnegatives sum: " << negatives_sum_1
			/*<< "\n\tstrings sum: " << strings_sum_1*/
			<< '\n';
		
		return EXIT_SUCCESS;
	}
	catch (const std::exception & xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}
