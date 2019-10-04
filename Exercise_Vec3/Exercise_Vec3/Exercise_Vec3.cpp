// Exercise_Vec3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Vec3.h"
#include <assert.h> 
int main()
{
	Vec3<int> vec1;
	Vec3<double> vecDouble;
	assert(vecDouble.x == 0.0);
	vecDouble.z = 9;
	assert(vecDouble.b == 9.);

	Vec3<int> vec2(8,7,2);
	assert(vec2.x == 8 && vec2.y == 7 && vec2.z == 2);

	vec1.x = 5;
	Vec3<int> vec3(vec1);
	assert(vec3.x == 5);

	vec1.y = 10;
	vec1.z = 12;
	assert(vec1.length() == sqrt(269));
	Vec3<int> vec1Normalized = vec1.normalize();
	assert(vec1Normalized.x <= 1 && vec1Normalized.y <= 1 && vec1Normalized.z <= 1);

	double distance = vec2.distance_to(vec1);
	assert(distance == sqrt(118));

	Vec3<int> sum = vec1 + vec3;
	assert(sum.x == 10 && sum.y == 10 && sum.z == 12);

	Vec3<int> sum2 = vec2 + 2;
	assert(sum2.x == 10. && sum2.y == 9. && sum2.z == 4.);
}
