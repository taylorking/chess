include(GoogleTest)

file(GLOB TEST_SRCS "*.cc")

add_executable(chess_tests ${TEST_SRCS})
target_link_libraries(chess_tests PUBLIC chess GTest::gtest GTest::gtest_main gmock)

gtest_discover_tests(chess_tests)

add_subdirectory(pieces)
