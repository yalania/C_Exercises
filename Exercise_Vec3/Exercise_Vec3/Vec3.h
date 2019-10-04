
template<class T>
class Vec3 {
public:
	T x = 0;
	T y = 0;
	T z = 0;

	Vec3(){}
	Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
	Vec3(const Vec3<T> & vector) :x(vector.x), y(vector.y), z(vector.z){}

	const Vec3<T> operator+ (const Vec3<T> & vector) {
		return Vec3(vector.x + x, vector.y + y, vector.z + z);
	}

	const Vec3<T> normalize() {
		double mod = Vec3::length();
		double normalizeX = x / mod;
		double normalizeY = y / mod;
		double normalizeZ = z / mod;
		return Vec3(normalizeX, normalizeY, normalizeZ);
	}

	const double distance_to(const Vec3<T> & vector) {

		return sqrt(pow(x - vector.x, 2) + pow(y - vector.y, 2) + pow(z - vector.z, 2));
	}

	const double length() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

};