import serial
from time import sleep
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume

ser = serial.Serial('COM5', 9600) # Choose COM port here.
sleep(2)  

devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, 0, None)
volume = interface.QueryInterface(IAudioEndpointVolume)

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()
        
        print(data)
        
        if "Potenciometar:" in data:
            pot_value = int(data.split(":")[1].split()[0])
            volume_level = pot_value / 1023.0
            volume.SetMasterVolumeLevelScalar(volume_level, None)
        
        if "Muted: " in data:
            muted_state = data.split("Muted: ")[1] == '1'
            
            if muted_state:
                volume.SetMute(True, None)
            elif not muted_state:
                volume.SetMute(False, None)
    sleep(0.1)
