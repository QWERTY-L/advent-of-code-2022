from functools import cmp_to_key

def compare(arr1, arr2):
    if(arr1 == arr2):
        return "EQ"
    if(type(arr1) == int and type(arr2) == int):
        return arr1 < arr2

    if(type(arr1) == int):
        arr1 = [arr1]
    if(type(arr2) == int):
        arr2 = [arr2]

    for i in range(len(arr1)):
        if(i >= len(arr2)):
            return False
        if(arr1[i] == arr2[i]):
            continue
        if(compare(arr1[i], arr2[i]) != "EQ"):
            return compare(arr1[i], arr2[i])
    if(len(arr1) == len(arr2)):
        return "EQ"
    return True

def cp(arr1, arr2):
    a = compare(arr1, arr2)
    if(a == "EQ"):
        return 0
    if(a == True):
        return 1
    if(a == False):
        return -1

array = []
while(True):
    in1 = input()
    if(in1 == "DONE"):
        break
    in2 = input()
    input()

    x = []
    y = []
    exec("x = " + in1) # I know it's cursed, but it works. I used python for a reason.
    exec("y = " + in2)

    array.append(x)
    array.append(y)

array.append([[2]])
array.append([[6]])

array.sort(key=cmp_to_key(cp), reverse=True)

print((array.index([[2]]) + 1)*(array.index([[6]]) + 1))