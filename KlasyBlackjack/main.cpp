#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
 
enum CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,
 
  MAX_SUITS
};
 
enum CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,
 
  MAX_RANKS
};

class Card
{
    CardSuit m_suit;
    CardRank m_rank;
public:
    Card(CardSuit suit = SUIT_CLUB, CardRank rank = RANK_2)
    {
        m_suit = suit;
        m_rank = rank;

    }

void printCard () const
{
  switch (m_rank)
  {
  case CardRank::RANK_2:
    std::cout << '2';
    break;
  case CardRank::RANK_3:
    std::cout << '3';
    break;
  case CardRank::RANK_4:
    std::cout << '4';
    break;
  case CardRank::RANK_5:
    std::cout << '5';
    break;
  case CardRank::RANK_6:
    std::cout << '6';
    break;
  case CardRank::RANK_7:
    std::cout << '7';
    break;
  case CardRank::RANK_8:
    std::cout << '8';
    break;
  case CardRank::RANK_9:
    std::cout << '9';
    break;
  case CardRank::RANK_10:
    std::cout << 'T';
    break;
  case CardRank::RANK_JACK:
    std::cout << 'J';
    break;
  case CardRank::RANK_QUEEN:
    std::cout << 'Q';
    break;
  case CardRank::RANK_KING:
    std::cout << 'K';
    break;
  case CardRank::RANK_ACE:
    std::cout << 'A';
    break;
  default:
    std::cout << '?';
    break;
  }
 
  switch (m_suit)
  {
  case CardSuit::SUIT_CLUB:
    std::cout << 'C';
    break;
  case CardSuit::SUIT_DIAMOND:
    std::cout << 'D';
    break;
  case CardSuit::SUIT_HEART:
    std::cout << 'H';
    break;
  case CardSuit::SUIT_SPADE:
    std::cout << 'S';
    break;
  default:
    std::cout << '?';
    break;
  }
}

int getCardValue() const
{
  if (m_rank <= CardRank::RANK_10)
  {
    return (static_cast<int>(m_rank) + 2);
  }
 
  switch (m_rank)
  {
  case CardRank::RANK_JACK:
  case CardRank::RANK_QUEEN:
  case CardRank::RANK_KING:
    return 10;
  case CardRank::RANK_ACE:
    return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}

};

class Deck
{
  std::array<Card,52> m_deck;
public:
    int m_nextCard = 0;
    Deck()
    {
    int index = 0;
    for(int i = SUIT_CLUB; i!= MAX_SUITS; i++)
    {
        for(int j = RANK_2; j!= MAX_RANKS; j++ )
        {
        m_deck[index] = Card(CardSuit(i),CardRank(j));
        index++;
        }    
    }

    }
    void PrintDeck()
    {
        for(Card c: m_deck)
        { c.printCard();
         std::cout<<" ";
        }
    }

    void shuffleDeck()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        m_nextCard = 0; // bo jak przeszuflujesz, to zaczynasz rozdawac od gory
    }

    const Card& dealCard()
    {   
        return m_deck[m_nextCard++];
    }
    //friend Player;
    //friend Dealer;
};

class Player
{
    int m_score=0;
public:
    void drawCard(Deck &deck)
    {
        Card drawn = deck.dealCard();
        m_score += drawn.getCardValue();
    }
    bool isBust()
    {
        if (m_score > 21)
        return true;
        else
        return false;
    }
    int showScore()
    {return m_score;}
};

class Dealer
{
    int m_deal=0;
public:
    void drawCard(Deck &deck)
    {
        Card drawn = deck.dealCard();
        //if(m_deal == 0)
        m_deal += drawn.getCardValue();
    }
    bool isBust()
    {
        if (m_deal > 21)
        return true;
        else
        return false;
    }

    int showScore()
    {return m_deal;}
};

bool play(Player &player, Deck &deck)
{   char choice;
    std::cout<<"\n Hit(h) or stand(s) ?\n";
    std::cin>>choice;
    switch(choice)
    {
        case 'h':
        {
        if(player.isBust())
        return false;
        else
        return true;
        }
        break;
        case 's':
        return false;
        default:
        return false;
    }
}

