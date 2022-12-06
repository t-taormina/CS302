"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina


class Node:
    def __init__(self, data):
        """
        Initializes a node with argument passed. Next pointer is defaulted
        to None."""
        self._data = data
        self._next = None

    def __str__(self):
        """Returns string representation of data stored in the node."""
        return self._data.__str__()

    def get_data(self):
        """Returns the data stored in the node."""
        return self._data

    def set_data(self, data):
        """Data passed as an argument replaces data stored in the node."""
        self._data = data
        return None

    def get_next(self):
        """Returns the next pointer. None is returned if no next node is
        present."""
        return self._next

    def set_next(self, new_next):
        """Argument passed replaces next node."""
        self._next = new_next
        return None

    def match(self, arg):
        """Calls match function of data(see events.py). Returns true if
        argument and the calling nodes data match."""
        return self._data.match(arg)

    def before(self, data):
        """Determines if self._data has a date member that is prior to the
        date of the object passed in the argument."""
        return self._data.before(data)


class LinkedList:
    def __init__(self, values=None):
        """Initializes a linked list. Values is either None or an array of
        objects that are inserted into the list."""
        self._head = None
        if values is not None:
            self.insert_multiple(values)

    def __str__(self):
        """ Returns string representation of data stored in the list."""
        return '\n'.join([str(node) for node in self])

    def __iter__(self):
        """Creates an iterator that can be used to loop through the list."""
        current = self._head
        while current:
            yield current
            current = current.get_next()

    def get_head(self):
        """Returns the head node of the linked list. Returns None if the list
        is empty."""
        return self._head

    def insert(self, data):
        """Inserts argument into the linked list sorted by the date member."""
        self._head = self.__insert(self._head, data)

    def insert_multiple(self, values):
        """Takes an array of objects as an argument and inserts each object
        into the linked list."""
        for val in values:
            self._head = self.__insert(self._head, val)

    def __insert(self, head, data):
        """Recursively inserts the data into the list sorted by the date
        member. No objects with the same title(non-case sensitive) will be
        entered."""
        if head is None:
            return Node(data)
        if head.before(data):
            head.set_next(self.__insert(head.get_next(), data))
        else:
            if not head.get_data().match_object(data):  # no duplicates
                temp = head
                head = Node(data)
                head.set_next(temp)
        return head

    def display(self):
        """Calls recursive display to display all objects stored in the list.
        """
        if self._head is None:
            return
        return self.__display(self._head)

    def __display(self, node):
        """Recursively displays all objects in the list."""
        if node is None:
            return
        print(node.get_data(), end="\n")
        self.__display(node.get_next())

    def display_specific(self, arg: str):
        """Displays an object if it matches the argument passed. Non-case
        sensitive."""
        if self._head is None:
            return None
        self.__display_specific(self._head, arg)

    def __display_specific(self, node, arg: str):
        """Recursively searches the list and displays object if the title
        matches the string passed as an argument."""
        if node is None:
            return None
        if node.match(arg):
            print(node)
        self.__display_specific(node.get_next(), arg)

    def remove_specific(self, arg: str):
        """Calls recursive function to remove a node if its data member has a
        title that mathes the string passed as an argument."""
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
        """Recursively searches for a node with a data member that has a title
        that matches the string passed as an argument."""
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
        """Initializes an array with the size passed as an argument. Each index
        contains a default linked list(head=None)."""
        self._size = size
        self._table = [LinkedList()] * self._size

    def __str__(self):
        """Returns a string representation of the entire table."""
        return '\n'.join([str(list) for list in self])

    def __iter__(self):
        """Creates an iterator that will iterate through each index of the
        table."""
        for list in self._table:
            yield list

    def display_all(self):
        """Iteratively progresses through the array and calls recursive display
        function from the LinkedList class."""
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].display()
        return None

    def display_category(self, type_indicator):
        """Dispaly specific category that is specified by the type indicator
        argument."""
        if self._table[type_indicator] is not None:
            # self._table[indicator].display()
            print(self._table[type_indicator])
        return None

    def display_specific_event(self, arg: str):
        """Displays an event that mathes the string passed as an argument.
        Nothing will be output if there is no match."""
        if len(arg) == 0:
            return None
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].display_specific(arg)
        return None

    def insert(self, data, indicator):
        """Inserts an array into the """
        if self._table[indicator].get_head() is None:
            self._table[indicator] = LinkedList()
        self._table[indicator].insert(data)
        return None

    def insert_multiple(self, data, type_indicator):
        """Inserts an array of objects into the linked list stored at the
        index specified by the type indicator."""
        if self._table[type_indicator].get_head() is None:
            self._table[type_indicator] = LinkedList()
        self._table[type_indicator].insert_multiple(data)
        return None

    def remove_event(self, arg: str):
        """Removes an item from the table if there is a a title member that
        matches the string argument."""
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                self._table[i].remove_specific(arg)
        return None

    def display_next(self):
        """Displays that object stored in the list that will occur next based
        on the date data member."""
        next_event = None
        for i in range(self._size):
            if self._table[i].get_head() is not None:
                if next_event is None:
                    next_event = self._table[i].get_head()
                elif next_event.get_data() is not None:
                    temp = self._table[i].get_head()
                    if temp is not None:
                        if temp.get_data().before(next_event.get_data()):
                            next_event = temp
        if next_event is not None:
            print(next_event.get_data())
        return None

    def display_next_specific(self, type_indicator):
        """Displays that object stored in the list that will occur next for a
        specific category based on the date data member. Type indicators are
        provided as constants. HOME = 0, AWAY = 1, VACATION = 2."""
        if self._table[type_indicator].get_head() is None:
            return None
        data = self._table[type_indicator].get_head()
        if data is not None:
            data = data.get_data()
            if data is not None:
                print(data)
        return None
