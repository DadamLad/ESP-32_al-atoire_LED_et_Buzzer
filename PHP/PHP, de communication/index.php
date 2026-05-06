<?php
$valeur = "Aucune donnée";

if (file_exists("valeur.txt")) {
$valeur = file_get_contents("valeur.txt");
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8">
<meta http-equiv="refresh" content="2">
<title>Donnée ESP32</title>
<style>
body {
font-family: Arial, sans-serif;
text-align: center;
margin-top: 50px;
}
.box {
display: inline-block;
padding: 20px 40px;
border: 2px solid #333;
border-radius: 12px;
font-size: 28px;
background-color: #f2f2f2;
}
</style>
</head>
<body>
<h1>Valeur reçue depuis l'ESP32</h1>
<div class="box"><?php echo htmlspecialchars($valeur); ?></div>

<h2>Commande ESP32</h2>

<h3>Commande LED</h3>
   <button onclick="fetch('http://ADRESSE_IP_ESP_32/led')">
   Allumer
   </button>
   
   
<h3>Commande son</h3>

   <button onclick="fetch('http://ADRESSE_IP_ESP_32/son')">
   Allumer
   </button>

</body>
</html>
