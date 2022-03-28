# RASM - The RAM-VM Assembler
# Copyright (c) 2022 Harish Kumar
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import argparse
import os
import sys
import re

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
             .replace("IFN", "13")   \
             .replace("IF", "12")   \
             .replace("PUTS", "14")   \
             .replace("NL", "15")   \
             .replace("HALT", "16")

    fcont = fcont.replace("RA", "0")  \
             .replace("RB", "1")   \
             .replace("RC", "2")  \
             .replace("RD", "3")   \
             .replace("RE", "4")   \
             .replace("RF", "5")   \
             .replace("IP", "6")   \

    matches = re.findall(r'"(.+?)"',fcont)
    if matches:
        for match in matches:
            chars = []
            for i in match:
                chars.append(str(ord(i)))
            stch = " ".join(chars)
            fcont = fcont.replace(f"\"{match}\"", f"{len(match)} {stch}")


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