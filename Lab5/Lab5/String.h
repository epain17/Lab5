#pragma once
#include "StringItt.h"
#include <iostream>
class String
{

public:

	
	typedef StringItt<char>::iterator iterator;
	typedef StringItt<char>::reverse_iterator reverse_iterator;

	iterator begin() { return iterator(m_Buffer); }
	iterator end() { return iterator(m_Buffer+m_Size); }
	reverse_iterator rbegin() { return reverse_iterator(m_Buffer + m_Size); }
	reverse_iterator rend() { return reverse_iterator(m_Buffer); }
	

	char* m_Buffer; 
	int m_Size;
	int m_Cap;

	
	
	
	
	String();

	String(const String& rhs);

	String(const char* cstr);

	String& operator=(const String& rhs);

	explicit operator bool();

	char& at(size_t i);

	const char& operator[](size_t i) const;

	char& operator[](size_t i);

	const char* data() const;

	//const char* begin() const;

	//const char* end() const;

	//const char* rbegin() const;

	//const char* rend() const;

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

