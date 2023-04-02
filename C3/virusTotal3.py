# @author
# @category Memory
# @keybinding
# @menupath Tools.Virus Total
# @toolbar
# Running binary through VirusTotal

# TODO Add User Code Here

# import requests
# import os
from ghidra.framework import Project
# import os
# import ghidra.app.util.bin.exporter.ExporterException as ExporterException
# import ghidra.app.util.bin.exporter.RawExporter as RawExporter

import urllib
import urllib2
import json

def main():


    # *done - Feeding file into virustotal
    url = "https://www.virustotal.com/api/v3/files"

    files = {"file": (out_file_path, open(out_file_path, "rb"), "application/octet-stream")}

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


    ### Changing the above code to use urllib/urllib2 ###########################################################

    requests = urllib2(Request(url))

    # data = urllib.urlencode(headers)

    requests.add_header("accept", "application/json")
    requests.add_header("x-apikey", "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a")

    requests.add_data(files)



if __name__ == "__main__":
    main()
