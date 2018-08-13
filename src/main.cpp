#include <iostream>
#include <string>
#include <vector>
#include "options.hpp"
#include "reader.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string> inputs = options::vectorize_input(argc, argv);

    std::string book = options::parse_input_for_book(inputs);
    book = reader::standardize_book_name(book);

    std::string chapter = options::parse_input_for_chapter(inputs);
    std::string verse = options::parse_input_for_verse(inputs);

    if ("" == verse)
    {
        std::cout << reader::get_bible_chapter(book, chapter) << std::endl;
    }
    else
    {
        std::cout << reader::get_bible_verse(book, chapter, verse) << std::endl;
    }

    return 0;
}
