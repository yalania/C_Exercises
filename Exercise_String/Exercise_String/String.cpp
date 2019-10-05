#include "String.h"

String::String(const char * newString) {
	const char* copyForCountingSize = newString;
	while (*copyForCountingSize++)
	{
		size++;
	}

	string = new char[size + 1];
	for (size_t i = 0; i <= size ; i++)
	{
		string[i] = *newString++;
	}
}

String::~String() {
	delete[] string;
}

String::String(const String & newString):size(newString.size) {
	string = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		string[i] = newString.string[i];
	}
}

String String::operator + (String const & otherString) {
	String newString;

	newString.size = size + otherString.size;
	newString.string = new char[newString.size + 1];

	for (size_t i = 0; i < size; i++)
	{
		newString.string[i] = string[i];
	}
	int j = size;
	for (size_t i = 0; i <= otherString.size; i++)
	{
		newString.string[j] = otherString.string[i];
		j++;
	}

	return newString;
}

const bool String::operator == (const String & otherString) {

	if (size == otherString.size) {
		for (size_t i = 0; i <= size; i++)
		{
			if (otherString.string[i] != string[i]) {
				return false;
			}
		}
	} else {
		return false;
	}

	return true;
}

size_t String::length() {
	return size;
}

void String::clear() {
	string[0] = '\0';
	size = 0;
}