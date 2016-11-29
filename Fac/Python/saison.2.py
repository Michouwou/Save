jj = int(input("Entrez le numero du jour : "))
mm = int(input("Entrez le numero du mois : "))

# Etant donne qu'il est ecrit dans le sujet que l'on suppose la date saisie
# comme existante, je n'ai fait aucun controle de securite

if ((jj >= 20 and mm == 3) or (mm == 4 or mm == 5) or (jj <= 19 and mm == 6)):
	print("Cette date tombera pendant le printemps!")
elif((jj >= 20 and mm == 6) or (mm == 7 or mm == 8) or (jj <= 21 and mm == 9)):
	print("Cette date tombera pendant l'ete!")
elif((jj >= 22 and mm == 9) or (mm == 10 or mm == 11) or (jj <= 20 and mm == 12)):
	print("Cette date tombera pendant l'automne!")
elif((jj >= 21 and mm == 12) or (mm == 1 or mm == 2) or (jj <= 19 and mm == 3)):
	print("Cette date tombera pendant l'hiver!")

# Ce 'else' n'est la que par 'proprete' etant donne que theoriquement la date est valide

else:
	print("Cette date n'est pas valide!")
