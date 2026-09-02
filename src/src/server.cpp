#include "server.hpp"

App::Server::Server() {
    m_port = static_cast<uint_least16_t>(App::ConfigManager::get().getPort());
    m_maxConnections = static_cast<uint_least16_t>(App::ConfigManager::get().getMaxConnections());

    m_activeConnections = 0;
}

awaitable<void> App::Server::listen() {
    /*
    auto executor = co_await boost::asio::this_coro::executor;
    tcp::acceptor acceptor(executor, {tcp::v4(), m_port});

    while(m_activeConnections < m_maxConnections) {
        m_activeConnections++;

        tcp::socket connection = co_await acceptor.async_accept();
        co_spawn(executor, write(std::move(connection)), boost::asio::detached);
    }
    */
}

awaitable<void> App::Server::write(tcp::socket socket)
{
    auto remoteEndpoint = socket.remote_endpoint();

    std::cout<<"IP client connesso: " << remoteEndpoint.address() << std::endl;
}
