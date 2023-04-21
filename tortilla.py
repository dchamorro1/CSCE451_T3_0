#Testing script
#@author Team 8.1
#@category _NEW_
#@keybinding 
#@menupath Tools.Misc.Tortilla Tool
#@toolbar tortillas.png

########################### imports ############################
from ghidra.util import Msg
from java.lang import IllegalArgumentException
from ghidra.program.util.string import StringSearcher
from ghidra.util.exception import CancelledException
from ghidra.program.model.address import AddressSet
from ghidra.program.model import address
from ghidra.program.model.address import Address
from ghidra.program.model.symbol import SourceType
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os
import re
import csv

######################## helper methods ########################

def write_file(file_name, mode, contents): 
    '''Inputs: file_name, mode (write: w or append: a), contents.'''

    try:
        with open(file_name, mode=mode) as file:
            file.write(contents)
        print("File write success!")
    except Exception as e:
        print(e)

def write_csvfile(file_name, contents):
    '''Inputs: file_name, contents'''

    try:
        #write to csv file, mode=wb is needed for no empty rows in excel
        with open(file_name, 'wb') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerows(contents)
        popup("CSV file created successfully at {}!".format(file_name))

    except Exception as e:
        print(e)

def read_file(file_name):
    '''Inputs: filepath
    Outputs: file contents'''

    f= open(file_name, mode='r')
    f_read = f.read()
    f.close()
    return f_read

def get_address_type(address):
    '''Returns array of all types applicable to an Address object'''

    types = []
    print("Getting address types.")
    if address.isConstantAddress():
        types.append("Address is a location in constant space.")
    if address.isExternalAddress():
        types.append("Address is in external address space.")
    if address.isHashAddress():
        types.append("Address is in HASH space.")
    if address.isLoadedMemoryAddress():
        types.append("Address is in loaded memory block.")
    if address.isMemoryAddress():
        types.append("Address is in memory.")
    if address.isNonLoadedMemoryAddress():
        types.append("Address is not loaded in real memory.")
    if address.isRegisterAddress():
        types.append("Address is register address.")
    if address.isStackAddress():
        types.append("Address is in stack space.")
    if address.isUniqueAddress():
        types.append("Address is in unique space.")
    if address.isVariableAddress():
        types.append("Address is in variable space.")
    print("Checks done.")
    return types

######################## main methods ########################
def find_exact_string():
    '''Performs string matching, supports regex as well'''

    try:
        search = askString("Text Search", "Enter text to be found: ")
        addr = findBytes(currentProgram.getMinAddress(), search, MAX_REFERENCES_TO)
        if(len(addr) == 0):
            popup("Text not found!")
            print("Text not found!")
        else:
            show(addr)
            print("{} instances of {} found".format(len(addr), search))
            popup("{} instances of {} found.\nRight click on the table and select 'export' to export results as csv file.".format(len(addr), search))
            goTo(addr[0])

    except IllegalArgumentException as error:
        Msg.warn(self, "Error during headless processing: " + error.toString())

def find_string_min_length():
    '''Finds all strings with user-input minimum length'''
    try: 
        min_length = askInt("minimum length", "Enter minimum string length to be found: ")
        if(min_length < 1):
            print("Invalid argument.")
        else:
            mem_list = []
            s_list = []
            add_list = []

            ss = StringSearcher(currentProgram, min_length, 1, False, True)

            def callback(s):
                mem_list.append(s)
                found_string = s.getString(currentProgram.getMemory())
                s_list.append(found_string)

                addr_found = find(found_string)
                if(addr_found != None):
                    add_list.append(addr_found)

            temp = ss.search(None, callback, True, monitor)
            # addr_set_view = ss.updateAddressesToSearch(temp, True)

            for x in range(len(mem_list)):
                print(s_list[x] , " found at " , mem_list[x])
            
            # show("Address", addr_set_view)
            show(add_list)
    except Exception as e:
        print(e)

def query_register():
    '''Checks user-given register for more information
    Address class documentation: 
    https://ghidra.re/ghidra_docs/api/ghidra/program/model/address/Address.html'''
    
    memory = currentProgram.getMemory()
    block = memory.getBlock(currentAddress)
    addr_set_view = AddressSet(block.getStart(), block.getEnd())

    addr_list = []
    addr = askAddress("address 1", "Enter address: ")
    addr_list.append(addr)
    try:
        print("Memory in address ", addr, " = ", memory.getByte(addr))
        show(addr_list)
        popup(
"""Additional information:
Virtual address: {}
Offset: {}
Addressable word offset: {}
Address space: {}
Pointer size in bytes: {}
Size of address in bits: {}
Hashcoded address: {}

Address types:
{}
            """.format(
            addr.getPhysicalAddress(), 
            #I asked HD. getPhysicalAddress returns a virtual address.
            addr.getOffset(),
            addr.getAddressableWordOffset(), 
            addr.getAddressSpace(), 
            addr.getPointerSize(),
            addr.getSize(),
            addr.hashCode(),
            "\n".join(get_address_type(addr))
        ))

    except Exception as e:
        popup("Invalid address.")
        print("Invalid address")
        print(e)

