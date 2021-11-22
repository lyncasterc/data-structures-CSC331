#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <map>
#include "BSTree.h"


// returns true if c is a punctuation that is commonly found at end of words.
// .,;:?!
bool isEOWPunc(char c)
{
    return c == '!' || c == '.' || c == '?' 
            || c == ',' || c == ':' || c == 
            ';' ;
}

// returns true if c is a punctuation that marks end of a sentence.
// .!?
bool isEOSPunc(char c)
{
    return c == '.' || c == '?' || c == '!';
}

// transforms all characters of string to lowercase
// removes punctuation at end of string
void processWord(std::string &word)
{
    for (auto &&i : word)
    {
        i = tolower(i);
    }

    word.erase(std::remove_if(word.end() - 1, word.end(), isEOWPunc), word.end());
}

// returns true if word is a string consisting only of letters and punctuation marks
bool isWord(const std::string &word)
{
    return std::regex_match(word, std::regex("^[A-Za-z!?,.:;']+$"));
}

int main()
{
    int unique_word_count = 0;
    int unique_word_count_3 = 0;
    int total_word_count = 0;
    int total_word_count_3 = 0;
    int word_length_total = 0;
    int total_sentence_count = 0;

    std::string line;
    std::ifstream in_file;
    std::map<std::string, int> dup_words;
    BSTree<std::string> word_tree;
    in_file.open("project_3_text.txt");

    while(getline(in_file, line))
    {
        std::stringstream stream(line);
        std::string word;
        total_sentence_count += std::count_if(line.begin(), line.end(), isEOSPunc);
        
        while(stream >> word)
        {
            if(isWord(word))
            {
                processWord(word);
                total_word_count++;
                word_length_total += word.length();
                total_word_count_3 += (word.length() > 3) ? 1 : 0;

                //Unique words
                if(!word_tree.searchItem(word))
                {
                    word_tree.insertItem(word);
                    unique_word_count++;

                    // words bigger than 3 chars
                    unique_word_count_3 += (word.length() > 3) ? 1 : 0;
                }

                else
                {
                    dup_words[word]++;
                }
            
            }
        }
    }


    std::cout << "Total number of words: " << total_word_count << std::endl;
    std::cout << "Number of unique words: " << unique_word_count << std::endl;
    std::cout << "Number of unique words greater than 3 characters: " << unique_word_count_3 << std::endl;
    std::cout << "Average word length: " << word_length_total / total_word_count << std::endl;
    std::cout << "Average sentence length: " << total_word_count / total_sentence_count << std::endl;


    



    
}