int main()
{

    const Card cardQueenHearts(SUIT_HEART,RANK_QUEEN);
    cardQueenHearts.printCard();
    std::cout<<" has the value: "<<cardQueenHearts.getCardValue()<<'\n';

    Deck deck1;
    /*
    deck1.PrintDeck();
    deck1.shuffleDeck();
    std::cout<<"\nshuffled:\n";
    deck1.PrintDeck();
    std::cout << "\nThe first card has value: " << deck1.dealCard().getCardValue() << '\n';
    std::cout << "The second card has value: " << deck1.dealCard().getCardValue() << '\n';
    */
    //------------ gra ---------------
    std::cout<<"\n ============= gra ============= \n";
    Dealer dealer;
    Player player;
    bool cont  = true;

    while(cont)
{
    deck1.shuffleDeck();
    dealer.drawCard(deck1);
    //dealer.drawCard(deck1);
    std::cout<<"\nThe first dealer's card's value is: "<<dealer.showScore();

    while(play(player,deck1))
    {
        player.drawCard(deck1);
        std::cout<<"Your score is: "<<player.showScore();
    }
    
    while(dealer.showScore()<17)
    {
        dealer.drawCard(deck1);
        std::cout<<"\nThe dealer's score is: "<<dealer.showScore();
    }

    //--------- kto wygral ------------
    if(player.isBust())
    std::cout<<"\n ~~~~~~przegrales~~~~~~~~";
    else if((player.showScore() > dealer.showScore()) || dealer.isBust())
    std::cout<<"\n ~~~~~~~wygrales~~~~~~~~";
    else
    std::cout<<"\n ~~~~~~przegrales~~~~~~~~";
    
//grac dalej?
char ch;
std::cout<<"\n Chcesz grac dalej? y/n";
std::cin>>ch;
switch(ch)
{
    case 'y':
    cont = true;
    break;
    case 'n':
    cont = false;
    break;
    default:
    cont = false;
    break;
// tylko nie ma resetu wartosci score ale mi sie nie chce
}
}
    return 0;
}


/*
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
 
enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,
 
  MAX_SUITS
};
 
enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,
 
  MAX_RANKS
};
 
struct Card
{
  CardRank rank{};
  CardSuit suit{};
};
 
struct Player
{
  int score{};
};
 
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;
 
// Maximum score before losing.
constexpr int maximumScore{ 21 };
 
// Minium score that the dealer has to have.
constexpr int minimumDealerScore{ 17 };
 

 

 
void printDeck(const deck_type& deck)
{
  for (const auto& card : deck)
  {
    printCard(card);
    std::cout << ' ';
  }
 
  std::cout << '\n';
}
 
deck_type createDeck()
{
  deck_type deck{};
 
  index_type card{ 0 };
 
  auto suits{ static_cast<index_type>(CardSuit::MAX_SUITS) };
  auto ranks{ static_cast<index_type>(CardRank::MAX_RANKS) };
 
  for (index_type suit{ 0 }; suit < suits; ++suit)
  {
    for (index_type rank{ 0 }; rank < ranks; ++rank)
    {
      deck[card].suit = static_cast<CardSuit>(suit);
      deck[card].rank = static_cast<CardRank>(rank);
      ++card;
    }
  }
 
  return deck;
}
 
void shuffleDeck(deck_type& deck)
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
  std::shuffle(deck.begin(), deck.end(), mt);
}
 
bool playerWantsHit()
{
  while (true)
  {
    std::cout << "(h) to hit, or (s) to stand: ";
 
    char ch{};
    std::cin >> ch;
 
    switch (ch)
    {
    case 'h':
      return true;
    case 's':
      return false;
    }
  }
}
 
// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
{
  while (true)
  {
    std::cout << "You have: " << player.score << '\n';
 
    if (player.score > maximumScore)
    {
      return true;
    }
    else
    {
      if (playerWantsHit())
      {
        player.score += getCardValue(deck[nextCardIndex++]);
      }
      else
      {
        // The player didn't go bust.
        return false;
      }
    }
  }
}
 
// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
{
  while (dealer.score < minimumDealerScore)
  {
    dealer.score += getCardValue(deck[nextCardIndex++]);
  }
 
  return (dealer.score > maximumScore);
}
 
bool playBlackjack(const deck_type& deck)
{
  index_type nextCardIndex{ 0 };
 
  Player dealer{ getCardValue(deck[nextCardIndex++]) };
 
  std::cout << "The dealer is showing: " << dealer.score << '\n';
 
  Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
  nextCardIndex += 2;
 
  if (playerTurn(deck, nextCardIndex, player))
  {
    return false;
  }
 
  if (dealerTurn(deck, nextCardIndex, dealer))
  {
    return true;
  }
 
  return (player.score > dealer.score);
}
 
int main()
{
  auto deck{ createDeck() };
 
  shuffleDeck(deck);
 
  if (playBlackjack(deck))
  {
    std::cout << "You win!\n";
  }
  else
  {
    std::cout << "You lose!\n";
  }
 
  return 0;
}
*/