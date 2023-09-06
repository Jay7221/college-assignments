with open("output.txt", "w") as outFile:
    with open("input.txt", "r") as inFile:
        for line in inFile:
            newLine = ""
            for ch in line.split():
                if ch != "":
                    newLine += ch + " "
            outFile.write(newLine + "\n")