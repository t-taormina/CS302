"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode


class RBnode:
    def __init__(self, data, review):
        """Initializes the node with all children and parent set to None and
        data set to the argument. Red is set to False by default."""
        self._data = data
        self._review = review
        self._red = True
        self._parent = None
        self._left = None
        self._right = None

    def __str__(self):
        """Returns string representation of the data and review members."""
        return (self._data.__str__() +
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

    def match(self, data: str):
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

    def get_data(self):
        return self._data


class RBtree:
    def __init__(self):
        """Initializes reb-black tree with root node as None."""
        self._root = None

    def __repr__(self):
        lines = []
        self.print_tree(lines)
        return '\n'.join(lines)

    def insert(self, data, review: str):
        """Calls recursive private insert function. Adds objects into the tree
        alphabetically. Takes string argument for the review field of the
        RBnode. Client is responsible for prompting for review and passing
        argument."""
        if self._root is None:  # empty tree
            self._root = RBnode(data, review)
            self._root.black()  # root node gets set to black
        else:
            self.__insert(self._root, data, review)

    def insert_multiple(self, values, reviews):
        """Prompts for review to be entered and loops through array "values"
        and calls insert for each value. "values" is an array of event objects.
        This function is mostly for testing purposes.
        """
        for i in range(len(values)):
            self.insert(values[i], reviews[i])

    def __insert(self, root, data, review: str):
        """Private recursive insert that enters data alphabetically."""
        if data < root._data:
            if root.get_left():
                self.__insert(root.get_left(), data, review)
            else:
                root.set_left(RBnode(data, review))
                root.get_left().set_parent(root)
                self.__fix_insert(root.get_left())
        else:
            if root.get_right():
                self.__insert(root.get_right(), data, review)
            else:
                root.set_right(RBnode(data, review))
                root.get_right().set_parent(root)
                self.__fix_insert(root.get_right())

    def __fix_insert(self, node):
        """Balances the tree using rotate functions."""
        if node and node.get_parent():
            while node.get_parent().is_red():
                if (node.get_parent() is
                   node.get_parent().get_parent().get_right()):
                    uncle = node.get_parent().get_parent().get_left()
                    if uncle:
                        if uncle.is_red():
                            uncle.black()
                            node.get_parent().black()
                            node.get_parent().get_parent().red()
                            node = node.get_parent().get_parent()
                    else:
                        if node is node.get_parent().get_left():
                            node = node.get_parent()
                            self.rotate_right(node)
                        node.get_parent().black()
                        node.get_parent().get_parent().red()
                        self.rotate_left(node.get_parent().get_parent())
                else:
                    uncle = node.get_parent().get_parent().get_right()
                    if uncle:
                        if uncle.is_red():
                            uncle.black()
                            node.get_parent().black()
                            node.get_parent().get_parent().red()
                            node = node.get_parent().get_parent()
                    else:
                        if node is node.get_parent().get_right():
                            node = node.get_parent()
                            self.rotate_left(node)
                        node.get_parent().black()
                        node.get_parent().get_parent().red()
                        self.rotate_right(node.get_parent().get_parent())
                if node is self._root:
                    break
        if self._root:
            self._root.black()

    def rotate_left(self, node):
        """Rotates the tree left at the node passed as an argument."""
        temp = node.get_right()
        node.set_right(temp.get_left())
        if temp.get_left() is not None:
            temp.get_left().set_parent(node)
        temp.set_parent(node.get_parent())
        if node.get_parent() is None:
            self._root = temp
        elif node is node.get_parent().get_left():
            node.get_parent().set_left(temp)
        else:
            node.get_parent().set_right(temp)
        temp.set_left(node)
        node.set_parent(temp)

    def rotate_right(self, node):
        """Rotates the tree right at the node passed as an argument."""
        temp = node.get_left()
        node.set_left(temp.get_right())
        if temp.get_right() is not None:
            temp.get_right().set_parent(node)
        temp.set_parent(node.get_parent())
        if node.get_parent() is None:
            self._root = temp
        elif node == node.get_parent().get_right():
            node.get_parent().set_right(temp)
        else:
            node.get_parent().set_left(temp)
        temp.set_right(node)
        node.set_parent(temp)

    def print_tree(self, lines, level=0):
        if self._root is None:
            return
        self.__print_tree(self._root, lines, level=0, child='root')

    def __print_tree(self, node, lines, level=0, child='root'):
        if node is None:
            return
        self.__print_tree(node.get_left(), lines, level + 1, child="l")
        lines.append(f'Level: {level} ' +
                     ('red' if node.is_red() else 'black') +
                     '\n' + child + '\n' + str(node))
        self.__print_tree(node.get_right(), lines, level + 1, child="r")

    def display(self):
        """Calls private recursive display. Displays all nodes in tree."""
        if self._root is None:
            return
        self.__display(self._root)

    def __display(self, root):
        """Private recursive function to display all nodes in the tree."""
        if root is None:
            return
        self.__display(root.get_left())
        print(root)
        self.__display(root.get_right())

    def retrieve(self, arg: str):
        """Returns a copy of event object that contains a matching title to
        the argument passed."""
        if self._root is None:  # empty tree
            return
        return self.__retrieve(self._root, arg)

    def __retrieve(self, root, arg: str):
        """Private recursive function to retrieve an event object that matches
        the argument passed."""
        if root is None:
            return
        elif root.match(arg) == 0:
            return root.get_data()
        elif root.match(arg) > 0:
            data = self.__retrieve(root.get_left(), arg)
        else:
            data = self.__retrieve(root.get_right(), arg)
        return data
