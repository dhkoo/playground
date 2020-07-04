#include "server.h"
 
namespace asio_async { 
Session::Session(boost::asio::io_service& io_service)
    : socket_(io_service) {}
Session::~Session() {}
 
void Session::start() {
  //client로부터 연결됨
  std::cout << "connected" << std::endl;
  //client로부터 비동기 read 실행
  socket_.async_read_some(boost::asio::buffer(data_, max_length),
      boost::bind(&Session::handle_read, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}
 
void Session::handle_read(const boost::system::error_code& error,
                          size_t bytes_transferred) {
  if (!error)
    std::cout << data_ << std::endl;
  else
    delete this;
}
 
Server::Server(boost::asio::io_service& io_service, short port)
    : io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port)) {
  start_accept();
}
Server::~Server() {}
 
void Server::start_accept() {
  Session* new_session = new Session(io_service_);
  //client로부터 접속될 때 까지 대기한다.
  acceptor_.async_accept(new_session->getSocket(),
      boost::bind(&Server::handle_accept, this, new_session,
        boost::asio::placeholders::error));
}
 
  //client로부터 접속이 되었을 때 해당 handler 함수를 실행한다.
void Server::handle_accept(Session* new_session,
                           const boost::system::error_code& error) {
  if (!error)
    new_session->start();
  else
    delete new_session;

  //client로부터 접속이 끊겼을 대 다시 대기한다.
  start_accept();
}
} // namespace asio_async
