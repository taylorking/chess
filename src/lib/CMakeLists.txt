add_subdirectory(model)
add_subdirectory(pieces)

file(GLOB SRCS "*.cc")

add_library(chess ${SRCS})

target_include_directories(chess PUBLIC ".")

target_link_libraries(chess PUBLIC models pieces)
