#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template <typename T, int dir>
class StringIterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
	T* _ptr;
	int direction;
	virtual bool invariant() { return _ptr != nullptr; }

	// Constructors
	~StringIterator() { _ptr = nullptr; }
	explicit StringIterator() : direction(dir) {};
	explicit StringIterator(T* ptr) :
		_ptr(ptr), direction(dir) {
		assert(invariant());
	}

	// Operators Gör om så att *ptr inte används, vill peka på platsen inte innehållet!
	virtual bool operator==(const StringIterator& rhs) { assert(invariant()); return _ptr == rhs._ptr; }
	virtual bool operator!=(const StringIterator& rhs) { assert(invariant()); return _ptr != rhs._ptr; }
	virtual T& operator*() { assert(invariant()); return *_ptr; }
	virtual T* operator->() { assert(invariant()); return _ptr; }
	virtual T& operator[](int i) { assert(invariant()); return *(_ptr + (i * direction)); }

	virtual StringIterator operator=(StringIterator rhs) { _ptr = rhs._ptr; assert(invariant()); return *this; }
	virtual StringIterator operator+(int i) { assert(invariant()); return StringIterator(_ptr + (i * direction)); }
	virtual StringIterator operator++(int) { assert(invariant()); StringIterator i = *this; _ptr += direction; return i; }
	virtual StringIterator operator++() { assert(invariant()); _ptr += direction; return *this; }

	virtual bool operator<(const StringIterator& rhs) { assert(invariant()); return _ptr < rhs._ptr; }
	virtual int operator-(StringIterator rhs) { assert(invariant()); int i = _ptr - rhs._ptr; return i; }
	virtual int operator+=(int rhs) { assert(invariant()); int i = _ptr + rhs; return i; }
	virtual StringIterator operator--() { assert(invariant()); _ptr -= direction; return *this; }
};