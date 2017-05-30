PIATTAFORMA HARDWARE E COMUNICAZIONE CON IL SERVER
==================================================

La nostra idea è quella di costruire una piattaforma hardware che simuli 
il parcheggio utilizzando una breadboard, diodi led RGB, cavi elettrici, 
sensori di luce LM35, un dispositivo Arduino e infine un cavo seriale.

La breadboard la utilizziamo come base per il parcheggio dove sopra 
posizioneremo un led RGB per sensore, che si illuminerà di rosso o verde
i quali rispettivamente indicano se il posto è occupato o libero. 

L'Arduino ha il compito di controllare lo stato dei sensori di luce e in 
base a quest'ultimi accendere l'apposito diodo led RGB con il colore
appropriato e inviare tramite cavo seriale i dati da visualizzare nel 
server. 

Nella realizzazione di questo progetto riscontreremo probabilmente dei 
problemi che riguarderanno:

-	come stabilire la connessione tra l'Arduino e il server

-	decidere se l'aggiornamento dei dati avviene tramite richiesta 
	del server ogni N minuti (secondi nel caso della nostra simulazione) 
	oppure Arduino invia i dati ogni volta che lo stato del parcheggio 
	cambia.

Abbiamo scelto la seconda opzione dato che è la più verosimile come
situazione, dato che appena una macchina arriva o se ne va lo stato del 
parcheggio, nel nostro caso dell'Arduino, cambia ed è piu sentato 
rispetto all'altra opzione.

Per quanto riguarda la parte software pensavamo di scrivere il programma
da inserire nell'Arduino in linguaggio C++.

Matteo Giangrasso e Christian Stefani, 4AIN.
 
 

