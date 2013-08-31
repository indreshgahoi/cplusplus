

#author - Indresh

#!/usr/bin/python
def balancedsmileys():
    f = open("BalancedSmileys.txt","r")
    o = open("BalancedSmileys.out","w")

    T = int(f.readline())
    for i in range(1,T+1):
        st = f.readline()
        prev,smiley,frowny,par = '',0,0,0
        flag = 1
        for ch in st:
            if ch == '(':
                if prev == ':':
                    frowny += 1
                else : par += 1
            elif ch == ')':
                if prev == ':': smiley += 1

                if par : par -= 1
                elif frowny: frowny -= 1
                elif smiley: smiley -= 1
                else :
                    flag = 0
                    break
            prev = ch

        if flag and not par:
            op =  "Case #"+str(i)+": YES\n"
        else :
            op = "Case #"+str(i)+": NO\n"
        o.write(op)

    f.close()
    o.close()


if __name__ == '__main__':
    balancedsmileys()
