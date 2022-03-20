#include "./framework.hpp"

#include <system_error>
#include <iostream>

#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/cmdline.hpp>
namespace opts = boost::program_options;

namespace black_winter
{
namespace cli
{

framework::framework(int argc, char** argv) :
    vars_map_(),
    opts_desc_("black-winter-cli options")
{
    this->parse_opts(argc, argv);
}

framework::~framework()
{

}

int framework::execute()
{
    int res = EXIT_SUCCESS;

    if (this->vars_map_.size() == 0)
    {
        this->show_help();
        res = EXIT_FAILURE;
    }
    else
    {

    }

    return res;
}

void framework::parse_opts(int argc, char** argv)
{
    this->opts_desc_.add_options()
        ("help", "shows allowed options")
        ("create", "create");

    opts::store(opts::parse_command_line(argc, argv, opts_desc_), this->vars_map_);
    opts::notify(this->vars_map_);   
}

void framework::show_help()
{
    std::cout << this->opts_desc_ << std::endl;
}

}    
}