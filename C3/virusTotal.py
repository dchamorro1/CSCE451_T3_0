# @author
# @category _NEW_
# @keybinding
# @menupath Tools.Virus Total
# @toolbar
# Running binary through VirusTotal

#TODO Add User Code Here
import urllib2
import os
import subprocess
import shutil
import json
import sys
import hashlib
import time

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

    
def main():
    print("Starting Script")

    state = getState()
    currentProgram = state.getCurrentProgram()
    name = currentProgram.getName()
    location = currentProgram.getExecutablePath()
    hash_sha = currentProgram.getExecutableSHA256()

    
    # name = 'test1.dat'
    # location = sys.argv[1] + name
    # h = hashlib.sha256()
    # with open(location, 'rb', buffering=0) as f:
    #     h.update(f.read())
    # hash_sha = h.hexdigest()
    # print(hash_sha)

    # Try hash
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

    # TODO: do stuff with output


if __name__ == "__main__":
    main()
