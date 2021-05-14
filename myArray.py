import numpy as np
class xtraArray():
    def __init__(self):
        pass
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
    
    def copyToNewArray(self, otherArray, sorted=False):
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
        

    
    def add(self, item):
        if(self.size==self.head):
            self=self.increase()
            self.head+=1
            self.obj[self.head]


def main():
    x=myArray(values=[1,2,3,4])
    y = myArray(values=[7,8,9])


if __name__ == '__main__':
    main()
