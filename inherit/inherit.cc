#include <iostream>

class RxTask;

class Task {
 public:
 	virtual ~Task() {};
	virtual void print() = 0;
	virtual RxTask* getRxTask() = 0;
};
class RxTaskPlatform {
 public:
 	virtual ~RxTaskPlatform() {}
	virtual void print() = 0;
};

class RxTask : public Task {
 public:
 	RxTask();
 	~RxTask() override {}
	void print() override {
		std::cout << "print From RxTask!" << std::endl;
		impl_->print();
	}
	
	RxTask* getRxTask() override { 
		std::cout << "getRxTask From RxTask!" << std::endl;
		return this; 
	}

	private:
		std::unique_ptr<RxTaskPlatform> impl_;
};

class RxTaskX11 : public RxTaskPlatform {
 public:
	RxTaskX11() {}
 	~RxTaskX11() override {}
	void print() override {
		std::cout << "From RxTaskX11!" << std::endl;
	}
};

RxTask::RxTask() : impl_(std::move(new RxTaskX11())) {}

int main() {
	Task* task = new RxTask();
	RxTask* rx_task = task->getRxTask();
	rx_task->print();
	delete task;
}
