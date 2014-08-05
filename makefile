#compiler: Wall:Warnings:all, c:compileToObject, std=c++11(c++2011features), g:produceDebugSymbols
CC=g++
CCFLAGS=-Wall -c -std=c++11
# linker: link sfml modules, s:stripStuff/minimize size
LD=g++
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
# include directory to search in
INC=./Include/
# directory for build-files like objs etc
TEMP=./Temp/
# source dir 
SRC=./Source/
# objects to be compiled (OBJ = TEMPDIR/OBJS)
OBJS=Aircraft.o Animation.o Application.o BloomEffect.o Button.o Command.o CommandQueue.o Component.o Container.o DataTables.o EmitterNode.o Entity.o GameOverState.o GameState.o IntoState.o Label.o LogoState.o Main.o MenuState.o MusicPlayer.o OutroState.o ParticleNode.o PauseState.o Pickup.o Player.o PostEffect.o Projectile.o SceneNode.o SoundNode.o SoundPlayer.o SpriteNode.o State.o StateStack.o TextNode.o Utility.o World.o 
OBJ=$(OBJS:%=$(TEMP)%) 

# executables name
EXE=prog

# Build all
all: $(EXE)
# Link Exe
$(EXE): $(OBJ)
	$(LD) -o $(EXE) $(OBJ) $(LDFLAGS)
# Build object-files
$(TEMP)%.o: $(SRC)%.cpp makefile
	$(CC) $< $(CCFLAGS) -I$(INC) -o $@
# delete
clean: clear
clear:
	rm -f *.o prog $(TEMP)/*.o
# run exe
run: $(EXE)
	./$(EXE)
