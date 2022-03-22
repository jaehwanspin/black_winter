#include <cstdint>
#include <cstddef>

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/address.hpp>

#include <black_winter/core.hpp>

constexpr uint16_t port = 7777;

int main(int argc, char** argv)
{
    boost::asio::io_context io_ctx;

    black_winter::core::server server(io_ctx,
        black_winter::core::config::default_config());

    io_ctx.run();

    return 0;
}