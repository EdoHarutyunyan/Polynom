#include "Polynom.h"
#include <iostream>
#include <cassert>
#include <cmath>

Polynom::Polynom()
	: m_head(new Node)
{
	std::cout << "Polynom()" << std::endl;
}


Polynom::~Polynom()
{
	std::cout << "~Polynom()" << std::endl;
}

//Polynom::Polynom(const Polynom& o)
//	: m_head(o.m_head)
//{
//	std::cout << "Polynom(copy)" << std::endl;
//}

//Polynom& Polynom::operator=(const Polynom& other)
//{
//	std::cout << "Polynom(assign)" << std::endl;
//	if (this == &other)
//	{
//		return *this;
//	}
//
//	Polynom tmp(other);
//	std::swap(*this, tmp);
//
//	return *this;
//}

void Polynom::Add(const double coeff, const size_t scale)
{
	Node* insertNode = UpperBound(scale);

	if (insertNode->m_scale == scale)
	{
		insertNode->m_coeff += coeff;
		return;
	}

	Node* newNode = new Node{ insertNode->m_next, scale, coeff };

	insertNode->m_next = newNode;
}

Polynom Polynom::operator+(const Polynom& old) const
{
	Polynom pol;

	pol.m_head->m_coeff = m_head->m_coeff + old.m_head->m_coeff;
	pol.m_head->m_scale = m_head->m_scale + old.m_head->m_scale;
	
	return pol;
}

Polynom::Node* Polynom::UpperBound(const size_t scale)
{
	assert(m_head != nullptr);
	Node* current = m_head;

	while (current->m_next != nullptr && current->m_next->m_scale >= scale)
	{
		current = current->m_next;
	}

	assert(current != nullptr);
	return current;
}


std::ostream& operator << (std::ostream& out, const Polynom& polynom)
{
	Polynom::Node* current = polynom.m_head->m_next;

	out << current->m_coeff << "X^" << current->m_scale;
	current = current->m_next;

	while (current != nullptr)
	{
		if (current != nullptr)
		{
			if (current->m_coeff > 0.0)
			{
				out << " + ";
			}
			else
			{
				out << " - ";
			}
		}
		if (const double coeff = fabs(current->m_coeff); coeff != 1)
		{
			out << coeff << "X^" << current->m_scale;
		}
		else
		{
			out << "X^" << current->m_scale;
		}

		current = current->m_next;
	}

	return out;
}
