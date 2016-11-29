import sys

age = int(input("Entrez votre age : "))
if (age < 1):
    sys.exit("Vous ne pouvez pas avoir " + str(age) + " annees")

etud = ""
while (etud != "oui") and (etud != "non"):
    etud = input("Entrez 'oui' si vous etes etudiants, 'non' sinon: ")
if (etud == "oui") and (age < 26):
    print("Vous pouvez beneficier d'un tarif jeune etudiant")
else:
    print("Vous ne pouvez pas beneficier d'un tarif etudiant")
