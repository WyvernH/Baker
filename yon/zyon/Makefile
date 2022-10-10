PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o zyon.o ../yon/yon.o

TARGET =	zyon

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

install: $(TARGET)
	install $(TARGET) $(BINDIR)

clean:
	rm -f $(OBJS) $(TARGET)

uninstall:
	unlink $(BINDIR)/$(TARGET)
