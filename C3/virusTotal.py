#@author
#@category Memory
#@keybinding
#@menupath Tools.Virus Total
#@toolbar
# Running binary through VirusTotal

import requests
import os
# from ghidra.framework import Project

def main():
    print("Starting Script")

    # TODO: get file with ghidra function

    # program = getCurrentProgram()
    #
    # # Define the output file path
    # out_file_path = os.path.join(str(program.getExecutablePath()), program.getName() + ".out")
    #
    # # Create a new raw exporter instance
    # exporter = RawExporter()
    #
    # try:
    #     # Export the program to the output file path
    #     exporter.export(program, out_file_path, monitor)
    #     print("Exported program to: " + out_file_path)
    # except ExporterException as e:
    #     print("Error exporting program: " + str(e))






    # TODO: Feeding file into virustotal
    url = "https://www.virustotal.com/api/v3/files"

    # path to exported .out file goes below?
    files = {"file": ("wordle.out", open("wordle.out", "rb"), "application/octet-stream")}

    headers = {
        "accept": "application/json",
        "x-apikey": "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a"
    }

    response = requests.post(url, files=files, headers=headers)

    print(response.text)

    analysis_url = response.json()["data"]["links"]["self"]

    print(analysis_url)

    response = requests.get(analysis_url, headers=headers)

    print("----Getting response from analysis_url----")
    print(response.text)

    # print("--- Getting data.links.sels---")
    # response = requests.get(response.json()["data"]["links"]["self"], headers=headers)
    # print(response.text)


if __name__ == "__main__":
    main()