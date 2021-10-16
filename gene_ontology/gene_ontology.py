import re
import sys

def split_terms(filename):
    with open(filename) as file:
        terms = []
        term = []
        for line in file:
            if len(line.strip()) == 0:
                terms.append(term)
                term = []
            else:
                term.append(line.strip())
        return terms[1:]
    return []

def map_protein_to_go(filename):
    protDict = dict()
    with open(filename) as file:
        for line in file:
            if len(line) and line[0] != '!':
                splitLine = line.split()
                if splitLine[1] not in protDict:
                    protDict[splitLine[1]] = set()
                m = re.match(r'GO_REF:(.*)', splitLine[4])
                if m:
                    protDict[splitLine[1]].add("GO:"+m.group(1))
                else:
                    m = re.match(r'GO:.*', splitLine[4])
                    if m:
                        protDict[splitLine[1]].add(m.group(0))

    return protDict

def parse_go_term(term):
    ID = None
    isas = set()
    for line in term:
        m = re.match(r'id: (.*)', line)
        if m:
            ID = m.group(1)
        m = re.match(r'is_a: (GO:\S*).*', line)
        if m:
            isas.add(m.group(1))
    return ID, isas

def find_parent_terms(go_id, go_dict):
    try:
        parents = [x for x in go_dict[go_id]]
    except KeyError:
        return []
    ancestors = [parents] + [find_parent_terms(x, go_dict) for x in parents]
    return set([item for sublist in ancestors for item in sublist])

def main():
    input_terms = sys.argv[1]
    input_annotations = sys.argv[2]
    output_filename = 'results.tsv'
    if len(sys.argv) > 3:
        output_filename = sys.argv[3] + '.tsv'
    terms = split_terms(input_terms)
    protDict = map_protein_to_go(input_annotations)
    go_dict = dict()
    for x in terms:
        ID, isas = parse_go_term(x)
        go_dict[ID] = isas

    with open(output_filename, 'w') as file:
        for key in protDict:
            file.write(key + '\t')
            if len(protDict[key]) == 0:
                file.write('\n')
            for i,x in enumerate(protDict[key]):
                if i > 0:
                    file.write('\t')
                file.write(x + '\t')
                ancestors = find_parent_terms(x, go_dict)
                if len(ancestors) == 0:
                    file.write('\n')
                for j,y in enumerate(ancestors):
                    if j > 0:
                        file.write('\t\t')
                    file.write(y + '\n')

if __name__=="__main__":
    main()
