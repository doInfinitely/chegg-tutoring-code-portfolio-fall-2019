import math

def madelung_constant(N):
    if N == 0:
        return 0
    elif N == 1:
        return sum([(-1)**(i+j+k)/math.sqrt(i**2+j**2+k**2) for i in range(-1, 2) for j in range(-1,2) for k in range(-1,2) if i != 0 or j != 0 or k != 0])
    else:
        delta = 0
        for i in [-N, N]:
            for j in range(-N, N+1):
                for k in range(-N, N+1):
                    delta  += (-1)**(i+j+k)/math.sqrt(i**2+j**2+k**2)

        for i in range(-(N-1), N):
            for j in [-N, N]:
                for k in range(-N, N+1):
                    delta  += (-1)**(i+j+k)/math.sqrt(i**2+j**2+k**2)
            for j in range(-(N-1), N):
                for k in [-N, N]:
                    delta  += (-1)**(i+j+k)/math.sqrt(i**2+j**2+k**2)
    return madelung_constant(N-1)+delta


print(madelung_constant(25))
