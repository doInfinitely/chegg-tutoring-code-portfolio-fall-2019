# Assignment 4, Question 2

from item import Item
from pokemon import Pokemon

class PokemonTrainer:
    '''A class to represent a Pokemon trainer.'''
    def __init__(name):
        self.name = name
        self.pokemon = []
        self.items = []
        self.current_active_pokemon = None
    def __iadd__(self, other):
        if isinstance(other, Pokemon):
            self.add_pokemon(other)
        if isinstance(other, Item):
            self.add_item(other)
    def add_pokemon(self, pkmn):
        self.pokemon.append(pkmn)
    def add_item(self, item):
        self.items.append(item)
