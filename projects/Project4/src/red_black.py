"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode


class RBnode:
    def __init__(self, data):
        self.data = data
        self.red = False
        self.parent = None
        self.left = None
        self.right = None

    def __str__(self):
        return self.data.__str__()
