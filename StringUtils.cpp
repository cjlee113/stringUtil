#include "StringUtils.h"
#include <cctype>
#include <cstring>
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
    auto copy = str;
    copy[0] = toupper(copy[0]);
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

std::string RStrip(const std::string &str) noexcept {
    int i = str.length() - 1; // the end of string
    while (i >= 0 && std::isspace(str[i])) {
        i--;
    }
    return str.substr(0, i + 1);
}

std::string Strip(const std::string &str) noexcept {
    int i = 0;           // the start of string
    int j = str.length(); // the end of string
    while (i < j && std::isspace(str[i])) {
        i++;
    }
    while (j > i && std::isspace(str[j - 1])) {
        j--;
    }
    return str.substr(i, j - i);
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
    std::string finalString; // create a final variable
    for (size_t i = 0; i < str.length(); ) { // setup loop to search through 'str'
        if (str.compare(i, old.length(), old) == 0) { // use compare to look through string for the old substring
            finalString += rep; // if the old substring is found, add the replacement substring to final variable
            i += old.length(); // iterate the length of old substring to 'i' to skip the old substring
        } else {
            finalString += str[i]; // if no old substring is found, add the current letter to the final variable
            i++;
        }
    }
    return finalString;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string result = vect[0];  // Start with the first element
    for (size_t i = 1; i < vect.size(); ++i) {
        result += str + vect[i];  // Add separator followed by the current element
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

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

}