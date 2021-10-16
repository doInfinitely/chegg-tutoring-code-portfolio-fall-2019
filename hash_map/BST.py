#!/usr/bin/python3

import random
import re

class GameRecord:
  """ Class representing data for a game. """
  __slots__ = 'md5', 'name', 'mfg', 'model'
  def __init__(self):
    self.md5 = md5
    self.name = name
    self.mfg = mfg
    self.model = mdel

  def __str__(self):
    return 'md5: %s => name: %s, mfg: %s, model: %s' % (self.md5, self.name, self.mfg, self.model)


class GameDatabase:
  """ Binary search tree based on 'BTNode's, storing game records. """
  __slots__ = 'root'

  #-------------------------- nested BTNode class --------------------------
  class _BTNode:
    """ Lightweight, nonpublic class for storing a BTNode. """
    __slots__ = 'record', 'left', 'right'

    def __init__(self, record, left = None, right = None):
      self.record = record
      self.left  = left
      self.right = right

    def hasLeft(self):
      """ Returns whether this node has a left child. """
      return self.left != None

    def hasRight(self):
      """ Returns whether this node has a right child. """
      return self.right != None

    def __lt__(self, other):
      """ Return True if other is a BTNode and this node is less than other. """
      return type(other) is type(self) and self.element < other.element
      

    def __gt__(self, other):
      """ Return True if other is a BTNode and this node is greater than other. """
      return type(other) is type(self) and self.element > other.element

    def __eq__(self, other):
      """ Return True if other is a BTNode and this node is equal to the other. """
      return type(other) is type(self) and self.element == other.element

  #-- c'tor
  def __init__(self):
    self.root = None
 

  #-- Public methods
  def insert(self, record):
    """ Insert element into the BST, keeping the BST property.
        Note that insertion is keyed on 'md5 """
    if self.root == None:
        self.root = self._BTNode(record)
    else:
        parent = self.root
        while True:
            if record['MD5'] == parent.record['MD5']:
                break
            elif record['MD5'] > parent.record['MD5']:
                if not parent.hasRight():
                    parent.right = self._BTNode(record)
                    break
                parent = parent.right
            else:
                if not parent.hasLeft():
                    parent.left = self._BTNode(record)
                    break
                parent = parent.left


  def find(self, md5):
    """ Search for key in the BST, returning the corresponding record. """
    current = self.root
    while current != None:
        if current.record['MD5'] == md5:
            return current
        elif current.record['MD5'] > md5:
            current = current.left
        else:
            current = current.right

    return None


  def keys(self):
    """ Collect all keys into a list, then return it. """
    def _keys(root):
        if root == None:
            return []
        return [root.record['MD5']] + _keys(root.left) + _keys(root.right)
    return _keys(self.root)


  def values(self):
    """ Collect all values into a list, then return it. """
    def _values(root):
        if root == None:
            return []
        return [root.record] + _values(root.left) + _values(root.right)
    return _values(self.root)

  def print(self):
    """ Print tree using inorder traversal. """
    def _print(root):
      if root != None:
        _print(root.left)
        print(root.record)
        _print(root.right)

    _print(self.root)
    print();


#-- Main method
db = GameDatabase()

filename = "database.txt"
print("Parsing database from", filename, "...")
#########################################################################
###  Read from the file and add it to the database ADT
with open('database.txt') as file:
    d = dict()
    for line in file:
        if not len(line.strip()):
            db.insert(d)
            d = dict()
        else:
            m = re.match(r'"Cart_(.*?)" "(.*?)"', line)
            if m:
                d[m.group(1)] = m.group(2)


#########################################################################

#########################################################################
###  DO NOT CHANGE ANY IN THIS AREA!  YOU WILL RECEIVE 0% FOR THIS
###  QUESTION IF YOU DO!!!  YOUR CODE *MUST* WORK WITH THE EXISTING CODE.

print("Testing print ...")
db.print()
print()

md5_1 = "393948436d1f4cc3192410bb918f9724"
md5_2 = "393948436d1f4cc3192410bb918f9725"
print("Testing lookup ...")
print("Searching for", md5_1, ": ", db.find(md5_1))
print("Searching for", md5_2, ": ", db.find(md5_2))
print()

print("Requesting all keys ...")
for key in db.keys():
  print(key, end=' ')
print()
print()

print("Requesting all values ...")
for value in db.values():
  print(value, end=' ')
print()
print()

###  END OF NON-CHANGEABLE AREA
#########################################################################

#########################################################################
# Add code to find an existing game record, change its contents,
# then re-insert it into the database
# Make sure to print the database before and after the change, to
# clearly indicate that your changes work

# ... Add your code here ...
print("Printing before change...")
db.print()
print()

d = db.find(md5_1)

d.record['Name'] = "Red Dead Redemption"

print("Printing after change...")
db.print()
print()
