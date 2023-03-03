#pragma once

#include "common.hpp"
#include "Deck.hpp" // "Player.hpp" now includes both "Deck.hpp" and "Card.cpp"

class Player {
public:
    // Ebala default constructor epeidh sto Blackjack.hpp orizw Player1 kai Dealer san private melh. Meta kanw set_name sthn start(). Einai swsto? Einai la8os?
    // Mporei na ginei pio effectively me diaforetiko tropo?

    // απαντηση: μπορουμε να έχουμε σαν default ορισμα (ονομα) "Dealer" και να χρησιμοποιείται η set_name για τον παικτη/παικτες. Με αυτο τον
    // τροπο χρειαζόμαστε μόνο έναν constructor.
    // Επισης, γενικα οταν ερθει η ωρα να βάλουμε πολλους παικτες, επειδη δε θα ξέρουμε ποσοι θα ειναι μπορουμε να τους κραταμε σε ενα
    // vector στο οποιο αν το σκεφτεις θα καλειται player constructor οταν ερθει η ωρα να δημιουργηθει ο εκάστοτε παικτης. 
    // Άρα, θα τον δημιουργούμε με την μία καλώντας: Player pX("Xname") και αρα η set_name δε θα μας χρειαζεται καθολου (νομιζω :P).
    Player(string given_name = "Dealer");

    void reset();

    void input_bet();
    int get_bet() const;
    void double_bet();
    int get_money() const;
    void add_money(int m = 0);
    int get_hand_value() const;
    int get_cards_in_hand() const;
    void set_hand_value(int);
    void set_name(string);
    string get_name() const;

    void draw(Deck&);
    void draw_fake(Card&);
    void print_hand();
    const vector<Card>& return_hand_cards() const;
    void print_dealer_hand();

    void set_busted(bool);
    bool is_busted() const;

    friend ostream& operator<< (ostream&, const Player&);

private:
    vector<Card> hand;
    int number_of_aces;
    small_int cards_in_hand;

    string name;
    int money;
    int round_bet;
    int hand_value;
    bool busted;
};
