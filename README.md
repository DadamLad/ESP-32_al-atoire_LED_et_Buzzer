# ESP-32_al-atoire_LED_et_Buzzer
Interface Web PHP pour le contrôle et l'archivage de données (CSV/TXT) provenant d'un ESP32.

# 1. 📋 Explication
L’ESP 32 génère des chiffres aléatoires (0 et 100) et les envoient sur la page PHP qui les affiche sur l’interface. A partir l’interface de la page PHP, l’utilisateur peut interagir avec des buttons : l’un allume la LED et l’autre activer le Buzzer.

## 2. 🛠️ Installation
### Matériel : 
* ESP32 DevKit V1 
* LED 
* Buzzer Arduino
### Modification
Dans GitHub aller dans le dossier code C/C++, télécharger le fichier « ESP 32, de communication ». Ensuite dans le dossier code PHP, télécharger le fichier « PHP, de communication ».
Pour le circuit électrique de la LED et du Buzzer il faut : relier le Buzzer avec soit le VCC ou le 3V3 de l’ESP 32, relier ensuite à l’entrée digitale et sur le GND de l’ESP 32. Pour la LED il faut relier l’entrée digitale et le GND seulement de l’ESP 32.

## 3. 📁 Configuration
Avant de lancer le projet, il faut configurer les dossiers : modifiez le fichier Communication_serv_ESP32.ino : à la ligne 6 là où il est écrit « ADRESSE IP SERVER/CHEMIN D'ACCES --> data.php » mettre l’adresse IP du serveur qui contient le fichier data.php et son chemin d’accès. De plus le code Arduino permet de connaitre l’adresse IP de l’ESP-32 en ouvrant le moniteur série à 115200 bauds quand le code sera téléverser.
Ensuite modifiez le fichier index.php : à la ligne 38 et 45 là où il est écrit « ADRESSE_IP_ESP_32 » mettre l’adresse IP de l’ESP-32. Modifier « int sortieled = 25 ; » et « int buzzer = 26 ; » en fonction des entrer digitale choisie en modifient le 25 et le 26.

##4. 🚀 Fonctionnement 
Le code est tableau de bord qui fait deux choses : Le fichier data.php regarde toutes les 2 secondes dans le fichier valeur.txt pour afficher la dernière info reçue, tandis que les boutons « Allumer » utilisent des liens qui permet à la page web de demander ou d'envoyer des données au serveur sans avoir besoin de recharger toute la page à l'adresse IP de votre ESP32 afin d'allumer la lumière ou le son sans changer de page. Le code data.php est le réceptionnaire. Il sert à intercepter les données envoyées par l'ESP32 via une requête POST, à les dater précisément selon l'heure, puis à les enregistrer de deux manières différentes. Il alimente le fichier valeur.txt pour mettre à jour l'affichage en temps réel sur ta page web et archive simultanément chaque relevé dans un fichier valeur.csv pour te permettre de consulter l'historique complet de tes données plus tard.
