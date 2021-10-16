
def deliveryBot(route, k):
    stops = []
    distanceTraveled = 0
    for i in range(len(route)):
        if route[i] - distanceTraveled > k:
            distanceTraveled += route[i-1]
            stops.append(route[i-1])
    return stops

if __name__ == "__main__":
    print deliveryBot([0, 20, 37, 54, 70, 90], 40)

'''
b. The time complexity of this algorithm is is O(n), where n is the number of charging pods, as the algorithm iterates through every element of the route array

c.
Via induction:
If the distance of the final stop from the C4C is is less than or equal to k, the robot need not charge and makes zero stops.

Assume tha algorithm works when the final charging point is at most k*(n-1) away from the C4C. (one could take an array where the final charging point is k*n away and truncate, for instance)

we prove that the algorithm works when the final charging point is more tahn k*(n-1_ but at most k*n away. Since we assume the algorithm works up to k*(n-1), we know the algorithm traversed the first portion of the array (until the occurence of the first element greater than k*(n-1)) with n-1 stops. At this point the robot is at most k*n - k*(n-1) = k away from the final element of the array and can reach the delivery point with one more charge, for a total of n charges.
'''
