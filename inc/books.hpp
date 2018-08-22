#ifndef BOOKS_HPP
#define BOOKS_HPP

#define BOOK(x, y) {#x, #y}
#define TOTAL_BOOKS 66

#include <string>

/**
 * @brief      A struct for containing the actual name of a book and a
 * shortened name of the book.
 */
struct bookmark
{
    std::string prose_name;
    std::string file_name;
};

extern bookmark book_list[];

#endif
