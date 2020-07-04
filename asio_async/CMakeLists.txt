cmake_minimum_required(VERSION 3.13)
 
project(asio_async)
find_package(Boost REQUIRED system)
find_package(Threads)
 
add_compile_options(
	-O0
)
include_directories(${Boost_INCLUDE_DIR})

set(server_srcs
		server_main.cc
    server.cc
)
add_executable(server ${server_srcs})

target_link_libraries(server
    ${Boost_LIBRARIES}
)

set(client_srcs
    client.cc
)

add_executable(client ${client_srcs})

target_link_libraries(client
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)
