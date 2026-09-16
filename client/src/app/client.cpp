#include "client.hpp"

VoiceChat::Client::Client(boost::asio::io_context& io_context, std::string ip, boost::asio::ip::port_type port) : m_socket(io_context), m_ip(ip), m_port(port) {}

void VoiceChat::Client::asyncConnect() {
    tcp::endpoint endpoint(boost::asio::ip::make_address(m_ip), m_port);

    m_socket.async_connect(endpoint, [](const boost::system::error_code& ec) {
        if (!ec)
        {
            // Connect succeeded.
        }
    });
}