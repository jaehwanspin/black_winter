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
#include <filesystem>

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>

namespace black_winter
{

/**
 * @author Jin
 * @brief server config
 * 
 */
class config
{
private:


public:
    static const config default_config();
    static const config from_json(const std::string& json_string);
    static const config from_json(std::string_view json_string);
    static const config from_json_file(const std::filesystem::path& config_file_path);
    static const config from_xml(const std::string& json_string);
    static const config from_xml(std::string_view json_string);
    static const config from_xml_file(const std::filesystem::path& config_file_path);

public:  
    config() noexcept;

    config(config&& other);


    boost::asio::ip::tcp::endpoint& endpoint();
    
private:
    boost::asio::ip::tcp::endpoint endpoint_;
    boost::asio::ssl::context      ssl_ctx_;
};

}



#endif