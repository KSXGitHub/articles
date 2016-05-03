
def permutations(pattern):

    if (len(pattern)):
        result = []
        for i in pattern:
            for j in permutations(pattern - {i}):
                result += [[i] + j]
        return result

    else:
        return [[]]
