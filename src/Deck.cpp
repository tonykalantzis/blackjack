#include "Deck.hpp"

#define NUM_OF_CARDS 52

Deck::Deck() {
    cards = new Card[NUM_OF_CARDS];

    for (int s = 0; s < 4; s++)
        for (int i = 0 ; i <= 12 ; i++)  
            cards[i+s*13].init((Card::Rank)(i + 1), (Card::Suit)s);

    top_card_pos = 0;
}

Deck::~Deck() {
    delete[] cards;
}

void Deck::shuffle_deck() {

    std::random_device rd;   // Seed generator
    std::mt19937 g(rd());    // Mersenne Twister RNG

    std::srand(std::time(NULL));
    std::shuffle(cards, cards + 52, g);
}

Card& Deck::get_top_card() {
    // check if the deck is exhausted => reshuffle
    if (top_card_pos == 52) {
        shuffle_deck();
        top_card_pos = 0;
    }

    top_card_pos++;
    return cards[top_card_pos-1];
}