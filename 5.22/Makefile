libmymath.so:add.o sub.o
		gcc -shared $^ -o $@ 

%.o:%.c
	gcc -fPIC -c $<

.PHONY:clean 
clean:
	rm -rf libmymath.so *.o

.PHONY:lib 
lib:
	mkdir lib 
	cp *.h lib 
	cp libmymath.so lib









#libmymath.a:add.o sub.o
#	ar -rc $@ $^
#
#%.o:%.c
#	gcc -c $<
#
#.PHONY:clean
#clean:
#	rm -rf *.o output libmymath.a
#
#.PHONY:output
#output:
#	mkdir output
#	cp -rf *.h output 
#	cp libmymath.a output
