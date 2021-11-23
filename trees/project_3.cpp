#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <regex>
#include <map>
#include "BSTree.h"

// Programmer: Stiven Cabrera
// Purpose: Project 3 solution - provides statistical report and style suggestions for a text document.
// Input: String - user inputs the file name of the text document.
// Output: Ostream - cout statements providing the report of the text document.


// returns true if c is a punctuation mark that is commonly found at end of words.
// .,;:?!
bool isEOWPunc(char c)
{
    return c == '!' || c == '.' || c == '?' 
            || c == ',' || c == ':' || c == 
            ';' ;
}

// returns true if c is a punctuation mark that marks end of a sentence.
// .!?
bool isEOSPunc(char c)
{
    return c == '.' || c == '?' || c == '!';
}

// transforms all characters of string to lowercase and
// removes punctuation at end of string
void processWord(std::string &word)
{
    for (auto &&i : word)
    {
        i = tolower(i);
    }

    word.erase(std::remove_if(word.end() - 1, word.end(), isEOWPunc), word.end());
}

// returns true if word is a string consisting only of letters 
// and punctuation marks commonly found at end of words.
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
    double avg_sentence_length, avg_word_length;

    std::vector<std::string> unique_words;
    std::string user_input, line;
    std::ifstream in_file;
    std::map<std::string, int> dup_words;
    BSTree<std::string> word_tree;

    std::cout << "FILE NAME: ";
    std::cin >> user_input;
    in_file.open(user_input);

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

                
                if(!word_tree.searchItem(word))
                {
                    word_tree.insertItem(word);
                    unique_words.push_back(word);
                    unique_word_count++;
                    unique_word_count_3 += (word.length() > 3) ? 1 : 0;
                }

                else
                {
                    dup_words[word] += (dup_words[word] == 0) ? 2 : 1;
                }
            
            }
        }
    }

    
    avg_word_length =  word_length_total / static_cast<double>(total_word_count);
    avg_sentence_length = total_word_count / static_cast<double>(total_sentence_count);

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\t\tSTATISTICS:\n\n";
    std::cout << "TOTAL NUMBER OF WORDS: " << total_word_count << std::endl;
    std::cout << "TOTAL NUMBER OF UNIQUE WORDS: " << unique_word_count << std::endl;
    std::cout << "TOTAL NUMBER OF UNIQUE WORDS WITH MORE THAN 3 LETTERS: " << unique_word_count_3 << std::endl;
    std::cout << "AVERAGE WORD LENGTH: " << avg_word_length << std::endl;
    std::cout << "AVERAGE SENTENCE LENGTH: " << avg_sentence_length << std::endl;


    std::cout << "\n\n\t\tSTYLE WARNINGS\n\n";

    std::cout << "WORDS USED TOO OFTEN: \n";

    for (auto &&i : dup_words)
    {
        if(i.first.length() > 3)
        {
            if((i.second / static_cast<double>(total_word_count_3)) * 100 > 5)
            {
                std::cout << i.first << std::endl;
            }
        }
    }
    
    if(avg_sentence_length > 10)
    {
        std::cout << "\nAVERAGE SENTENCE LENGTH TOO LONG - " << avg_sentence_length << " words\n";
    }
    
    if(avg_word_length > 5)
    {
        std::cout << "\nAVERAGE WORD LENGTH TOO LONG - " << avg_word_length << " characters\n";
    }

    std::sort(unique_words.begin(), unique_words.end());

    std::cout << "\t\tINDEX OF UNIQUE WORDS\n\n";

    char alpha = toupper(unique_words[0][0]);
    std::cout << std::endl << alpha << std::endl;

    for (auto &&i : unique_words)
    {
        if(toupper(i[0]) != alpha)
        {
            alpha = toupper(i[0]);
            std::cout << std::endl << alpha << std::endl;
        }

        std::cout << i << std::endl;
    }
    
    

}






