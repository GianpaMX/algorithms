add_executable(sudoku_check main.c sudoku_check.c)
target_link_libraries(sudoku_check LINK_PUBLIC btree print_array)
