import re
import string
from collections import Counter


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def MultiplicationTable(v):

    for x in range(11):

        print(v, " * ", x,  " = ", (v*x))
        x = x + 1
    return 0

def DoubleValue(v):
    return v * 2

def SqaureValue(v):
    return v * v


    # displays the days item list and qauntity sold to user
def DisplayQuantityList():
   with open("items.txt") as List:                                   
        dict = Counter(line.split()[0] for line in List)             
        for i, q in dict.items():                                 
            print('   {:<14}: {:>3}'.format(i, q))      
       
   return
    # search for the number of time a single item was sold returns quantity
def	ItemSearch(v):                                      
      with open("items.txt") as List:
        dict = Counter(line.split()[0] for line in List)
        
        quantity = dict.get(v)                  
        if quantity is None:                    
            quantity = 0                                                                                           
        return quantity

    # creates .dat to be read/formated for display
def CreateHistogram():                            
    file = open("frequency.dat", mode='w')
    with open("items.txt") as List:                         
        dict = Counter(line.split()[0] for line in List)
        for i, j in dict.most_common():       
           file.write('{} {}\n'.format(i, j))
           
    file.close()
    return

def histogram(seq):

    counted = ()
    
    for k in sorted(counted):
        print(f'{"*"* counted[k] : <20} {k : ^15}')
    
    return 0




