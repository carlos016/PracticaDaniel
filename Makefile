CC=g++
CXXFLAGS=-g

OBJS = ./src/main_polynomial.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o main_polynomial ${OBJS}

clean:
	rm main_polynomial && cd src &&  rm -rf *.o
