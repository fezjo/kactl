#!/bin/bash
flags="-O2 -g -std=c++17 -Wall -Wextra -Wfatal-errors -Wconversion -Wshadow"
alias c="g++ $flags"
export CXXFLAGS="$flags -fsanitize=undefined,address"
function cr() {
	exe=${1%.*}
	make $exe && printf "compiled\n--------\n" && time ./$exe
}
xmodmap -e 'clear lock' -e 'keycode 66=Escape' #caps = Esc
