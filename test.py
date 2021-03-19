def getProp(text, label):
    res = {}
    for index, lab in enumerate(label):
        if len(lab.split('-')) != 2:
            continue
        state, key  = lab.split('-')
  
        if key in res:
            #print(res[key])
            temp = res[key]
            temp.append([state, index])
            #print("temp:", temp)
            res[key] = temp
        else:
            #print(key, [state,index])
            res[key] = [[state, index]]
    ret = {}
    #print("res:", res)
    for key, value in enumerate(res):
        #print("value 1:", res[value])
        # 处理顺序错误
        if res[value][0][0] != 'B' or res[value][-1][0] != 'E':
            return {}
        B = 0
        E = 0
        for val in res[value]:
            if val[0] == 'B':
                B += 1
            if val[0] == 'E':
                E += 1
        # 个数错误
        if B > 1 or E > 1:
            return {}
        


        ret[value] = ''.join(text[res[value][0][1]:res[value][-1][1] + 1])
    
    return ret
    

text = ['小', '明', '是', '中', '国','人']
label = ['B-name', 'E-name', 'N', 'B-nation','I-nation','E-nation']
label2 = ['B-name', 'E-name', 'N', 'B-nation','E-nation','E-nation']
label3 = ['B-name', 'E-nation', 'N', 'B-nation','E-nation','E-nation']
print(getProp(text, label))     
print(getProp(text, label2))     
print(getProp(text, label3))     
            
        