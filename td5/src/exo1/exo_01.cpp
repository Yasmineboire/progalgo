#include <iostream>
#include <string>

//question 1
size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash {0}; 
    for(size_t i {0}; i < s.size(); ++i) {
        hash += s[i];
        hash %= max;
    }

    return hash;
}

//question2

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash {0}; 
    for(size_t i {0}; i < s.size(); ++i) {
        hash += s[i] * (i + 1);
        hash %= max;
    }

    return hash;
}

int main () {
    std::string str {};
    std::cout << "Entre une string : ";
    std::getline(std::cin, str); 

    size_t h1 = folding_string_hash(str, 100);
    size_t h2 = folding_string_ordered_hash(str, 100);

    std::cout << "la somme exo 1 vaut : " << h1 << std::endl;
    std::cout << "la somme exo 2 vaut : " << h2 << std::endl;

    return 0;
}
