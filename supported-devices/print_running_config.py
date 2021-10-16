'''
code that ssh's into admin@10.90.54.224 and prints out the running config 
'''

import paramiko
from paramiko import client

class ssh:
    client = None
 
    def __init__(self, address, username, password):
        print("Connecting to server.")
        self.client = client.SSHClient()
        self.client.set_missing_host_key_policy(client.AutoAddPolicy())
        self.client.connect(address, username = username, password=password, look_for_keys=False)
 
    def sendCommand(self, command):
        if(self.client):
            stdin, stdout, stderr = self.client.exec_command(command)
            while not stdout.channel.exit_status_ready():
                # Print data when available
                if stdout.channel.recv_ready():
                    alldata = stdout.channel.recv(1024)
                    prevdata = b"1"
                    while prevdata:
                        prevdata = stdout.channel.recv(1024)
                        alldata += prevdata
 
                    print(str(alldata, "utf8"))
        else:
            print("Connection not opened.")

      
    def exit_ssh(self): 
        print "Command done, closing SSH connection"
        self.client.close()  

connection = ssh('10.90.54.224', 'admin', 'C1sco12345')
connection.sendCommand('show run')
