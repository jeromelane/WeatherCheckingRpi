bme280:main2.o bme280.o sensor.o Average.o
	g++ -Wall -o bme280 main2.o sensor.o bme280.o Average.o -lwiringPi
main2.o: main2.cpp Average.h sensor.h
	g++ -Wall -c main2.cpp
Average.o: Average.cpp Average.h sensor.h
	g++ -Wall -c Average.cpp
bme280.o: bme280.c bme280.h bme280_defs.h
	gcc -Wall -c bme280.c -std=gnu99
sensor.o: sensor.c sensor.h
	gcc -Wall -c sensor.c -std=gnu99
clean:
	rm Average.o main2.o bme280.o bme280 sensor.o
