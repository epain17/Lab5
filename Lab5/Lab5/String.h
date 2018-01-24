#pragma once
class String
{


public:
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

	const char* begin() const;

	const char* end() const;

	const char* rbegin() const;

	const char* rend() const;

	int size() const;

	void reserve(size_t i);

	int capacity() const;

	void shrink_to_fit();

	void push_back(const char c);

	void resize(size_t n);

	String& operator+=(const String& rhs);

	friend bool operator!=(const String& lhs, const String& rhs);

	friend bool operator==(const String& lhs, const String& rhs);
	~String();
};

