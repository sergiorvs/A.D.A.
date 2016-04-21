#include <iostream>

using namespace std;

int padre(int i){return i/2;}
int izq_hijo(int i){return (2*i)+1;}
int der_hijo(int i){return (2*i)+2;}

void max_heapify(int* a,int i,int tam_heap)
{
    int l=izq_hijo(i);
    int r=der_hijo(i);
    int largest;
    if(l<tam_heap && a[l]>a[i])
    {
        largest=l;
    }else{largest=i;}
    if(r<tam_heap and a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int aux=a[i];
        a[i]=a[largest];
        a[largest]=aux;
        max_heapify(a,largest,tam_heap);
    }
}

int heap_extract_max(int* a,int size)
{
    if(size<0)
    {
        cout<<"ERROR!! heap underflow"<<endl;
    }
    int max=a[0];
    a[0]=a[size];
    size--;
    max_heapify(a,0,size);
    return max;
}

void heap_increse_key(int* a,int i,int key)
{
    if(key<a[i]){cout<<"ERROR!!! new key is smaller tahn current key"<<endl;}
    a[i]=key;
    while(i>0 && a[padre(i)]<a[i])
    {
        int tmp=a[i];
        a[i]=a[padre(i)];
        a[padre(i)]=tmp;
        i=padre(i);
    }
}

void max_heap_insert(int*a,int key,int size)
{
    size++;
    a[size]=-99999;
    heap_increse_key(a,size,key);
}


