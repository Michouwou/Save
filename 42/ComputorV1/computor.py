def operateur(chaine):
	resultat = []
	for e in chaine:
		if (e == '=' or e == '+' or
				e == '-' or e == '*' or
				e == '^'):
			resultat.append(e)
	return (resultat)

def nombres(chaine):
	i = 0
	length = len(chaine)
	resultat = []
	while (i < length):
		tmp_num = ""
		while (i < length and (chaine[i] == '0' or chaine[i] == '1' or
				chaine[i] == '2' or chaine[i] == '3' or
				chaine[i] == '4' or chaine[i] == '5' or
				chaine[i] == '6' or chaine[i] == '7' or
				chaine[i] == '8' or chaine[i] == '9')):
			tmp_num += str(chaine[i])
			i += 1
		if (len(tmp_num) != 0):
			resultat.append(int(tmp_num))
		i += 1
	return (resultat)

chaine = input("Enter your string");
print(operateur(chaine))
print(nombres(chaine))
