#include "server.hpp"

App::Server::Server() {
    m_port = static_cast<boost::asio::ip::port_type>(App::ConfigManager::get().getPort());
    m_maxConnections = static_cast<uint_least16_t>(App::ConfigManager::get().getMaxConnections());

    m_activeConnections = 0;
}

awaitable<void> App::Server::listen() {
    auto executor = co_await boost::asio::this_coro::executor;
    tcp::acceptor acceptor(executor, {tcp::v4(), m_port});

    while(m_activeConnections < m_maxConnections) {
        m_activeConnections++;

        tcp::socket connection = co_await acceptor.async_accept();
        co_spawn(executor, _handleClientReq(std::move(connection)), boost::asio::detached);
    }
}

awaitable<void> App::Server::_handleClientReq(tcp::socket socket)
{
    while(true) {
        char buffer[4000];
        std::size_t n = co_await socket.async_read_some(boost::asio::buffer(buffer));

        std::cout << "Messaggio ricevuto: " << buffer << std::endl;
    }
}
