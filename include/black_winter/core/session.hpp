#ifndef __BLACK_WINTER_CORE_SESSION_HPP__
#define __BLACK_WINTER_CORE_SESSION_HPP__

#include <memory>
#include <boost/asio/ip/tcp.hpp>

namespace black_winter
{
namespace core
{

class session : public std::enable_shared_from_this<session>
{

public:


private:
    boost::asio::ip::tcp::socket socket_;
    

};

}
}


#endif