CC = g++ # C compiler
INCLUDEPATH = -I../ConvolutionCore
LIBRARYPATH = -L../ConvolutionCore
LIBS = -lconvolutioncore
CFLAGS = $(INCLUDEPATH) $(LIBRARYPATH) -c -fPIC -Wall -Werror -O2 -g # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libmcconvolution.so # target lib

SRCS =  convolution3.cpp image3.cpp kernel3.cpp util.cpp # source files
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
