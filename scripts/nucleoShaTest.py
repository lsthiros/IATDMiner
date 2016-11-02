
import serial, sys, time

midstate = 0x4a03aeb2bcf3ad77d705828c4ec62fa2282784a285936a72c71636a4ddef7254
target = 0x00000000000000000440C4000000000000000000000000000000000000000000
header_leftovers = 0x15274c646c51f957c4400418

ser = serial.Serial(sys.argv[1], baudrate=115200)

ser.write("[writeSpi")
# print "[writeSpi"

i = 31
while i >= 0:
    # print("," + "%x"%((midstate >> (8 * i) & 0xFF)))
    ser.write("," + "%x"%((midstate >> (8 * i) & 0xFF)))
    i -= 1
    time.sleep(.001);

i = 11
while i >= 0:
    # print("," + "%x"%((header_leftovers >> (8 * i) & 0xFF)))
    ser.write("," + "%x"%((header_leftovers >> (8 * i) & 0xFF)))
    i -= 1
    time.sleep(.001);

i = 31
while i >= 0:
    # print("," + "%x"%((target >> (8 * i) & 0xFF)))
    ser.write("," + "%x"%((target >> (8 * i) & 0xFF)))
    i -= 1
    time.sleep(.001);

# print "]"
ser.write("]")

ser.close()
