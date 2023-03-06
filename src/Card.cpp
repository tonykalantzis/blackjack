#include "Card.hpp"

void Card::init(Rank r, Suit s) {
    rank = r;
    suit = s;
    
    // ace
    if (rank == ACE)
        points = 11;
    else
        points = rank > TEN ? 10 : rank;

    status = IN_DECK;
}

small_int Card::get_points() const {
    return points;
}

string Card::get_rank() const {
    switch (rank) {
    case ACE:
        return "A";
    case JACK:
        return "J";
    case QUEEN:
        return "Q";
    case KING:
        return "K";
    default:
        return std::to_string(rank);
    }
}

string Card::get_suit() const {
    switch (suit) {
    case SPADE:
        return "♠";
    case HEART:
        return "♥";
    case CLUB:
        return "♣";
    default:
        return "♦";
    }
}

Card::Status Card::get_status() const {
    return status;
}

void Card::set_status(Status s) {
    status = s;
}

//----------------PRINTING
    // ╔═════════╗ (1) 11x7 total (9 between) 
    // ║10       ║ (2)
    // ║         ║ (3)
    // ║    ♠    ║ (4)
    // ║         ║ (3)
    // ║       10║ (5)
    // ╚═════════╝ (6)

void Card::print_2d() {
    // ╔-201 ═-205 ╗-187 ║-186 ╝-188 ╚-200
    // (1)
    std::cout << "╔"/* char(201)*/;
    for(int i = 0 ; i < 9 ; i++) {
        std::cout << "═" /*char(205)*/;
    }
    std::cout << "╗"/*char(187)*/ << std::endl;
    // (2) 
    std::cout << "║"/*char(186)*/;
    if (rank == 10)
        std::cout << " 10      " << "║" << std::endl;//10 and 7 spaces 
    else 
        std::cout << " " << get_rank() << "       " << "║"/*char(186)*/ << std::endl;
    // (3)
    std::cout << "║"/*char(186)*/ << "         " << "║"/*char(186)*/ << std::endl;
    // (4)
    std::cout << "║"/*char(186)*/ << "    " << get_suit() << "    " << "║"/*char(186)*/ << std::endl;
    // (3)'
    std::cout << "║"/*char(186)*/ << "         " << "║"/*char(186)*/ << std::endl;
    //(2)'
    std::cout << "║"/*char(186)*/;
    if (rank == 10)
        std::cout << "      10 " << "║" << std::endl;//10 and 7 spaces 
    else 
        std::cout << "       " << get_rank() << " " << "║"/*char(186)*/ << std::endl;
    //(1)'
    std::cout << "╚"/*char(200)*/;
    for(int i = 0 ; i < 9 ; i++) {
        std::cout << "═"/*char(═)*/;
    }
    std::cout << "╝"/*char(188)*/ << std::endl;

    return;
}

void Card::print_one() {
    std::cout << "╔"/* char(201)*/;
    for(int i = 0 ; i < 9 ; i++) {
        std::cout << "═" /*char(205)*/;
    }
    std::cout << "╗";/*char(187)*/
}

void Card::print_two() {
    std::cout << "║"/*char(186)*/;
    if (rank == 10)
        std::cout << " 10      " << "║";//10 and 7 spaces 
    else 
        std::cout << " " << get_rank() << "       " << "║"/*char(186)*/;
}

void Card::print_three() {
    std::cout << "║"/*char(186)*/ << "         " << "║"/*char(186)*/;
}

void Card::print_four() {
    std::cout << "║"/*char(186)*/ << "    " << get_suit() << "    " << "║"/*char(186)*/;
}

void Card::print_five() {
    std::cout << "║"/*char(186)*/;
    if (rank == 10)
        std::cout << "      10 " << "║";//10 and 7 spaces 
    else 
        std::cout << "       " << get_rank() << " " << "║"/*char(186)*/;
}

void Card::print_six() {
    std::cout << "╚"/*char(200)*/;
    for(int i = 0 ; i < 9 ; i++) {
        std::cout << "═"/*char(═)*/;
    }
    std::cout << "╝"/*char(188)*/;
}
