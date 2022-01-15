#include <iostream>
#include <string.h>
#include <stdexcept>
/*
    templating allows us to simply insert our arguments and create class or function when used. thus allowing us to creat
    a dynamic typed array
*/
template<typename T, size_t S>
class Array
{
    public:
        int index;
        Array();
        void push(T &value);
        void pop();
        void insert(T &value, size_t index);
        void remove(size_t index);
        void quickSort(int low, int high);
        int partition( int low, int high);
    public:
        /* constexpr makes this function available at compile time. if abesent would not be 
        able to use function at compile time ex -> Array<int, data.size()> we are setting another
        array to same size as data */ 
        constexpr size_t size() const { return S; }

        /* this function overloads the [](index) operator with our own in this case it returns
        a refence to the object of whatever type. in other words this replaces a get function
        that would take in the index as parameter*/
        T& operator[](size_t index) { 
                if(index<this->size()){
                    return m_Data[index]; 
                }else{
                    throw std::invalid_argument("Error out of bounds");
                }
            }
        const T& operator[](size_t index) const { 
                if(index<this->size()){
                    return m_Data[index]; 
                }else{
                    throw std::invalid_argument("Error out of bounds");
                }
            }
        /* this function simply returns a pointer to the data. same as doing &ex[0] which is address of 
        first item */
        T* Data() { return m_Data; }
        const T* Data() const { return m_Data; }

    private:
        T m_Data[S];
};

template<typename T, size_t S>
Array<T,S>::Array()
{
    this->index = 0;

    if (std::is_same<T,int>::value){
        memset(this->Data(),0,this->size()*sizeof(int));
    }
}
/*pushes an element to array*/
template<typename T, size_t S>
void Array<T,S>::push(T &value){
    this->index >= this->size()?
    throw std::invalid_argument("Cannot add more elements")
    :this->m_Data[this->index++] = value;
}
/*deletes last element in array*/
template<typename T, size_t S>
void Array<T,S>::pop(){
    this->index==0?
    throw std::invalid_argument("Cannot remove more elements")
    :this->index--;
}

/*
inserts an element into index if available, if not then 
it moves all elements to the right over if possible to then
insert element
*/
template<typename T, size_t S>
void Array<T,S>::insert(T &value, size_t index){
    if (index> this->index){
        throw std::invalid_argument("index out of range");
    }else if(index==this->index){
        this->m_Data[this->index++] = value;
    }else{
        int count = this->index;
        while(count>index){
            std::swap(this->m_Data[count],this->m_Data[(count-1)]);
            count--;
        }
        this->m_Data[count] = value;
        this->index++;
    }
}
/*
removes an item at a specific index
*/
template<typename T, size_t S>
void Array<T,S>::remove(size_t index){
    if (index>= this->index){
        throw std::invalid_argument("index out of range");
    }else{
        while(index<this->index){
            std::swap(this->m_Data[index],this->m_Data[(index+1)]);
            index++;
        }
        this->index--;
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<typename T, size_t S>
int Array<T,S>::partition( int low, int high){
    T pivot = this->m_Data[high]; //pivot point is the last element
    int i = (low - 1); //Index of smaller element

    for (int j = low; j <= high - 1; j++){

        //if current element is smaller than or equal to pivot
        if (this->m_Data[j] <= pivot)
        {
            i++;// increment index of smaller element
            std::swap(this->m_Data[i],this->m_Data[j]);
        }
    }
    std::swap(this->m_Data[i+1],this->m_Data[high]);
    return (i + 1);

}

/* The main function that implements QuickSort
  low  --> Starting index,
  high  --> Ending index */
template<typename T, size_t S>
void Array<T,S>::quickSort( int low, int high){
    if (low < high)
    {
            /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = this->partition(low, high);
        
        this->quickSort(low, pi-1);
        this->quickSort(pi+1, high);
    }

}

int main ()
{

    Array<std::string, 5> x;
    std::string test = "ahey";
    std::string test2 = "beye";
    std::string test3 = "guy";
    std::string test4 = "hgello";
    x.push(test);
    x.push(test4);
    x.push(test2);
    x.push(test3);
    x.quickSort(0,(x.index-1));
    Array<int,5> y;
    int num1 = 0;
    int num2 = 3;
    int num3 = 13;
    int num4 = 3;
    y.push(num1);
    y.push(num2);
    y.push(num3);
    y.push(num4);
    y.push(num1);
    y.quickSort(0,(y.index-1));
    for( size_t i = 0; i < x.index; i++)
        {
            std::cout<< x[i] << " " << x.index <<std::endl;
        }
/*
*/
    //std::cin.get();
}