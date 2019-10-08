

class String {
	char * string = nullptr;
	size_t size = 0;
	size_t bufferSize = 0;

public:
	String() {};
	String(const char * newString);
	String(const String & otherString);
	String(String && otherString);
	virtual ~String();

    String operator + (const String & string) const;
	bool operator == (const String  & string) const;
	String & operator= (String && otherString);
	String & operator= (const String & otherString);

	size_t length() const;
	void clear();


};
