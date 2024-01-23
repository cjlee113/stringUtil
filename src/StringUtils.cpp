#include "StringUtils.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <cmath>
#include <algorithm>
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

std::string Capitalize(const std::string &str) noexcept{
    auto Copy = str;
    Copy[0] = std::toupper(Copy[0]);
    for(size_t i = 1; i < Copy.length(); i++) {
        Copy[i] = tolower(Copy[i]);
    }
    return Copy;
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

std::string LStrip(const std::string &str) noexcept{
    int i = 0; //the start of string
    while (i < str.length() && std::isspace(str[i])) {
        i++;
    }
    return str.substr(i);
}

std::string RStrip(const std::string &str) noexcept{
    int j = str.length();
    while (j > 0 && std::isspace(str[j - 1])) {
        j--;
    }
    return str.substr(0, j);
}


std::string Strip(const std::string &str) noexcept{
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
    std::string result = str;
    size_t found = result.find(old);

    while (found != std::string::npos) {
        result.replace(found, old.length(), rep);
        found = result.find(old, found + rep.length());
    }

    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{ //***
    std::vector<std::string> result;
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


std::string Join(const std::string &separator, const std::vector<std::string> &strings) noexcept {
    std::string result;  // Start with an empty string
    for (size_t i = 0; i < strings.size(); ++i) {
        result += strings[i];
        if (i != strings.size() - 1) {
            result += separator;
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

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    std::string copy1, copy2;
    if (ignorecase) {
        copy1 = StringUtils::Lower(left);
        copy2 = StringUtils::Lower(right);
    } else {
        copy1 = left;
        copy2 = right;
    }
    const size_t size1 = copy1.size();
    const size_t size2 = copy2.size();
    int matrix[size1 + 1][size2 + 1];

    if (size1 == 0)
        return int(size2);
    if (size2 == 0)
        return int(size1);

    for (size_t i = 0; i <= size1; ++i) {
        matrix[i][0] = int(i);
    }
    for (size_t j = 0; j <= size2; ++j) {
        matrix[0][j] = int(j);
    }

    for (size_t i = 1; i <= size1; ++i) {
        for (size_t j = 1; j <= size2; ++j) {
            int substitutionCost = (copy1[i - 1] == copy2[j - 1]) ? 0 : 1;
            matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + substitutionCost});
        }
    }
    return matrix[size1][size2];
}
}