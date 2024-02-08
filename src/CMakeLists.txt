add_subdirectory(lib)

file(GLOB SRCS "*.cc")

add_executable(chess.m ${SRCS})

target_link_libraries(chess.m PUBLIC chess)
