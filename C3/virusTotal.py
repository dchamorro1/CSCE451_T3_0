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

key =  '6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a'
def main():
    print("Starting Script")

    state = getState()
    currentProgram = state.getCurrentProgram()
    name = currentProgram.getName()
    location = currentProgram.getExecutablePath()

    # Submit the file
    url = "https://www.virustotal.com/api/v3/files"
    path = '/tmp/{0}'.format(name)
    shutil.copyfile(location, path)
    command = "curl --request POST \
     --url {url} \
     --header 'accept: application/json' \
     --header 'content-type: multipart/form-data' \
     --header 'x-apikey: {key}' \
     --form file=@{file}".format(**{'url': url, 'key': key,'file':path})
    scan_result = subprocess.check_output(command,shell=True)
    print(scan_result)
    os.remove(path)

    # Actual data
    scan_url = json.loads(scan_result)['data']['links']['self']

    command2 = "curl --request GET \
        --url {url} \
        --header 'x-apikey: {key}'".format(**{'url': scan_url, 'key': key})
    result = subprocess.check_output(command2,shell=True)
    result = json.loads(result)
    print result

    # print("--- Getting data.links.sels---")
    # response = requests.get(response.json()["data"]["links"]["self"], headers=headers)
    # print(response.text)


if __name__ == "__main__":
    main()
