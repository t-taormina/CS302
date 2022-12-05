"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode


class RBnode:
    def __init__(self, data):
        self._data = data
        self._review: str
        self._red = False
        self._parent = None
        self._left = None
        self._right = None

    def __str__(self):
        return self._data.__str__()

    def __lt__(self, other):
        """
        """
        return self._data.__lt__(other)

    def __ge__(self, other):
        """
        """
        return self._data.__ge__(other)

    def red(self):
        """
        """
        self._red = True
        return None

    def is_red(self):
        """
        """
        return self._red

    def black(self):
        """
        """
        self._red = False
        return None

    def match(self, data):
        """
        """
        return self._data.match(data)

    def add_review(self, arg: str):
        """
        """
        self._review = arg
        return None

    def set_right(self, arg):
        """
        """
        self._right = arg
        return None

    def get_right(self):
        """
        """
        return self._right

    def set_left(self, arg):
        """
        """
        self._left = arg
        return None

    def get_left(self):
        """
        """
        return self._left

    def set_parent(self, arg):
        """
        """
        self._parent = arg
        return None

    def get_parent(self):
        """
        """
        return self._parent


class RBtree:
    def __init__(self):
        """
        """
        self._root = None

    def insert(self, data):
        """
        """
        if self._root is None:
            self._root = RBnode(data)
            return
        self._root = self.__insert(self._root, data)

    def __insert(self, root, data):
        """
        """
        if root is None:
            node = RBnode(data)
            node.red()
            return node
        else:
            if root._data.match_node(data):
                return root
            elif root._data < data:
                root.set_right(self.__insert(root.get_right(), data))
                if root.get_right().get_parent() is None:
                    root.get_right().set_parent(root)
            else:
                root.set_left(self.__insert(root.get_left(), data))
                if root.get_left().get_parent() is None:
                    root.get_left().set_parent(root)
        return root

    def display(self):
        """
        """
        if self._root is None:
            return None
        self.__display(self._root)
        return None

    def __display(self, root):
        """
        """
        if root:
            self.__display(root.get_left())
            print(root)
            self.__display(root.get_right())
        return None
