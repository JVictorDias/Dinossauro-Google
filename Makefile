#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need

#LIBRARY_PATHS specifies the additional library paths we'll need
# only needed on Windows, on Ubuntu it is already as system enviroment

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -g compiles with debug 
# -Wl,-subsystem,windows gets rid of the console window

#LINKER_FLAGS specifies the libraries we're linking against
# -lmingw32 must come before -lSDL2main
# -lSDL2main must come before -lSDL2

#OBJ_NAME specifies the name of our exectuable

ifeq ($(OS),Windows_NT)
	INCLUDE_PATHS := -ID:\CPP_Projects\PIG\include
	INCLUDE_PATHS += -ID:\CPP_Projects\PIG\include\SDL
	INCLUDE_PATHS += -ID:\CPP_Projects\PIG\include\SDL_image
	
	LIBRARY_PATHS := -LD:\CPP_Projects\PIG\lib_x64
	
	COMPILER_FLAGS := -g -Wl,-subsystem,windows
	
	LINKER_FLAGS = -lpthread -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

	OBJ_NAME = main.exe
else
	INCLUDE_PATHS := -I$(HOME)/CPP_Projects/PIG/include
	INCLUDE_PATHS += -I/usr/include/SDL2
	
	COMPILER_FLAGS := -g
	
	LINKER_FLAGS = -lpthread -lSDL2 -lSDL2_ttf -lSDL2_image
	
	OBJ_NAME = main
endif

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)