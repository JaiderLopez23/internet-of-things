
import serial
import time

from supabase import create_client, Client
from getPort import port

url = "https://ybfwezxaqhtrsbkawkte.supabase.co"
key = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InliZndlenhhcWh0cnNia2F3a3RlIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NjA2MzU2MDYsImV4cCI6MjA3NjIxMTYwNn0.MFcyyVF-Csozrgfx1B-a07x2y6E_m30UX4Ma-Gy94MU"   
supabase: Client = create_client(url, key)

esp_port = port
baud_rate = 9600

serial_port = serial.Serial(esp_port, baud_rate, timeout=1)
time.sleep(2)  # Espera a que el ESP esté listo


while True:
    raw = serial_port.readline()
    data = raw.decode('utf-8', errors='ignore').strip()
    if data:
        try:
            humidity, temperature = data.split(",")
            humidity = float(humidity)
            temperature = float(temperature)

            # --- ENVÍO A SUPABASE ---
            response = supabase.table("data").insert({
                "humidity": humidity,
                "temperature": temperature
            }).execute()

            print("✅ Datos enviados:", humidity, temperature)
        except ValueError:
            print("⚠️ Formato de datos inválido:", data)
        except Exception as e:
            print("❌ Error al enviar a Supabase:", e)
    time.sleep(1)

