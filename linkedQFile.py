class Node: # skapar en nod
	def __init__(self, value, nextNode=None):
		self.value = value # sätter värdet på noden
		self.next = nextNode # sätter värdet på nästa nod

class LinkedQ:
	def __init__(self):
		self.__first = None # sätter första nod
		self.__last = None # sätter sista nod

	def enqueue(self, x):	#stoppa in x sist
		ny = Node(x) # ny nod 
		if self.__first==None: # om första noden är tom
			self.__first = ny # då blir den nya noden den första noden
			self.__last = ny # sista noden blir också den nya noden
		else:
			gammal = self.__last # spara den förra noden som var sist
			self.__last = ny # nu blir den nya noden den sista noden
			gammal.next = ny # den förra noden blir pekar på den nya noden

	def dequeue(self):	#plocka ut det som står först
		if self.__first==None: # om första noden är tom
			return None # det finns inget att plocka ut
		else:
			nod = self.__first # första noden sparas
			x = nod.value # värdet på första noden
			self.__first = nod.next # första noden blir nästa nod
			return x

	def isEmpty(self):	# kolla om kön är tom
		if self.__first==None: # om första noden är tom
			return True # kön är tom
		else:
			return False # kön är inte tom