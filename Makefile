# C++26 Feature Probe v3.1 - Windows cmd.exe first
CXX ?= g++
CXXFLAGS ?= -std=c++26 -Wall -Wextra
ENV_BAT ?=

.PHONY: all test test-mingw info report clean
all: test

test:
	@cmd /d /c run-tests.cmd --cxx "$(CXX)" --flags "$(CXXFLAGS)"

test-mingw:
	@cmd /d /c run-tests.cmd --env "$(ENV_BAT)" --cxx "$(CXX)" --flags "$(CXXFLAGS)"

info:
	@$(CXX) --version
	@$(CXX) -dumpmachine
	@$(CXX) -dumpfullversion

report:
	@type report.txt

clean:
	@if exist bin rmdir /s /q bin
	@if exist logs rmdir /s /q logs
	@if exist report.txt del /q report.txt
	@if exist feature-macros.txt del /q feature-macros.txt
	@mkdir bin
	@mkdir logs
