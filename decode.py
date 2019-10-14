import codecs
import shutil
import os.path

f = open("interpreter_input.smp",errors='ignore')
##print(f.read())
if f.mode == "r":
    data = f.read()
    for byte in data:
        print(byte)
##        for i in range(8):
##            #bit = 2**i & byte
##            print(i)
f.closed
