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
CLASSES			= Ability Command Exception InventoryHolder Player GameFlow Values AbilityHolder Util BlackjackGameMaster GameMaster
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



# Only play 1 game
MAINPERMEN				= $(SOURCE_FOLDER)/kerajaanpermenmain.cpp
MAINBLACKJACK 			= $(SOURCE_FOLDER)/blackjackmain.cpp
PERMEN					= Permen
BLACKJACK 				= blackjack

permen:compilepermen
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(PERMEN)

compilepermen:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRC) $(MAINPERMEN) -o $(OUTPUT_FOLDER)/$(PERMEN)
	@echo Compilation Done!

runpermen:
	@$(OUTPUT_FOLDER)/$(PERMEN)


blackjack:compileblackjack
	@echo Starting program
	@$(OUTPUT_FOLDER)/$(BLACKJACK)

compileblackjack:
	@echo Compiling...
	@$(CXX) $(CPPFLAGS) $(SRC) $(MAINBLACKJACK) -o $(OUTPUT_FOLDER)/$(BLACKJACK)
	@echo Compilation Done!

runblackjack:
	@$(OUTPUT_FOLDER)/$(BLACKJACK)
