CC = g++ # C compiler
CFLAGS = -c -fPIC -Wall -Werror -O2 -g # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libconvolutioncore.so # target lib

SRCS =  point.cpp rectangle.cpp # source files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}
