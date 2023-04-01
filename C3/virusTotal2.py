#TODO write a description for this script
#@author
#@category Memory
#@keybinding
#@menupath Tools.Virus Total
#@toolbar
# Running binary through VirusTotal

import requests

def main():

    sha256 = 'f09e46aea92879a055074fe23ea9c516902dfef1a7c343b6781aa219280db4ec'



    # Enter your API key here
    api_key = '6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a'

    # Specify the URL of the VirusTotal API
    url = 'https://www.virustotal.com/vtapi/v2/file/report'

    # Enter the file path of the file you want to scan
    file_path = 'wordle.out'

    # Open the file and read its contents as binary data
    # with open(file_path, 'rb') as file:
    #     file_data = file.read()

    # Create the request parameters
    params = {'apikey': api_key, 'resource': file_path}

    # Make the request to the API and get the response
    # response = requests.post(url, params=params)
    response = requests.get(url, params=params)

    # Print out the response
    print(response.text)


if __name__ == "__main__":
    main()