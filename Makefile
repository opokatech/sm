.PHONY: sm
sm:
	g++ -Wall -Wextra -pedantic *.cpp -o $@

clean:
	@rm -f sm
