#ifndef __BLACK_WINTER_CORE_INTERNAL_FILE_LOADER_HPP__
#define __BLACK_WINTER_CORE_INTERNAL_FILE_LOADER_HPP__

#include <fstream>

#include <boost/json/value.hpp>
#include <boost/json/object.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace black_winter
{
namespace core
{
namespace internal
{

template <typename _FileType>
class file_loader
{
    
public:
    file_loader()
private:
    boost::property_tree::ptree pt_;
};

}
}
}

#endif