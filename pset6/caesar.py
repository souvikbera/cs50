import sys
import cs50

def main():
    if (len(sys.argv)!=2):
        print("error")
        exit(1)
        
    k=int(sys.argv[1])
    k=k%26
    print("plaintext:",end="")
    c=cs50.get_string()
    print("ciphertext:",end="")
    l=len(c)
    for i in range(l):
        b=ord(c[i])
        if(b>=65 and b<=90):
            if(b+k>90):
                b=b+k-26
            else:
                b=b+k
        elif(b>=97 and b<=122):
            if(b+k>122):
                b=b+k-26
            else:
                b=b+k
        print("{}".format(chr(b)),end="")
    print("")
    exit(0)
            
if __name__ == "__main__":
    main()
        

    
    
    
        
            
        