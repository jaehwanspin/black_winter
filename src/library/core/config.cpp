#include <black_winter/core/config.hpp>

namespace black_winter
{

// static

/**
 * @author Jin
 * @brief
 * 
 */
const config config::default_config()
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_json(const std::string& json_string)
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_json(std::string_view json_string)
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_json_file(const std::filesystem::path& config_file_path)
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_xml(const std::string& json_string)
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_xml(std::string_view json_string)
{
    config cfg;

    return cfg;
}

/**
 * @author Jin
 * @brief
 * 
 */
const config config::from_xml_file(const std::filesystem::path& config_file_path)
{
    
}


// non-static
config::config() :
    endpoint_(),
    ssl_ctx_(boost::asio::ssl::context::tlsv12)
{

}

boost::asio::ip::tcp::endpoint& endpoint()
{
    return this->endpoint_;
}


}