#include <black_winter/core/config.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/json/object.hpp>
#include <boost/json/array.hpp>
#include <boost/json/value.hpp>

namespace black_winter
{
namespace core
{

// class config::server_config::ssl_config

/**
 * @author Jin
 * @brief Construct a new config::server config::ssl config::ssl config object
 * 
 */
config::server_config::ssl_config::ssl_config() :
    use_ssl_(false),
    ssl_cert_(),
    ssl_key_(),
    ssl_dh_(),
    ssl_ctx_(boost::asio::ssl::context_base::tls)
{
}

/**
 * @author Jin
 * @brief Construct a new config::server config::ssl config::ssl config object
 * 
 * @param cert 
 * @param key 
 * @param dh 
 * @param ssl_ctx 
 */
config::server_config::ssl_config::ssl_config(const std::string& cert,
                                              const std::string& key,
                                              const std::string& dh,
                                              boost::asio::ssl::context_base::method ssl_method) :
    use_ssl_(true),
    ssl_cert_(cert),
    ssl_key_(key),
    ssl_dh_(dh),
    ssl_ctx_(ssl_method)
{
}

config::server_config::ssl_config::ssl_config(const std::filesystem::path& cert_path,
                                              const std::filesystem::path& key,
                                              const std::filesystem::path& dh,
                                              boost::asio::ssl::context_base::method ssl_method) :
    ssl_ctx_(ssl_method)
{
}



// static

/**
 * @author Jin
 * @brief
 * 
 */
const config config::default_config()
{
    
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
}