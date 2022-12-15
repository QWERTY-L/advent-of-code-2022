def compare(arr1, arr2):
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


counter = 1
sOut = 0
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

    if(x != y and compare(x.copy(), y.copy())):
        sOut += counter
    #if(x < y):
    #    print(counter)

    counter += 1

print(sOut)