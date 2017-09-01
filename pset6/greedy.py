import cs50
def main():
    while True:
        print("O hai! How much change is owed?")
        f=cs50.get_float()
        if f<0:
            break
        sum=int(round(f*100))
        quarter=sum//25
        rem=sum%25
        dime=rem//10
        rem=rem%10
        nickel=rem//5
        rem=rem%5
        total=quarter+dime+nickel+rem
        print("{}".format(total))
if __name__ == "__main__":
    main()