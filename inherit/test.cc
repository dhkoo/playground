#include <iostream>

class Base {
 public:
 	Base() {}
	virtual ~Base() {}

	virtual void print() = 0;
	void baseFunc() { std::cout << "!!!!!!!!!!" << std::endl; }
};

class Derived : public Base {
 public:
  Derived(int value) { value_ = value; }
	~Derived() override {}

	void print() override { std::cout << value_ << std::endl; }

 private:
  int value_;
};

class Dederived : public Derived {
 public:
 	Dederived(int value) : Derived(value) {}
	~Dederived() override {};
};

int main() {
	Base* obj = new Derived(3);
	obj->print();

	Dederived test(2);
	test.baseFunc();
}

