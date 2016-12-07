#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "lexer.yy.h"
#include "token_types.hpp"

/* collect every token from the input */
std::vector<int> lex(const char* input) {
  std::vector<int> tokens = std::vector<int>();

  YY_BUFFER_STATE bufferState = yy_scan_string(input);

  while(int token = yylex()) { tokens.push_back(token); }

  yy_delete_buffer(bufferState);

  return tokens;
}


TEST(VersionTest, RecognizesVersionKeyword) {
  std::vector<int> tokens = lex("version 0.1.12");

  ASSERT_EQ(KW_VERSION, tokens.at(0));
  ASSERT_EQ(VERSION_NUMBER, tokens.at(1));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
