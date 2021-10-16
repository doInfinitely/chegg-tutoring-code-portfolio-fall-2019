"""
UMass ECE 241 - Advanced Programming
Homework #4     Fall 2019
hw4_q2_sol_2019.py - DP planks with turtle
"""
import turtle


def dpChoosePlanks(plankList, totalDistance):
    cache = {0:tuple()}
    while True:
        for key in cache.keys():
            for x in plankList:
                if key+x == totalDistance:
                    return [y for y in cache[key]]+[x]
                if key+x not in cache:
                    cache[key+x] = tuple([y for y in cache[key]]+[x])


def printPlanks(planksUsed, totalDistance):
    dist = totalDistance
    plankOrder=[]
    while dist > 0:
        thisDistance = planksUsed[dist]
        plankOrder.append(thisDistance)
        print("In printPlanks:plank:{}".format(thisDistance))
        dist = dist - thisDistance
    print(plankOrder[::-1])
    return plankOrder[::-1]


def side(steps,t,color):
    for step in steps:
        t.color(color[step])
        t.forward(step)

def plankSetup(totalDist, plankList):
    print("Making distance for", totalDist, "requires")
    planks = dpChoosePlanks(plankList, totalDist)
    print(len(planks), " planks")
    print("They are:")
    print planks
    #A_list = printPlanks(planksUsed, totalDist)
    return planks


def main():
    t = turtle.Turtle()
    myWin = turtle.Screen()
    t.shape("classic")
    t.speed(1)
    for dists in [(64,67), (25,27)]:
        a_Dist = dists[0]
        b_Dist = dists[1]
        plankList = [1, 5, 10, 21, 25]
        plankColor = {1:'red',5:'blue',10:'black',21:'green',25:'violet'}

        A_list=plankSetup(a_Dist,plankList)

        t.left(90)
        print("A_list:{}".format(A_list))
        side(A_list,t,plankColor)

        t.right(90)
        B_list = plankSetup(b_Dist, plankList)
        print("B_list:{}".format(B_list))
        side(B_list, t, plankColor)

        t.right(90)
        print("A_list:{}".format(A_list))
        side(A_list, t, plankColor)

        t.right(90)
        print("B_list:{}".format(B_list))
        side(B_list, t, plankColor)

    myWin.exitonclick()

main()
