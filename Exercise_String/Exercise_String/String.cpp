#include "String.h"

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

String::String(const String & newString){
	*this = newString;
}

String::String(String && otherString) {
	*this = std::move(otherString);
}

String & String::operator= (String && otherString) {
	size = otherString.size;
	bufferSize = otherString.bufferSize;
	string = otherString.string;
	otherString.string = nullptr;
	otherString.bufferSize = 0;
	otherString.size = 0;
	return *this;
}
String & String::operator= (const String & otherString) {
	size = otherString.size;
	bufferSize = otherString.bufferSize;
	string = new char[bufferSize];
	std::memcpy(string, otherString.string, bufferSize);
	return *this;
}

String::~String() {
	delete[] string;
}


String String::operator + (const String  & otherString) const{
	String newString;

	newString.size = size + otherString.size;
	newString.bufferSize = size + 1;
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

bool String::operator == (const String & otherString) const{

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

 size_t String::length() const{
	return size;
}

void String::clear() {
	size = 0;
}
