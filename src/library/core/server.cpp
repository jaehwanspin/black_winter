#include <black_winter/core/server.hpp>

#include <chrono>

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace black_winter
{
namespace core
{

boost::uuids::random_generator rand_identifier_gen;

// static

/**
 * @authro Jin
 * @brief global server objects
 * 
 */
std::unordered_map<std::string, server*> server::servers;

/**
 * @author Jin
 * @brief get static server by identifier
 * 
 * @param identifier 
 * @return std::shared_ptr<server> 
 */
server& server::get_server(const std::string& identifier)
{
    return *server::servers[identifier];
}

/**
 * @author Jin
 * @brief 
 * 
 * @return std::unordered_set<std::string> const 
 */
std::unordered_set<std::string> const server::server_identifiers()
{
    std::unordered_set<std::string> ids;
    for (auto server : server::servers) ids.insert(std::get<0>(server));
    return std::move(ids);
}


// non-static

/**
 * @author Jin
 * @brief Construct a new server::server object
 * 
 * @param io_ctx 
 */
server::server(boost::asio::io_context& io_ctx) noexcept :
    io_ctx_(io_ctx),
    config_(config::default_config()),
    server_identifier_(boost::uuids::to_string(rand_identifier_gen()))
{

}

/**
 * @author Jin
 * @brief Construct a new server::server object
 * 
 * @param server_identifier 
 * @param io_ctx 
 * @param endpoint 
 */
server::server(boost::asio::io_context& io_ctx,
               const config& cfg) noexcept :
    io_ctx_(io_ctx),
    config_(std::move(cfg))
{
    server::servers[this->server_identifier_] = this;
}

/**
 * @author Jin
 * @brief Destroy the server::server object
 * 
 */
server::~server()
{
    server::servers.erase(this->server_identifier_);
}

/**
 * @author Jin
 * @brief 
 * 
 * @return boost::asio::io_context& 
 */
boost::asio::io_context& server::io_context() const
{
    return this->io_ctx_;
}

/**
 * @author Jin
 * @brief 
 * 
 * @return std::string& const 
 */
const std::string& server::server_identifier()
{
    return this->server_identifier_;
}

/**
 * @author Jin
 * @brief 
 * 
 * @return boost::asio::ip::tcp::endpoint& const 
 */
const boost::asio::ip::tcp::endpoint& server::endpoint()
{
    return this->config_.endpoint();
}

} // core 
} // black_winter