def output_decompiled():
    '''outputs all decompiled code into a text file'''

    decomp = DecompInterface()
    decomp.openProgram(currentProgram)
    func_list = []
    funcIter = currentProgram.getListing().getFunctions(True)

    #ask filepath
    filepath = askDirectory("Save location", "Save").getAbsolutePath() + "\\decompiled_code.txt"
    print("Save location: " + filepath)
    if os.path.exists(filepath):
        os.remove(filepath)

    # iterate through functions, get their decompiled and put in file
    while(funcIter.hasNext() and not monitor.isCancelled()):
        func = funcIter.next()
        func_list.append(func)

        d = decomp.decompileFunction(func, 30, monitor)
        func_sig = d.getDecompiledFunction().getSignature()
        func_code = d.getDecompiledFunction().getC()
        
        write_file(filepath, 'a', func_sig + "\n" + func_code)

    
def get_listing_variables():
    '''symbols will be returned in a csv file.'''

    #ask filepath
    filepath = askDirectory("Save location", "Save").getAbsolutePath() + "\\symbols.csv"
    print("Save location: " + filepath)
    if os.path.exists(filepath):
        os.remove(filepath)

    #get symbol table (array of symbols)
    try: 
        symbols = currentProgram.getSymbolTable()
        #edit headers here
        data = [['Name', 'Address', 'ID', 'Symbol Type', 'Source']]

        for symbol in symbols.getDefinedSymbols():
            rowdata = []
            rowdata.append(symbol.getName())
            rowdata.append(symbol.getAddress().getPhysicalAddress())
            rowdata.append(symbol.getID())
            rowdata.append(symbol.getSymbolType())
            rowdata.append(symbol.getSource())
            data.append(rowdata)

        #write to csv file, mode=wb is needed for no empty rows in excel
        write_csvfile(filepath, data)
        
    except Exception as e:
        print(e)

def get_listing_functions():
    '''function details will be returned in a csv file'''

    #ask filepath
    filepath = askDirectory("Save location", "Save").getAbsolutePath() + "\\functions.csv"
    print("Save location: " + filepath)
    if os.path.exists(filepath):
        os.remove(filepath)

    try:
        functions = currentProgram.getListing().getFunctions(True)
        data = [["Function Name", "ID", "Parent Namespace", "Address Set"]]
        for function in functions:
            rowdata = []
            rowdata.append(function.getName())
            rowdata.append(function.getID())
            rowdata.append(function.getParentNamespace())
            rowdata.append(function.getBody())
            data.append(rowdata)
        
        write_csvfile(filepath, data)

    except Exception as e:
        print(e)
        
def rename_listing():
    '''Renames variables found in listing'''
    symbols = currentProgram.getSymbolTable()

    #check if all variable names need to be displayed
    if askYesNo("Display variables", "Display a list of current variables in console?\nNote: Console is in CodeBrowser window."):
        for symbol in symbols.getAllSymbols(True):
            print(symbol.getName())

    #use csv file as map?
    if askYesNo("CSV file mapping", "Use a csv file mapping to replace multiple variables?\nRow format: Original name, new name\nSelect 'No' for single variable replacement."):
        csvfilepath = askFile("CSV file upload", "Crunch")
        with open(csvfilepath.getAbsolutePath(), 'rb') as file:
            csvfile = csv.reader(file)
            for line in csvfile:
                # print(line)       #useful for debugging, can read csv file data
                for symbol in symbols.getAllSymbols(True):
                    if symbol.getName() == line[0]:
                        symbol.setName(line[1], SourceType.USER_DEFINED)
                funcIter = currentProgram.getListing().getFunctions(True)
            
                while(funcIter.hasNext() and not monitor.isCancelled()):
                    func = funcIter.next()
                    vars = func.getLocalVariables()

                    # iterate through all variables
                    for v in vars:
                        if(v.getName() == line[0]):
                            print(v.getName(), " found in function ", func.getName())
                            v.setName(line[1], SourceType.USER_DEFINED)
            popup("All variables replaced!")
            print("All variables replaced!")

    else:
        #get current name and new variable name
        curr_name = askString("Current name", "Variable name to replace")
        if(curr_name == None):
            print("Invalid string")
            return
        
        new_name = askString("New variable name", "New name")
        if(new_name == None):
            print("Invalid string")
            return
        
        count = 0
        for symbol in symbols.getAllSymbols(True):
            if symbol.getName() == curr_name:
                symbol.setName(new_name, SourceType.USER_DEFINED)
                count += 1
            funcIter = currentProgram.getListing().getFunctions(True)
            while(funcIter.hasNext() and not monitor.isCancelled()):
                func = funcIter.next()
                vars = func.getLocalVariables()

                # iterate through all variables
                for v in vars:
                    if(v.getName() == curr_name):
                        print(v.getName(), " found in function ", func.getName())
                        v.setName(new_name, SourceType.USER_DEFINED)

        if(count>0):
            print("Found ", count, " instances of ", curr_name)
        else:
            print("Found ", count, " instances of ", curr_name, ". Nothing is replaced.")

