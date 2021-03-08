class Node:
	def __init__(self, key, data, right=None, left=None, parent=None):
		self.key = key
		self.data = data
		self.right = right
		self.left = left

class BinTree:
	def __init__(self, root=None):
		self.root = root

	def store(self, key, data): #store(nyckel, data) som lagrar data som value i ditt binärträd, med nyckel som key.
		nod = Node(key, data)
		if self.root == None: # om det inte finns root
			self.root = nod # då blir nod root
		else:
			parentnod = self.root # annars, ta fram noden till root
			self.recstore(nod, parentnod) # använd hjälpfunktionen recstore

	def recstore(self, nod, parent):
		if parent.key > nod.key: # om föräldern är större än noden
			if parent.left == None: # spara noden till vänster om den är tom
				parent.left = nod
			else:
				parentnod = parent.left
				self.recstore(nod, parentnod) # annars blir den nya föräldern noden till vänster
		elif parent.key < nod.key: # om föräldern är mindre än noden
			if parent.right == None: # spara noden till höger om den är tom
				parent.right = nod
			else:
				parentnod = parent.right # annars blir den nya föräldern noden till höger
				self.recstore(nod, parentnod)

	def search(self, key): #search(x) som returnerar data associerat med x och kastar KeyError om nyckeln inte finns. 
		nod = self.root
		if nod != None: # om root är None, returnera None
			return self.recsearch(nod, key) # annars anropas recsearch
		else:
			raise KeyError

	def recsearch(self, nod, key): # hjälpfunktion till search
		try:
			if nod == None: # noden är tom, returnera None
				return None
			elif nod.key == key:
				return nod.data # returnerar data till noden
			elif nod.key < key: # om nodens nyckel är mindre än den nyckel du söker
				nod = nod.right
				return self.recsearch(nod, key) # kolla höger om noden
			elif nod.key > key: # om nodens nyckel är större än den nyckel du söker
				nod = nod.left
				return self.recsearch(nod, key) # kolla vänster om noden
		except KeyError:
			pass

	def inorder(self):
		if self.root != None: # om root finns
			nod = self.root 
			self.recinorder(nod) # rekursiv hjälpfunktion recinorder
		print(" ")

	def recinorder(self, nod): # hjälpfunktion till inorder
		if nod.left != None: # om det noden har en pekare till vänster (ett tal som är mindre)
			self.recinorder(nod.left) # gå vidare med det talet som är mindre
		print(nod.data, end = " ") # minsta talet printas först sen högsta pga rekursiv
		if nod.right != None: # om noden har en pekare till höger (ett tal som är större)
			self.recinorder(nod.right) # gå vidare med det talet (printar sista)

	def __contains__(self, key):
		done = False
		nod = self.root
		while not done:	
			if nod == None: # noden finns inte
				return False
			elif nod.key == key: # nodens nyckel är nyckeln du söker
				return True
			elif nod.key < key: # nodens nyckel är mindre än nyckeln du söker
				nod = nod.right
			elif nod.key > key: # nodens nyckel är större än nyckeln du söker
				nod = nod.left
