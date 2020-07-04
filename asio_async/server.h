#ifndef ASIO_ASYNC_H_
#define ASIO_ASYNC_H_

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

namespace asio_async {

class Session {
	public:
		Session(boost::asio::io_service& io_service);
		~Session();

		tcp::socket& getSocket() { return socket_; }
		void start();

	private:
		void handle_read(const boost::system::error_code& error,
										 size_t bytes_transferred);

		tcp::socket socket_;
		enum { max_length = 1024 };
		char data_[max_length];
};

class Server {
	public:
		Server(boost::asio::io_service& io_service, short port);
		~Server();

	private:
		void start_accept();
		void handle_accept(Session* new_session,
											 const boost::system::error_code& error);

		//boost 1.66이후 (Ubuntu 18.10 이후) 버전의 경우 io_context를 사용
		//session(boost::asio::io_context& io_service)
		boost::asio::io_service& io_service_;
		boost::asio::ip::tcp::acceptor acceptor_;
};
} // namespace asio_async
#endif  //ASIO_ASYNC_H_
