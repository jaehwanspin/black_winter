#ifndef __BLACK_WINTER_SERVER_HPP__
#define __BLACK_WINTER_SERVER_HPP__

/**
 * @file server.hpp
 * @author Jin (http://github.com/jaehwanspin)
 * @brief defines class server
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <black_winter/core/config.hpp>

namespace black_winter
{
namespace core
{

/**
 * @author Jin
 * @brief HTTP server class
 * 
 */
class server
{
private:
    static std::unordered_map<std::string, server*> servers;
public:
    [[nodiscard]] static server& get_server(const std::string& identifier);
    [[nodiscard]] static std::unordered_set<std::string> const server_identifiers();

public:
    server(boost::asio::io_context& io_ctx) noexcept;
    explicit server(boost::asio::io_context& io_ctx,
                    const config& cfg) noexcept;
    virtual ~server();

    [[nodiscard]] boost::asio::io_context&              io_context() const;
    [[nodiscard]] const std::string&                    server_identifier();
    [[nodiscard]] const boost::asio::ip::tcp::endpoint& endpoint();

private:

    boost::asio::io_context&       io_ctx_;
    config                         config_;
    std::string                    server_identifier_;
};

} // core
} // black_winter

#endif