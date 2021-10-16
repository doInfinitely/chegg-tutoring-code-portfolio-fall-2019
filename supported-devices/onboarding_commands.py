#!/usr/bin/env python

"""
currently holding method stubs for certain functions
"""
from print_running_config import ssh

# Validate SmartNet Coverage Status 
def validate_smartnet():
	# api call to get coverage status from device serial number
	# https://api.cisco.com/sn2info/v2/coverage/status/serial_numbers/{sr_no,sr_no,sr_no}
	# see service_line_descr field, and search for "SMARTnet"
	return 

# Identify licenses available on the system 
def sh_licenses(conn):
	conn.sendCommand("sh license")


# Identify CDP neighbors and add to discovered device inventory
def sh_cdp(conn):
	conn.sendCommand("sh cdp neighbors")


if __name__ == '__main__':

	connection1 = ssh('10.90.54.224', 'admin', 'C1sco12345')
	connection2 = ssh('10.95.34.9', 'cisco', 'Cisco321')

	connection1.exit_ssh()
	connection2.exit_ssh()
	
