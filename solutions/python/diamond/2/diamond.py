def rows(letter):
    if letter == "A":
        return ["A"]
    result = []
    size = (((ord(letter) - 65) + 1) * 2) - 1
    for i in range((ord(letter) - 65) + 1):
        temp = ""
        for j in range(size):
            if (size // 2 - i) == j or (size // 2 + i) == j:
                temp += str(chr(65+i))
            else:
                temp += " "
        result.append(temp)
        
    for i in range((size//2) - 1,-1,-1):
        result.append(result[i])
        
    return result
