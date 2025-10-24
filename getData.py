#script python
import serial
import time
import os

arduino_port = "COM6"  # Cambia esto al puerto correcto donde está conectado tu Arduino
baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2) 
while True:
    data=ser.readline().decode('utf-8').rstrip()
    if data:
        humidity, temperature = data.split(',')
        print(f"Humidity: {humidity}%, Temperature: {temperature}°C")
    time.sleep(1)
    #rstrip: elimina espacios en blanco al final de la cadena
    #Timeout: tiempo de espera para la comunicacion serial
    