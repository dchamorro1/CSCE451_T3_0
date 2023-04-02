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

    # requests = urllib2(Request(url))
    requests = urllib2.urlopen(url)

    # data = urllib.urlencode(headers)

    requests.add_header("accept", "application/json")
    requests.add_header("x-apikey", "6a90acebb6999746d1649a244d982d162cf87488440afc942d46a99abe4ee98a")

    requests.add_data(files)

    html = requests.read()
    print(html)


if __name__ == "__main__":
    main()
