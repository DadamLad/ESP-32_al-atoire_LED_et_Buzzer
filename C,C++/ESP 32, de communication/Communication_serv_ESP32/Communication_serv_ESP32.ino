#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
const char* ssid = "TPSN035";    // à modifier
const char* password = "BTSSN2022"; // à modifier aussi
const char* serverName = "http://ADRESSE IP SERVER/CHEMIN D'ACCES --> data.php";
int myrandom = 0 ;

WebServer server(80);

int sortieled = 25;   // Sortie Digitale de la led
int buzzer = 26;      // Sortie Digitale du buzzer
int frequence = 2000;
void handleLED(); // Déclaration de la variable handleLED
void handleSON(); // Déclaration de la variable handleSON

void gestionLED() {
  Serial.println("reception info client led");
  digitalWrite(sortieled, HIGH);    // Allumé la LED 
  delay(3000);    // Attendre 3 seconde
  digitalWrite(sortieled, LOW);     // Eteindre la LED
  delay(3000);    // Attendre 3 seconde
  
  
  server.send(200, "text/plain", "LED test"); //Envoi une réponse du sérveur à l'arriver de la requête
}

void gestionSON() {
  Serial.println("reception info client son");
  ledcWriteTone(buzzer, 1000);
  delay(500);   // Attendre 0.5 seconde
  ledcWriteTone(buzzer, 500); 
  delay(500);   // Attendre 0.5 seconde
  ledcWriteTone(buzzer, 1000); 
  delay(500);   // Attendre 0.5 seconde
  ledcWriteTone(buzzer, 500); 
  delay(500);   // Attendre 0.5 seconde
  ledcWriteTone(buzzer, 0); 

  Serial.println("reception info client son");
  server.send(200, "text/plain", "Son test");
}

void setup() {

  Serial.begin(115200);
  pinMode(sortieled, OUTPUT);
  ledcAttach(buzzer, frequence,8);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);   // Attendre 0.5 seconde
    Serial.print(".");
  }

  Serial.println(WiFi.localIP()); //Affiche l'adresse IP de l'ESP32

  server.on("/led", gestionLED);  //
  server.on("/son", gestionSON);

  server.begin();
}

void loop() {
  server.handleClient();
  if (WiFi.status() == WL_CONNECTED) {  // Si c'est connecter alors:
    int valeur = random(0,100);         // Génération de valeur aléatoire de 0 à 100
    Serial.print("Valeur envoyer:");    // Afficher "Valeur envoyer:"
    Serial.print(valeur);               // Sa valeur
    HTTPClient http;
    http.begin(serverName);         
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String data = "valeur=" + String(valeur); //création de donnée à envoyer (POST)
    int httpReponse = http.POST(data);  //la requête de poste
    Serial.print("HTTP Reponse code: ");  //réponse de la requête 
    Serial.println(httpReponse);  //Affiche le code Réponse

    http.end(); //Ferme la connexion HTTP
  }

  delay(2000); // Attendre 2 seconde
}
