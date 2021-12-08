# TUTO démarrage STM32CubeIDE

Démarrage STM32CubeIDE: version 1.7.0

* ouvrir un projet déja existant:
	- file
	- open project from file system	
	- dans "import source" cliquer sur directory et choisir le dossier portant le nom du projet à ouvrir
	- cliquer sur sélectionner dossier 


* créer un nouveau:
	- file 
	- new
	- STM32 project cela vaouvrir une fenetre de dialogue afin de choisir le MCU ou la board utilisée  
	- cliquer sur board selector
	- dans Commercial Part number : écrire le nom de la board (ici STM32F429I-DISC1)
	- cliquer sur la board afin de l'avoir surlignée 
	- cliquer sur next
	- une boite de dialogue apparait:
		- mettre le nom du projet 
		- choisir où stocker le projet
		- quel langage utilisé (ici #C)
		- choisir binary type : Executable
		- choisir project type : STM32Cube
	- cliquer sur finish
	- Une boite de dialogue s'ouvre : les deux réponses sont possibles 


* procédure conseillée:
	- supprimer toutes les entrées sorties sélectionnés lors de la création du projet:
		- cliquer sur Pinout  --> clear Pinouts
	- ou 
		- ctrl + P 


* démarrage du projet:
   
Maintenant il faut regarder dans la datasheet de la board quelles pins sont utilisées pour quelles fonctions.
Datasheet:   https://www.st.com/resource/en/user_manual/um1670-discovery-kit-with-stm32f429zi-mcu-stmicroelectronics.pdf

* En fonction du projet voulu selectionner les pins :
	- rechercher dans la barre en bas à droite (clignotement de la pin choisit)
	- clique gauche pour déterminer la fonction de la pin
	-  clique droit pour la renommer



Utilisation STM32CubeMX:


* Lancer le projet:
	- Une fois le code écrit il est nécessaire de le BUILD
		- Clique droit sur le projet en cours dans la fenetre project explorer
		- Build project
		Cette action permet de vérifier toutes erreurs potentielles du code.
	- Ensuite il faut le RUN ou le DEBUG
		- Clique droit sur le projet en cours 
		- Run as / Debug as
		- STM32 cortex-M C/C++ application

Le run implémente le code sur la ship alors que le debug implémente et permet d'acceder aux variables créées dans le code afin de vérifier si tout se passe comme prévu.


