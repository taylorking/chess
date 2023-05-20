file(GLOB SRCS "*.cc")

add_library(chess ${SRCS})

target_include_directories(chess PUBLIC ".")
add_subdirectory(pieces)
target_link_libraries(chess PUBLIC pieces)
