//
// Created by wsnzg6 on 2026/7/10.
//

#ifndef BIGGIES_H
#define BIGGIES_H

#include <string>
#include <vector>

namespace primer {
    std::string make_plural(size_t, const std::string& , const std::string&);
    void elimDups(std::vector<std::string>&);
    void sort_words(std::vector<std::string>&);
    void biggies(std::vector<std::string>&, std::vector<std::string>::size_type);
} // primer

#endif // BIGGIES_H
