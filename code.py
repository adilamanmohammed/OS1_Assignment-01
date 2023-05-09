import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import scipy as sp

#declaration of required variables 
A=[]
M=[]
file = input_dir = 'file.csv'
P=0
n=10
p2=1
lamdaf=1

#reading files from file
df = pd.read_csv(file, usecols =['N','I','D'])

#logic
for i in range(len(df)):
    
    P = df.loc[i,"I"]
    M.append(df.loc[i,"I"])
    L = df.loc[i,'D']
    
    X=( (1-P)  *  (  (lamdaf  *  (n*(n+1)/2)   *  (p2+lamdaf) )  -  lamdaf ))/100
    A.append(X)


#printing output
print(df)
print("Results output:")

plt.plot(M, A)
  
# naming the x axis
plt.xlabel('Throughput')
# naming the y axis
plt.ylabel('Probability of Failure Transactions')
  
#title to graph
plt.title('Effect of Failure Transactions')
  
#showing the graph
plt.show()


plt.savefig("OUTPUT.pdf")