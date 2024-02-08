find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SRCS "*.cc")

add_executable(pieces_tests ${TEST_SRCS})
target_link_libraries(pieces_tests PUBLIC models pieces GTest::gtest GTest::gtest_main)
target_include_directories(pieces_tests PUBLIC ".")
gtest_discover_tests(pieces_tests)
add_test(pieces_tests          COMMAND testDriver --config $<CONFIG>
                            --exe $<TARGET_FILE:myexe>))
