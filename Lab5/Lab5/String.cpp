#include "stdafx.h"
#include "String.h"
#include <string>
#include<iostream>
#include <assert.h>
#include <memory.h>




String::String() :
	m_Buffer(new char[11]), m_Size(0), m_Cap(10)
{
	m_Buffer[m_Size] = 0;
}

String::~String()
{
	delete[] m_Buffer;
}

String::String(const char* cstr)
{
	m_Size = strlen(cstr);
	m_Cap = m_Size + 2;
	m_Buffer = new char[m_Cap + 1];
	memcpy(m_Buffer, cstr, m_Cap);
	m_Buffer[m_Size] = 0;


}

String::String(const String& rhs)//copy construct
	: m_Size(rhs.m_Size), m_Cap(rhs.m_Cap)
{
	m_Buffer = new char[m_Cap + 1];
	memcpy(m_Buffer, rhs.m_Buffer, m_Cap + 1);
	m_Buffer[m_Size] = 0;
}

String& String::operator=(const String& rhs)
{
	if (rhs.m_Buffer == 0)
	{
		delete[] m_Buffer;
		m_Buffer = 0;
		m_Size = 0;
		m_Cap = 0;
		return *this;
	}

	if (this != &rhs)
	{
		delete[] m_Buffer;
		m_Buffer = new char[rhs.m_Cap + 1];
		memcpy(m_Buffer, rhs.m_Buffer, m_Cap);
		m_Size = rhs.m_Size;
		m_Cap = rhs.m_Cap;
		m_Buffer[m_Size] = 0;
		assert(Invariant());

	}

	return *this;
}

String:: operator bool()
{
	if (m_Size == 0)
	{
		return false;
	}

	return true;


}

char& String::at(size_t i)
{
	if (i < 0 || i > m_Cap)
	{
		std::cout << "Out of bounds" << std::endl;
		exit(0);
	}

	else
	{
		return m_Buffer[i];
	}
}

const char& String::operator[](size_t i) const
{
	return m_Buffer[i];
}

char& String::operator[](size_t i)
{
	return m_Buffer[i];
}

const char* String::data() const
{
	return m_Buffer;
}


bool String::Invariant()
{
	if (this->m_Buffer[this->m_Size] == '\0')
	{
		return true;
	}
	else
		return false;
}

int String::size() const
{
	return m_Size;
}

void String::reserve(size_t i)
{
	assert(Invariant());

	m_Cap = i;
	char* temp = new char[m_Cap + 1];
	memcpy(temp, m_Buffer, m_Cap);
	delete[] m_Buffer;
	m_Buffer = new char[m_Cap + 1];
	memcpy(m_Buffer, temp, m_Cap);
	delete[] temp;

	m_Buffer[m_Size] = 0;
	assert(Invariant());

}

int String::capacity() const
{
	return m_Cap;
}

void String::shrink_to_fit()
{
	assert(Invariant());

	m_Cap = m_Size;
	char* temp = new char[m_Cap + 1];
	memcpy(temp, m_Buffer, m_Cap);
	delete[] m_Buffer;
	m_Buffer = new char[m_Cap + 1];
	memcpy(m_Buffer, temp, m_Cap);
	delete[] temp;
	m_Buffer[m_Size] = 0;

	assert(Invariant());

}

void String::push_back(const char c)
{
	m_Size++;
	if (m_Size > m_Cap)
	{
		m_Cap = m_Size * 1.2;
		char* temp = new char[m_Cap + 1];
		memcpy(temp, m_Buffer, m_Cap);
		delete[] m_Buffer;
		m_Buffer = new char[m_Cap + 1];
		memcpy(m_Buffer, temp, m_Cap);
		delete[] temp;
	}

	int pushPos = (m_Size - 1);
	m_Buffer[pushPos] = c;
	m_Buffer[m_Size] = 0;
	assert(Invariant());

}

void String::resize(size_t n)
{
	if (n > m_Cap)
	{
		m_Cap = n *1.2;
		char *temp = new char[m_Cap + 1];
		memcpy(temp, m_Buffer, m_Cap);
		for (size_t i = m_Size; i < m_Cap; i++)
		{
			temp[i] = char();

		}
		delete[] m_Buffer;
		m_Buffer = new char[m_Cap + 1];
		m_Size = n;
		memcpy(m_Buffer, temp, m_Cap);
		delete[] temp;
	}
	m_Buffer[m_Size] = 0;
	assert(Invariant());

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
	assert(Invariant());

	return *this;
}

std::ostream& operator<<(std::ostream& out, const String& ptr)
{
	for (size_t i = 0; i < ptr.m_Size; i++)
	{
		out << ptr.m_Buffer[i];
	}
	return out;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return!(lhs == rhs);
}

bool operator==(const String& lhs, const String& rhs)
{
	return(strcmp(lhs.m_Buffer, rhs.m_Buffer) == 0);
}