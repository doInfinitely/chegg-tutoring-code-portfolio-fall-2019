"""
UMass ECE 241 - Advanced Programming
Homework #4     Fall 2019
hw4_q1_2019.py - Recursive fern with turtle
"""
import math
import turtle
import random

pen = turtle.Turtle()
mywin = turtle.Screen()
pen.color('blue')
pen.width(3)


""""
Tree code is only in this file for reference.
It is not needed for solving the assignment!!!
"""

def tree(n,l):
    if n==0 or l<2:
        return

    pen.forward(l)
    pen.left(45)
    tree(n-1, l/2)
    pen.right(90)
    tree(n-1, l/2)
    pen.left(45)
    pen.backward(l)

# tree(30,100)
# mywin.exitonclick()

def fern(n,l):
    print l
    if n==0 or l < 5:
        return

    mult = 1.0
    for i in range(n):
        angle = random.choice([40, 55])
        if i == n-1:
            angle = 5
        if i % 2 == 0:
            angle *= -1

        mult /= 2 
        if i == n-1:
            mult = 1.0/2
        pen.forward(1.0/n*l)
        pen.right(angle)
        fern(n, mult*l)
        pen.right(-1*angle)
    pen.backward(l)


#fern(1,100)
fern(3,100)
#fern(5,100)
mywin.exitonclick()
