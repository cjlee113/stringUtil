# Project X README

Student 1: Christopher Lee (920724149)


## Project Status
* Few functions needed to be finished. Some of the functions should work but don't maybe due to segmentation fault.
* Had an extra StringUtils.cpp that I was editing instead of the main one, copying code from second one to main one

## Known Issues
Capitalize function, RStrip function, Strip function, Replace function, Split function, Join function (segmentation fault)
* Had two StringUtils.cpp so I got rid of one and Capitalize, RStrip, and Strip function worked. May have messed up commits since I was     commiting to another StringUtils.cpp instead of the main one

Join, Expandtabs, and Editdistance function have error that won't allow them to run tests
* Fixed error, was an extra { in front of Join function that cut it off from top stuff

## Code References
* [Find command](https://www.geeksforgeeks.org/std-find-in-cpp/)
* [Levenshtein distance](https://en.wikipedia.org/wiki/Levenshtein_distance)
* [Push_back command](https://www.geeksforgeeks.org/list-push_back-function-in-c-stl/)
* [Erase command](https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/)
* [Levenshtein distance example](https://github.com/guilhermeagostinelli/levenshtein/blob/master/levenshtein.cpp)

## Generative AI Use
I used ChatGPT to find commands that I used, then looked them up on Geeksforgeeks

### Prompt 1
what does find() do
### Response 1
The find() method is a built-in function in Python that is used to search for a substring within a string and returns the index of the first occurrence of the substring. If the substring is not found, it returns -1. 

### Chagnes 1
Used .find() in Replace function

### Prompt 2
What does push_back()do

### Response 2
The push_back() function is commonly used in programming languages like C++ and is associated with dynamic arrays or vectors. Specifically, it is a method used to add an element to the end of a container, such as an array or vector.

In C++, the push_back() function is often used with vectors from the Standard Template Library (STL). For example, if you have a vector named myVector, you can use myVector.push_back(element) to add the specified element to the end of the vector.
### Changes 2
Used .push_back in Split funciton