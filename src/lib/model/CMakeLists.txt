file(GLOB SRCS "*.cc")

add_library(models ${SRCS})
target_include_directories(models PUBLIC .)
target_link_libraries(models PUBLIC chess)
set_property(TARGET models PROPERTY CXX_STANDARD 20)
