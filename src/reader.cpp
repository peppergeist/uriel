#include <fstream>
#include <iostream>
#include "books.hpp"
#include "options.hpp"
#include "reader.hpp"

bool reader::is_book_name(std::string book_name)
{
    return false;
}

std::string reader::standardize_book_name(std::string book_name)
{
    if (book_name.size() < 2)
    {
        std::cerr << "Book name not recognized." << std::endl;
        exit(1);
    }

    /* capitalize first letter, lowercase the rest */
    book_name[0] = toupper(book_name[0]);
    for (int i = 1; i < book_name.size(); ++i)
    {
        book_name[i] = tolower(book_name[i]);
    }

    return book_name;
}

std::string reader::get_bible_verse(std::string book, std::string chapter,
    std::string verse)
{
    std::ifstream file(options::secondary_data_path);
    return "";
}

std::string reader::get_bible_chapter(std::string book, std::string chapter)
{
    return "";
}
