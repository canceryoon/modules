CC=gcc
CXX=g++
OBJS=cy_queue.o cy_thread.o cy_threadManager.o cy_logger.o
SRCS=cy_queue.cpp main.cpp
LIBS=
INCS=
TARGET=all

INCDIR=
LIB64DIR=
LIB64=-lpthread

LIBS=$(LIB64DIR) $(LIB64)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $(TARGET) main.cpp $(OBJS) $(INCDIR) $(LIBS)	

logger : cy_queue.o cy_logger.o
	$(CXX) -o logger log_main.cpp $(OBJS) $(INCDIR) $(LIBS)

cy_logger.o : cy_threadManager.o
	$(CXX) -c cy_logger.cpp  $(INCDIR) $(LIBS)

thd : cy_threadManager.o
	$(CXX) -o thd thd_main.cpp cy_thread.o $(INCDIR) $(LIBS)

cy_threadManager.o : cy_thread.o
	$(CXX) -c cy_threadManager.cpp $(INCDIR) $(LIBS)

cy_thread.o : 
	$(CXX) -c cy_thread.cpp $(INCDIR) $(LIBS) 

cy_queue.o : 
	$(CXX) -c cy_queue.cpp

$(OBJ)
clean:
	rm -rf *.o cyq thd logger
