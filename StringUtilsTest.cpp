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
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
