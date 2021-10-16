#!/usr/bin/env python3

import random

__author__ = ""

# Write your classes here

class Card(object):
    def __init__(self, val):
        self._val = val
        self._action = None
            
    def play(self, player, game):
        player._hand._cards.remove(self)

    def action(self, player, game, slot):
        if self._action == None:
            game.set_action('NO_ACTION')

    def __str__(self):
        return "Card()".format(self._player, self._game, self._slot)

    def __repr__(self):
        return str(self)


class NumberCard(Card):
    def get_number(self):
        return self._val

    def __str__(self):
        return 'NumberCard({0})'.format(self._val)
        

class CoderCard(Card):
    def get_name(self):
        return self._val

    def __str__(self):
        return 'CoderCard({0})'.format(self._val)


class TutorCard(Card):
    def __init__(self, val):
        super().__init__(val)
        self._action = 'PICKUP_CODER'

    def get_name(self):
        return self._val
        
    def __str__(self):
        return 'TutorCard({0})'.format(self._name)


class KeyboardKidnapperCard(Card):
    def __init__(self):
        self._action = 'STEAL_CODER'

    def __str__(self):
        return "KeyboardKidnapperCard()"


class AllNighterCard(Card):
    def __init__(self):
        self._action = 'SLEEP_CODER'

    def __str__(self):
        return "AllNighterCard()"


class Deck (object):
    def __init__(self, starting_cards=None):
        self._cards = []
        if starting_cards:
            self._cards.extend(starting_cards)
    
    def get_cards(self):
        return self._cards

    def get_card(self, slot):
        return self._cards[slot]

    def top(self):
        return self._cards[-1]

    def remove_card(self, slot):
        return self._cards.pop(slot)

    def get_amount(self):
        return len(self._cards)

    def shuffle(self):
        random.shuffle(self._cards)
        
    def pick(self, amount):
        output = self._cards[-amount:]
        self._cards = self._cards[:-amount]
        return output

    def add_card(self, card):
        self._cards.append(card)

    def add_cards(self, cards):
        self._cards.extend(cards)

    def copy(self, deck):
        self._cards.extend(deck._cards)

    def __str__(self):
        return "Deck({0})".format(self._cards)

    def __repr__(self):
        return str(self)

class Player(object):
    def __init__(self, name):
        self._name = name
        self._hand = Deck()
        self._coders = Deck()

    def get_name(self):
        return self._name

    def get_hand(self):
        return self._hand

    def get_coders(self):
        return self._coders

    def has_won(self):
        return len(self._coders.get_amount()) >= 4

def main():
    print("Please run gui.py instead")


if __name__ == "__main__":
    main()
