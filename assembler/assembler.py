# The RAM-VM Assembler

import sys

if len(sys.argv) <  2:
    print("No Arguments Given")
    sys.exit(-1)

fname = sys.argv[1]

with open(fname) as fr:
    fcont = fr.read()

fcont = fcont.replace("PUSH", "0")  \
             .replace("POP", "1")   \
             .replace("FREE", "2")  \
             .replace("ADD", "3")   \
             .replace("SUB", "4")   \
             .replace("MUL", "5")   \
             .replace("DIV", "6")   \
             .replace("SET", "7")   \
             .replace("MOV", "8")   \
             .replace("LDR", "9")   \
             .replace("PSR", "10")   \
             .replace("HALT", "11")  # \
#             .replace("SET", "12")   \

with open(fname.replace(".rvm", ".o"), "w") as fw:
    fw.write(fcont)