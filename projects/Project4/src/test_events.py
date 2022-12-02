"""
Tyler Taormina
taormina@pdx.edu
Test suite for Program 4 CS302
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode

from events import Event, Home, Away, Vacation
from aLL import Node, LinkedList, Table
from red_black import RBnode, RBtree


class TestEvent:
    def test_event_init(self):
        event = Event("lunch", "timberline", "20221114")
        assert event._title == "lunch"
        assert event._location == "timberline"
        assert event._date == "20221114"
