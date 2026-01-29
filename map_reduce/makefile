PARAMS = -Wall #-g -v

all: controller worker client

controller: controller.cpp
	g++ controller.cpp -o controller $(PARAMS)
worker: worker.cpp
	g++ worker.cpp -o worker $(PARAMS)
client: client.cpp
	g++ client.cpp -o client $(PARAMS)

clean:
	rm controller
	rm worker 
	rm client
