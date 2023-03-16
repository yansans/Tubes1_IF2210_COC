#include "InventoryHolder/DeckCards.hpp"
#include "Storage/DeckStorage.hpp"
#include "BlackjackGameMaster/BlackjackGameMaster.hpp"
#include "GameMaster/KerajaanPermen.hpp"
#include "Exception/Exception.h"

#include <iostream>

int tanyaMainLagi(int status){ // status, 0 : awal, 1 : akhir
    if(status == 0)printf("Pilih permainan:\n");
    else if(status == 1)printf("Lanjut?\n");
    printf("1. Main Kerajaan Permen\n");
    printf("2. Main Blackjack\n");
    if(status == 1)printf("3. Exit\n");

    printf("Pilihan : ");
    bool validInput = false;
    int option;
    while(!validInput){
        try{
            string input;
            getline(cin, input);
            if(input == "1"){
                option = 1;
            }else if(input == "2"){
                option = 2;
            }else if(input == "3" && status == 1){
                option = 3;
            }else{
                throw InvalidOptionInputException();
            }
            validInput = true;
        }catch(InvalidOptionInputException e){
            printf("Pilihan tidak valid, tolong pilih opsi yang diberikan\n");
        }
    }
    return option;
}

int main() {




    return 0;
}