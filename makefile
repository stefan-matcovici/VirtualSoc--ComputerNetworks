all : client server
client:
	cd Client/gui; \
	mkdir build/; \
	cd build/; \
	qmake ../client.pro; \
	$(MAKE); \

server:
	cd Server && $(MAKE);\

.PHONY: all client server
clean :
	rm -rf Server/build Client/gui/build
