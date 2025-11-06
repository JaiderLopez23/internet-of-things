import serial.tools.list_ports

def detectBoardPorts():
    ports = serial.tools.list_ports.comports()

    for port in ports:
        if "USB-SERIAL CH340" in port.description or "CP210x" in port.description:
            # print(f"board port: {port.description}")
            # print(f"board device: {port.device}")
            # print(f"Port name: {port.name}")
            # print(f"HWID: {port.hwid}")
            # print(f"vendor ID: {port.vid}")
            # print(f"Location: {port.location}")
            # print(f"Manufacturer: {port.manufacturer}")
            return port.device
    return None

port = detectBoardPorts()

if port:
    print(f"Detected board on port: {port}")
else:
    print("No compatible board detected.")
