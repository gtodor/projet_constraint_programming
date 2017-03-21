all: solver

solver: main.cpp domaine.cpp problem.cpp queens.cpp node.cpp prune.cpp solver.cpp backtracking.cpp arcConsistency.cpp
	g++ -Wall -Wextra -O3 -o $@ $^

domaine.cpp: domaine.hpp
problem.cpp : problem.hpp
queens.cpp: queens.hpp
node.cpp: node.hpp
prune.cpp: prune.hpp
solver.cpp:solver.hpp
backtracking.cpp:backtracking.hpp
arcConsistency.cpp:arcConsistency.hpp

PHONY: clean

clean:
	@rm *~ solver


