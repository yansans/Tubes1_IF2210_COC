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
CLASSES			= Command Exception InventoryHolder Player GameFlow Values Util
MAIN			= $(SOURCE_FOLDER)/main.cpp
SRC 			= $(foreach class, $(CLASSES), $(wildcard $(SOURCE_FOLDER)/$(class)/*.cpp))

EXECUTABLE		= MAIN

run: compile
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(EXECUTABLE)

compile:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRC) $(MAIN) -o $(OUTPUT_FOLDER)/$(EXECUTABLE)
	@echo Compilation Done!

# CLASS DRIVER
COMMAND_DRIVER	= $(SOURCE_FOLDER)/Command/test/test.cpp
command: compilecommand
	@$(OUTPUT_FOLDER)/$^

compilecommand: 
	@$(CXX) $(CPPFLAGS) $(SRC) $(COMMAND_DRIVER) -o $(OUTPUT_FOLDER)/$@








# TEMPORARY FLAG FOR KERAJAAN PERMEN
CLASSESPERMEN			= Ability Command Exception InventoryHolder Player GameFlow Values AbilityHolder
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



