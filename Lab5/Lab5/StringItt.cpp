#include "stdafx.h"
#include "StringItt.h"


StringItt::StringItt(char* initLoc)
{
	current = initLoc;
}

bool StringItt::operator!=(const StringItt &rhs) const
{
	return this->current != rhs.current;
}

StringItt& StringItt::operator++()
{
	current++;
	return *this;
}

StringItt& StringItt::operator++(int unused_parameter)
{
	current++;
	return *this;
}

StringItt& StringItt::operator--()
{
	current--;
	return *this;
}

StringItt& StringItt::operator--(int unused_parameter)
{
	current--;
	return *this;
}


char& StringItt::operator*()
{
	return *current;
}

StringItt::~StringItt()
{
}
