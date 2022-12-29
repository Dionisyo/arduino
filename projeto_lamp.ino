// Projeto simulando o funcionamento de uma lâmpada de emergência.



int digitalLed = 10;
int buttonCase = 7;
bool stateButton = false;
int sensorLDR = A0;
int readBotao = 0;
int valorLDR = 0;
//Setando as portas do LED, BOTÃO E SENSOR.

void setup() {
  // setando o funcionamento do Pino e a velocidade de conexão.
  pinMode(digitalLed,OUTPUT);
  pinMode(buttonCase,INPUT);
  pinMode(sensorLDR,INPUT);
  Serial.begin(9600);

}

void loop() {
  // Lendo as portas analógicas e digitais.
  valorLDR = analogRead(sensorLDR);
  readBotao = digitalRead(buttonCase);
 Serial.print("Valor Sensor: ");
    Serial.println(valorLDR);
  // Se o botão estiver em HIGH o código alterará o valor booleano para diferente do estado atual.
  if (readBotao == HIGH){
    stateButton = !stateButton;
  }
  // Se o estado for verdadeiro ligará a led e se o valor do Sensor for acima de 850 apagará.
  if (stateButton == true){
    digitalWrite(digitalLed,HIGH);
   
    if (valorLDR >850){
      digitalWrite(digitalLed,LOW);
    }
    // Se o estado for falso apagará a led.
  }else{
    digitalWrite(digitalLed,LOW);
  }



    }
 
  

