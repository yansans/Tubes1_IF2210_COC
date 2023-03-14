#include "TableCards.hpp"

TableCards::TableCards()
    : InventoryHolder(5) { }
    
void TableCards::drawCard(DeckCards deckCards)
{
    insertCard(deckCards.getItem(0));
    deckCards -= deckCards.getItem(0);

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
