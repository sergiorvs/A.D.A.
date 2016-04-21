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

void build_max_heap(int* a,int tam)
{
    for(int i=(tam/2);i>=0;i--)
    {
        max_heapify(a,i,tam);
    }
}

void heap_sort(int *a,int tam)
{
    int heap_size=tam;
    build_max_heap(a,tam);
    for(int i=tam-1;i>=1;i--)
    {
        int aux=a[0];
        a[0]=a[i];
        a[i]=aux;
        heap_size--;
        max_heapify(a,0,heap_size);
    }
}


int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    heap_sort(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<", ";
    }
    return 0;
}
