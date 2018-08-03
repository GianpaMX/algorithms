add_executable(balance_parenthesis main.c is_balanced.c is_balanced.h ../first_not_repeating_char/first_not_repeating_char.c ../first_not_repeating_char/first_not_repeating_char.h)
target_link_libraries (balance_parenthesis LINK_PUBLIC stack)
