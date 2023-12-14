#Write a Python program that computes the net amount of a bank account based
#following: D 100 W 200 (Withdrawal is not allowed if balance is going negative.
#Write functions for withdraw and deposit) D means deposit while W means
#withdrawal. Suppose the following input is supplied to the program: D 300 D
#300 W 200 D 100 Then, the output should be: 500

bal=[]
net_amount=0

for i in range (0,5) :
        str=input("Enter Transaction : ")
        transaction= str.split()
        type=transaction[0]
        amount= int(transaction[1])
        if type=='d':
                net_amount = net_amount+amount
        if type=='w':
                net_amount = net_amount-amount
print("your bank balance is :",net_amount,"rs")
