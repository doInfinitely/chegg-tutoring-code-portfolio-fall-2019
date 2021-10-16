
def injective(domain, codomain, function):
    inverse = dict()
    for x in domain:
        if function(x) not in codomain:
            raise ValueError
        if function(x) in inverse:
            return (inverse[function(x)], x)
        inverse[function(x)] = x
    return None

def surjective(domain, codomain, function):
