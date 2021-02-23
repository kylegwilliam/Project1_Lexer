cmake_minimum_required(VERSION 3.17)
project(Project1_Lexer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1_Lexer main.cpp Lexer.cpp Lexer.h Token.cpp Token.h Automaton.cpp Automaton.h MatcherAutomaton.cpp MatcherAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h Rule.cpp Rule.h)