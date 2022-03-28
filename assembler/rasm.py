# RASM - The RAM-VM Assembler

import argparse
import os
import sys

__version__ = 1.0
__author__ = "M.V.Harish Kumar"
__version_str__ = f"This is RASM - The RAM-VM assembler v{__version__} Created by {__author__}"


def asedit(fcont):
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
             .replace("PREG", "11")   \
             .replace("HALT", "12")

    fcont = fcont.replace("RA", "0")  \
             .replace("RB", "1")   \
             .replace("RC", "2")  \
             .replace("RD", "3")   \
             .replace("RE", "4")   \
             .replace("RF", "5") 
             
    return fcont

def writeobj(fname, asmcont):
    objfname = fname[:-4] + ".o"
    with open(objfname, "w") as fw:
        fw.write(asmcont)


def assemble(fname):
    if not os.path.exists(fname):
        sys.stderr.write(f"Error: Cannot open file {fname}\n")
        sys.exit(-1)
    else:
        with open(fname) as fr:
            fcont = fr.read()
        asmcont = asedit(fcont)
        writeobj(fname, asmcont)
        


my_parser = argparse.ArgumentParser(prog="rasm",
                                    description="The RAM-VM Assembler")

my_parser.add_argument('File',
                        metavar='file',
                        type=str,
                        help="The File to assemble")

my_parser.add_argument("-v",
                        "--version",
                        action="version",
                        version=__version_str__,
                        help="shows version info of RASM")

args = my_parser.parse_args()

assemble(args.File)