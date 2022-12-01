"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina


class Node:
    def __init__(self, data):
        self._data = data
        self._next = None

    def __str__(self):
        return self._data.__str__()

    def get_data(self):
        return self._data

    def set_data(self, data):
        self._data = data
        return None

    def get_next(self):
        return self._next

    def set_next(self, new_next):
        self._next = new_next
        return None


class LinkedList:
    def __init__(self, values=None):
        self._head = None
        if values is not None:
            self.insert_multiple(values)

    def get_head(self):
        return self._head

    def insert(self, data):
        self._head = self.__insert(self._head, data)

    def insert_multiple(self, values):
        for val in values:
            self._head = self.__insert(self._head, val)

    def __insert(self, head, data):
        if head is None:
            return Node(data)
        else:
            head.set_next(self.__insert(head.get_next(), data))
        return head

    def display(self):
        if self._head is None:
            return
        return self.__display(self._head)

    def __display(self, node):
        if node is None:
            return
        print(node.get_data(), end="\n")
        self.__display(node.get_next())


class Table:
    def __init__(self, size: int):
        self._size = size
        self._table = [LinkedList()] * self._size

    def display_all(self):
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].display()
        return None

    def insert(self, data, indicator):
        if self._table[indicator].get_head() is None:
            self._table[indicator] = LinkedList()
        self._table[indicator].insert_multiple(data)
        return None
