#TortillaTotal
#@author Team 3.0 and 8.1
#@category _NEW_
#@keybinding 
#@menupath Tools.Misc.Tortilla Total
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
from ghidra.app.decompiler import DecompileOptions, DecompInterface
from ghidra.app.decompiler import DecompileResults
from ghidra.util.task import ConsoleTaskMonitor
import os
import re
import csv
import subprocess
import shutil
import json
import sys
import hashlib
import time

from javax.swing import JFrame, JButton, JPanel, SwingUtilities
from javax.swing import JTable, JScrollPane
from java.awt import Dimension
from java.util.concurrent import CountDownLatch
from ghidra.program.model.symbol import SymbolUtilities
import javax.swing.table.DefaultTableCellRenderer as DefaultTableCellRenderer
import java.awt.Font as Font

from javax.swing import JFrame, JTable, JScrollPane, SwingConstants
from javax.swing.table import DefaultTableCellRenderer, TableColumn
from java.awt import Color, Font, Component

# Table
def displayTable(headers, data, title):
    frame = JFrame(title)
    frame.setSize(1200, 400)

    # Create the Table
    table = JTable(data, headers)

    # Set font and size of headers and cells
    table = JTable(data, headers)
    table.getTableHeader().setFont(Font("Arial", Font.BOLD, 12))
    table.setFont(Font("Arial", Font.PLAIN, 12))

    # Set background colors of table and headers
    table.setBackground(Color.WHITE)
    table.getTableHeader().setBackground(Color.LIGHT_GRAY)

    # Add alternating row colors
    table.setRowHeight(25)

    # Adjust column widths to fit content
    table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF)
    for i in range(table.getColumnCount()):
        column = table.getColumnModel().getColumn(i)
        preferredWidth = column.getMinWidth()
        maxWidth = column.getMaxWidth()
        for j in range(table.getRowCount()):
            cellRenderer = table.getCellRenderer(j, i)
            c = table.prepareRenderer(cellRenderer, j, i)
            width = c.getPreferredSize().width + table.getIntercellSpacing().width
            preferredWidth = max(preferredWidth, width)
            if preferredWidth >= maxWidth:
                preferredWidth = maxWidth
                break
        column.setPreferredWidth(preferredWidth)

    scrollPane = JScrollPane(table)
    frame.add(scrollPane)

    # Displaying Table
    frame.setPreferredSize(Dimension(1200, 400))
    frame.pack()
    frame.setLocationRelativeTo(None) # center window
    frame.setVisible(True)

chosen_option = None

class MyGUI:
    global chosen_option
    def __init__(self):

        self.frame = JFrame("Choose an Option")
        self.frame.setSize(600, 200)

        panel = JPanel()

        malware_button = JButton("Malware Detector", actionPerformed=self.malware_detector)
        panel.add(malware_button)

        string_button = JButton("String Extractor", actionPerformed=self.string_extractor)
        panel.add(string_button)
        
        find_string_button = JButton("Find strings with minimum length", actionPerformed=self.find_string)
        panel.add(find_string_button)

        string_search_button = JButton("String search (Regex allowed)", actionPerformed=self.find_exact)
        panel.add(string_search_button)

        query_register_button = JButton("Query specific register", actionPerformed=self.query_reg)
        panel.add(query_register_button)

        output_decompiled_button = JButton("Output decompiled code", actionPerformed=self.output_dec)
        panel.add(output_decompiled_button)

        get_variables_button = JButton("Get all variables", actionPerformed=self.get_var)
        panel.add(get_variables_button)

        get_functions_button = JButton("Get all functions", actionPerformed=self.get_func)
        panel.add(get_functions_button)

        rename_button = JButton("Rename listing variables", actionPerformed=self.rename_var)
        panel.add(rename_button)

        to_ascii_button = JButton("Decimal to ASCII converter", actionPerformed=self.ascii_convert)
        panel.add(to_ascii_button)

        to_dec_button = JButton("ASCII to Decimal converter", actionPerformed=self.dec_convert)
        panel.add(to_dec_button)

        help_button = JButton("Help", actionPerformed=self.help_display)
        panel.add(help_button)

        self.frame.add(panel)
        # self.frame.setLocationRelativeTo(None) # center window
        self.frame.setVisible(True)

    def malware_detector(self, event):
        global chosen_option
        print("You clicked the Malware Detector button.")
        chosen_option = "malware"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()
        # self.latch.countDown()

    def string_extractor(self, event):
        global chosen_option
        print("You clicked the String Extractor button.")
        chosen_option = "string_extractor"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def find_string(self, event):
        global chosen_option 
        chosen_option = "find_string_min_length"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def find_exact(self, event):
        global chosen_option 
        chosen_option = "find_exact_string"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()
    
    def query_reg(self, event):
        global chosen_option 
        chosen_option = "query_register"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()
    
    def output_dec(self, event):
        global chosen_option 
        chosen_option = "output_decompiled"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()
    
    def get_var(self, event):
        global chosen_option 
        chosen_option = "get_listing_variables"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def get_func(self, event):
        global chosen_option 
        chosen_option = "get_listing_functions"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def rename_var(self, event):
        global chosen_option 
        chosen_option = "rename_listing"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def ascii_convert(self, event):
        global chosen_option 
        chosen_option = "to_ascii"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def dec_convert(self, event):
        global chosen_option 
        chosen_option = "to_dec"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

    def help_display(self, event):
        global chosen_option 
        chosen_option = "help"
        SwingUtilities.getWindowAncestor(event.getSource()).dispose()

