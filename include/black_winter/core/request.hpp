#ifndef __BLACK_WINTER_CORE_REQUEST_HPP__
#define __BLACK_WINTER_CORE_REQUEST_HPP__

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>

namespace black_winter
{
namespace core
{

class request : boost::beast::http::request<boost::beast::http::string_body>
{
public:
    

private:
    boost::asio::ip::tcp::endpoint endpoint_;

};

}
}

#endif