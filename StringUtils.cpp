#include "StringUtils.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <cmath>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    if (end == 0) {
        end = str.length();
    }
    if (start < 0) {
        start = str.length() + start;
    }
    if (end < 0) {
        end = str.length() + end;
    }
    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept{ //???
    auto copy = str;
    copy[0] = toupper(str[0]);
    for (size_t Index = 1; Index < copy.length(); Index++) {
        copy[Index] = tolower(copy[Index]);
    }
    return copy;
}

std::string Upper(const std::string &str) noexcept{
    auto Copy = str;
    int i = 0;
    while (Copy[i] != '\0') {
        Copy[i] = std::toupper(Copy[i]);
        i++;
    }
    return Copy;
}

std::string Lower(const std::string &str) noexcept{
    auto Copy = str;
    int i = 0;
    while (Copy[i] != '\0') {
        Copy[i] = std::tolower(Copy[i]);
        i++;
    }
    return Copy;
}

std::string LStrip(const std::string &str) noexcept {
    int i = 0; // the start of string
    while (i < str.length() && std::isspace(str[i])) {
        i++;
    }
    return str.substr(i);
}

std::string RStrip(const std::string &str) noexcept { //???
    /*
    auto copy = str;
    for (size_t i = copy.length(); i > 0; i--){
        if (copy[i - 1] != ' ') {
            copy.erase(i, std::string::npos);
            break;
        }
    }
    return copy;
*/
    for (int j = str.length(); j > 0; j--){
        if (str[j - 1] != ' ') {
            return str.substr(0,j - 1);
            break;
        }
    }
}

std::string Strip(const std::string &str) noexcept {
    auto copy = RStrip(str);
    auto strip_string = LStrip(copy);
    return strip_string;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    int i = width - str.length(); //width subtracted by string length 
    int leftside = i / 2; //divide by 2 to get half of i to put in front and behind string
    int rightside = i - leftside; //subtract leftside from i to get the remaining width for rightside
    return std::string(leftside, fill) + str + std::string(rightside, fill); //return value with the string in the middle of two halves of 'fill'
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    int leftside = width - str.length();
    return str + std::string(leftside, fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    int rightside = width - str.length();
    return std::string(rightside, fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    auto copy = str;
    int found = copy.find(old);
    while (found != std::string::npos){
        copy.erase(found, old.length());
        copy.insert(found, rep);
        found = copy.find(old);
    }
    return copy;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt = "") { //???
    std::vector<std::string> result;

    if (str.empty()) {
        return result; // Return an empty vector for an empty input string
    }

    std::string token;

    if (splt.empty()) {
        // If splt is empty, split on white space
        size_t start = 0;
        size_t length = str.length();

        for (size_t i = 0; i <= length; ++i) {
            if (i == length || std::isspace(str[i])) {
                result.push_back(str.substr(start, i - start));
                start = i + 1;
            }
        }
    } else {
        size_t start = 0;
        size_t length = str.length();

        for (size_t i = 0; i <= length; ++i) {
            if (i == length || str[i] == splt[0]) {
                if (str.substr(i, splt.length()) == splt) {
                    result.push_back(str.substr(start, i - start));
                    start = i + splt.length();
                }
            }
        }
    }

    return result;
}


std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{ //???
    std::string result;  // Start with the first element
    for (size_t i = 0; i < vect.size(); i++) {
        result.append(vect[i]);
        if (i != vect.size() - 1){
            result.append(str);
        }
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    size_t i = 0;
    while (i < str.length()) {
        if (str[i] == '\t') {
            int spaces = tabsize - (result.length() % tabsize);
            result.append(spaces, ' ');
        } else {
            result += str[i];
            }
            i++;
        }
        return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase = false) {
    const int size1 = left.size();
    const int size2 = right.size();

    if (size1 == 0) return size2;
    if (size2 == 0) return size1;

    std::string word1 = (ignorecase) ? StringUtils::Lower(left) : left;
    std::string word2 = (ignorecase) ? StringUtils::Lower(right) : right;

    int verif[size1 + 1][size2 + 1] = {};

    for (int i = 0; i <= size1; ++i) verif[i][0] = i;
    for (int j = 0; j <= size2; ++j) verif[0][j] = j;

    for (int i = 1; i <= size1; ++i)
        for (int j = 1; j <= size2; ++j)
            verif[i][j] = std::min({verif[i - 1][j] + 1, verif[i][j - 1] + 1, verif[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])});

    return verif[size1][size2];
}
}
