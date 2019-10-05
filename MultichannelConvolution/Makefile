CXX = g++ # C compiler
INCLUDEPATH = -I../ConvolutionCore
LIBRARYPATH = -L../ConvolutionCore
LIBS = -lconvolutioncore
CXXFLAGS = $(INCLUDEPATH) -c -fPIC -Wall -Werror -O2 -g # C flags
LDFLAGS = $(LIBRARYPATH) -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libmCXXonvolution.so # target lib

SRCS =  convolution3.cpp image3.cpp kernel3.cpp util.cpp # source files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}
