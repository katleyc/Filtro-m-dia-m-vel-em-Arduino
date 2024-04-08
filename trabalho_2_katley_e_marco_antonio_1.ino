const int sensorPin = A0; // Pino do sensor analógico
const int numReadings = 10; // Número de leituras para a média móvel

int readings[numReadings]; // Array para armazenar as leituras
int index = 0; // Índice atual do array

void setup() {
  pinMode(sensorPin, INPUT); // Define o pino do sensor como entrada
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  // Lê o valor do sensor analógico
  int sensorValue = analogRead(sensorPin);
  
  // Armazena o novo valor no array
  readings[index] = sensorValue;
  
  // Atualiza o índice, voltando para zero quando necessário
  index = (index + 1) % numReadings;
  
  // Calcula a média móvel
  float total = 0;
  for (int i = 0; i < numReadings; i++) {
    total += readings[i];
  }
  float average = total / numReadings;
  
  // Envia os valores para o Serial Plotter
  Serial.print(sensorValue);
  Serial.print(',');
  Serial.println(average);
  
  delay(300); // Ajusta o tempo de delay conforme necessário
}
