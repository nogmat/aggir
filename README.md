# AGGIR

Ce programme permet de calculer le groupe iso-ressource d'un individu selon l'algorithme de la grille AGGIR publié dans l'annexe II du Décret n°97-427 du 28 avril 1997 et développé par le Syndicat national de gérontologie clinique de France.

## Pour commencer...

Vous pourrez trouver dans ce fichier les instructions pour compiler et tester le programme sur votre machine locale.

### Pré-requis

La librairie Gtk pour C++ est nécessaire pour pouvoir compiler. 
Sous Ubuntu, il suffit d'installer le paquet suivant : 

```
apt install libgtkmm-3.0-dev
```

## Fonction du programme

Afin d'effectuer le calcul il est nécessaire de choisir une modalité pour chacune des variables discriminantes.

### Codage des items

* Modalité A : la personne fait seule et spontanément, habituellement, totalement et correctement
* Modalité B : la personne peut faire seule, mais ne le fait pas spontanément, ou/et correctement ou/et habituellement ou/et partiellement
* Modalité C : la personne ne fait pas, il faut faire à sa place ou faire faire par quelqu'un d'autre

### Variables discrimantes

* Cohérence : converser ou se comporter de façon logique et sensée 
* Orientation : se repérer dans le temps, les moments de la journée et les lieux 
* Toilette corporelle : comprend la toilette du haut (tête, tronc) et la toilette du bas 
* Habillage : comprend l'habillage du haut, l'habillage moyen, et l'habillage du bas 
* Alimentation : comprend le fait de servir et le fait de manger 
* Élimination : correspond à la capacité de la personne à gérer l'hygiène de l'élimination et non la continence (élimination urinaire et élimination fécale )
* Transferts : comprend le fait de se coucher, s'asseoir, se lever
* Déplacements à l'intérieur : évalue si des moyens techniques sont nécessaires à l'intérieur
* Déplacements à l'extérieur : évalue si des moyens techniques sont nécessaires à l'extérieur 
* Communication à distance : utilisation d'un téléphone, d'une télé-alarme

## Créé avec

* [Emacs](https://www.gnu.org/software/emacs/) - L'éditeur de texte le plus utilisé.
* [Magit](https://magit.vc/manual/magit/) - Utilisé pour synchroniser les dépôts.

## Auteur

* **Matthieu Nogatchewsky** - [Nogzer](https://github.com/nogzer)

## Licence

Ce travail est "open source".
