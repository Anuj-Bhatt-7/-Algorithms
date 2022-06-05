class Node:

    def __init__(self, value):

        self.leftChild = None
        self.rightChild = None
        self.value = value


    def insert(self, value):

        if self.value:
            if value < self.value:
                if self.leftChild is None:
                    self.leftChild = Node(value)
                else:
                    self.leftChild.insert(value)
            elif value > self.value:
                if self.rightChild is None:
                    self.rightChild = Node(value)
                else:
                    self.rightChild.insert(value)
        else:
            self.value = value


    def PrintTree(self):
        if self.leftChild:
            self.leftChild.PrintTree()
        print( self.value),
        if self.rightChild:
            self.rightChild.PrintTree()

    def printInorder(self, root):
        res = []
        if root:
            res = self.printInorder(root.leftChild)
            res.append(root.value)
            res = res + self.printInorder(root.rightChild)
        return res



    def printPre(self, root):
        res = []
        if root:
            res.append(root.value)
            res = res + self.printPre(root.leftChild)
            res = res + self.printPre(root.rightChild)
        return res


    def prinPost(self, root):
        res = []
        if root:
            res = self.prinPost(root.leftChild)
            res = res + self.prinPost(root.rightChild)
            res.append(root.value)
        return res


root = Node(40)
root.insert(30)
root.insert(50)
root.insert(25)
root.insert(35)
root.insert(15)
root.insert(28)
root.insert(45)

print("\nInorder traversal of Binary tree:\n")
print(root.printInorder(root))

print("\nPostorder traversal of Binary tree:\n")
print(root.prinPost(root))

print("\nPreorder traversal of Binary tree:\n")
print(root.printPre(root))