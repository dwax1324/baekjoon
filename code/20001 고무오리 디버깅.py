# 고무오리 디버깅
# 구현

a = input()

b = ""
mun = 0
gomu = 0
while(b != "고무오리 디버깅 끝"):
    b = input()
    if b == "문제":
        mun += 1
    elif b == "고무오리":
        mun -= 1
        if(mun < 0):
            mun = 2
if mun == 0:
    print("고무오리야 사랑해")
else:
    print("힝구")
