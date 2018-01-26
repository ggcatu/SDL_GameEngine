#OBJS specifies which files to compile as part of the project
OBJS = initialize.cpp Game.cpp TextureManager.cpp GameObject.cpp Vector2D.cpp Map.cpp Collision.cpp ECS/ECS.hpp ECS/PositionComponent.hpp

#CC specifies which compiler we're using
CC = g++ -std=c++11

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -I/usr/include/SDL2 -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
