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
		if (lst[i] == var and i + 1 < taille and lst[i + 1] == '^'):
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
		elif (lst[i] == var):
			lst[i] = 'X'
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

def concat_vars(lst):
	i = 0
	taille = len(lst)
	while i < taille:
		if (lst[i] == '*' and i >= 1 and i + 1 < taille):
			if (lst[i - 1] == 1 or lst[i - 1] == "X" or lst[i - 1] == "Y"):
				lst[i - 1], lst[i + 1] = lst[i + 1], lst[i - 1]
			if (lst[i + 1] == 1):
				lst.pop(i)
				lst.pop(i)
				taille -= 2
			elif (lst[i + 1] == 'X' or lst[i + 1] == 'Y'):
				lst.pop(i)
				taille -= 1
			else:
				sec = lst.pop(i + 1)
				lst.pop(i)
				lst[i - 1] *= sec
				taille -= 2
		i += 1
	return (lst)

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

def passe_signe(lst):
	i = 0
	taille = len(lst)
	while i < taille:
		if (lst[i] == '-'):
			lst[i + 1] *= -1
		if (lst[i] == '-' or lst[i] == '+') :
			lst.pop(i)
			taille -= 1
		i += 1
	return (lst)

def reduire_polynome(left, right):
	i = 0
	sub = [0] * 3
	taille1 = len(left)
	taille2 = len(right)
	while (i < taille1):
		if (type(left[i]) is int and (i == taille1 - 1 or (type(left[i + 1]) is int))):
			sub[0] += left[i]
		if (type(left[i]) is int and i + 1 < taille1 and left[i + 1] == 'X'):
			sub[1] += left[i]
		if (type(left[i]) is int and i + 1 < taille1 and left[i + 1] == 'Y'):
			sub[2] += left[i]
		i += 1
	i = 0
	while (i < taille2):
		if (type(right[i]) is int and (i == taille2 - 1 or (type(right[i + 1]) is int))):
			sub[0] -= right[i]
		if (type(right[i]) is int and i + 1 < taille2 and right[i + 1] == 'X'):
			sub[1] -= right[i]
		if (type(right[i]) is int and i + 1 < taille2 and right[i + 1] == 'Y'):
			sub[2] -= right[i]
		i += 1
	return ([sub[2], "Y", sub[1], "X", sub[0]])

def print_reduit(reduced):
	print("Reduced form :", str(reduced[0]) if reduced[0] >= 0 else ("-" + str(-reduced[0]))
	, "* " + var + "^2", ("+ " + str(reduced[2])) if reduced[2] >= 0 else ("- " + str(-reduced[2])), "* " + var + "^1",
	("+ " + str(reduced[4])) if reduced[4] >= 0 else ("- " + str(-reduced[4])), "* " + var + "^0 = 0")

def calcul_delta(polynome):
	return (polynome[2] ** 2 - 4 * polynome[0] * polynome[4])

def trouve_solutions(polynome):
	delta = calcul_delta(polynome)
	if (delta > 0):
		solution1 = (-polynome[2] + floor(sqrt(delta, 6))) / (2*polynome[0])
		solution2 = (-polynome[2] - floor(sqrt(delta, 6))) / (2*polynome[0])
		complexe = False
	elif (delta < 0):
		solution1 = (-polynome[2] + floor(sqrt(delta, 6))) / (2*polynome[0])
		solution2 = (-polynome[2] - floor(sqrt(delta, 6))) / (2*polynome[0])
		complexe = True
	else:
		solution1 = -polynome[2] / (2*polynome[0])
		solution2None
		complexe = False

def sqrt(nombre, precision):
	a = nombre
	b = 1
	precision = 10 ** -precision
	while (a - b > precision):
		a = (a + b) / 2
		b = nombre / a
		print ("a = ", a, " b = ", b)
	return (a)

def pgcd(nb1, nb2):
	a = nb1
	b = nb2
	r = nb2
	while b != 0:
		r = a%b
		a = b
		b = r
	return (a)

def floor(nb):
	result = 0
	print(nb)
	while (nb > 1.0 or nb < -1.0):
		result += 1
		nb += -1.0 if nb > 0 else 1.0
	return (int(result))

def frac(nb):
	power = 1
	while (int(nb) - floor(nb) != 0):
		power *= 10
		nb *= 10
	return (nb / pgcd(power, nb), power / pgcd(power, nb))

polynome = input("Entrez votre polynome : ")
lst, var = polynome_valide(polynome)
print(lst)
concat_nombres(lst)
print(lst, "\n", transforme_variables(lst, var))
print(concat_vars(lst))
print(passe_signe(lst))
lst1, lst2 = split_equal(lst)
reduced = reduire_polynome(lst1, lst2)
print_reduit(reduced)
print(reduced)
print(calcul_delta(reduced))
print(trouve_solutions(reduced))
print(frac(8.25), frac(1.233333), frac(4.55795))