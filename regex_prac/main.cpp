#include <iostream>
#include <vector>
#include <regex>
#include <iterator>

int main()
{
    std::string line{"this is a line, in which regex is to be searched\n\
                      regex search should return true for #00aafd #02aafd .#03aafd#00aafd#00aafd#00aafd#00aafd#00aafd#00aafd\
                      because this is color and it should get caught in the regex"};
    std::regex color_regex("#([a-f0-9]{2})([a-f0-9]{2})([a-f0-9]{2})");

    std::cout << "pattern " 
              << (std::regex_search(line, color_regex) ? "" : "not ")
              << "found.\n";

    std::smatch colors;
    if(std::regex_search(line, colors, color_regex))
        for(auto & item : colors)
            std::cout << "--" << item << "\n";


    auto word_begin = std::sregex_iterator(std::begin(line), std::end(line), color_regex);
    auto word_end   = std::sregex_iterator();

    for(auto & i = word_begin; i != word_end; ++i)
    {
        auto word = *i;
        std::cout << word.str() << ", ";
    }


    std::cout << std::endl;
	return 0;
}
