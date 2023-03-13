# Compiler
CXX				= g++
LIN				= ld

# Directory
SOURCE_FOLDER 	= src
OUTPUT_FOLDER	= bin
OBJECT_FOLDER	= bin/obj

# FLAGS
VERSION 		= --std=c++11
WARNING_CFLAG 	= -Wall -Wextra
CPPFLAGS		= $(VERSION) 

# LIST
CLASSES			= Ability Command Exception InventoryHolder Player Turn Values
MAIN			= $(SOURCE_FOLDER)/main.cpp
SRC 			= $(foreach class, $(CLASSES), $(wildcard $(SOURCE_FOLDER)/$(class)/*.cpp))\
				  $(MAIN)

run: compile
	@echo Starting program
	@$(OUTPUT_FOLDER)/Main

compile:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRC) -o $(OUTPUT_FOLDER)/Main
	@echo Compilation Done!


	




