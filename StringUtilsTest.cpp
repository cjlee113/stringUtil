#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base,0),"Hello");
    EXPECT_EQ(StringUtils::Slice(Base,1),"ello");
}

TEST(StringUtilsTest, Capitalize){
    std::string base = "Hello"

    EXPECT_EQ(StringUtils::Capitalize(Base),"Hello");
    EXPECT_EQ(StringUtils::Capitalize(std::string()),"");
    EXPECT_EQ(StringUtils::Capitalize(" hello")," hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"),"Hello");
    EXPECT_EQ(StringUtils::Capitalize("    \t\r\n:*^73"),"   \t\r\n:*^73");
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Upper(Base),"HELLO");
}

TEST(StringUtilsTest, Lower){
     std::string Base = "HELLO";

    EXPECT_EQ(StringUtils::Lower(Base),"hello");
}

TEST(StringUtilsTest, LStrip){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::LStrip(Base), Base)
    EXPECT_EQ(StringUtils::LStrip("    Hello"), "Hello");
    EXPECT_EQ(StringUtils::LStrip("          "), "");
    EXPECT_EQ(StringUtils::LStrip(" \t  Hello World"), "Hello World");
}

TEST(StringUtilsTest, RStrip){
    std::string Base = "hello";
    
    EXPECT_EQ(StringUtils::LStrip(Base), Base)
    EXPECT_EQ(StringUtils::LStrip("Hello    "), "Hello");
    EXPECT_EQ(StringUtils::LStrip("          "), "");
    EXPECT_EQ(StringUtils::LStrip("Hello World \t  "), "Hello World");
}

TEST(StringUtilsTest, Strip){
    std::string Base = "hello";
    
    EXPECT_EQ(StringUtils::LStrip(Base), Base)
    EXPECT_EQ(StringUtils::LStrip("    Hello    "), "Hello");
    EXPECT_EQ(StringUtils::LStrip("          "), "");
    EXPECT_EQ(StringUtils::LStrip(" \t  Hello World \t  "), "Hello World");
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("Hello", 9), "  Hello  ");
    EXPECT_EQ(StringUtils::Center("Hello", 10), "  Hello   ");
    EXPECT_EQ(StringUtils::Center("A", 5), "  A  ");
    EXPECT_EQ(StringUtils::Center("", 7), "       ");
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("Hello", 9), "Hello    ");
    EXPECT_EQ(StringUtils::LJust("Hello", 10), "Hello     ");
    EXPECT_EQ(StringUtils::LJust("A", 5), "A    ");
    EXPECT_EQ(StringUtils::LJust("", 7), "       ");
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::LJust("Hello", 9), "    Hello");
    EXPECT_EQ(StringUtils::LJust("Hello", 10), "     Hello");
    EXPECT_EQ(StringUtils::LJust("A", 5), "    A");
    EXPECT_EQ(StringUtils::LJust("", 7), "       ");
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("Hello World", "World", "Friends"), "Hello Friends");
    EXPECT_EQ(StringUtils::Replace("Hi Friends", "World", "Everyone"), "Hi Everyone");
    EXPECT_EQ(StringUtils::Replace("Hi Hi Hi", "Hi", "Bye"), "Bye Bye Bye");
    EXPECT_EQ(StringUtils::Replace("Hello World", "World", ""), "Hello ");
    EXPECT_EQ(StringUtils::Replace("Hello World", "Hello", ""), " Universe");
    EXPECT_EQ(StringUtils::Replace("", "Hello", "Hi"), "");
}

TEST(StringUtilsTest, Split){
    EXPECT_EQ(StringUtils::Split(" A B C "), std::vector<std::string>("A", "B", "C"));
    EXPECT_EQ(StringUtils::Split(" I am friendly "), std::vector<std::string>("I", "am", "friendly"));
    EXPECT_EQ(StringUtils::Split(" One, Two, Three ", ","), std::vector<std::string>("One", "Two", "Three"));
    EXPECT_EQ(StringUtils::Split("", ""), std::vector<std::string>{});
}

TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(" ", (" A B C ")), "A B C");
    EXPECT_EQ(StringUtils::Join(" ", ("I", "am", "friendly")), "I am friendly");
    EXPECT_EQ(StringUtils::Join(", ", ("One", "Two", "Three")), "One, Two, Three");
    EXPECT_EQ(StringUtils::Join("", ()), "");
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
