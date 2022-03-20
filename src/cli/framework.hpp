#ifndef __BLACK_WINTER_CLI_FRAMEWORK_HPP__
#define __BLACK_WINTER_CLI_FRAMEWORK_HPP__

#include <vector>
#include <string>
#include <memory>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

namespace black_winter
{
namespace cli
{

class framework
{

private:
    void parse_opts(int argc, char** argv);
    void show_help();

public:
    explicit framework(int argc, char** argv);
    virtual ~framework();

    int execute();

private:
    boost::program_options::variables_map vars_map_;
    boost::program_options::options_description opts_desc_;
};

}    
}

#endif