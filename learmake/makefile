objects = hello.o add.o sub.o
main:clean ${objects}
	 gcc main.c ${objects} -o main.o

hello.o:hello.c
	echo "hello makefile"
	gcc -c hello.c
add.o:add.c
	gcc -c add.c
sub.o:sub.c
	gcc -c sub.c

.PHONY:clean
clean:
	rm -rf ${objects}
