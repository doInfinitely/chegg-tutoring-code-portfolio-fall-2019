import lab6_queue
import stacks
import copy

def read_dictionary(filename):
    """Reads the file containing the list of words and stores it in wordlist"""
    wordlist = [] # This will contain all of the words
    
    ###### Write more code here! ######
    
    with open(filename) as file:
        for line in file:
            wordlist.append(line.strip())
    

    return wordlist
    
def build_ladder(start, end):
    """Finds the shortest word ladder that connects start and end words.
    
    Returns None if such a ladder does not exist.
    """
    
    wordlist = read_dictionary('dictionary.txt') # Contains all of the allowed words
    
    used = set() # This will be a set of words that you have used while you searched
    
    word_ladders = lab6_queue.Queue() # This is your queue of stacks that will hold all of the word ladders in progress
    
    ###### Write more code here! ######
    used.add(start)
    stack = stacks.LinkedStack()
    stack.push(start)
    word_ladders.enqueue(stack)
    neighbor = True
    while len(word_ladders):
        stack = word_ladders.dequeue()
        for x in [y for y in wordlist if hamming1(stack.top(), y) and y not in used]:
            used.add(x)
            stack2 = copy.deepcopy(stack)
            stack2.push(x)
            if x == end:
                return stack2
            word_ladders.enqueue(stack2)
    return None


# determines if the hamming distance between two words is exactly 1
def hamming1(word1, word2):
    if abs(len(word1)-len(word2)) > 1:
        return False
    if abs(len(word1)-len(word2)) == 1:
        words = sorted([word1, word2], key=len)
        for i,c in enumerate(words[0]):
            if c != words[1][i]:
                return False
        return True
    diff = 0
    for i,c in enumerate(word1):
        if c != word2[i]:
            diff += 1
        if diff > 1:
            return False
    return diff != 0
