bme280:main2.o bme280.o sensor.o
	gcc -Wall -o bme280 main2.o sensor.o bme280.o -lwiringPi -std=gnu99
main2.o: main2.cpp bme280.h bme280_defs.h
	g++ -Wall -c main2.cpp
bme280.o: bme280.c bme280.h bme280_defs.h
	gcc -Wall -c bme280.c -std=gnu99
sensor.o: sensor.c sensor.h
	gcc -Wall -c sensor.c -std=gnu99
clean:
	rm main2.o bme280.o bme280
