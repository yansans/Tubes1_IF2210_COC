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
CLASSES			= Command Exception InventoryHolder Player Turn Values 
MAIN			= $(SOURCE_FOLDER)/main.cpp
SRC 			= $(foreach class, $(CLASSES), $(wildcard $(SOURCE_FOLDER)/$(class)/*.cpp))\
				  $(MAIN)

EXECUTABLE		= MAIN

run: compile
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(EXECUTABLE)

compile:
	@echo Compiling...
	@echo $(SRC)
	@$(CXX) $(CPPFLAGS) $(SRC) -o $(OUTPUT_FOLDER)/$(EXECUTABLE)
	@echo Compilation Done!

# TEMPORARY FLAG FOR KERAJAAN PERMEN
CLASSESPERMEN			= Ability Command Exception InventoryHolder Player Turn Values
MAINPERMEN				= $(SOURCE_FOLDER)/kerajaanpermenmain.cpp
SRCPERMEN 				= $(foreach class, $(CLASSESPERMEN), $(wildcard $(SOURCE_FOLDER)/$(class)/*.cpp))\
							$(MAINPERMEN)

permen:compilepermen
	@echo Starting program
	@$(OUTPUT_FOLDER)/Permen

compilepermen:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRCPERMEN) -o $(OUTPUT_FOLDER)/Permen
	@echo Compilation Done!



