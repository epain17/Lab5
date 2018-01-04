#include "stdafx.h"
#include "String.h"
#include <string>
#include<iostream>



String::String() :
	m_Buffer(""), m_Size(0)
{
	
	
	
}


String::~String()
{
	delete[] m_Buffer;
}

String::String(const char* cstr)
{
	m_Size = strlen(cstr);
	m_Buffer = new char[m_Size + 1];
	memcpy(m_Buffer, cstr, m_Size);
	m_Buffer[m_Size] = 0;


}

String::String(const String& rhs)//copy construct
	: m_Size(rhs.m_Size)
{
	m_Buffer = new char[m_Size + 1];
	memcpy(m_Buffer, rhs.m_Buffer, m_Size + 1);
}


String& String::operator=(const String& rhs)
{
	if (rhs.m_Buffer == 0)
	{
		delete[] m_Buffer;
		m_Buffer = 0;
		m_Size = 0;
		return *this;
	}

	if (this != &rhs)
	{
		delete[] m_Buffer;
		m_Buffer = new char[rhs.m_Size + 1];
		memcpy(m_Buffer, rhs.m_Buffer, m_Size);
		m_Size = rhs.m_Size;
		m_Buffer[m_Size] = 0;
	}

	return *this;
}

String:: operator bool()
{
	return m_Buffer != "";
}

char& String::at(size_t i)
{
	if (i < 0 || i >= m_Size)
	{
		std::cout << "Out of bounds" << std::endl;
		exit(0);
	}

	else
	{
		return m_Buffer[i];
	}
}

 char& String::operator[](int i) const
{
	return m_Buffer[i];
}

const char* String::data() const
{
	return m_Buffer;
}

int String::size() const
{
	return m_Size;
}

void String::reserve(size_t)
{

}

int String::capacity() const
{
	return m_Size;
}

void String::shrink_to_fit()
{

}

void String::push_back(const char c)
{
	m_Size++;
	int pushPos = (m_Size - 1);
	m_Buffer[pushPos] = c;

	
}

void String::resize(size_t n)
{

}

String& String::operator+=(const String& rhs)
{
	char** temp = &m_Buffer;
	*temp = new char[m_Size];
	strcpy_s(m_Buffer, m_Size, *temp);
	strcat_s(m_Buffer, m_Size, rhs.m_Buffer);

	if (m_Size != 0)
	{
		delete[] temp;

	}

	m_Size = strlen(m_Buffer);
	return *this;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return!(lhs == rhs);
}

bool operator==(const String& lhs, const String& rhs)
{
	return(strcmp(lhs.m_Buffer, rhs.m_Buffer) == 0);
}