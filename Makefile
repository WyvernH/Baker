DIRS =		yon zyon

all: $(DIRS)
	for dir in $(DIRS) ; do $(MAKE) -C $${dir} ; done

install: $(DIRS)
	for dir in $(DIRS) ; do $(MAKE) -C $${dir} install ; done

clean: $(DIRS)
	for dir in $(DIRS) ; do $(MAKE) -C $${dir} clean ; done

uninstall:
	for dir in $(DIRS) ; do $(MAKE) -C $${dir} uninstall ; done
