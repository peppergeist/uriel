#ifndef BOOKS_HPP
#define BOOKS_HPP

#define BOOK(x, y, z) {#x, #y, #z}
#define TOTAL_BOOKS 66

#include <string>

/**
 * @brief      A struct for containing the actual name of a book and a
 * shortened name of the book.
 */
struct bookmark
{
    std::string actual_name;
    std::string short_name;
    std::string file_name;
};

extern bookmark book_list[];

#endif
