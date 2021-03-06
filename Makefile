CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = c4
OBJECTS = main.o cell.o grid.o textdisplay.o player.o node.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
