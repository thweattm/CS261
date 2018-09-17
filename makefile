FILES=main.cpp AirDuct.cpp AirDuct.h Bathroom.cpp Bathroom.h BossesOffice.cpp BossesOffice.h BreakRoom.cpp BreakRoom.h ChattyCathy.cpp ChattyCathy.h Closet.cpp Closet.h HallWay.cpp HallWay.h Player.cpp Player.h Room.cpp Room.h YourOffice.cpp YourOffice.h
EXECUTABLE=FinalProject

main: ${FILES}
	g++ -g ${FILES} -o ${EXECUTABLE}

clean:
	rm -f *.o
	rm ${EXECUTABLE}