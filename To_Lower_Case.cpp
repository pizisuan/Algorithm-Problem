







#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>


std::string toLowerCase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}


int main()
{
	std::string test = toLowerCase("HELLO");
	std::string test2 = toLowerCase("here");
	std::string test3 = toLowerCase("LOVELY");

	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;

  return 0;
}
