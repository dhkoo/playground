#include <iostream>

class Base {
 public:
 	Base(int value) { 
		value_ = new int();
		*value_ = value; 
		ref_ = 3;
	}
	virtual ~Base() { delete value_; }

	void printValue() {
		std::cout << *value_ << std::endl;
	}
	int* getPointer() { return value_; }
 private:
 	int* value_;
	int ref_;
};

class Derived : public Base {
 public:
  Derived(int value) : Base(value) {}
	~Derived() override {}
};

int main() {
	Derived* myclass = new Derived(3);
	myclass->printValue();
	*(myclass->getPointer()) = 5;
	myclass->printValue();

	Base bclass(2);
	Base& refClass = bclass;

}
