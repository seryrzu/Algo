CXX=g++

# CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS +=  -Wall -Wextra -pthread
CXXFLAGS += --std=c++11
LDFLAGS += -pthread -lpthread -lgtest_main 

main: clean ld ldtest

clean: 
	rm -f *.o

ldtest: list-test.o list.o
	${CXX} ${LDFLAGS} $^ -lgtest_main -lgtest -o $@

ld: list.o
	${CXX} ${LDFLAGS} list.o -o list

list.o: 
	${CXX} -c ${CXXFLAGS} list.cpp -o list.o

list-test.o: 
	${CXX} -c ${CXXFLAGS} list-test.cpp -o list-test.o
