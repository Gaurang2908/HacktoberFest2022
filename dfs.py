import queue

class Node:
    def __init__(self):
        self.data=None
        self.neighbors=[]

class Graph:
    def __init__(self):
        self.root=None
        self.nodes=[]

    def NodeExists(self, SearchNodeData, SearchNode):
        for x in self.nodes:
            if x.data==SearchNodeData:
                x.neighbors.append(SearchNode)
                return True
        return False

    def getNeighborNodes(self, nodes):
        nodesList = ""
        for x in nodes:
            nodesList += str(x.data + " ")
        return nodesList    

    def buildGraph(self):
        nodesToAdd=queue.Queue()
        rootData = input("Enter root data : ")
        rootNode = Node()
        rootNode.data = rootData
        self.root = rootNode
        nodesToAdd.put(rootNode)

        while not nodesToAdd.empty():
            node = nodesToAdd.get()
            self.nodes.append(node)

            if not node.neighbors:
                neighborCount = int(input("Enter no of neighbors of node {} : ".format(node.data)))
            else:
                nodesList = self.getNeighborNodes(node.neighbors)    
                neighborCount = int(input("Enter no of neighbors of node {} other than node(s) {} : ".format(node.data, nodesList)))
            
            for _ in range(neighborCount):
                neighborData = input("Enter neighbor data : ")
                if not self.NodeExists(neighborData, node):
                    newNode = Node()
                    newNode.data = neighborData
                    newNode.neighbors.append(node)
                    node.neighbors.append(newNode)
                    nodesToAdd.put(newNode)
                    self.nodes.append(newNode)               

    def dfs(self):
        stack, visited = [], []
        root = self.root
        stack.append(root)
        print("\nDFS : ")
        while len(stack)>0:
            node = stack.pop()
            if node not in visited:
                visited.append(node)
                print(node.data,end=" ")
            for x in node.neighbors:
                if x not in visited:
                    stack.append(x)                


graph = Graph()
graph.buildGraph()
graph.dfs()
