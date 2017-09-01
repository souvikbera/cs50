import cs50
def main():
    while True:
        print("Height :",end="")
        h=cs50.get_int()
        if h<0 or h>23:
            break
        for i in range(h):
            for j in range(i+1,h):
                print(" ",end="")
            for k in range(2+i):
                print("#",end="")
            print("")
            
if __name__ == "__main__":
    main()