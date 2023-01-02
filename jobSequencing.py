def printJobScheduling(arr, t) :
 
    n = len(arr)
 
    for i in range(n) :
        for j in range(n - 1 - i) :
            if arr[j][2] < arr[j + 1][2] :
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            
    result = [False] * t
 
    job = ['-1'] * t

    profit = 0

    for i in range(len(arr)) :
        for j in range(min(t - 1, arr[i][1] - 1), -1, -1) :
            if result[j] is False :
                result[j] = True
                job[j] = arr[i][0]
                profit += arr[i][2]
                break
    print("Following is maximum profit sequence of jobs")
    print(job)
    print("Maximum Profit :",profit)

arr = [['J1', 2, 100],
       ['J2', 1, 19],
       ['J3', 2, 27],
       ['J4', 1, 25],
       ['J5', 3, 15]] 

t = arr[0][1]

for i in range(len(arr)) :
    if arr[i][1] > t :
        t = arr[i][1]

printJobScheduling(arr, t)