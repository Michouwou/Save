# J'ai decide de ne pas mettre de boucle de verification de la validite des 
# donnees entrees, le but du programme etant de repondre si la date saisie est
# valide ou non, je trouvais cela un peu contradictoire
#
# Ce programme inclut evidemment les exercices 7.3 et 7.4

jj = int(input("Entrez le numero du jour : "))
mm = int(input("Entrez le numero du mois : "))
aaaa = int(input("Entrez l'annee : "))

if (jj > 0 and mm > 0 and jj < 32 and mm < 13):

	# Si le mois est impair et inferieur a 8 :
	# ---> janvier, mars, mai, juillet
	# Ou pair superieur a 7 :
	# ---> aout, octobre, decembre

	if (((mm % 2 == 1) and (mm < 8)) or ((mm % 2 == 0) and (mm > 7))):
		print("Cette date est valide.")

	# Ce n'etait pas beaucoup plus rapide de suivre la meme
	# logique qu'au dessus

	elif (((mm == 4) or (mm == 6) or (mm == 9) or (mm == 11)) and (jj < 31)):
		print("Cette date est valide.")

	# Si c'est le mois de fevrier, on a deux cas :
	#	cas 1 : Le jour est moins de 29 (tout va bien)
	#	cas 2 : Le jour est 29, auquel cas il faut que l'annee soit bissextile

	elif ((mm == 2) and ((jj < 29) or ((jj == 29) and ((aaaa % 4 == 0) and (aaaa % 100 != 0)) or (aaaa % 400 == 0)))):
		print("Cette date est valide.")
	else:
		print("Cette date est invalide.")
else:
	print("Cette date est invalide.")
