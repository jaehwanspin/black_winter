#ifndef __BLACK_WINTER_CONFIG_HPP__
#define __BLACK_WINTER_CONFIG_HPP__

/**
 * @file config.hpp
 * @author Jin (https://github.com/jaehwanspin)
 * @brief defines class config
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <filesystem>

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>

namespace black_winter
{
namespace core
{

/**
 * @author Jin
 * @brief server config
 * 
 */
class config
{
public:
    class server_config
    {
    public:
        class ssl_config
        {
            bool                      use_ssl_;
            std::string               ssl_cert_;
            std::string               ssl_key_;
            std::string               ssl_dh_;
            boost::asio::ssl::context ssl_ctx_;

        public:
            ssl_config() = default;
            ssl_config(const std::string& cert,
                       const std::string& key,
                       const std::string& dh,
                       boost::asio::ssl::context_base::method ssl_method);
            ssl_config(const std::filesystem::path& cert_path,
                       const std::filesystem::path& key,
                       const std::filesystem::path& dh,
                       boost::asio::ssl::context_base::method ssl_method);
        };

    private:
        boost::asio::ip::tcp::endpoint endpoint_;
        ssl_config                     ssl_cfg_;

    public:
        server_config(const boost::asio::ip::tcp::endpoint& endpoint);
        server_config(const boost::asio::ip::tcp::endpoint& endpoint,
                      boost::asio::ssl::context_base::method ssl_method);
    };

private:
    friend class server;

public:
    static const config default_config();
    static const config from_json(const std::string& json_string);
    static const config from_json(std::string_view json_string);
    static const config from_json_file(const std::ifstream& config_file_stream);
    static const config from_json_file(const std::filesystem::path& config_file_path);
    static const config from_xml(const std::string& json_string);
    static const config from_xml(std::string_view json_string);
    static const config from_xml_file(const std::ifstream& config_file_stream);
    static const config from_xml_file(const std::filesystem::path& config_file_path);

public:  
    config() noexcept;
    config(const config&) = delete;
    config(const config&& other);
    
    std::string& server_identifier() const;
    server_config& server_config() const;
    
private:
    std::string server_identifier_;

};

} // core
} // black_winter


#endif