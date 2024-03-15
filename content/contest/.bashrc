#!/bin/bash
alias c="g++ -O2 -g -std=c++17 -Wall -Wextra -Wfatal-errors"
export CXXFLAGS="-O2 -g -std=c++17 -Wall -Wextra -Wfatal-errors -Wconversion  -fsanitize=undefined,address"
function cr() {
	exe=${1%.*}
	make $exe && echo compiled && time ./$exe
}
xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
