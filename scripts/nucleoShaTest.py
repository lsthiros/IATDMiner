
import serial, sys, time

midstate = 0x4a03aeb2bcf3ad77d705828c4ec62fa2282784a285936a72c71636a4ddef7254
target = 0x00000000000000000440C4000000000000000000000000000000000000000000
header_leftovers = 0x15274c646c51f957c4400418

ser = serial.Serial(sys.argv[1], baudrate=115200, timeout=.2)

ser.write("[writeSpi,0,0,0,0,0")
# print "[writeSpi"


i = 0
while i < 32:
    # print("," + "%x"%((midstate >> (8 * i) & 0xFF)))
    ser.write("," + "%u"%((midstate >> (8 * i) & 0xFF)))
    i += 1
    time.sleep(.001);

i = 0
while i < 12:
    # print("," + "%x"%((header_leftovers >> (8 * i) & 0xFF)))
    ser.write("," + "%u"%((header_leftovers >> (8 * i) & 0xFF)))
    i += 1
    time.sleep(.001);

i = 0
while i < 32:
    # print("," + "%x"%((target >> (8 * i) & 0xFF)))
    ser.write("," + "%u"%((target >> (8 * i) & 0xFF)))
    i += 1
    time.sleep(.001);

# print "]"
ser.write("]")

print ser.read(1024)

ser.close()
