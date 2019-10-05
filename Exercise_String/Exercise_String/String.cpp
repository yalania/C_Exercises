#include "String.h"
#include <iostream>

String::String(const char * otherString) {
	const char* copyForCountingSize = otherString;
	while (*copyForCountingSize++)
	{
		size++;
	}
	bufferSize = size + 1;
	string = new char[bufferSize];
	std::memcpy(string, otherString, bufferSize);
}

String::String(const String & newString):size(newString.size), bufferSize(size + 1) {
	string = new char[bufferSize];
	std::memcpy(string, newString.string, bufferSize);
}

String::String(String && otherString) {
	*this = std::move(otherString);
}

String & String::operator= (String && otherString) {
	size = otherString.size;
	bufferSize = otherString.bufferSize;
	string = otherString.string;
	otherString.string = nullptr;
	return *this;
}

String::~String() {
	delete[] string;
}


const String String::operator + (const String  & otherString) {
	String newString;

	newString.size = size + otherString.size;
	newString.bufferSize = (bufferSize + otherString.bufferSize) - 1;
	newString.string = new char[newString.bufferSize];

	std::memcpy(newString.string, string, bufferSize - 1);
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

const size_t String::length() {
	return size;
}

void String::clear() {
	string[0] = '\0';
	size = 0;
}