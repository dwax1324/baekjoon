

try:
    while(True):
        arr = [0 for i in range(10)]
        a = int(input())
        cnt = 2
        oa = a
        while(1):
            for ai in str(a):
                arr[int(ai)] += 1
            print(a)
            flag = True
            for i in range(10):
                if arr[i] == 0:
                    flag = False
            if(flag):
                break
            a = oa*cnt
            cnt += 1
        print(cnt-1)
except:
    exit()
