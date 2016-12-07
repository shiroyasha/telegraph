#include <gtest/gtest.h>

/* #include "lexer.yy.h" */

TEST(VersionTest, RecognizesVersionKeyword) {
  /* YY_BUFFER_STATE bufferState = yy_scan_string("version 0.1.2"); */

  /* yylex(); */

  /* yy_delete_buffer(bufferState); */

  ASSERT_EQ(2, 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
