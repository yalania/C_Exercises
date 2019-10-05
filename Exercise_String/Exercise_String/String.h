

class String {
	char * string = nullptr;
	size_t size = 0;

public:
	String() {};
	String(const char * newString);
	String(const String & newString);
	~String();

	String operator + (const String & string);
	const bool operator == (const String  & string);

	size_t length();
	void clear();


};
