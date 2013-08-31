CXXFLAGS =	-O2 -g -Wall -fmessage-length=0



OBJS= Kth_Parent.o

LIBS =

BUILD_DIR=/usr/build/

OBJS_FILE=$(foreach d,$(OBJS),$(BUILD_DIR)$d)

#TARGET =	ProgrammingStuff1
TARGET =	Main



$(TARGET):	$(OBJS)
	$(CXX) -o $(BUILD_DIR)$(TARGET) $(OBJS_FILE) $(LIBS)

all:	$(TARGET)




#includepath
#src/Utility

#filepath
#src/spoj/DataStructure/Heap/heap.cpp
#src/codechef/FEB13/MagicBoard.cpp
#src/Hackerrank/Median.cpp
#src/InterviewPreparation/binary_tree/maxPathSum.cpp
#src/c++Excersize/MemoryManagement/Integer.cpp
#src/InterviewPreparation/binary_tree/maxPathSum.cpp
#src/InterviewPreparation/list/ReverseLinkList.cpp
#src/InterviewPreparation/DP/MaximumRectangle.cpp
#src/InterviewPreparation/Array/RemoveDuplicatesFromSortedArray.cpp
#src/InterviewPreparation/search/wordSearch.cpp
#src/InterviewPreparation/recurrsion/subsets.cpp
#src/InterviewPreparation/Array/geeksforgeeks/ArraypairSumX.cpp
#src/InterviewPreparation/Array/geeksforgeeks/MajorityElement.cpp
#src/InterviewPreparation/Array/geeksforgeeks/FindTheNumbersOddOccurrence.cpp
#src/InterviewPreparation/Array/geeksforgeeks/FindMissingNumber.cpp
#src/InterviewPreparation/Array/geeksforgeeks/RotateArray.cpp
#src/os/sanjay/process/
#src/InterviewPreparation/strings
#CURRENT_DIR=src/InterviewPreparation/graph/
INCLUDE_DIR1=src/Utility
INCLUDE_DIR2=src/InterviewPreparation/Array
INCLUDE_DIR_STRING=src/InterviewPreparation/strings
INC=$(INCLUDE_DIR1) 
INC_PARAMS=$(foreach d, $(INC), -I$d)
INC_PARMS_STRING=$(foreach d,$(INCLUDE_DIR_STRING),-I$d)
STRINGS_FILE=$(INCLUDE_DIR_STRING)/stringtokenizer.h $(INCLUDE_DIR_STRING)/stringtokenizer.c

CURRENT_DIR=src/InterviewPreparation/strings/

FILE_NAME=stringTokenizer_test.c
FILE_PATH=$(CURRENT_DIR)$(FILE_NAME)

HAKERRANK_PATH=src/Hackerrank/

	



main.o:
	gcc   -c -g   $(FILE_PATH) -o $(BUILD_DIR)main.o
	


JourneyToMoon.o:
	gcc -c -g  $(HAKERRANK_PATH)JourneyToMoon.c -o $(BUILD_DIR)JourneyToMoon.o

stringTokenizer.o:$(STRINGS_FILE)
	gcc -c -g $(INC_PARMS_STRING) $(INCLUDE_DIR_STRING)/stringtokenizer.c -o $(BUILD_DIR)stringTokenizer.o

Kth_Parent.o:
	gcc -c -g $(HAKERRANK_PATH)Kth_Parent.cpp -o $(BUILD_DIR)Kth_Parent.o
clean:
	rm -f $(OBJS_FILE) $(BUILD_DIR)$(TARGET) 

run:
	make clean
	make all
	clear
	$(BUILD_DIR)$(TARGET) < input.txt > output1.txt
run1:
	make clean
	make all
	clear
	$(BUILD_DIR)$(TARGET)	