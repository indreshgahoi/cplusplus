CC       = c++
CFLAGS   = -g -O2
DFLAGS   = -DPACKAGE=\"threadsystem\" -DVERSION=\"3.0\" -DPTHREAD=1 -DUNIX_MSG_Q=1 -DSTDC_HEADERS=1
IFLAGS   = -I/usr/local/ThreadMentor/fedora4/include
TMLIB    = /usr/local/ThreadMentor/fedora4/Visual/libthreadclass.a
TMLIB_NV    = /usr/local/ThreadMentor/fedora4/NoVisual/libthreadclass.a

OBJ_FILE = merge.o merge-main.o
EXE_FILE = merging 

${EXE_FILE}: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB} -lpthread

merge.o: merge.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c merge.cpp

merge-main.o: merge-main.cpp
	${CC} ${DFLAGS} ${IFLAGS} ${CFLAGS} -c merge-main.cpp

noVisual: ${OBJ_FILE}
	${CC} ${FLAGS}  -o ${EXE_FILE}  ${OBJ_FILE} ${TMLIB_NV} -lpthread
	
clean:
	rm -f ${OBJ_FILE} ${EXE_FILE}

