def RepresentsInt(string):
    try: 
        int(string)
        return True
    except ValueError:
        return False

def RepresentsFloat(string):
    try:
        float(string)
        return True
    except ValueError:
        return False
