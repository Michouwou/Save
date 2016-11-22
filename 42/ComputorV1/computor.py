import sys

def concat_nombres(lst):
	taille = len(lst)
	i = 0
	while i < taille:
		while (i + 1 < taille and lst[i] >= '0' and lst[i] <= '9' and lst[i + 1] >= '0' and lst[i + 1] <= '9'):
			print(lst[i])
			lst[i] += lst.pop(i + 1)
			taille -= 1
			i += 1
		i += 1
	i = 0
	while i < taille:
		if (lst[i][0] >= '0' and lst[i][0] <= '9'):
			lst[i] = int(lst[i])
		i += 1
	return lst

def transforme_variables(lst, var):
	i = 0
	taille = len(lst)
	while i < taille:
		if (lst[i] == var and lst[i + 1] == '^'):
			if (lst[i + 2] == 0):
				lst[i] = 1
			elif(lst[i + 2] == 1):
				lst[i] = 'X'
			elif(lst[i + 2] == 2):
				lst[i] = 'Y'
			else:
				erreur_syntaxe("Le degre de votre variable est negatif ou superieur a 2 : '" + str(lst[i]) + str(lst[i + 1]) + str(lst[i + 2]) + "'")
			taille -= 2
			lst.pop(i + 1)
			lst.pop(i + 1)
		i += 1
	return (lst)

def split_equal(lst):
	left_side = []
	right_side = []
	equal = False
	for e in lst:
		if (e == '='):
			equal = True
		elif (equal):
			right_side.append(e)
		else:
			left_side.append(e)
	return (left_side, right_side)

def erreur_syntaxe(chaine):
	print("Erreur de syntax :::")
	print("\t" + chaine)
	sys.exit(0)

def polynome_valide(chaine):
	lst = []
	var = 0
	for e in chaine:
		if (e == '+' or e == '-' or
			e == '*' or e == '^' or
			e == '=' or (e >= '0' and
			e <= '9') or e == var):
			lst.append(e)
		elif (var == 0):
			var = e
			lst.append(e)
		elif (e == ' ' or e == '\t'):
			pass
		else:
			erreur_syntaxe("Plus d'une variable déclarée : '" + e + "' et '" + var + "'")
	if (var == 0):
		erreur_syntaxe("Votre expression ne contient pas de variable")
	return (lst, var)

polynome = input("Entrez votre polynome : ")
lst, var = polynome_valide(polynome)
print(lst)
concat_nombres(lst)
print(lst, "\n", transforme_variables(lst, var))
print(split_equal(lst))