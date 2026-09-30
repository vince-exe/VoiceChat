#include "client.hpp"

VoiceChat::Client::Client(boost::asio::io_context& io_context, std::string ip, boost::asio::ip::port_type port) : m_socket(io_context), m_ip(ip), m_port(port) {}

awaitable<void> VoiceChat::Client::asyncConnect() {
    tcp::endpoint endpoint(boost::asio::ip::make_address(m_ip), m_port);

    co_await m_socket.async_connect(endpoint);
    
    std::cout << "Connessione riuscita!" << std::endl;    
}

awaitable<void> VoiceChat::Client::run() {
    co_await asyncConnect();

    NetPacket packet(NetPacket::Header::Comunication, "Client Vincenzo Caliendo wow!!");
    const std::vector<uint8_t> data = packet.serialize();

    m_socket.async_send(boost::asio::buffer(data, data.size()), [&](const boost::system::error_code& error, std::size_t bytes_transferred) {
        if(error)
            std::cout<<"Error nel send: " << error.message() << std::endl;

        std::cout << "Byte trasferred: " << bytes_transferred << std::endl;
    });
}