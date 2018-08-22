#include <fstream>
#include <iostream>
#include "books.hpp"
#include "options.hpp"
#include "reader.hpp"

std::string reader::standardize_book_name(std::string book_name)
{
    if (book_name.size() < 2)
    {
        std::cerr << "Book name not recognized." << std::endl;
        exit(1);
    }

    /* lowercase all letters, replace spaces with hyphens */
    for (int i = 1; i < book_name.size(); ++i)
    {
        book_name[i] = tolower(book_name[i]);
        if (' ' == book_name[i])
        {
            book_name[i] = '-';
        }
    }

    for (int i = 0; i < TOTAL_BOOKS; ++i)
    {
        if (book_list[i].prose_name == book_name)
        {
            return book_list[i].file_name;
        }
    }

    return book_name;
}

std::string reader::get_bible_verse(std::string book, std::string chapter,
    std::string verse)
{
    DBOUT("Looking for file in " << options::primary_data_path << ".");
    std::ifstream file(options::primary_data_path + book);
    if (!file.good())
    {
        DBOUT("File not found in primary data path."
            << "Looking for file in " << options::secondary_data_path
            << ".");

        file.open(options::secondary_data_path + book);

        if (!file.good())
        {
            std::cerr << "[ERROR] Cannot find file " + book + "." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    bool at_chapter = false;

    std::string line = "";
    while (std::getline(file, line))
    {
        if (!at_chapter)
        {
            if (line == "<CHAPTER cnumber=\"" + chapter + "\">")
            {
                at_chapter = true;
            }

            continue;
        }

        if (line.find("<VERS vnumber=\"" + verse + "\">") != std::string::npos)
        {
            line.erase(0, line.find(">") + 1);
            line.erase(line.find("<"));
            return line;
        }

        if ("</CHAPTER>" == line)
        {
            std::cerr << "[ERROR] Verse " + verse + " not found." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return "";
}

void reader::print_bible_chapter(std::string book, std::string chapter)
{
    DBOUT("Looking for file in " << options::primary_data_path << ".");
    std::ifstream file(options::primary_data_path + book);
    if (!file.good())
    {
        DBOUT("File not found in primary data path. "
            << "Looking for file in " << options::secondary_data_path
            << ".");

        file.open(options::secondary_data_path + book);

        if (!file.good())
        {
            std::cerr << "[ERROR] Cannot find file " + book + "." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    bool at_chapter = false;

    std::string line = "";
    while (std::getline(file, line))
    {
        if (!at_chapter)
        {
            if (line == "<CHAPTER cnumber=\"" + chapter + "\">")
            {
                at_chapter = true;
            }

            continue;
        }
        else
        {
            if ("</CHAPTER>" == line)
            {
                return;
            }
        }

        line.erase(0, line.find(">") + 1);
        line.erase(line.find("<"));
        std::cout << line << std::endl;
    }
}
