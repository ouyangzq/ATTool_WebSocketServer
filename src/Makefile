ifndef CC
CC = gcc
endif
ifndef LD
LD = ld
endif

SOURCES = controller.c dataxfer.c devcfg.c readconfig.c selector.c ser2net.c utils.c telnet.c http.c sha1.c list.c 
SOURCES2 = pdu.c pdu_decoder.c ucs2_to_utf8.c ATTool.c
OBJS := $(SOURCES:.c=.o)
OBJS2 := $(SOURCES2:.c=.o)

ifndef CFLAGS
CFLAGS := -O2
endif
CPPFLAGS := -I ATTool

n2w: $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

ATTool: $(OBJS2)
	$(CC) $^ -o $@ $(LDFLAGS2)


clean:
	rm -rf n2w ATTool $(OBJS)

compile: n2w ATTool

install: compile
	mkdir -p $(DESTDIR)/usr/sbin
	cp n2w $(DESTDIR)/usr/sbin/n2w
	cp ATTool $(DESTDIR)/usr/sbin/ATTool

	

