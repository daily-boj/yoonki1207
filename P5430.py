T = int(input())
for _ in range(T):
    p = input()
    arr_len = int(input())
    command = input()
    arr = []
    command = "arr = "+command
    exec(command)
    # print(arr)
    ab = [0, 0]
    k = 0
    for i in p:
        if i == 'R':
            k = (k+1)%2
        else:
            ab[k] += 1
    if ab[0]+ab[1] > len(arr):
        print('error')
        continue
    if k == 0:
        arr = arr[ab[0]:len(arr)-ab[1]]
    else :
        arr.reverse()
        arr = arr[ab[1]:len(arr) - ab[0]]


    print('[', end='')
    for i in range(len(arr)):
        if i != 0:
            print(',', end='')
        if arr[i] != ' ':
            print(arr[i], end='')
    print(']')