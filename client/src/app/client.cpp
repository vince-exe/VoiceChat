#include "client.hpp"

VoiceChat::Client::Client(boost::asio::io_context& io_context, std::string ip, boost::asio::ip::port_type port) : m_socket(io_context), m_ip(ip), m_port(port) {}

awaitable<void> VoiceChat::Client::asyncConnect() {
    tcp::endpoint endpoint(boost::asio::ip::make_address(m_ip), m_port);

    co_await m_socket.async_connect(endpoint);

    std::cout << "aspettando la connessione" << std::endl;
}