def ascii_converter(mode): # mode either toDec or toAscii
    if(mode == "toAscii"):
        input = askString("decimal", "Enter int to convert to ASCII (separate integers with spaces): ")
        input_list = input.split()
        res_str = ""
        try:
            for dec in input_list:
                res_str += chr(int(dec))
        except:
            print("Invalid input.")
            popup("Invalid input.")
            return
        
        popup("Ascii of {} is {}".format(input, res_str))
        print("Ascii of {} is {}".format(input, res_str))

    elif(mode == "toDec"):
        input = askString("ascii", "Enter ASCII character/string to convert to decimal form: ")
        res_str = ""
        for x in input:
            res_str += str(ord(x)) + " "
        popup("Decimal of {} is {}".format(input, res_str))
        print("Decimal of {} is {}".format(input, res_str))

    else:
        print("Invalid mode")

def help():

    helpstring = """
Tortilla Tool aims to enhance a reverser's experience by providing rapid edit features as highlighted below.
Developers: Eliana, Alfonso, Chun Hui, Michael

String search:
    Searches for exact matches to a given input string. 

Find strings with minimum length:
    Searches for strings of given minimum character length.

Query specific register:
    Gets information regarding a specific register at given address value.
    Note: "Invalid address" may appear if given address is not a register. 

Output decompiled code:
    Creates decompiled_code.txt at the specified directory with all Ghidra-generated decompiled code.

Get all variables:
    Creates symbols.csv at the specified directory with all variables.
    Data labels: ['Name', 'Address', 'ID', 'Symbol Type', 'Source']

Get all functions:
    Creates functions.csv at the specified directory with all functions.
    Data labels: ["Function Name", "ID", "Parent Namespace", "Address Set"]

Rename listing variables:
    1. Get a list of register names in Console in the CodeBrowser. 
    2. Either upload a CSV with all mappings [original variable name, new variable name], 
        or choose 'No' and enter the original variable name followed by the new variable name.
    This will rename all variables in the decompiled code.
    To check if this has worked, get all variables by running the script again to obtain symbols.csv, then compare.

Decimal to ASCII/ ASCII to Decimal converter:
    A helpful converter for decimal/ ASCII.
    """
    
    shorterHelp = """
Tortilla Tool aims to enhance a reverser's experience by providing rapid edit features.
Developers: Eliana, Alfonso, Chun Hui, Michael

Please refer to the console in CodeBrowser for more information on each function.
    """
    popup(shorterHelp)
    print(helpstring)

######################## main ########################
try:
    if(currentAddress == None):
        print("Current address is null.")

    if(currentProgram == None):
        print("Current program is null.")

    # prompt for user choice
    menu_choice = askChoice("Welcome to Tortilla Tool!", 
                            "What would you like to do?", 
                            [
                                "String search (Regex allowed)", 
                                "Find strings with minimum length", 
                                "Query specific register", 
                                "Output decompiled code", 
                                "Get all variables", 
                                "Get all functions", 
                                "Rename listing variables", 
                                "Decimal to ASCII converter", 
                                "ASCII to Decimal converter", 
                                "Help"
                            ], 
                            "String search")

    if(menu_choice == "Find strings with minimum length"):
        find_string_min_length()

    elif(menu_choice == "String search (Regex allowed)"):
        find_exact_string()
    
    elif(menu_choice == "Query specific register"):
        query_register()
        
    elif(menu_choice == "Output decompiled code"):
        output_decompiled()
    
    elif(menu_choice == "Get all variables"):
        get_listing_variables()

    elif(menu_choice == "Get all functions"):
        get_listing_functions()

    elif(menu_choice == "Rename listing variables"):
        rename_listing()

    elif(menu_choice == "Decimal to ASCII converter"):
        ascii_converter('toAscii')

    elif(menu_choice == "ASCII to Decimal converter"):
        ascii_converter('toDec')

    elif(menu_choice == "Help"):
        help()

    else:
        raise CancelledException

except CancelledException:
    print("Operation cancelled")

except Exception as e:
    print(e)

# acknowledgements
# AskScriptPy.py: https://github.com/NationalSecurityAgency/ghidra/blob/master/Ghidra/Features/Python/ghidra_scripts/AskScriptPy.py