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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
