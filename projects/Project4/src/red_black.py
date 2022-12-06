"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode


class RBnode:
    def __init__(self, data):
        """Initializes the node with all children and parent set to None and
        data set to the argument. Red is set to False by default."""
        self._data = data
        self._review: str
        self._red = False
        self._parent = None
        self._left = None
        self._right = None

    def __str__(self):
        """Returns string representation of the data and review members."""
        return (self._data.__str__() +
                '\n' +
                f'Review: {self._review}\n')

    def __lt__(self, other):
        """Determines if self has alphabetical priority over the argument
        passed."""
        return self._data.__lt__(other)

    def __ge__(self, other):
        """Determines if other has alphabetical over self."""
        return self._data.__ge__(other)

    def red(self):
        """Sets red data member to True."""
        self._red = True
        return None

    def is_red(self):
        """Returns red data member."""
        return self._red

    def black(self):
        """Sets red data member to False."""
        self._red = False
        return None

    def match(self, data):
        """Determines if self has a matching data member to the argument
        passed."""
        return self._data.match(data)

    def add_review(self, arg: str):
        """Replaces review data member with argument."""
        self._review = arg
        return None

    def set_right(self, arg):
        """Sets right child node with argument."""
        self._right = arg
        return None

    def get_right(self):
        """Returns right child node."""
        return self._right

    def set_left(self, arg):
        """Sets left child node with argument."""
        self._left = arg
        return None

    def get_left(self):
        """Returns left child node."""
        return self._left

    def set_parent(self, arg):
        """Sets parent node with argument."""
        self._parent = arg
        return None

    def get_parent(self):
        """Returns parent node."""
        return self._parent


class RBtree:
    def __init__(self, nil):
        """Initializes reb-black tree with root node as None."""
        self._nil = RBnode(nil)
        self._nil.set_parent(self._nil)
        self._nil.set_left(self._nil)
        self._nil.set_right(self._nil)
        self._nil.black()
        self._root = self._nil

    def __repr__(self):
        lines = []
        self.print_tree(lines)
        return '\n'.join(lines)

    def insert(self, data, review: str):
        """Calls recursive private insert function. Adds objects into the tree
        alphabetically. Takes string argument for the review field of the
        RBnode. Client is responsible for prompting for review and passing
        argument."""
        self._root = self.__insert(self._root, self._root, data, review)

    def __insert(self, root, parent, data, review: str):
        """Private recursive insert that enters data alphabetically."""
        if root == self._nil:
            root = RBnode(data)
            root.add_review(review)
            root.set_left(self._nil)
            root.set_right(self._nil)
            root.set_parent(parent)
            if parent == self._nil:
                return root
            elif parent.get_parent() == self._nil:
                root.red()
                return root
            else:
                root.red()
                self.__fix_insert(root)
                return root
        else:
            if root._data.match_object(data):
                return root
            if root._data < data:
                root.set_right(self.__insert(root.get_right(),
                                             root, data, review))
            else:
                root.set_left(self.__insert(root.get_left(),
                                            root, data, review))
        return root

    def __fix_insert(self, node):
        """Balances the tree using rotate functions."""
        while node.get_parent().is_red():
            # right line case
            if node.get_parent() == node.get_parent().get_parent().get_right():
                uncle = node.get_parent().get_parent().get_left()
                if uncle.is_red():
                    uncle.black()
                    node.get_parent().black()
                    node.get_parent().get_parent().red()
                    node = node.get_parent().get_parent()
                else:
                    if node == node.get_parent().get_left():
                        node = node.get_parent()
                        self.rotate_right(node)
                    node.get_parent().black()
                    node.get_parent().get_parent().red()
                    self.rotate_left(node.get_parent().get_parent())
            else:
                uncle = node.get_parent().get_parent().get_right()
                if uncle.is_red():
                    uncle.black()
                    node.get_parent().black()
                    node.get_parent().get_parent().red()
                    node = node.get_parent().get_parent()
                else:
                    if node == node.get_parent().get_right():
                        node = node.get_parent()
                        self.rotate_left(node)
                    node.get_parent().black()
                    node.get_parent().get_parent().red()
                    self.rotate_right(node.get_parent().get_parent())
            if node == self._root:
                break
        self._root.black()

    def rotate_left(self, node):
        """Rotates the tree left at the node passed as an argument."""
        temp = node.get_right()
        node.set_right(temp.get_left())
        if temp.get_left() != self._nil:
            temp.get_left().set_parent(node)
        temp.set_parent(node.get_parent())
        if node.get_parent() == self._nil:
            self._root = temp
        elif node == node.get_parent().get_left():
            node.get_parent().set_left(temp)
        else:
            node.get_parent().set_right(temp)
        temp.set_left(node)
        node.set_parent(temp)

    def rotate_right(self, node):
        """Rotates the tree right at the node passed as an argument."""
        temp = node.get_left()
        node.set_left(temp.get_right())
        if temp.get_right() != self._nil:
            temp.get_right().set_parent(node)
        temp.set_parent(node.get_parent())
        if node.get_parent() == self._nil:
            self._root = temp
        elif node == node.get_parent().get_right():
            node.get_parent().set_right(temp)
        else:
            node.get_parent().set_left(temp)
        temp.set_right(node)
        node.set_parent(temp)

    def print_tree(self, lines, level=0):
        if self._root == self._nil:
            return None
        else:
            self.__print_tree(self._root, lines, level=0)
        return None

    def __print_tree(self, node, lines, level=0):
        if node != self._nil:
            self.__print_tree(node.get_left(), lines, level + 1)
            lines.append(f'Level: {level}' + ('r' if node.is_red() else 'b') +
                         '\n' + str(node))
            self.__print_tree(node.get_right(), lines, level + 1)
        return None

    def display(self):
        """Calls private recursive display. Displays all nodes in tree."""
        if self._root == self._nil:
            return None
        self.__display(self._root)
        return None

    def __display(self, root):
        """Private recursive function to display all nodes in the tree."""
        if root != self._nil:
            self.__display(root.get_left())
            print(root)
            self.__display(root.get_right())
        return None
