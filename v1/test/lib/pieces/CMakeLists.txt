find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SRCS "*.cc")

add_executable(pieces_tests ${TEST_SRCS})
target_link_libraries(pieces_tests PUBLIC chess pieces GTest::gtest GTest::gtest_main gmock)
target_include_directories(pieces_tests PUBLIC ".")
gtest_discover_tests(pieces_tests)
