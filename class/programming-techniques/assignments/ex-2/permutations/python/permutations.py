
def permutations(pattern):

    if (pattern.__len__()):
        result = set();
        for i in result:
            for j in permutations(pattern - {i}):
                result.add([i] + j)

    else:
        return {[]}
