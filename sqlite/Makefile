CC=gcc
CXX=g++
OBJS=cy_sqlite.o
SRCS=cy_sqlite.cpp main.cpp
LIBS=
INCS=
TARGET=cy_sqlite

INCDIR=-I/usr/include
LIB64DIR=-L/usr/lib64
LIB64=-lsqlite3

LIBS=$(LIB64DIR) $(LIB64)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $(TARGET) main.cpp $(OBJS) $(INCDIR) $(LIBS)	

cy_sqlite.o : cy_sqlite.cpp
	$(CXX) -o $(OBJS) -c cy_sqlite.cpp $(INCDIR) $(LIBS) 

$(OBJ)
clean:
	rm -rf *.o cy_sqlite


