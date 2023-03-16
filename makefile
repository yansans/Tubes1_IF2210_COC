# Compiler
CXX				= g++
LIN				= ld

# Directory
SOURCE_FOLDER 	= src
OUTPUT_FOLDER	= bin
OBJECT_FOLDER	= bin/obj

# FLAGS
VERSION 		= --std=c++17
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
CLASSESPERMEN			= Ability Command Exception InventoryHolder Player GameFlow Values AbilityHolder Util BlackjackGameMaster GameMaster
MAINPERMEN				= $(SOURCE_FOLDER)/kerajaanpermenmain.cpp
SRCPERMEN 				= $(foreach class, $(CLASSESPERMEN), $(wildcard $(SOURCE_FOLDER)/$(class)/*.cpp))\
							

PERMEN					= Permen
permen:compilepermen
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(PERMEN)

compilepermen:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRCPERMEN) $(MAINPERMEN) -o $(OUTPUT_FOLDER)/$(PERMEN)
	@echo Compilation Done!

runpermen:
	@$(OUTPUT_FOLDER)/$(PERMEN)


MAINBLACKJACK 			= $(SOURCE_FOLDER)/blackjackmain.cpp
BLACKJACK 				= blackjack
blackjack:compileblackjack
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(BLACKJACK)

compileblackjack:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRCPERMEN) $(MAINBLACKJACK) -o $(OUTPUT_FOLDER)/$(BLACKJACK)
	@echo Compilation Done!

runblackjack:
	@$(OUTPUT_FOLDER)/$(BLACKJACK)
