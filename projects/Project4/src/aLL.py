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

    def match(self, arg):
        return self._data.match(arg)


class LinkedList:
    def __init__(self, values=None):
        self._head = None
        if values is not None:
            self.insert_multiple(values)

    def __str__(self):
        return '\n'.join([str(node) for node in self])

    def __iter__(self):
        current = self._head
        while current:
            yield current
            current = current.get_next()

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

    def display_specific(self, arg: str):
        """
        """
        if self._head is None:
            return
        self.__display_specific(self._head, arg)

    def __display_specific(self, node, arg: str):
        if node is None:
            return
        if node.match(arg):
            print(node)
        self.__display_specific(node.get_next(), arg)

    def remove_specific(self, arg: str):
        if self._head is None:
            return
        if self._head.match(arg):
            temp = self._head.get_next()
            del self._head
            self._head = temp
            return
        self._head = self.__remove_specific(self._head,
                                            self._head.get_next(),
                                            arg)

    def __remove_specific(self, prev, current, arg: str):
        if current is None:
            return
        if current.match(arg):
            temp = current.get_next()
            del current
            prev.set_next(temp)
            return prev
        prev.set_next(self.__remove_specific(prev.get_next(),
                                             current.get_next(),
                                             arg))
        return prev


class Table:
    def __init__(self, size: int):
        self._size = size
        self._table = [LinkedList()] * self._size

    def __str__(self):
        return '\n'.join([str(list) for list in self])

    def __iter__(self):
        for list in self._table:
            yield list

    def display_all(self):
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].display()
        return None

    def display_category(self, indicator):
        if self._table[indicator] is not None:
            # self._table[indicator].display()
            print(self._table[indicator])
        return None

    def display_specific_event(self, arg: str):
        """
        """
        if len(arg) == 0:
            return None
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].display_specific(arg)
        return None

    def insert(self, data, indicator):
        if self._table[indicator].get_head() is None:
            self._table[indicator] = LinkedList()
        self._table[indicator].insert_multiple(data)
        return None

    def remove_event(self, arg: str):
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].remove_specific(arg)
        return None