# Virustotal
key =  '6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a'
url = "https://www.virustotal.com/api/v3/"
def get_results(scan_url):
    command2 = "curl --request GET \
        --url {url} \
        --header 'accept: application/json' \
        --header 'x-apikey: {key}'".format(**{'url': scan_url, 'key': key})

    print(command2)
    result = subprocess.check_output(command2,shell=True)
    print(result)

    if askYesNo("Malware analysis", "Would you like to save the analysis report in your local computer?"):
        filepath = askDirectory("Save location", "Save").getAbsolutePath() + "/malware_analysis.txt"
        popup("Save location: " + filepath)
        if os.path.exists(filepath):
            os.remove(filepath)
        write_file(filepath, "w", result) 

    result = json.loads(result)
    return result

def submit_file(name, location): # location includes name
    path = '/tmp/{0}'.format(name)
    shutil.copyfile(location, path)
    command = "curl --request POST \
     --url {url} \
     --header 'accept: application/json' \
     --header 'content-type: multipart/form-data' \
     --header 'x-apikey: {key}' \
     --form file=@{file}".format(**{'url': url+'files', 'key': key,'file':path})
    scan_result = subprocess.check_output(command,shell=True)
    print(scan_result)
    os.remove(path)
    return json.loads(scan_result)


# String extractor
def extract_string_literals():
    # Set up the decompiler interface
    decomp_interface = DecompInterface()
    decomp_interface.openProgram(currentProgram)
    options = DecompileOptions()

    # Get all functions in the binary
    functions = currentProgram.getFunctionManager().getFunctions(True)

    matches = {}

    # Iterate over all functions and extract string literals
    with open('string_literals.txt', 'w') as f:
        for function in functions:
            try:
                # Decompile the function
                results = decomp_interface.decompileFunction(function, 60, monitor)
                if results is None:
                    continue

                # Extract string literals from the decompiled code
                markup = results.getCCodeMarkup()
                if markup:
                    # print("\n\n\n")
                    # print(markup)

                    # printing type of the variable markup
                    # print("type of variable markup: ", type(markup))

                    # if the markup contains an item within "" or within '', print the string literal

                    markup = str(markup)

                    # CHECK THE FOLLOWING REGEX EXPRESSION TO MAKE SURE THAT ITS CAPTURING CORRECTLY
                    string_regex = re.compile(r"['\"](.*?)['\"]")

                    if re.findall(string_regex, markup):
                        # print the name of the function were currently checking for string literals
                        fxn_name = function.getName()
                        fxn_lits = re.findall(string_regex, markup)
                        print("Function name: ", fxn_name)
                        # print the string literals found in the function
                        print("Found the following string: ", fxn_lits)
                        print("\n")
                        if(fxn_name not in matches):
                            matches[fxn_name] = []
                        matches[fxn_name].extend(fxn_lits)

            except Exception as e:
                print(e)

    # Clean up the decompiler interface
    decomp_interface.dispose()
    print(matches)
    return matches

