"""
Tyler Taormina
taormina@pdx.edu
Test suite for Program 4 CS302
"""
# cSpell:ignore Taormina
# cSpell:ignore RBnode


from client import Client
import random
import datetime
from events import Event, Home, Away, Vacation, date
from red_black import RBtree
from aLL import Table, LinkedList

# Type Indicators.
HOME = 0
AWAY = 1
VACATION = 2
TYPE_INDICATORS = [HOME, AWAY, VACATION]
TABLE_SIZE = 3
NIL = Event("Null", "Null", date(2022, 1, 1))
ENTER = 'PRESS ENTER TO CONTINUE:'
CENTER = 80
MAIN_MENU_SIZE = 9


class TestEvent:
    def test_event_init(self):
        event = Event("lunch", "timberline", date(2022, 11, 14))
        assert event._title == "lunch"
        assert event._location == "timberline"
        assert event._date == date(2022, 11, 14)

    def test_event_comparisons(self):
        e1 = Event("lunch", "timberline", date(2022, 11, 14))
        e2 = Event("dinner", "timberline", date(2022, 11, 14))
        assert (e2 < e1) is True
        assert (e2 >= e1) is False

    def test_event_edit(self):
        e1 = Event("lunch", "timberline", date(2022, 11, 14))
        e1.edit_title("dinner")
        assert e1._title == "dinner"
        e1.edit_location("mammoth")
        assert e1._location == "mammoth"

    def test_event_match_object(self):
        e1 = Event("lunch", "timberline", date(2022, 11, 14))
        e2 = Event("lunch", "work", date(2022, 11, 14))
        e3 = Event("dinner", "work", date(2022, 11, 14))
        assert e1.match_object(e2) is True
        assert e1.match_object(e3) is False

    def test_event_match(self):
        e1 = Event("lunch", "timberline", date(2022, 11, 14))
        e2 = Event("dinner", "work", date(2022, 11, 14))
        arg1 = "lunch"
        arg2 = "dinner"
        assert e1.match(arg1) == 0
        assert e1.match(arg2) == 1
        assert e2.match(arg1) == -1

    def test_event_before(self):
        e1 = Event("lunch", "timberline", date(2022, 11, 14))
        e2 = Event("dinner", "work", date(2022, 11, 15))
        e3 = Event("dinner", "work", date(2022, 11, 14))
        assert e1.before(e2) is True
        assert e2.before(e1) is False
        assert e1.before(e3) is False


