import unittest


class TestSum(unittest.TestCase):
    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple_false(self):
        self.assertEqual(sum((1, 2, 2)) == 6)

    def test_remove_last(self):
        name = "tyler"
        self.assertEqual("r", name[-1]) 


if __name__ == "__main__":
    unittest.main()
