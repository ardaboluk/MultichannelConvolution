CC = g++ # C compiler
INCLUDEPATH = -I../ConvolutionCore -I../MultichannelConvolution
LIBRARYPATH = -L../ConvolutionCore -L../MultichannelConvolution
LIBS = -lconvolutioncore -lmcconvolution `pkg-config --cflags --libs opencv`
CFLAGS = $(INCLUDEPATH) $(LIBRARYPATH) -Wall -O2 -g # C flags
LDFLAGS = # linking flags
RM = rm -f  # rm command
TARGET = ConvolutionTest # target

SRCS =  ConvolutionTest.cpp # source files

.PHONY: all
all: ${TARGET}

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	-${RM} ${TARGET}