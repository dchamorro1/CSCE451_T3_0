# @author
# @category Memory
# @keybinding
# @menupath Tools.Virus Total
# @toolbar
# Running binary through VirusTotal

# import urllib
# import urllib.request
import urllib2


def main():
    print("Starting Script")

    ### Changing old code to use urllib/urllib2 ###########################################################

    state = getState()
    currentProgram = state.getCurrentProgram()
    location = currentProgram.getExecutablePath()

    url = "https://www.virustotal.com/api/v3/files"

    files = {"file": (currentProgram, open(location, "rb"), "application/octet-stream")}

    headers = {
        "accept": "application/json",
        "x-apikey": "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a"
    }

    opener = urllib2.build_opener(urllib2.HTTPHandler())

    # Create a request object with POST method and data
    request = urllib2.Request(url, data=files)
    request.get_method = lambda: 'POST'

    request.add_header("accept", "application/json")
    request.add_header("x-apikey", "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a")

    # Send the request and get the response
    response = opener.open(request)

    print(response.read())


if __name__ == "__main__":
    main()
