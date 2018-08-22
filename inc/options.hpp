#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#define DBOUT( x )  if (options::debug_mode_on) \
                    { std::cout << "[DEBUG] " << x << std::endl; }

#include <string>

namespace options
{
    static std::string primary_data_path = "/usr/local/opt/uriel/dat/";
    static std::string secondary_data_path = "dat/";
    static bool debug_mode_on = false;
}

#endif
