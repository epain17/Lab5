#pragma once

class StringItt
{
private:
	char* current;
public:
	StringItt(char* initLoc);
	~StringItt();

	bool operator != (const StringItt &rhs) const;

	StringItt& operator ++();

	StringItt& operator ++(int unused_parameter);

	StringItt& operator --();

	StringItt& operator --(int unused_parameter);

	char& operator* ();
};

