n = int(input())

# 문자열


for i in range(n):
    a = input()
    arr = [0 for i in range(26)]

    for j in range(len(a)):
        if((ord(a[j]) >= 65 and ord(a[j]) <= 90) or (ord(a[j]) >= 97 and ord(a[j]) <= 122)):
            arr[ord(a[j].upper())-65] += 1

    pen = 1
    dpen = 1
    tpen = 1
    for j in range(26):
        if(arr[j] < 1):
            pen = 0
            break
    for j in range(26):
        if(arr[j] < 2):
            dpen = 0
            break

    for j in range(26):
        if(arr[j] < 3):
            tpen = 0
            break

    if(tpen):
        print(f"Case {i+1}: Triple pangram!!!")
    elif(dpen):
        print(f"Case {i+1}: Double pangram!!")
    elif(pen):
        print(f"Case {i+1}: Pangram!")
    else:
        print(f"Case {i+1}: Not a pangram")
