import serial

serial1 = serial.Serial()
serial1.baudrate = 115200
serial1.port = '/dev/cu.usbmodemL41008G71'
serial1.open()

serial2 = serial.Serial()
serial2.baudrate = 115200
serial2.port = '/dev/cu.usbmodemL41009D81'
serial2.open()

while 1:
    character = serial1.readline()
    print(character.decode('utf-8'))
    serial2.write(character)
