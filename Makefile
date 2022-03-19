packages:
	sudo apt-get update -y && \
	sudo apt-get install build-essential && \
	sudo apt-get install -y cppcheck clang-tidy python3-pip libc6-dbg lcov libgtest-dev && \
	pip3 install cpplint && \
	sudo apt-get install valgrind

build:
	mkdir build && \
	cd build && \
	cmake ../untitled && \
	make
analysis:
	chmod +x ./linters/run.sh &&\
	./linters/run.sh

test:
	./build/tests/test_stake && \
	valgrind --tool=memcheck --leak-check=yes ./build/tests/test_stake

report:
	lcov -t "build/tests/test_stake" -o coverage.info -c -d build/start