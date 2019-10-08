
template<class T>
class Vec3 {
public:
	union {
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { T a, b, c; };
		T vals[3];
	};

	Vec3(): x(0), y (0), z(0){}
	Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
	Vec3(const Vec3<T> & vector) :x(vector.x), y(vector.y), z(vector.z){}

	 Vec3<T> operator+ (const Vec3<T> & vector) const {
		return Vec3(vector.x + x, vector.y + y, vector.z + z);
	}

	 Vec3<T> operator+ (T value) const {
		return Vec3(x + value, y + value, z + value);
	}

	Vec3<T> normalize() const {
		double mod = Vec3::length();
		T normalizeX = x / mod;
		T normalizeY = y / mod;
		T normalizeZ = z / mod;
		return Vec3(normalizeX, normalizeY, normalizeZ);
	}

    double distance_to(const Vec3<T> & vector) const {

		return sqrt(pow(x - vector.x, 2) + pow(y - vector.y, 2) + pow(z - vector.z, 2));
	}

    double length() const {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

};