def decode(string):
    result = ""
    count = ""
    for character in string:
        if character.isdigit():
            count += character
        else:
            if count != "":
                result += character * int(count)
                count = ""
            else:
                result += character
    return result
            
    
    
    


def encode(string):
    temp = ""
    if len(string) == 0:
        return string
    for index,letter in enumerate(string):
        
        if index == len(string) - 1:
            temp += letter
            break
        
        if letter != string[index+1]:
            temp += letter + "*"
        
        else:
            temp += letter
    
    split_list = temp.split("*")
    result = ""
    
    for word in split_list:
        
        if word.count(word[0]) == 1:
            result += word
        else:
            result += str(word.count(word[0])) + word[0]

    return result
