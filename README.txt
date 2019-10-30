=============== PROJECT 2 ===============
===     Austen Kelly (951632601)	  ===
===            10/29/2019	       	  ===
=========================================

This project contains a parser written for Quack.
If run with a valid quack program, it prints out the
resulting AST object. Else, it returns the line number
of the first syntax error. (I'm hoping to implement better
error handling soon, but figured its best to turn in this
working version before possibly breaking it with error
handling issues.)


To set up:
	1) Run "make image"
	2) Run "docker image ls" (to check it successfully
				created the image "compilers-parser")
	3) Run "docker run -it compilers-parser"

The dockerfile copies from michalyoung/cis461:base, creates
my project as proj1, and builds the program.

To run (after building):

	./bin/parser samples/LexChallenge.qk


