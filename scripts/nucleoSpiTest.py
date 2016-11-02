
import serial, sys, time, array

# Parse the response of the buspirate into received bytes
def parseData(readString):
    
    lines = readString.split('\r\n')

    readBytes = []

    for line in lines:
        if len(line) > 0 and line[0] == '<':
            tokens = line.split('<')
            tokens = tokens[1].split('>')
            tokens = tokens[0].split(',')

            for token in tokens:
                if len(token) > 0:
                    readBytes.append(int(token, 16))


            # 5 Tokens in a valid line from the buspirate
            # if len(tokens) == 5:
                # readBytes.append(int(tokens[3], 0))

    
    return readBytes


def checkLists(inList, outList):
    if outList == inList:
        status = True
    else:
        status = False
        print "Expected: " + str(inList)
        print "Received: " + str(outList)

    return status



# Write and read a number of bytes from the SPI
def writeReadSpi(ser, inData):
    # Write the SPI command
    ser.write('[writeSpi,' + ",".join(map(str, inData)) + "]")

    time.sleep(.03)
    readString = ser.read(32 * len(inData))

    outData = parseData(readString)
    return outData


def testCase1(ser):

    inputList = [1,2,3,4,5,6,7,8,9,0];
    writeReadSpi(ser, inputList)

    outList = writeReadSpi(ser, [0,0,0,0,0,0,0,0,0,0])

    print "Test Case 1: " + str(checkLists(inputList, outList))

def testCase2(ser):

    inputList1 = [1,2,3,4,5,6,7,8,9,0xA]
    inputList2 = [0x8A, 0x9B, 0xAC, 0xBD, 0xCE, 0xDF, 0xE0, 0xF1, 0x02, 0x13]

    writeReadSpi(ser, inputList1)

    for i in range(0, 1000, 2):
        print int(i)
        outList = writeReadSpi(ser, inputList2)

        if checkLists(inputList1, outList) == False:
            print "Failed at " + str(i)
            return False

        outList = writeReadSpi(ser, inputList1)

        if checkLists(inputList2, outList) == False:
            print "Failed at " + str(i + 1)
            return False
        
    print "Test Case 2: Pass" 
    return True

    

ser = serial.Serial(sys.argv[1], 115200, timeout=0)


testCase1(ser)
testCase2(ser)


