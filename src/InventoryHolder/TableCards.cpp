#include "TableCards.hpp"

TableCards::TableCards()
    : InventoryHolder(5) { }
    
void TableCards::drawCard()
{
    insertItem(Deck.getItem(0));
    Deck -= Deck.getItem(0);

}

void TableCards::displayCard(){
    std::cout << "Kartu pada meja adalah:" << std::endl;
    for(int i=0;i<getSize()-1;i++){
        std::cout << getItem(i);
        std::cout << " && ";
    }
    if(getSize() != 0)std::cout << getItem(getSize() - 1);
    std::cout << std::endl;
}
