const int LEDPINR = 3;                                 //led rosso del RGB
const int LEDPING = 2;                                 //led verde del RGB
const int LDR_PIN= A0;                                 //fotoresistenza

int ldrValue;                                          //variabile per gestire il valore che acquisisce del sensore di luce
int flag = 1;                                          //flag per la gestione del stato del parcheggio
int fstart = 0;                                        //flag per gestire il posto occupato nel primo ciclo


void setup() 
{
  Serial.begin(9600);                                  //inizializzazione della seriale
  pinMode(LEDPINR,OUTPUT);                             //iniziallizzazione ledPin rosso
  pinMode(LEDPING,OUTPUT);                             //iniziallizzazione ledPin verde  
}

void loop() 
{
  
  delay(2000);                                          //frequenza con cui si controlla lo stato del parcheggio
  ldrValue = analogRead(LDR_PIN);                      //lettura del valore del sensore

  if (fstart == 0 && ldrValue < 200)                   //controllo sul sensore e sul flag
  {
    digitalWrite(LEDPINR, HIGH);                       //accende il led rosso
    Serial.println("Il posto e' occupato");            //messaggio che viene al server python    
    fstart = 1;                                        //grazie a questo flag non si entra più in questo if
    flag = 1;                                          //flag che indica lo stato del parcheggio, cioè occupato
    
                                                       //non serve mettere digitalWrite(LEDPING, LOW); 
                                                       //dato che queste istruzioni vengono esguite solo alla prima volta 
                                                       //col led spento e solo nel caso in cui il posto è occupato                                                     
  }
  
  else if(ldrValue < 200 && flag == 0)                 //controllo sul sensore e sul flag
  {
   digitalWrite(LEDPINR, HIGH);                        //accende il led rosso
   digitalWrite(LEDPING, LOW);                         //spegne il led verde
   Serial.println("Il posto e' occupato");             //messaggio che viene al server python   
   flag = 1;                                           //flag che indica lo stato del parcheggio, cioè occupato
  }
  
  else if (ldrValue > 200 && flag == 1)                //controllo sul sensore e sul flag
  {
    digitalWrite(LEDPING, HIGH);                       //accende il led verde
    digitalWrite(LEDPINR, LOW);                        //spegne il led rosso
    Serial.println("Il e' posto libero");              //messaggio che viene al server python  
    flag = 0;                                          //flag che indica lo stato del parcheggio, cioè libero
  }  
  
}
