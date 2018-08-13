#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <string>
#include <vector>

namespace options
{
    static std::string primary_data_path = "/usr/local/opt/uriel/dat/bible.xml";
    static std::string secondary_data_path = "dat/bible.xml";

    /**
     * @brief      Converts the input arguments to a standard stl vector.
     *
     * @param[in]  argc  The argument count
     * @param      argv  The argument vector
     *
     * @return     A vector of the input arguments
     */
    std::vector<std::string> vectorize_input(int argc, char *argv[]);

    /**
     * @brief      Parses a vector of strings for a book of the Bible.
     *
     * @param[in]  input  The input vector
     *
     * @return     The name of a Bible book found in the input
     */
    std::string parse_input_for_book(std::vector<std::string> input);

    /**
     * @brief      Parses a vector of strings for a chapter number.
     *
     * @param[in]  input  The input vector
     *
     * @return     The integer index of a chapter of a book
     */
    std::string parse_input_for_chapter(std::vector<std::string> input);

    /**
     * @brief      Parses a vector of strings for a verse number.
     *
     * @param[in]  input  The input vector
     *
     * @return     The integer index of a verse of a chapter
     */
    std::string parse_input_for_verse(std::vector<std::string> input);
}

#endif
