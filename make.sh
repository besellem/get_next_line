# -Wall -Wextra -Werror -fsanitize=address
gcc -D BUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c -I get_next_line.h
# gcc -Wall -Wextra -Werror -fsanitize=address get_next_line_bonus.c get_next_line_utils_bonus.c -I get_next_line_bonus.h
