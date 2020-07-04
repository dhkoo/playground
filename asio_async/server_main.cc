#include "server.h"

int main(int argc, char* argv[]) {
	try {
		if (argc != 2) {
			std::cerr << "Usage: async_tcp_echo_server <port>\n";
			return 1;
		}
	
		boost::asio::io_service io_service;
		asio_async::Server async_tcp_echo_server(io_service, atoi(argv[1]));

		io_service.run();

		} 
		catch (exception& e) {
			cerr << "Exception: " << e.what() << "\n";
		}

		return 0;
}
