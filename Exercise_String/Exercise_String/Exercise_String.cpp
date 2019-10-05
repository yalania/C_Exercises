// Exercise_String.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "String.h"
#include <assert.h>

int main()
{
	String string1("Hello");
	String string2(" world");

	assert(!(string1 == string2));

	String string3("Hello world");
	String sum = string1 + string2;
	assert(sum == string3);

	String string4(string1);
	assert(string4 == string1);

	assert(string4.length() == 5);

	string4.clear();
	assert(string4.length() == 0 && !(string4 == string1));


	
}
