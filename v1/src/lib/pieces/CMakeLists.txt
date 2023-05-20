file(GLOB SRCS "*.cc")

add_library(pieces ${SRCS})

target_include_directories(pieces PUBLIC ".")

target_link_libraries(pieces PUBLIC chess)


