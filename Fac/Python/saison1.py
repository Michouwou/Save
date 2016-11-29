p = "printemps"
e = "été"
a = "automne"
h = "hiver"
attempts = 0
saison = ""

# Je me suis permis de custom un peu et de donner 3 chances à
# l'utilisateur de rentrer une saison valide

while (attemps < 3 and saison != p and saison != e and saison != a and saison != h):
	saison = lower(input("Veuillez entrer une saison : "))
	attemps++
if (saison == p):
	print("Printemps : du 20 mars au 19 juin")
elif (saison == e):
	print("Été : du 20 juin au 21 septembre")
elif (saison == a):
	print("Automne : du 22 septembre au 20 décembre")
elif (saison == h):
	print("Hiver : du 21 décembre au 19 mars")
else:
	print("Vous avez entré trois fois un nom qui n'est pas une saison...")
