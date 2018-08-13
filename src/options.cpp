
#include "options.hpp"

std::vector<std::string> options::vectorize_input(int argc, char *argv[])
{
    std::vector<std::string> vectorized_inputs;
    for (int i = 0; i < argc; ++i)
    {
        vectorized_inputs.push_back(argv[i]);
    }

    return vectorized_inputs;
}

std::string options::parse_input_for_book(std::vector<std::string> input)
{
    for (int i = 0; i < input.size(); ++i)
    {

    }

    return "";
}

std::string options::parse_input_for_chapter(std::vector<std::string> input)
{
    return "";
}

std::string options::parse_input_for_verse(std::vector<std::string> input)
{
    return "";
}
