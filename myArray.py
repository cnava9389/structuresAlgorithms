import numpy as np

class myArray(object):
    def __init__(self,head=0,values=[],size=10):
        self.size = size
        self.values = values
        self.head = head
        if values==None or len(values)<1:
            self.obj = np.empty(size,dtype=object)
        else:
            self.obj = np.array(values)
            self.size = len(self.obj)
            self.head=self.size
        
    def __str__(self):
        return f"{self.obj[:self.head]}"
    
    def copyTo(self, otherArray, sorted=False):
        #this will return new array with values from both arrays
        arr= myArray(size=self.size+otherArray.size)
        if not sorted:
            for i in range(self.head):
                arr.obj[arr.head]=self.obj[i]
                arr.head+=1
            for i in range(otherArray.head):
                arr.obj[arr.head]=otherArray.obj[i]
                arr.head+=1
            return arr
        
    def increase(self, percent=.75):
        #new arr with new increase based on percentage
        otherSize = int(self.size*percent)
        arr = myArray(size=otherSize)
        return arr.copyTo(self)   
    
    #!find a better way for this 
    def decrease(self,percent=0):
        newSize= int(self.size - (self.size*percent))
        if (newSize)>=(self.head):
            arr = myArray(size=(self.size-newSize))
            return arr.copyTo(self)
        else:
            arr = myArray(size=self.head)
            return arr.copyTo(self)
    
    def add(self, item):
        if(self.size==self.head):
            self=self.increase()
            self.head+=1
            self.obj[self.head]

def main():
    x=myArray(values=[1,2,3,4])
    print(x.size)
    x= x.decrease()
    print(x.size)
   

if __name__ == '__main__':
    main()