class TestHome:
    def test_home_init(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        home = Home("0400pm", guests, "Family dinner", date(2022, 11, 14))
        assert home._title == "Family dinner"
        assert home._start_time == "0400pm"
        assert home._location == "Home"
        assert home._date == date(2022, 11, 14)

    def test_home_comparisons(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        h1 = Home("0400pm", guests, "Family dinner", date(2022, 11, 14))
        h2 = Home("0400pm", guests, "BBQ", date(2022, 11, 14))
        assert (h2 < h1) is True
        assert (h2 >= h1) is False

    def test_home_add_guest(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        h2 = Home("0400pm", guests, "BBQ", date(2022, 11, 14))
        h2.add_guest("Tyler")
        assert h2._guest_list[-1] == "Tyler"

    def test_home_match(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        h1 = Home("0400pm", guests, "BBQ", date(2022, 11, 14))
        assert h1.match("BBQ") == 0
        assert h1.match("bbq") == 0
        assert h1.match("Dinner") == -1
        assert h1.match("A") == 1

    def test_home_match_object(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        h1 = Home("0400pm", guests, "BBQ", date(2022, 11, 14))
        h2 = Home("0400pm", guests, "bbq", date(2022, 11, 14))
        h3 = Home("0400pm", guests, "Dinner", date(2022, 11, 14))
        h4 = Home("0400pm", guests, "a", date(2022, 11, 14))
        assert h1.match_object(h1) is True
        assert h1.match_object(h2) is True
        assert h1.match_object(h3) is False
        assert h1.match_object(h4) is False

    def test_home_before(self):
        guests = ["Layna", "Ry", "Grandpa", "Grandma",
                  "Aaron", "Mom", "Frank"]
        h1 = Home("0400pm", guests, "BBQ", date(2022, 11, 1))
        h2 = Home("0400pm", guests, "bbq", date(2022, 11, 1))
        h3 = Home("0400pm", guests, "Dinner", date(2022, 11, 2))
        assert h1.before(h2) is False
        assert h1.before(h3) is True
        assert h3.before(h1) is False


class TestAway:
    def test_away_init(self):
        a = Away("Casual", "0400pm", "Soccer Dinner", "Kells",
                 date(2022, 11, 14))
        assert a._title == "Soccer Dinner"
        assert a._start_time == "0400pm"
        assert a._location == "Kells"
        assert a._dress_code == "Casual"
        assert a._date == date(2022, 11, 14)

    def test_away_comparisons(self):
        a1 = Away("Casual", "0400pm", "Soccer Dinner", "Kells",
                  date(2022, 11, 14))
        a2 = Away("Casual", "0400pm", "Soccer Breakfast", "Kells",
                  date(2022, 11, 14))
        assert (a1 >= a2) is True
        assert (a1 < a2) is False

    def test_away_match(self):
        a1 = Away("Casual", "0400pm", "Soccer breakfast", "Kells",
                  date(2022, 11, 14))
        arg1 = "soccer BREAKFAST"
        arg2 = "breakfast"
        arg3 = "Zebra"
        assert a1.match(arg1) == 0
        assert a1.match(arg2) == 1
        assert a1.match(arg3) == -1

    def test_away_match_object(self):
        a1 = Away("Casual", "0400pm", "Soccer breakfast", "Kells",
                  date(2022, 11, 14))
        a2 = Away("Casual", "0400pm", "Soccer BREAKFAST", "Kells",
                  date(2022, 11, 14))
        a3 = Away("Casual", "0400pm", "soccer dinner", "Kells",
                  date(2022, 11, 14))
        assert a1.match_object(a2) is True
        assert a1.match_object(a3) is False

    def test_away_before(self):
        a1 = Away("Casual", "0400pm", "Soccer breakfast", "Kells",
                  date(2022, 11, 14))
        a2 = Away("Casual", "0400pm", "Soccer BREAKFAST", "Kells",
                  date(2022, 12, 2))
        a3 = Away("Casual", "0400pm", "soccer dinner", "Kells",
                  date(2022, 11, 14))
        assert a1.before(a2) is True
        assert a1.before(a3) is False


class TestVacation:
    def test_vacation_init(self):
        pack = ["toothbrush", "clothes", "laptop", "phone", "charger"]
        v1 = Vacation(date(2023, 1, 1), pack, "Family vacation",
                      "Costa Mesa", date(2022, 12, 29))
        assert v1._title == "Family vacation"
        assert v1._location == "Costa Mesa"
        assert v1._end_date == date(2023, 1, 1)

    def test_vacation_comparisons(self):
        pack = ["toothbrush", "clothes", "laptop", "phone", "charger"]
        v1 = Vacation(date(2023, 1, 1), pack, "Family vacation",
                      "Costa Mesa", date(2022, 12, 29))
        v2 = Vacation(date(2023, 2, 20), pack, "vacation",
                      "Hawaii", date(2023, 2, 14))
        assert (v1 < v2) is True
        assert (v1 >= v2) is False

    def test_vacation_match(self):
        pack = ["toothbrush", "clothes", "laptop", "phone", "charger"]
        v1 = Vacation(date(2023, 1, 1), pack, "Family vacation",
                      "Costa Mesa", date(2022, 12, 29))
        arg1 = "FAMILY VAcatiON"
        arg2 = ""
        arg3 = "VACATIon"
        assert v1.match(arg1) == 0
        assert v1.match(arg2) == 1
        assert v1.match(arg3) == -1

    def test_vacation_match_object(self):
        pack = ["toothbrush", "clothes", "laptop", "phone", "charger"]
        v1 = Vacation(date(2023, 1, 1), pack, "Family vacation",
                      "Costa Mesa", date(2022, 12, 29))
        v2 = Vacation(date(2023, 2, 20), pack, "vacation",
                      "Hawaii", date(2023, 2, 14))
        v3 = Vacation(date(2023, 1, 1), pack, "Family VACATION",
                      "Costa Mesa", date(2022, 12, 29))
        assert v1.match_object(v2) is False
        assert v1.match_object(v3) is True

    def test_vacation_before(self):
        pack = ["toothbrush", "clothes", "laptop", "phone", "charger"]
        v1 = Vacation(date(2023, 1, 1), pack, "Family vacation",
                      "Costa Mesa", date(2022, 12, 29))
        v2 = Vacation(date(2023, 2, 20), pack, "vacation",
                      "Hawaii", date(2023, 2, 14))
        v3 = Vacation(date(2023, 1, 3), pack, "Gambling trip",
                      "Vegas", date(2022, 12, 25))
        assert v1.before(v2) is True
        assert v1.before(v3) is False
        assert v1.before(v1) is False


class TestLinkedList:
    def test_LL_init(self):
        l1 = LinkedList()
        assert l1.get_head() is None
        l1.insert_multiple(self.build_home_list())
        assert l1.get_head() is not None

    def test_LL_retrieve(self):
        l1 = LinkedList()
        homes = self.build_home_list()
        l1.insert_multiple(homes)
        data = l1.retrieve_event("bbq")
        data2 = l1.retrieve_event("no event")
        if data:
            assert data.match_object(homes[1])
        assert data2 is None

    def test_LL_remove(self):
        l1 = LinkedList()
        homes = self.build_home_list()
        l1.insert_multiple(homes)
        data = l1.retrieve_event("bbq")
        if data:
            assert data.match_object(homes[1])
        l1.remove_specific("bbq")
        data = l1.retrieve_event("bbq")
        assert data is None

    def test_LL_sorted(self):
        l1 = LinkedList()
        homes = self.build_home_list()
        l1.insert_multiple(homes)
        prev = l1.get_head()
        if prev:
            node = prev.get_next()
            while node:
                if prev:
                    assert prev.before(node.get_data()) is True
                    prev = node
                    node = node.get_next()

    def build_home_list(self):
        """Fills test tree and table with Home Events."""
        guests = ["Tony", "Alex", "Zach", "Will", "KJ", "Mom", "Frank"]
        h1 = Home("1200PM",
                  guests,
                  "Family Dinner",
                  date(2022, 12, 23))
        guests = ["Layna", "Ry", "Grandpa", "Grandma", "Aaron", "Mom", "Frank"]
        h2 = Home("0500PM",
                  guests,
                  "BBQ",
                  date(2022, 1, 1))
        guests = ["Taury", "Monique"]
        h3 = Home("0800AM",
                  guests,
                  "Breakfast",
                  date(2022, 12, 26))
        return [h1, h2, h3]

    def build_away_list(self):
        """Fills test tree and table with Away Events."""
        a1 = Away("Casual",
                  "1200PM",
                  "Work Dinner",
                  "Din Thai Fung",
                  date(2022, 12, 20))
        a2 = Away("Formal",
                  "0500PM",
                  "Ball",
                  "Convention Center",
                  date(2022, 12, 22))
        a3 = Away("Semi-Formal",
                  "0700PM",
                  "Cocktails",
                  "Kells",
                  date(2022, 12, 14))
        a4 = Away("Casual",
                  "0300PM",
                  "Family BBQ",
                  "Moms",
                  date(2022, 12, 24))
        return [a1, a2, a3, a4]

    def build_vacation_list(self):
        """Fills test tree and table with Vacation Events."""
        items = ["toiletries", "socks", "pants", "hat", "shoes",
                 "slippers", "laptop", "books"]
        v1 = Vacation(date(2023, 1, 5),
                      items,
                      "Family Vacation",
                      "California",
                      date(2022, 12, 23))
        v2 = Vacation(date(2022, 12, 20),
                      items,
                      "Ski Trip",
                      "Mt. Hood",
                      date(2022, 12, 16))
        return [v1, v2]


class TestTree:
    def test_tree_build(self):
        tree = RBtree()
        homes = self.build_home_list()
        tree.insert_multiple(homes, self.build_reviews(homes))
        assert tree._root is not None
        data = tree.retrieve("bbq")
        if data:
            assert data.match("BBQ") == 0

        data = tree.retrieve("ski trip")
        assert data is None

    def build_reviews(self, values):
        """Builds a list of reviews for testing."""
        testing = ["It was fun.", "It was amazing.", "I'd never do it again",
                   "Plan a little differently next year", "YESSSSS",
                   "Invite Mom to this.", "Call Frank about this one.",
                   "Lets find a better venue", "Hopefully I am not sick"]
        reviews = []
        for i in range(len(values)):
            num = random.randint(0, len(testing)-1)
            reviews.append(testing[num])
        return reviews

    def build_home_list(self):
        """Fills test tree and table with Home Events."""
        guests = ["Tony", "Alex", "Zach", "Will", "KJ", "Mom", "Frank"]
        h1 = Home("1200PM",
                  guests,
                  "Family Dinner",
                  date(2022, 12, 23))
        guests = ["Layna", "Ry", "Grandpa", "Grandma", "Aaron", "Mom", "Frank"]
        h2 = Home("0500PM",
                  guests,
                  "BBQ",
                  date(2022, 1, 1))
        guests = ["Taury", "Monique"]
        h3 = Home("0800AM",
                  guests,
                  "Breakfast",
                  date(2022, 12, 26))
        return [h1, h2, h3]

    def build_away_list(self):
        """Fills test tree and table with Away Events."""
        a1 = Away("Casual",
                  "1200PM",
                  "Work Dinner",
                  "Din Thai Fung",
                  date(2022, 12, 20))
        a2 = Away("Formal",
                  "0500PM",
                  "Ball",
                  "Convention Center",
                  date(2022, 12, 22))
        a3 = Away("Semi-Formal",
                  "0700PM",
                  "Cocktails",
                  "Kells",
                  date(2022, 12, 14))
        a4 = Away("Casual",
                  "0300PM",
                  "Family BBQ",
                  "Moms",
                  date(2022, 12, 24))
        return [a1, a2, a3, a4]

    def build_vacation_list(self):
        """Fills test tree and table with Vacation Events."""
        items = ["toiletries", "socks", "pants", "hat", "shoes",
                 "slippers", "laptop", "books"]
        v1 = Vacation(date(2023, 1, 5),
                      items,
                      "Family Vacation",
                      "California",
                      date(2022, 12, 23))
        v2 = Vacation(date(2022, 12, 20),
                      items,
                      "Ski Trip",
                      "Mt. Hood",
                      date(2022, 12, 16))
        return [v1, v2]
