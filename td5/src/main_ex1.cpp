#include <string>
#include <limits>
#include <unordered_set>
#include <iostream>

size_t folding_string_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += s[i];
        hash %= max;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += s[i] * (i + 1);
        hash %= max;
    }
    return hash;
}

int main()
{
    std::string str{0};
    std::cout << "entre un string :";
    std::cin >> str;
    folding_string_hash(str, 100);
    folding_string_ordered_hash(str, 100);
}