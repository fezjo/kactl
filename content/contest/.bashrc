export CXXFLAGS="-O2 -g -std=c++17 -Wall -Wextra -Wconversion \
	-Wfatal-errors -fsanitize=undefined,address"
alias c='g++ $CXXFLAGS'
function cr() {
	exe=${1%.*}
	make $exe && ./$exe
}
xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
