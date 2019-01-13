class Solution:
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        def findisland(x,y):
            stack = [(x,y)]
            ga.add((x,y))
            while stack:
                # print(stack)
                i,j = stack.pop()
                if i-1>-1 and A[i-1][j] == 1 and (i-1,j) not in ga:
                    ga.add((i-1,j))
                    stack.append((i-1,j))

                if i+1<n and A[i+1][j] == 1 and (i+1,j) not in ga:
                    ga.add((i+1,j))
                    stack.append((i+1,j))

                if j-1>-1 and A[i][j-1] == 1 and (i,j-1) not in ga:
                    ga.add((i,j-1))
                    stack.append((i,j-1))

                if j+1<n and A[i][j+1] == 1 and (i,j+1) not in ga:
                    ga.add((i,j+1))
                    stack.append((i,j+1))

        def bfs(startgroup):
            stack = list(startgroup)
            find = False
            count = 0
            dx = [-1,1,0,0]
            dy = [0,0,-1,1]
            while not find:
                count +=1
                nstack = []
                while stack:
                    i,j = stack.pop()
                    for d in range(4):
                        nx , ny = i+dx[d], j + dy[d]
                        if nx>-1 and nx<n and ny>-1 and ny<n and (nx, ny) not in startgroup:
                            if A[nx][ny] == 1:
                                find = True
                                break
                            startgroup.add((nx,ny))
                            nstack.append((nx,ny))
                if not find:
                    stack = nstack
            # print(startgroup, stack, nstack)
            return count

        ga = set()
        n = len(A)
        for i in range(n):
            for j in range(n):
                if A[i][j] == 1:
                    findisland(i,j)
                    # print(ga)
                    return bfs(ga)-1



print(Solution().shortestBridge([[0,1],[1,0]]))
print(Solution().shortestBridge([[0,1,0],[0,0,0],[0,0,1]]))
print(Solution().shortestBridge( [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]))