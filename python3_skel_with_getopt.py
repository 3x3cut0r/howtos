#!/usr/bin/python3
#
# Author:       Julian Reith
# E-Mail:       julianreith@gmx.de
# Version:      0.1
# Last Updated: 2020-01-21
#
# Description:
# Short description ...
#
# Usage:
#  python3.py [must] <optional>
#
# Options:
#  -h, --help               show this help
#  -o, --option1=true       set option1 true or False
#  -p, --option2=true       set option2 true or False
#  -v, --verbose            Verbose mode
#

### IMPORTS ###
import sys
import getopt

### GLOBAL VARS ###
verbose = 0                     # 0 = off, 1 = on

### CLASSES ###
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

### FUNCTIONS ###
def exec_options():
    fullCmdArguments = sys.argv             # given arguments as array[] (with script itself)
    argumentList = fullCmdArguments[1:]     # given arguments as array[] (without script itself)
    unixOptions = "ho:p:vV"                  # allowed arguments (short format, o: means: need value)
    gnuOptions = [  "help",                 # allowed arguments (long format)
                    "option1=",
                    "option2=",
                    "verbose",
                    "version" ]
    # get arguments + values
    try:
        arguments, values = getopt.getopt(argumentList, unixOptions, gnuOptions)
    except getopt.error as err:
        print (str(err))
        sys.exit(2)
    # for arguments which needs to be alone ... exit() after
    for currentArgument, currentValue in arguments:
        if currentArgument in ("-h", "--help"):
            usage()
            sys.exit(0)
        elif currentArgument in ("-V", "--version"):
            print ("python3.py Version 0.1")
            sys.exit(0)
    # for arguments with higher priority ...
    for currentArgument, currentValue in arguments:
        if currentArgument in ("-v", "--verbose"):
            print(bcolors.WARNING + " -- VERBOSE MODE --" + bcolors.ENDC)
            verbose = 1
    # for arguments with normal priority which could be combined ...
    for currentArgument, currentValue in arguments:
        if currentArgument in ("-o", "--option1"):
            print (("Setting Option1 = (%s)") % (currentValue))
        elif currentArgument in ("-p", "--option2"):
            print (("Setting Option2 = (%s)") % (currentValue))

def usage():
    print(bcolors.BOLD + "Usage:" + bcolors.ENDC)
    print(" python3.py [must] <optional>\n")
    print(bcolors.BOLD + "Description:" + bcolors.ENDC)
    print(" Short script description\n")
    print(bcolors.BOLD + "Options:" + bcolors.ENDC)
    print(" -h, --help              show help")
    print(" -o, --option1=true      set option1 true or False")
    print(" -p, --option2=true      set option1 true or False")
    print(" -v, --verbose           Verbose mode\n")

### START OF SCRIPT ###
def main(argv):
    exec_options()

    # ENTER YOUR SCRIPT CODE HERE ...

    pass

if __name__ == "__main__":
    main(sys.argv)
