#pragma once
#include <iostream>
#include <memory.h>
#include "StringItt.h"
class String
{
	char* m_Buffer; 
	int m_Size;
	int m_Cap;

public:

	// Iterator
	using iterator = StringIterator<char, 1>;
	using reverse_iterator = StringIterator<char, -1>; // reverse
	
	iterator begin() { return iterator(m_Buffer); }
	iterator end() { return iterator(m_Buffer + m_Size); }
	reverse_iterator rbegin() { return reverse_iterator(m_Buffer + m_Size - 1); }
	reverse_iterator rend() { return reverse_iterator(m_Buffer-1); }
	
	
	
	String();

	String(const String& rhs);

	String(const char* cstr);

	String& operator=(const String& rhs);

	bool Invariant();

	explicit operator bool();

	char& at(size_t i);

	const char& operator[](size_t i) const;

	char& operator[](size_t i);

	const char* data() const;

	int size() const;

	void reserve(size_t i);

	int capacity() const;

	void shrink_to_fit();

	void push_back(const char c);

	void resize(size_t n);

	String& operator+=(const String& rhs);

	friend std::ostream& operator<<(std::ostream& out, const String& prt);

	friend bool operator!=(const String& lhs, const String& rhs);

	friend bool operator==(const String& lhs, const String& rhs);

	~String();
};

