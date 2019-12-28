CC=g++
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lz -lm -W

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog *~

