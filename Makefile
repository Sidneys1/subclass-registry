CXX=/usr/bin/clang++
CXX_ARG=--std=c++14 -Wall -Werror -Wextra

.PHONY: all

all: a.out

a.out: main.cpp
	@$(CXX) $(CXX_ARG) main.cpp