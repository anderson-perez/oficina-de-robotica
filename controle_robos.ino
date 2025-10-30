/*
Projeto Oficina de Robótica
Universidade Federal de Santa Catarina (UFSC)

Programa que modela uma classe para o controle dos robôs utilizados nas aulas.
*/

/* Definir as portas onde serão ligados o controle dos motores 
e a leitura do sensor de ultrasom
*/
#define PORT_M1_1       3
#define PORT_M1_2       5  
#define PORT_M2_1       6
#define PORT_M2_2       9
#define PORT_TRIGGER    7
#define PORT_ECHO       8


class Robo {
  
  private:
    unsigned int port_m1_1;       // Motor da esquerda (frente)
    unsigned int port_m1_2;       // Motor da esquerda (tras)
    unsigned int port_m2_1;       // Motor da direita (frente)
    unsigned int port_m2_2;       // Motor da direita (tras)
   
    unsigned int port_trigger;
    unsigned int port_echo;

  public:
    void setup(unsigned int portM11, 
           unsigned int portM12, 
           unsigned int portM21,
           unsigned int portM22,
           unsigned int portTRIGGER,
           unsigned int portECHO);

    float distancia();
    void ir_para_frente(unsigned int velocidade);
    void ir_para_tras(unsigned int velocidade);
    void virar_a_direita(unsigned int velocidade);
    void virar_a_esquerda(unsigned int velocidade);
    void parar_motores();

};

void Robo::setup(unsigned int portM11, 
           unsigned int portM12, 
           unsigned int portM21,
           unsigned int portM22,
           unsigned int portTRIGGER,
           unsigned int portECHO
           )
{
  /* Define atributos da classe*/
  port_m1_1     = portM11;
  port_m1_2     = portM12;
  port_m2_1     = portM21;
  port_m2_2     = portM22;
  port_trigger  = portTRIGGER;
  port_echo     = portECHO;
  

  /* Configura motores*/
  pinMode(port_m1_1, OUTPUT);
  pinMode(port_m1_2, OUTPUT);
  pinMode(port_m2_1, OUTPUT);
  pinMode(port_m2_2, OUTPUT);

  /* Configura sensor de ultrasom*/
  pinMode(port_trigger, OUTPUT);
  pinMode(port_echo, INPUT);
}

float Robo::distancia()
{
  float tempo;

  digitalWrite(port_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(port_trigger, LOW);
  tempo = pulseIn(port_echo, HIGH);

  return tempo / 58.3;
}

void Robo::ir_para_frente(unsigned int velocidade)
{
  analogWrite(port_m1_1, velocidade);
  analogWrite(port_m2_1, velocidade);
}

void Robo::ir_para_tras(unsigned int velocidade)
{
  analogWrite(port_m1_2, velocidade);
  analogWrite(port_m2_2, velocidade);
}

void Robo::virar_a_direita(unsigned int velocidade)
{
  analogWrite(port_m1_2, velocidade);
  digitalWrite(port_m1_1, HIGH);
}

void Robo::virar_a_esquerda(unsigned int velocidade)
{
  parar_motores();
  
  analogWrite(port_m1_1, velocidade);
  digitalWrite(port_m2_1, HIGH);
}

void Robo::parar_motores()
{
  analogWrite(port_m1_1, 0);
  analogWrite(port_m1_2, 0);  
}

/*
Instância da classe Robo.
*/
Robo robo;

void setup() 
{  
  robo.setup(PORT_M1_1, PORT_M1_2, PORT_M2_1, PORT_M2_2, PORT_TRIGGER, PORT_ECHO);

}

void loop() 
{

  
}