#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX 

// Define os pinos que serao utilizados
int pedVerde = 6;  
int pedVermelho = 7;
int carroVerde = 4;
int carroAmarelo = 3;
int carroVermelho = 2;

int buzzer = 8;

// delay padrao para carros e pedestres
double delayVerdeCarros = 10000;
double delayVerdePedestres = 5000;
int delayAmareloCarros = 3000;
int delayAmareloPedestres = 5000;

int delayAntesBotao;

// strings para tratar os dados vindo do servidor NodeJS
String dadosServidorNode, part1, part2;

void setup() // Define os pinos como saidas
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);

  pinMode(buzzer, OUTPUT); // aviso sonoro
 
  digitalWrite(carroVerde, HIGH); // Coloca na posição inicial. Somente o verde dos carros e o vermelho dos pedestres acesos
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroVerde, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
}

void loop()
{ 
  delayAntesBotao = delayVerdeCarros / 2;
  digitalWrite(carroVerde, HIGH); // Acende o verde dos carros e o vermelho dos pedestres
  digitalWrite(pedVermelho, HIGH);   
  
  delay(delayAntesBotao);

  if (bluetooth.available() > 0){
    char bluebyte = bluetooth.read();
    if (bluebyte == 'B') { // se o botao for apertado antes de ter passado metade do tempo verde para carros, altera o estado para priorizar o verde de pedestre.
      Serial.println("Bluetooth ativado!");
      Serial.println("Espera somente metade do tempo dos carros.");
      digitalWrite(carroVerde, LOW);
      digitalWrite(carroAmarelo, HIGH); // apaga o verde dos carros e acende o amarelo
      delay(delayAmareloCarros); // aguarda mais 3 segundos
      
      digitalWrite(carroAmarelo, LOW); // apaga o amarelo dos carros e acende o vermelho
      digitalWrite(carroVermelho, HIGH);
      delay(1000); 
      digitalWrite(pedVermelho, LOW); // apaga o vermelho dos pedestres e acende o verde
      digitalWrite(pedVerde, HIGH);
    
      int tempoPedestreLoop = delayVerdePedestres / 1000;
      for (int y = 0; y < tempoPedestreLoop; y++) {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(500);
      }
      
      // delay(delayVerdePedestres);  // aguarda mais 5 segundos
      
      digitalWrite(pedVerde, LOW);
      
      int delayDentroLoop = delayAmareloPedestres / 1000;
      digitalWrite(buzzer, HIGH); // buzz fica ligado para indicar que o amarelo de pedestre esta ativado
      for(int x = 0; x<5; x++) { // Pisca o vermelho dos pedestres
        digitalWrite(pedVermelho, HIGH);
        delay(500);
        digitalWrite(pedVermelho, LOW);
        delay(500);
      }
      digitalWrite(buzzer, LOW); // apos fechar o sinal pedestre, desliga o buzz
      digitalWrite(pedVermelho, HIGH);
      
      delay(1000);
      digitalWrite(carroVermelho, LOW); 
      digitalWrite(carroVerde, HIGH);
      return; // ao fim, volta ao loop inicial.
    }
  }

  delay(delayAntesBotao);
  
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH); // apaga o verde dos carros e acende o amarelo
  delay(delayAmareloCarros); // aguarda mais 3 segundos
  
  digitalWrite(carroAmarelo, LOW); // apaga o amarelo dos carros e acende o vermelho
  digitalWrite(carroVermelho, HIGH);
  delay(1000); 
  digitalWrite(pedVermelho, LOW); // apaga o vermelho dos pedestres e acende o verde
  digitalWrite(pedVerde, HIGH);

  int tempoPedestreLoop = delayVerdePedestres / 1000;
  for (int y = 0; y < tempoPedestreLoop; y++) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  
  // delay(delayVerdePedestres);  // aguarda mais 5 segundos
  
  digitalWrite(pedVerde, LOW);
  
  int delayDentroLoop = delayAmareloPedestres / 1000;
  digitalWrite(buzzer, HIGH); // buzz fica ligado para indicar que o amarelo de pedestre esta ativado
  for(int x = 0; x<5; x++) { // Pisca o vermelho dos pedestres
    digitalWrite(pedVermelho, HIGH);
    delay(500);
    digitalWrite(pedVermelho, LOW);
    delay(500);
  }
  digitalWrite(buzzer, LOW); // apos fechar o sinal pedestre, desliga o buzz
  digitalWrite(pedVermelho, HIGH);
  
  delay(1000);
  digitalWrite(carroVermelho, LOW); 
  digitalWrite(carroVerde, HIGH);
 // quando o arduino receber uma nova rotina vinda do servidor NodeJS
  if (Serial.available() > 0) {
    while(Serial.available() > 0) {
      dadosServidorNode = Serial.readString();  
    }
    part1 = dadosServidorNode.substring(0, dadosServidorNode.indexOf("|"));
    part2 = dadosServidorNode.substring(dadosServidorNode.indexOf("|") + 1);
  
    delayVerdeCarros = part1.toDouble() * 1000;
    delayVerdePedestres = part2.toDouble() * 1000;
    Serial.println("Novos dados do servidor: " + String(dadosServidorNode) + "\nAplicando nova rotina!");
    Serial.println("Novo tempo para carros: " + String(delayVerdeCarros));
    Serial.println("Novo tempo para pedestres: " + String(delayVerdePedestres));
  }
}
