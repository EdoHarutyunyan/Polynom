#include <iostream>
#include "Polynom.h"

int main()
{
	Polynom p;
	Polynom p2;
//	Polynom p3;
	int scale{ 0 };
	double coeff{ 0.0 };

	size_t count{ 0 };
	std::cin >> count;
	for (size_t i = 0u; i < count; i++)
	{
		std::cin >> coeff >> scale;
		p.Add(coeff, scale);
	}

	p2 = p;
	//p3 = p + p2;
//	std::cout << p << std::endl;
//	std::cout << p2 << std::endl;
//	std::cout << p3 << std::endl;
	system("pause");
	return 0;
}