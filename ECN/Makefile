CXX = g++
CXXFLAGS = -Wall -g
target:
\tcmd

main: main.o interpreter.o Runtime.o Frame.o MyMemory.o Data.o
    $(CXX) $(CXXFLAGS) -o main main.o interpreter.o MyMemory.o Runtime.o Data.o Frame.o
main.o: main.cpp interpreter.h Runtime.h Frame.h MyMemory.h Data.h
    $(CXX) $(CXXFLAGS) -c main.cpp

interpreter.o: interpreter.h MyMemory.h Data.h
Runtime.o: Runtime.h MyMemory.h Data.h
Frame.o: Frame.h MyMemory.h Data.h
MyMemory.o: MyMemory.h Data.h
Data.o: Data.h
 
#g++ -Wall -g -c -o Data.o Data.cpp
#g++ -Wall -g -c -o MyMemory.o MyMemory.cpp
#g++ -Wall -g -c -o Frame.o Frame.cpp
#g++ -wall -g -c -o Runtime.o Runtime.cpp
#g++ -Wall -g -c -o interpreter.o interpreter.cpp
#g++ -Wall -g -c main.cpp 


#g++ -Wall -g -o main main.o interpreter,o Runtime.o Data.o Frame.o 
clean:
    -rm -f test *.o
