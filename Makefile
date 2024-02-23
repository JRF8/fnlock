# this is my makefile for fnlock

CC=gcc #compiler
PREFIX=/usr/local


all:	fnlock.o
	$(CC) fnlock.c -o fnlock

clean:  fnlock.o fnlock
	rm fnlock.o fnlock

install:	fnlock
	mkdir -p $(DESTDIR)$(PREFIX)/bin/
	cp fnlock $(DESTDIR)$(PREFIX)/bin/
	chown root:root $(DESTDIR)$(PREFIX)/bin/fnlock
	chmod ug+s $(DESTDIR)$(PREFIX)/bin/fnlock

uninstall:	$(DESTDIR)$(PREFIX)/bin/fnlock
	rm $(DESTDIR)$(PREFIX)/bin/fnlock
