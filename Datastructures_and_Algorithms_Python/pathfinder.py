import sys
class Node():
    def __init__(self,state,parent,action):
        self.state = state
        self.parent = parent
        self.action = action

class StackFrontier():
    def __init__(self):
        self.frontier=[]
    def add(self,n):
        self.frontier.append(n)
    def IsEmpty(self):
        return len(self.frontier)==0
    def contains_state(self,state):
        return any(node.state == state for node in self.frontier)
    def remove(self):
        if self.IsEmpty():
            raise Exception("The Stack is Empty")
        else:
            node = self.frontier[-1]
            self.frontier = self.frontier[:-1]
            return node
    
class QueueFrontier(StackFrontier):
    def remove(self):
        if self.IsEmpty():
            raise Exception("Queue is Empty")
        else:
            node = self.frontier[0]
            self.frontier = self.frontier[1:]
            return node

class Maze():
    def __init__(self,filename,algorithm):
        self.algorithm = algorithm
        with open(filename) as f:
            contents = f.read()
        
        contents = contents.splitlines()
        self.height = len(contents)
        self.width = max([len(i) for i in contents])
        self.walls = []
        for i in range(self.height):
            rows = []
            for j in range(self.width):
                try:
                    if contents[i][j] == 'A':
                        self.start = (i,j)
                        rows.append(False)
                    elif contents[i][j] == 'B':
                        self.goal = (i,j)
                        rows.append(False)
                    elif contents[i][j] == ' ':
                        rows.append(False)
                    else:
                        rows.append(True)
                except IndexError:
                    rows.append(False)
            self.walls.append(rows)
        self.solution = None

    def print(self):
        solution = self.solution[1] if self.solution is not None else None
        print()
        print("Type of Algorithm: ",self.algorithm.upper())
        print()
        for i,rows in enumerate(self.walls):
            for j,col in enumerate(rows):
                if col:
                    print("#",end="")
                elif self.start == (i,j):
                    print("A",end="")
                elif self.goal == (i,j):
                    print("B",end="")
                elif solution is not None and (i, j) in solution:
                    print('*',end="")
                else:
                    print(" ", end="")
            print()
        print()
        print("Num of cells explored: ",self.num_explored)
        print()

    def neigbour(self,state):
        row,col= state
        possible_ways = [
            ('up',(row+1,col)),
            ('down',(row-1,col)),
            ('left',(row,col-1)),
            ('right',(row,col+1))
        ]
        result = []
        for action,(r,c) in possible_ways:
            if 0<=r<self.height and 0<=c<self.width and not self.walls[r][c]:
                result.append((action,(r,c)))
        return result

    def solve(self):
        self.num_explored=0
        start = Node(state = self.start,parent=None,action=None)
        if self.algorithm == 'bfs':
            frontier = QueueFrontier()
        elif self.algorithm == 'dfs':
            frontier = StackFrontier()
        else:
            raise Exception("\n\tValueError: wrong algorithm selected only BFS or DFS are available\n")
        frontier.add(start)
        self.explored = set()
        while True:
            if frontier.IsEmpty():
                raise Exception("no Solution")
            node = frontier.remove()
            self.num_explored+=1
            if node.state == self.goal:
                action = []
                cells = []
                while node.parent is not None:
                    action.append(node.action)
                    cells.append(node.state)
                    node = node.parent
                action.reverse()
                cells.reverse()
                self.solution = (action,cells)
                return (action,cells)
            self.explored.add(node.state)
            for action,state in self.neigbour(node.state):
                if state not in self.explored and not frontier.contains_state(state):
                    child = Node(state=state,parent=node,action=action)
                    frontier.add(child)
try:
    pattern = Maze(sys.argv[1],sys.argv[2])
except IndexError:
    raise Exception("\n\nInputError: Input should be given as following pattern:\n\n\tpython [python_filename].py [maze_filename].txt [BFS or DFS algorithm] \n")
pattern.solve()
pattern.print()