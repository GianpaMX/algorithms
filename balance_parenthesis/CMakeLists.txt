add_executable(balance_parenthesis main.c is_balanced.c is_balanced.h)
target_link_libraries (balance_parenthesis LINK_PUBLIC stack)
