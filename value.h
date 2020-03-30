#ifndef VALUE_H
#define VALUE_H

class Value
{
private:
	char* var;

public:
	static unsigned int exactness;
	Value();
    Value(const char* str);
    Value(const Value& V);
	~Value();
    Value& operator=(const Value& V);

    friend Value operator+(Value d1, Value d2);
    friend Value operator-(Value d1, Value d2);
    friend Value operator*(Value d1, Value d2);
    friend Value operator/(Value d1, Value d2);
    friend Value operator^(Value d1, Value d2);
    friend Value operator-(Value d);

	Value factorial();
	Value sin();
	Value cos();
	Value tan();
	Value sqrt();

    operator const char* () const { return var; }
};

#endif  // VALUE_H
