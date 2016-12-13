#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "ast/ast.hpp"
#include "lexer.yy.h"
#include "parser.tab.h"

ast::Telegraph* parse(const char* input) {
  YY_BUFFER_STATE bufferState = yy_scan_string(input);

  ast::Telegraph* ast = new ast::Telegraph();

  yyparse(ast);

  yy_delete_buffer(bufferState);

  return ast;
}

TEST(VersionTest, ParsesVersion) {
  ast::Telegraph* ast = parse("version 0.1.12");

  ASSERT_EQ(ast->version(), "0.1.12");

  delete ast;
}

TEST(EnumTest, ParsesEnumerations) {
  ast::Telegraph* ast = parse("enum Test { VALUE_A, VALUE_B, VALUE_C }");

  ASSERT_EQ(ast->enums().size(), 1);
  ASSERT_EQ(ast->enums().at(0)->name(), "Test");

  ASSERT_EQ(ast->enums().at(0)->values().size(), 3);
  ASSERT_EQ(ast->enums().at(0)->values().at(0), "VALUE_A");
  ASSERT_EQ(ast->enums().at(0)->values().at(1), "VALUE_B");
  ASSERT_EQ(ast->enums().at(0)->values().at(2), "VALUE_C");

  delete ast;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
