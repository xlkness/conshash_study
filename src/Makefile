CC=g++
CFLAG =
SRCDIR = ./
OBJDIR = ./
BINDIR = ./

SRC = $(wildcard ${SRCDIR}/*.cpp)
OBJ = $(patsubst %.cpp,${OBJDIR}/%.o,$(notdir ${SRC}))

conhash:$(OBJ)
	$(CC) $(CFLAG) $^ -o $@
$(OBJDIR)/%.o:$(SRCDIR)/*.c
	$(CC) $^ -o $@ -c

clean:
	rm -rf *.o $(EXE)
