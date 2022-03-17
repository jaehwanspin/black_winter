#include "./framework.hpp"

int main(int argc, char** argv)
{
    return bw::cli::framework(argc, argv).execute();
}