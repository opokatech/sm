sm: main.cpp  Makefile
	g++ -Wall -Wextra -pedantic main.cpp State.cpp StateMachine.cpp StateStartUp.cpp StateOperational.cpp -o $@

clean:
	@rm -f sm
