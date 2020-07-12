#include <iostream>
/*
Proxy 패턴 정리
- 하나의 추상 인터페이스를 만들어 proxy의 public에 인터페이스로서 놓고,
- proxy에서는 인터페이스 구현을 원형 객체의 인터페이스를 사용함
- 원형 클래스 또한 추상 인터페이스를 상속 받았기 때문에 proxy에서 사용하는
  인터페이스와 동일한 함수가 있음

** 프록시는 같은 형태의 인터페이스를 가진 객체의 함수를 호출하는 인터페이스 제공
** 추상 인터페이스를 통해서 원형 객체 함수의 변경이 인터페이스와 무관해짐
  - 서드파티 라이브러리를 사용하는데 해당 라이브러리가 변경될 것을 예상하여
	  현재 라이브러리의 동작을 그대로 옮겨 패턴을 구현했을 때 유용
*/

class IOriginal {
	public:
		virtual void DoSomething(int value) = 0;
};

class Original : public IOriginal {
	public:
		void DoSomething(int value) {
			std::cout << "value : " << value << std::endl;
		};
};

class Proxy : public IOriginal {
	public:
		Proxy() : mOrig_(new Original()) {}
		~Proxy() {
			delete mOrig_;
		}

		void DoSomething(int value) {
			mOrig_->DoSomething(value);
		}

	private:
		Original *mOrig_;
};

int main() {

	Proxy* proxy = new Proxy();
	proxy->DoSomething(3);

	return 0;
}
