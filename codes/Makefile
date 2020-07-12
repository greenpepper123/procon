CC = g++
CFLAGS = -g -Wall
SRCS := $(wildcard *.cpp)
OBJS := $(addprefix build/,$(patsubst %.cpp,%.o,$(SRCS)))
EXECS := $(patsubst %.cpp,%,$(SRCS))

build/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXECS): $(OBJS)
	$(CC) $(CFLAGS) -o $@ build/$@.o

all: $(EXECS)

clean:
	rm -rf $(EXECS) $(OBJS)
