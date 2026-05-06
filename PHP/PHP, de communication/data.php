<?php
date_default_timezone_set("Pacific/Noumea");

if (isset($_POST['valeur'])) {
	$txtFile = __DIR__ . "/valeur.txt";
    $valeur = $_POST['valeur'];

    $date = date("Y-m-d");
    $heure = date("H:i:s");

    $fichier = fopen("valeur.csv", "a");
    fputcsv($fichier, [$date, $heure, $valeur]);
    fclose($fichier);
	file_put_contents($txtFile, $valeur);
    echo "OK";
}
?>
