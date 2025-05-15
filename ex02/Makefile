NAME = ex02

SRC = 	src/main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp\
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/PresidentialPardonForm.cpp \
	
OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror -I./inc

RM = rm -rf

GREEN   = \033[32m
RED     = \033[31m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

%.o: %.cpp
	@echo "$(GREEN)Compiling $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing executable $(NAME)...$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re