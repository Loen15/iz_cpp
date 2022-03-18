packages:
	sudo apt-get update -y && \
	sudo apt-get install build-essential && \
	sudo apt-get install -y cppcheck clang-tidy python3-pip libc6-dbg lcov libgtest-dev && \
	pip3 install cpplint && \
	sudo apt-get install valgrind

build:
	mkdir build && \
	cd build && \
	cmake .. &&\
	cmake --build . &&\

analysis:
	chmod +x ./linters/run.sh &&\
	./linters/run.sh

test:
	./build/tests/test_stake && \
	valgrind --tool=memcheck --leak-check=yes ./build/tests/test_stake &&\
	lcov -t "tests/tests_stake" -o coverage.info -c -d start/ &&\
    genhtml -o report coverage.info &&\
    python3 -m http.server 8000