CC=gcc
CXX=g++
OBJS=cy_queue.o
SRCS=cy_queue.cpp main.cpp
LIBS=
INCS=
TARGET=cyq

INCDIR=
LIB64DIR=
LIB64=

LIBS=

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $(TARGET) main.cpp $(OBJS) $(INCDIR) $(LIBS)	

cy_queue.o : cy_queue.cpp
	$(CXX) -o $(OBJS) -c cy_queue.cpp $(INCDIR) $(LIBS) 

$(OBJ)
clean:
	rm -rf *.o cy_queue.o cyq


