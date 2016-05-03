
def permutations(pattern):

    if (pattern.__len__()):
        result = []
        for i in pattern:
            for j in permutations(pattern - {i}):
                result += [[i] + j]
        return result

    else:
        return [[]]
