#pragma once
#include <sstream>
#include <iostream>

class Polynom
{
	friend std::ostream& operator << (std::ostream& out, const Polynom&);

public:
	Polynom();
	~Polynom();

	//Polynom(const Polynom& o);
	//Polynom& operator=(const Polynom& other);

	void Add(const double coeff, const size_t scale);
	Polynom operator+(const Polynom& old) const;


private:

	struct Node	
	{
		Node(Node* nex = nullptr, size_t sc = 0u, double coef = 0.0)
			: m_next(nex)
			, m_scale(sc)
			, m_coeff(coef)
		{
			std::cout << "Node()" << std::endl;
		}

		Node(const Node& o)
			: m_next(o.m_next)
			, m_scale(o.m_scale)
			, m_coeff(o.m_coeff)
		{
			std::cout << "Node(copy)" << std::endl;
		}

		Node* m_next;
		size_t m_scale;
		double m_coeff;
	};

	Node* UpperBound(const size_t scale);

	Node* m_head;
};
