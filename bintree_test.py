import unittest

from bintree import *

class BintreeTest(unittest.TestCase):

    def testInsert(self): # testar att spara nyckeln "adam" med värdet 123
        b = BinTree()
        b.store("adam", 123)
        nod = b.root
        self.assertEqual(nod.key, "adam")
        self.assertEqual(nod.data, 123)

    def testInsertMore(self): # testar att noder sparas rätt i binärträdet
        b = BinTree()
        b.store(10, 10)
        b.store(5, 5)
        b.store(20, 20)
        nod = b.root
        left = nod.left
        right = nod.right
        self.assertEqual(left.data, 5)
        self.assertEqual(right.data, 20)

    def testContains(self): # testar att noderna går att hitta
        b = BinTree()
        b.store(10, 10)
        b.store(5, 5)
        b.store(20, 20)
        self.assertIn(5, b)
        self.assertNotIn(8, b)

    def testSearch(self): # testar search metoden
        b = BinTree()
        b.store(10, "tio")
        b.store(5, "fem")
        b.store(20, "tjugo")
        self.assertEqual(b.search(10), "tio")        

    def testKeyError(self): # testar att KeyError fungerar
        b = BinTree()        
        with self.assertRaises(KeyError): 
            b.search("eva") 

if __name__ == '__main__':
    unittest.main()