#include<stdio.h>
#define MAX_SIZE 50 

typedef int ElemType;

typedef struct{
	ElemType data[MAX_SIZE];
	int length;
}SqList;

void InitList(SqList &L){
	L.length = 0;
	for(int i=0;i<MAX_SIZE;i++){
		L.data[i] = 0;
	}
}

bool Empty(SqList L){
	return L.length==0;
}

bool ListInsert(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1) return false;
	for(int j=L.length;j>=i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
	
}

bool ListDelete(SqList &L,int i){
	if(i<1||i>L.length) return false;
	for(int j=i;j<=L.length;j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

ElemType GetElem(SqList L,int i){
	return L.data[i-1];
}

int LocateElem(SqList L,ElemType e){
	if(Empty(L)) return -1;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]==e){
			return i+1;
		}
	}
	return -1;
}


void PrintList(SqList L){
	if(Empty(L)) printf("NULL");
	for(int i=0;i<L.length;i++){
		printf("|%d| ",L.data[i]);
	}
	printf("\n");
}


void DestoryList(SqList L){}

int main(){
	SqList L;
	InitList(L);
	PrintList(L);
	ListInsert(L,1,5);
	ListInsert(L,2,6);
	ListInsert(L,3,7);
	ListInsert(L,4,9);
	PrintList(L);
	printf("The %dth element is %d.\n",2,GetElem(L,2));
	printf("The element %d is in the %dth place.\n",7,LocateElem(L,7));
	ListDelete(L,2);
	PrintList(L);
	return 0;
}
