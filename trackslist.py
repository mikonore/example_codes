import operator
import timeit

class Song:
	def __init__(self, idnr, artist, title, length, year):
		self.idnr = idnr
		self.artist = artist
		self.title = title
		self.length = length
		self.year = year

	def __lt__(self, other):
		return self.length < other.length

	def __gt__(self, other):
		return self.length > other.length

	def __ge__(self, other):
		return self.length >= other.length

	def __le__(self, other):
		return self.length <= other.length

	def __eq__(self, other):
		return self.length == other.length


def trackslist(): # läser in låtar och returnerar en lista med alla låtar som objekt
	tracks = []
	with open('sang-artist-data.txt', 'r') as file: # läser filen 'sang-artist-data.txt' på formatet IDNR	ARTIST	LÅT	LÄNGD	ÅR
		for line in file: 
			line = line.strip()
			line = line.split('\t')
			s = Song(line[0], line[1], line[2], line[3], line[4]) # skapar objekt med alla attribut
			tracks.append(s) # lägger till objekten i listan
	return tracks

def n_longest(trackslist, n): # hittar den n:e längsta låten
	m = 0
	found = {}

	while m != n:
		m += 1
		longest_track = trackslist[0]
		for track in trackslist:
			if longest_track < track and track.length not in found: # om längsta låten < track och längden av track inte finns i found
				longest_track = track # track är den nya längsta låten

		found[longest_track.length] = None # lägger till längden som key i dict

	return longest_track

def sort_longest(trackslist, n): # sorterar listan med avseende på längden
	sortedlist = sorted(trackslist, key=operator.attrgetter('length'))
	N = len(sortedlist)
	longest_track = sortedlist[N-n]
	return longest_track


def main(): # tar tid på varje operation med timeit
	lista = trackslist()
	n = 2
	tid = timeit.timeit(stmt = lambda: n_longest(lista, n), number = 10)
	sorttid = timeit.timeit(stmt = lambda: sort_longest(lista, n), number = 10)
	print("Osorterad tog", round(tid, 4) , "sekunder")
	print("Sorterad tog", round(sorttid, 4) , "sekunder")

if __name__ == '__main__':
	main()
