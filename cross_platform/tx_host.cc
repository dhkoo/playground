#include <iostream>

class TxHost {
	public:
		class TxHostDetail {
			public:
				TxHostDetail() {};
				virtual ~TxHostDetail() {};
				virtual void funcDetail() = 0;
		};
		TxHost();
		~TxHost() { delete host_; }
		void func() {
			std::cout << "func" << std::endl;
			host_->funcDetail();
		}

	private:
		TxHostDetail* host_;
};

class TxHostPOSIX : public TxHost::TxHostDetail {
	public:
		TxHostPOSIX() {};
		~TxHostPOSIX() {};
		
		void funcDetail() {
			std::cout << "funcDetail" << std::endl;
		}
	private:
		void funcInPrivate() {
			std::cout << "funcDetail in private" << std::endl;
		}
};

TxHost::TxHost() : host_(new TxHostPOSIX()) {}

int main() {
  TxHost* host = new TxHost();
  host->func();
}
