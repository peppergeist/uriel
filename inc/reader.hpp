#ifndef READER_HPP
#define READER_HPP

#include <string>

namespace reader
{
    /**
     * @brief      Attempts to coerce the given string of the name of a book of
     * the Bible into the format used in the data files.
     *
     * @param[in]  book_name  The book name
     *
     * @return     The name of the book as used in data files
     */
    std::string standardize_book_name(std::string book_name);

    /**
     * @brief      Gets a specific Bible verse given a book, chapter, and verse.
     *
     * @param[in]  book     The book
     * @param[in]  chapter  The chapter
     * @param[in]  verse    The verse
     *
     * @return     The Bible verse
     */
    std::string get_bible_verse(std::string book, std::string chapter,
        std::string verse);

    /**
     * @brief      Prints an entire Bible chapter given the book and chapter.
     *
     * @param[in]  book     The book
     * @param[in]  chapter  The chapter
     */
    void print_bible_chapter(std::string book, std::string chapter);
}

#endif
