CC := g++ -std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: mario.out

mario.out: main.o CommandHandler.o rsdl.o Brick.o Block.o Clay.o Pipe.o Flag.o Sprites.o Mario.o Goomba.o Enemies.o Kroopa.o Question.o
	$(CC) main.o rsdl.o CommandHandler.o Brick.o Block.o Clay.o Pipe.o Flag.o Sprites.o Mario.o Goomba.o Enemies.o Kroopa.o Question.o $(CCFLAGS) -o mario.out

main.o: CommandHandler.hpp main.cpp
	$(CC) -c main.cpp -o main.o

CommandeHandler.o: CommandeHandler.hpp Sprites.hpp Mario.hpp Enemies.hpp CommandHandler.cpp
	$(CC) -c CommandHandler.cpp -o CommandHandler.o

Brick.o: Brick.hpp src/rsdl.hpp Sprites.hpp Brick.cpp
	$(CC) -c Brick.cpp -o Brick.o
	
Question.o: Question.hpp src/rsdl.hpp Sprites.hpp Question.cpp
	$(CC) -c Question.cpp -o Question.o

Block.o: Block.hpp src/rsdl.hpp Sprites.hpp Block.cpp
	$(CC) -c Block.cpp -o Block.o

Clay.o: Clay.hpp src/rsdl.hpp Sprites.hpp Clay.cpp
	$(CC) -c Clay.cpp -o Clay.o

Flag.o: Flag.hpp src/rsdl.hpp Sprites.hpp Flag.cpp
	$(CC) -c Flag.cpp -o Flag.o

Pipe.o: Pipe.hpp src/rsdl.hpp Sprites.hpp Pipe.cpp
	$(CC) -c Pipe.cpp -o Pipe.o

Sprites.o: Sprites.hpp Brick.hpp Block.hpp Clay.hpp Flag.hpp Pipe.hpp Question.hpp Sprites.cpp
	$(CC) -c Sprites.cpp -o Sprites.o

Enemies.o: src/rsdl.hpp Goomba.hpp Kroopa.hpp Enemies.hpp Sprites.hpp Enemies.cpp
	$(CC) -c Enemies.cpp -o Enemies.o

Mario.o: src/rsdl.hpp Mario.hpp Sprites.hpp Mario.cpp
	$(CC) -c Mario.cpp -o Mario.o
	
Goomba.o: src/rsdl.hpp Goomba.hpp Enemies.hpp Sprites.hpp Goomba.cpp
	$(CC) -c Goomba.cpp -o Goomba.o

Kroopa.o: src/rsdl.hpp Kroopa.hpp Enemies.hpp Sprites.hpp Kroopa.cpp
	$(CC) -c Kroopa.cpp -o Kroopa.o

rsdl.o: src/rsdl.hpp src/rsdl.cpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o