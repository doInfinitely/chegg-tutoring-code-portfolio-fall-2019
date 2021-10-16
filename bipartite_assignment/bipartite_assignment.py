import sys

with open('inputPS4.txt') as f:
    students = []
    topics = set()
    num_sol = dict()
    keys = dict()
    for line in f:
        students.append(set())
        for x in line.split('/')[1:]:
            x = x.strip()
            students[-1].add(x)
            topics.add(x)

# unsatisfiable if the number of students doesn't equal that of the topics
if len(topics) != len(students):
    with open('outputPS4.txt', 'w') as g:
        g.write('The total number of allocations possible is: 0')
    sys.exit(0)
for i in range(len(students)+1)[1:]:
    print 'subproblem size: {0}'.format(i)
    keys[i] = []
    if i == 1:
        for j in range(len(students)):
            for x in topics:
                key = (frozenset([j]), frozenset([x]))
                # we find the number of solutions for all subproblems of size 1
                # i.e. one student, one class
                #num_sol[key] = int(x in students[j])
                if x in students[j]: # if size 1 subproblem is unsatisfiable don't even store the zero value for improved performance
                    num_sol[key] = 1 
                    keys[i].append(key)
    else:
        for key in keys[i-1]:
            for key2 in keys[1]:
                # we attempt to extend the partial solution contained in key
                # with a size one partial solution so long as the two are
                # disjoint with respect to students and topics
                if len(key[0] & key2[0]) == 0 and len(key[1] & key2[1]) == 0:
                    newkey = [set(),set()]
                    # we construct the new key
                    # first by merging the students
                    newkey[0].update(key[0])
                    newkey[0].update(key2[0])
                    # then by merging the topics
                    newkey[1].update(key[1])
                    newkey[1].update(key2[1])
                    # cast to hashable type
                    newkey[0] = frozenset(newkey[0])
                    newkey[1] = frozenset(newkey[1])
                    newkey = tuple(newkey)
                    if newkey not in num_sol:
                        num_sol[newkey] = 0
                        keys[i].append(newkey)
                    num_sol[newkey] += num_sol[key] * num_sol[key2]

with open('outputPS4.txt', 'w') as g:
    # if there are solutions to the problem output how many
    if len(keys[len(students)]):
        g.write('The total number of allocations possible is: {0}'.format(num_sol[keys[len(students)][0]]))
    else:
        g.write('The total number of allocations possible is: 0')
