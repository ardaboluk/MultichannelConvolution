CC = g++ # C compiler
INCLUDEPATH = -I../ConvolutionCore -I../MultichannelConvolution
LIBRARYPATH = -L../ConvolutionCore -L../MultichannelConvolution
LIBS = -lconvolutioncore -lmcconvolution `pkg-config --cflags --libs opencv`
CFLAGS = $(INCLUDEPATH) -Wall -O2 -g # C flags
LDFLAGS = $(LIBRARYPATH) # linking flags
RM = rm -f  # rm command
TARGET = ConvolutionTest # target

SRCS =  ConvolutionTest.cpp # source files
OBJS = 	$(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET}

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	-${RM} ${TARGET}
