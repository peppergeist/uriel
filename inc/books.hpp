#ifndef BOOKS_HPP
#define BOOKS_HPP

#define BOOK(x, y) {#x, #y}
#define TOTAL_BOOKS 66

#include <string>

struct bookmark
{
    std::string actual_name;
    std::string short_name;
};

extern bookmark book_list[];

#endif
