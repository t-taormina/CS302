"""
Tyler Taormina
taormina@pdx.edu
"""
# cSpell:ignore Taormina

from config import TABLE_SIZE


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return self.data.__str__()
