#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "ast/ast.hpp"
#include "lexer.yy.h"
#include "parser.tab.h"

/* collect every token from the input */
std::vector<int> lex(const char* input) {
  std::vector<int> tokens = std::vector<int>();

  YY_BUFFER_STATE bufferState = yy_scan_string(input);

  while(int token = yylex()) { tokens.push_back(token); }

  yy_delete_buffer(bufferState);

  return tokens;
}

TEST(VersionTest, RecognizesVersions) {
  std::vector<int> tokens = lex("version 0.1.12");

  ASSERT_EQ(KW_VERSION, tokens.at(0));
  ASSERT_EQ(VERSION_NUMBER, tokens.at(1));
}

TEST(StructTest, RecognizesStructs) {
  std::vector<int> tokens = lex("struct User { }");

  ASSERT_EQ(KW_STRUCT, tokens.at(0));
  ASSERT_EQ(IDENTIFIER, tokens.at(1));
}

TEST(EnumTest, RecognizesEnums) {
  std::vector<int> tokens = lex("enum TokenTypes { TOKEN_A; TOKEN_B }");

  ASSERT_EQ(KW_ENUM, tokens.at(0));
  ASSERT_EQ(IDENTIFIER, tokens.at(1));
  ASSERT_EQ(IDENTIFIER, tokens.at(3));
  ASSERT_EQ(IDENTIFIER, tokens.at(5));
}

TEST(EventTest, RecognizesEvents) {
  std::vector<int> tokens = lex("event user_created publishes Person");

  ASSERT_EQ(KW_EVENT, tokens.at(0));
  ASSERT_EQ(IDENTIFIER, tokens.at(1));
  ASSERT_EQ(KW_PUBLISHES, tokens.at(2));
  ASSERT_EQ(IDENTIFIER, tokens.at(3));
}

TEST(ErrorTest, RecognizesErrors) {
  std::vector<int> tokens = lex("error DivisionByZero { String message; }");

  ASSERT_EQ(KW_ERROR, tokens.at(0));
  ASSERT_EQ(IDENTIFIER, tokens.at(1));
  ASSERT_EQ(IDENTIFIER, tokens.at(3));
  ASSERT_EQ(IDENTIFIER, tokens.at(4));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
