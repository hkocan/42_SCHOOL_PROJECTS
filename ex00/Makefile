NAME = ex00

SRC = src/main.cpp \

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -I./inc

RM = rm -rf

GREEN   = \033[32m
RED     = \033[31m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CXX) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

%.o: %.cpp
	@echo "$(GREEN)Compiling $<$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)Removing executable $(NAME)...$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re