def malware():
    print("Executing malware code")

    # Try hash
    state = getState()
    currentProgram = state.getCurrentProgram()
    name = currentProgram.getName()
    location = currentProgram.getExecutablePath()
    hash_sha = currentProgram.getExecutableSHA256()
    result = get_results(url + 'files/' + hash_sha)

    # Upload file if that doesn't work
    if('error' in result):
        print('File not found')
        print('Prompt to upload file?')
        # Submit the file
        scan_result = submit_file(name,location)
        print(json.dumps(scan_result, indent=4, sort_keys=True))

        # Actual data
        scan_url = scan_result['data']['links']['self']
        result = None

        # Takes time to process
        # try multiple times with exp backoff
        for i in range(6): # upto 2^6 or 64 seconds wait
            result = get_results(scan_url)
            if(result['data']['attributes']['status'] == 'completed'):
                break
            print("trying again", result['data']['attributes']['status'])
            time.sleep(2**i) # exponential back-off 2, 4, 8, 16 sec
        if result == None:
            print('Could not upload file please try again')
            return -1

        # file and hash results are different but contain the same information
        # get hash result
        result = get_results(url + 'files/' + hash_sha)

    print('Display output')
    print(json.dumps(result, indent=4, sort_keys=True))

    # Parse the JSON data to extract the attributes
    attributes = result['data']['attributes']
    rows = []
    for key, value in attributes.items():
        rows.append([key, str(value)])
    headers = ["Attribute", "Value"]

    displayTable(headers, rows, title="Malware Analysis and File Data")
    pass

def string_extractor():
    # Code for string extractor starts HERE vvv
    print("Executing string extractor code")
    strings = extract_string_literals() 
    print(strings.keys(), strings.values())
    displayTable(["Function", "Strings"], strings.items(), title="Function and String Literals")
    pass

######################## Tortilla methods ########################


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
Tortilla Total aims to enhance a reverser's experience by providing rapid edit features and malware analysis as highlighted below.
Developers: Eliana, Alfonso, Chun Hui, Michael, Caleb, Jarrett, Daniel

Malware Detector: 
    Passes the binary file to VirusTotal to detect if there are known malware in the code.

String Extractor:
    Extracts all the strings in the code.

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

Decimal to ASCII / ASCII to Decimal converter:
    A helpful converter for decimal/ ASCII.
    """
    
    shorterHelp = """
Tortilla Total aims to enhance a reverser's experience by providing rapid edit features and malware analysis as highlighted below.
Developers: Eliana, Alfonso, Chun Hui, Michael, Caleb, Jarrett, Daniel

Please refer to the console in CodeBrowser for more information on each function.
    """
    popup(shorterHelp)
    print(helpstring)

def main():
    print("Starting Script")
    global chosen_option
    latch = CountDownLatch(1)
    gui = MyGUI()

    valid_options = ["malware", 
                     "string_extractor", 
                     "find_string_min_length", 
                     "find_exact_string", 
                     "query_register", 
                     "output_decompiled",
                     "get_listing_variables",
                     "get_listing_functions",
                     "rename_listing",
                     "to_ascii",
                     "to_dec",
                     "help"]

    while chosen_option not in valid_options:
        pass

    if chosen_option == "malware":
        malware()

    if chosen_option == "string_extractor":
        string_extractor()

    if chosen_option == "find_string_min_length":
        find_string_min_length()

    if chosen_option == "find_exact_string":
        find_exact_string()
    
    if chosen_option == "query_register":
        query_register()
        
    if chosen_option == "output_decompiled":
        output_decompiled()
    
    if chosen_option == "get_listing_variables":
        get_listing_variables()

    if chosen_option == "get_listing_functions":
        get_listing_functions()

    if chosen_option == "rename_listing":
        rename_listing()

    if chosen_option == "to_ascii":
        ascii_converter('toAscii')

    if chosen_option == "to_dec":
        ascii_converter('toDec')

    if chosen_option == "help":
        help()

    else:
        print("Operation ended.")
        # raise CancelledException


if __name__ == "__main__":
    main()

# acknowledgements
# AskScriptPy.py: https://github.com/NationalSecurityAgency/ghidra/blob/master/Ghidra/Features/Python/ghidra_scripts/AskScriptPy.py