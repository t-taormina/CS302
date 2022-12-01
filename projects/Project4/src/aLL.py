"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return self.data.__str__()


class LinkedList:
    def __init__(self, values=None):
        self.head = None
        if values is not None:
            self.insert_multiple(values)

    def insert(self, data):
        self.head = self.__insert(self.head, data)

    def insert_multiple(self, values):
        for val in values:
            self.head = self.__insert(self.head, val)

    def __insert(self, head, data):
        if head is None:
            return Node(data)
        else:
            head.next = self.__insert(head.next, data)
        return head

    def display(self):
        if self.head is None:
            return
        return self.__display(self.head)

    def __display(self, node):
        if node is None:
            return
        print(node.data, end="\n")
        self.__display(node.next)


class Table:
    def __init(self, size: int):
        self.size = size
        self.table = [LinkedList] * self.size

    def display(self):
        return None

    def __display(self, node):
        return None

    def insert(self, data, indicator: int):
        return None

    def __insert(self, node):
        return None
