
CC = gcc
O_FLAGS = -fpic -c -Wall -I/usr/include/python2.6
SO_FLAGS = -shared
OBJECTS = math_bin.o wrapper.o
SO = math_bin.so

all:$(SO)

$(SO):$(OBJECTS)
	$(CC) $(SO_FLAGS) -o $@ $(OBJECTS)
    
%.o:%.c
	$(CC) $(O_FLAGS) $<

clean:
	rm -fr *.o *.so
