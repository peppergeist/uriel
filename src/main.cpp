#include <iostream>
#include <string>
#include <vector>
#include "options.hpp"
#include "reader.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string> inputs;
    for (int i = 0; i < argc; ++i) {
        inputs.push_back(argv[i]);
    }

    if (inputs.size() < 2) {
        std::cout << "Input must be of the form [book] [chapter]:[verse] "
        << "or [book] [chapter]" << std::endl
        << "Sample input:" << std::endl << "uriel genesis 1:1" << std::endl;
        return 0;
    }

    int book_offset = argc - 3;
    std::string book = inputs[1];
    for (int i = 0; i < book_offset; ++i) {
        book += " ";
        book += argv[2 + i];
    }

    std::string chapter = "";
    std::string verse = "";
    book = reader::standardize_book_name(book);

    if (inputs[argc - 1].find(":") != std::string::npos) {
        chapter = inputs[argc - 1].substr(0, inputs[argc - 1].find(":"));
        verse = inputs[argc - 1].substr(inputs[argc - 1].find(":") + 1);
    } else {
        chapter = inputs[argc - 1];
    }

    if ("" == verse) {
        reader::print_bible_chapter(book, chapter);
    } else {
        std::cout << reader::get_bible_verse(book, chapter, verse) << std::endl;
    }

    return 0;
}
