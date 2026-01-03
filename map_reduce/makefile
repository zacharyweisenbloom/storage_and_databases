PARAMS = -Wall -g -v
all: controller worker
controller: controller.cpp
	g++ controller.cpp -o controller $(PARAMS)
worker: worker.cpp
	g++ worker.cpp -o worker $(PARAMS)
	

clean:
	rm controller
	rm worker 
