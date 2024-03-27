CXX_FLAGS = -std=c++17

TRGT = snake

DO: DO_SNAKE

DO_SNAKE: controller.o game.o view.o main.o
	@g++ controller.o game.o view.o main.o -o $(TRGT) $(CXX_FLAGS)
	@rm -f *.o
	@echo '$(TRGT) has been done'
	@echo '.o files are cleaned'

controller.o: Controller/controller.cpp
	@g++ -c -o  controller.o Controller/controller.cpp $(CXX_FLAGS)

game.o: Game/game.cpp
	@g++ -c -o game.o Game/game.cpp $(CXX_FLAGS)

view.o: Ui/view.cpp
	@g++ -c -o view.o Ui/view.cpp $(CXX_FLAGS)

main.o: Main/main.cpp
	@g++ -c -o main.o Main/main.cpp $(CXX_FLAGS)

run: $(TRGT)
	@./$(TRGT)

clean:
	@rm -f *.o
	@echo '.o files are cleaned'
