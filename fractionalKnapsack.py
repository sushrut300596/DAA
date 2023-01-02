class Item : 
    def __init__(self, w, p, i) :
        self.w = w
        self.p = p
        self.i = i
        self.ratio = p // w
 
    def __lt__(self, other) :
        return self.ratio < other.ratio 
 
class FractionalKnapSack :
    @staticmethod
    def getMaxProfit(w, p, M) :
        arr = []
        for i in range(len(w)) :
            arr.append(Item(w[i], p[i], i))
 
        arr.sort(reverse=True)
 
        totalProfit = 0
        print("i\tPi\tWi\tM\tXi\tPi*Xi")
        for i in arr :
            currentW = int(i.w)
            currentP = int(i.p)
            if M - currentW >= 0 :
                M -= currentW
                totalProfit += currentP
                print(i.i, "\t", i.p, "\t", i.w, "\t", M, "\t", 1, "\t", totalProfit)
            else :
                fraction = M / currentW
                totalProfit += currentP * fraction
                M = int(M - (currentW * fraction))
                print(i.i, "\t", i.p, "\t", i.w, "\t", M, "\t", round(fraction,2), "\t", totalProfit)
                break
        return totalProfit

w = [1, 3, 5, 4, 1, 3, 2]
p = [5, 10, 15, 7, 8, 9, 4]
M = 15
 
maxProfit = FractionalKnapSack.getMaxProfit(w, p, M)
print("Maximum profit in Knapsack =", maxProfit)