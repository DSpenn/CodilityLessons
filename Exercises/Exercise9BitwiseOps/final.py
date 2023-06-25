https://app.codility.com/demo/results/trainingZ2UXNY-969/
https://app.codility.com/demo/results/trainingDEEGVV-8XT/
def solution(A, B, C):
    if (A == 0 or B == 0 or C == 0): 
        return 2 ** 30

#    bin(A)[2:].zfill(30)

    a = 0
    b = 0
    c = 0
    #aZero = zeroFind(A)
    #bZero = zeroFind(B)
    #cZero = zeroFind(C)
    #print('a:',a, 'b:',b, 'c:',c)
    
    AorB = A | B
    #print ('AorB:', AorB, '{0:b}'.format(AorB))
    AorC = A | C
    #print( 'AorC:', AorC, decimalToBinary(AorC))
    BorC = B | C
    #print('BorC:', BorC ,decimalToBinary(BorC))
    AorBorC = A | B | C
    #print('AorBorC:', AorBorC,decimalToBinary(AorBorC))
    #print('AorB:',AorB, oneFind(AorB),'AorC:', AorC, oneFind(AorC),'BorC:', BorC, oneFind(AorC),'AorBorC:', AorBorC, oneFind(AorBorC))

    nAorB = 0
    nAorC = 0
    nBorC = 0
    nAorBorC = 0
    #print('nAorB:',nAorB,'nAorC:', nAorC,'nBorC:', nBorC,'nAorBorC:', nAorBorC)

    for i in range(0, 30):
        if ((A >> i) & 1 == 0):
            print(A >> i)
            print ((A >> i) & 1)
            a += 1
        if (((B >> i) & 1) == 0):
            b += 1
        if (((C >> i) & 1) == 0):
            c += 1

        if ((AorB >> i) & 1 == 0):
            nAorB += 1
        if (((AorC >> i) & 1) == 0):
            nAorC += 1
        if (((BorC >> i) & 1) == 0):
            nBorC += 1

        if (((AorBorC >> i) & 1) == 0):
            nAorBorC += 1


    #print('a',a,'aZero:', aZero,'b:', b , bZero, c, cZero)
    #print("a:", a,  "b:", b, "c:", c, "nAorB:", nAorB, "nAorC:", nAorC, "nBorC:", nBorC, "nAorBorC:", nAorBorC)


    #result = a- nAorB - nAorC - nBorC + b + c + nAorBorC
    #result = a + b + c - nAorB - nAorBorC - nBorC + nAorBorC
    result = (1 << a) + (1 << b) + (1 << c) - (1 << nAorB) - (1 << nAorC) - (1 << nBorC) + (1 << nAorBorC)
    #print('result:', result)
    return result

def zeroFind(num):
    zeros = bin(num).replace("0b", "").count('0')
    #.zfill(30)???
    return zeros

def oneFind(num):
    return bin(num).replace("0b", "").count('1')

def decimalToBinary(n):
    return bin(n).replace("0b","")