CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o zyon.o ../yon/yon.o

TARGET =	zyon

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

all: $(TARGET)

install: $(TARGET)
	install $(TARGET) /usr/local/bin

clean:
	rm -f $(OBJS) $(TARGET)

uninstall:
	unlink /usr/local/bin/$(TARGET)
