#!/usr/bin/python3

#####################################################################
# 32-bit cyclic shift
# Cycle all bits left by the given amount
# Remember that the input value and the return value must operate
# on the assumption that all data is 32-bits
def cyclicLeftShift( value, shift ):
  return 0  # Implement this!


#####################################################################
# Tester code (DO NOT CHANGE!)
# Test some numbers with a few shift values, to make sure
# your shifting function is working
# If you see an 'X' at the end of output, then your function
# isn't working!  Note that the markers may use other values
# for testing; the following isn't meant to be exhaustive
data = [
  [ 0x12345678, 0x12345678,  0 ],
  [ 0x12345678, 0x23456781,  4 ],
  [ 0x12345678, 0x34567812,  8 ],
  [ 0x12345678, 0x45678123, 12 ],
  [ 0x12345678, 0x56781234, 16 ],
  [ 0x12345678, 0x67812345, 20 ],
  [ 0x12345678, 0x78123456, 24 ],
  [ 0x12345678, 0x12345678, 32 ],
  [ 0x40000000, 0x00000001,  2 ],
]

for i in range(len(data)):
  actual = cyclicLeftShift(data[i][0], data[i][2])
  expected = data[i][1]
  result = "" if actual == expected else "X"
  print("%8X <- %2d = %8X (expected %8X)  %s" % (data[i][0], data[i][2], actual, expected, result))
