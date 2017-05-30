import serial                                               
import time

#impostazione della porta arduino
port = 'COM10'
#instanzia dela porta seriale
ard = serial.Serial(port,9600,timeout = 5)
#un piccolo di ritardo
time.sleep(2)
#flag per gestire la prima esecuzione
flag = 0
#ciclo infinito
while True:
    #un piccolo di ritardo
    time.sleep(1)
    #lettura del messaggio inviato da Arduino
    msg = ard.read(ard.inWaiting())
    #se il messaggio e' vuoto non fa niente
    if msg != "":
        #viene eseguito solo la prima volta e per una questione di estetica
        if flag == 0:
            print("-----------------------------------")
            #grazie a questo flag non si entra piu' in questo if
            flag = 1
        print("")
        #printa il messaggio ricevuto da Arduino
        print (msg)
        print("-----------------------------------")
