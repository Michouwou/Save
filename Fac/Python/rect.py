from utils import *

x_sd = ""
y_sd = ""
x_ig = ""
y_ig = ""

while (RepresentsInt(x_sd) == False):
    x_sd = input("Entrez l'abscisse du coin superieur droit : ")
while (RepresentsInt(y_sd) == False):
    y_sd = input("Entrez l'ordonnee du coin superieur droit : ")
while (RepresentsInt(x_ig) == False):
    x_ig = input("Entrez l'abscisse du coin inferieur gauche : ")
while (RepresentsInt(y_ig) == False):
    y_ig = input("Entrez l'ordonnee du coin inferieur gauche : ")


x_sd = int(x_sd)
y_sd = int(y_sd)
x_ig = int(x_ig)
y_ig = int(y_ig)
y_sg = y_sd
x_sg = x_ig
y_id = y_sd
x_id = x_ig

if (x_sd > x_ig and y_sd > y_ig):
    print("Très beau rectangle")
else:
    print("Incohérent")

pt_x = "";
pt_y = "";

print("Entrez les coordonnees d'un point à tester")
while (RepresentsInt(pt_x) == False):
    pt_x = input("x : ")
while (RepresentsInt(pt_y) == False):
    pt_y = input("y : ")

pt_x = int(pt_x)
pt_y = int(pt_y)

if (pt_x > x_ig and pt_x < x_sd and pt_y > y_ig and pt_y < y_sd):
    print("Le point (", pt_x, ";", pt_y, ") est strictement inclus dans votre rectangle")
else:
    print("Le point (", pt_x, ";", pt_y, ") n'est pas inclus dans votre rectangle")

width = x_sd - x_ig
height = y_sd - y_ig
if (height == width):
    print("Vous avez saisi un carré")
elif (height > width):
    print("Votre rectangle est plus haut que long")
else:
    print("Votre rectangle est plus long que haut")
