class Solution:
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        groupa = set() # tuple coor, value true/false
        n = len(A)
        stack = set()
        flag = False
        count = 0
        def island(x,y):
            #x,y int
            if (x, y) not in groupa:
                groupa.add((x,y))
            if x> 0 and A[x-1][y] == 1 and (x-1,y) not in groupa:
                island(x-1,y)
            if x+1<n and A[x+1][y] == 1 and (x+1,y) not in groupa:
                island(x+1,y)
            if y+1<n and A[x][y+1] == 1 and (x,y+1) not in groupa:
                island(x,y+1)
            if y>0 and A[x][y-1] == 1 and (x,y-1) not in groupa:
                island(x,y-1)

        def bfs(x,y):
            if (x,y) in groupa:
                bfs(x+1, y)
                bfs(x-1, y)
                bfs(x, y+1)
                bfs(x, y-1)
            else:
                if x > -1 and x <n and y > -1 and y <n:
                    if A[x][y] == 0:
                        A[x][y] = 'x'
                        stack.add((x,y))
                    elif A[x][y] == 1:
                        flag = True

        for i in range(n):
            for j in range(n):
                if A[i][j] == 1:
                    island(i,j)
                bfs(i,j)
                print(stack)
                while not flag:
                    count += 1
                    ns = list(stack)
                    stack = set()
                    for k,v in ns:
                        bfs(k,v)
                    # print(stack, ns)
                break
        return count


print(Solution().shortestBridge([[0,1],[1,0]]))
print(Solution().shortestBridge([[0,1,0],[0,0,0],[0,0,1]]))
print(Solution().shortestBridge( [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]))