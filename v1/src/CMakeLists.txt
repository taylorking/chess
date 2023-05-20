
add_executable(tkchess "tkchess.m.cc")

add_subdirectory(lib)

target_link_libraries(tkchess PUBLIC chess)
