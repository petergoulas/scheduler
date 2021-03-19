##Adapted from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
##and https://stackoverflow.com/questions/18252734/using-o-files-in-makefile
##and workshops materials

##Create executable 
all: $(scheduler.c)
	gcc scheduler.c -o scheduler -std=c99 -O3 -Wall -Wpedantic -lm
	
##clean
clean:
	rm -rf *.o scheduler