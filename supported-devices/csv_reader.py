"""
csv_reader.py
method for retreiving network device information for csv files with the 
following columns in the following order:
    hostname, ip_address, username, password, contact, location, type, version,
    model, chassis_serial, chassis_mac, hw_tput_lvl, uptime, interfaces
@param a .csv file
@return a list representing the cscv file
"""

def csv_reader(fileName):
    try:
        myFile = open(fileName, 'r')
    except:
        print("File I/O error")
    header = myFile.readline()
    headerList = header.split(',')
    output = []
    output.append(headerList)
    line = myFile.readline()
    while line != '':
        lineList = line.split(',')
        output.append(lineList)
        line = myFile.readline()
    myFile.close()
    return output
