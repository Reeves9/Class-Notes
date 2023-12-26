class node:
    def __init__(self,value,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right
    def __str__(self):
        return "Node("+str(self.value)+")"

def walk(tree):
    if tree is not None:
        print(tree.value)
        walk(tree.left)
        walk(tree.right)

myTree=node(1,node(2,node(4),node(5)),node(3,node(6),node(7)))
walk(myTree)
        
    