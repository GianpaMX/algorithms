add_library (factorial factorial.c)
target_include_directories (factorial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
