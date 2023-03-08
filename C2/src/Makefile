bf.out: brainfuck.c
	g++ brainfuck.c -o bf.out

main.out: main.cpp
	g++ main.cpp -o main.out
	strip -s main.out -o a.out

codes.txt: bf.out
	./gen_programs.sh

clean:
	rm *.out codes.txt