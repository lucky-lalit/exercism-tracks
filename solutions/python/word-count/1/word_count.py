def count_words(sentence):
    sentence =sentence.lower()
    temp = ""
    result = []
    for letter in sentence:
        if letter.isalnum() or letter == "'":
            temp += letter
        else:
            temp += " "
            
    words = temp.split()
    
    for word in words:
        if word == "'":
            continue
        result.append(word.strip("'"))
        
    unique = []
    for word in result:
        if word not in unique:
            unique.append(word)
            
    dic = {}
    for word in unique:
        dic[word] = result.count(word)
    return dic
    
    
