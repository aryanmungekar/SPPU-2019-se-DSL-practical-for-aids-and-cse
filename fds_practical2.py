#Write a Python program to store marks scored in subject “Fundamental of Data
#Structure” by N students in the class. Write functions to compute following:
#a) The average score of class
#b) Highest score and lowest score of class
#c) Count of students who were absent for the test
#d) Display mark with highest frequency




data=[]
n=int(input("Enter number of elements: "))
for i in range(0,n):
 ele=int(input("Elements: "))
 data.append(ele)
 
max=data[0]
min=data[0]
for i in range(0,n):
 if data[i]>max:
  max=data[i]


 if data [i]<min:
  min=data[i]
print("Maximum marks: ",max)
print("Minimum marks: ",min)


sum=0
for i in range (0,n):
 sum=sum+data[i]
avg=sum/n
print("Average: ",avg) 

count=0
for i in range(0,n):
 if data[i]==-1:
  count=+1
print("Absent students: ",count)    
   
fcount=0
for i in range (0,n):
 count=0
 for j in range (0,n):
    if data[i]==data[j]:
       count+=count+1
       if fcount<count:
        fcount=count
        most=data[i]
print("Most marks obtained: ",fcount)