const int Trig = 8; //Déclaration d’une constante Trig
const int Echo = 9; //Déclaration d’une constante Echo
const int VITESSE = 340 ; //Déclaration d’une constante VITESSE = 340 m/s
 
void setup() {
  pinMode(Trig, OUTPUT); //Affectation de la broche Trig comme sortie
  pinMode(Echo, INPUT); //Affectation de la broche Echo comme entrée
  digitalWrite(Trig, LOW); //Mise au niveau bas sur la broche Trig
  Serial.begin(9600); //Initialisation de la communication série avec le PC
}
void loop()
{
  digitalWrite(Trig, HIGH); //Mise au niveau haut sur la broche Trig
  delayMicroseconds(10); //Pause de 10 µs
  digitalWrite(Trig, LOW); //Mise au niveau bas sur la broche Trig
  unsigned long duree = pulseIn(Echo, HIGH); //Lecture de la durée de l’état haut sur Echo
  if(duree > 30000)
  {
    Serial.println("Onde perdue, mesure échouée !");
  } //Si duree est supérieure à 30ms, l’onde est considérée comme perdue
  else
  {
    duree = duree/2; //Division de la durée par deux
    float temps = duree/1000000.0; //Conversion en seconde
    float distance = (temps*VITESSE)*100; //Calcul de la distance
    Serial.print("Durée [µs] = "); //Ecriture de "Durée = "
    Serial.println(duree); //Affichage du temps de vol d'un trajet en secondes
    Serial.print("Distance [cm] = "); //Ecriture de "Distance = "
    Serial.println(distance); //Affichage de la distance mesurée en mètres

   
    float celerite = (distance/temps)*0.01;
    
    Serial.print("celerité de l'onde [m/s]");
    Serial.println(celerite);
    
  }
  delay(1000); //Pause de 1000ms

}
