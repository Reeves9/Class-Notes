class node:
    def __init__(self,value,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right
    def __str__(self):
        return "node("+str(self.value)+")"

def bfs(node,queue):
    queue.append(node)
    while len(queue) > 0:
        node = queue.pop(0)
        if node is not None:
            print(node)
            queue.append(node.left)
            queue.append(node.right)

myTree=node(1,node(2,node(4),node(5)),node(3,node(6),node(7)))
bfs(myTree,[])