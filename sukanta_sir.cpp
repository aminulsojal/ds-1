#include<stdio.h>
#include<stdlib.h>


#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
	if(listMaxSize == 0){
        initializeList();
	}
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;

	return SUCCESS_VALUE ;
}


int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position >= length ) return NULL_VALUE;
	list[position] = list[length-1] ;
	length-- ;
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;
}
int addLength()
{
    return length;
}

int insertItemAt(int position,int item)
{

    if(length == listMaxSize){
        listMaxSize = listMaxSize*2;
        int *templist,i;
        templist = (int*)malloc((listMaxSize)*sizeof(int));
        for(i = 0; i < length; i++){
            templist[i]= list[i];
        }
        free(list);
        list = templist;
    }
    if(position >= length) return NULL_VALUE;
    if(position < length){
        list[length] = list[position];
        list[position] = item;
        length++;
        return SUCCESS_VALUE;
    }
}

void shrink()
{
    if(length == listMaxSize/2 && listMaxSize != LIST_INIT_SIZE){
        listMaxSize = listMaxSize/2;
        list = (int*)malloc(sizeof(int)*listMaxSize) ;
    }
}

void deleteLast()
{
    length--;
    shrink();
}
void clear()
{

    length = 0;
    listMaxSize = 0;
    free(list);
}



void deleteAll()
{

    while(listMaxSize != LIST_INIT_SIZE) deleteLast();
    length = 0;
}

void postFix()
{
    char ara[100];
    printf("please enter the Expression : ");
    scanf("%s",ara);
    int i = 0,newitem,k,result;
    while(ara[i] != '\0')
    {
        if(ara[i] >= '0' && ara[i] <= '9'){
            k = ara[i]-48;
            insertItem(k);
        }
        else {
            if(ara[i] == '+')newitem = list[length-2]+list[length-1];
            if(ara[i] == '-')newitem = list[length-2]-list[length-1];
            if(ara[i] == '*')newitem = list[length-2]*list[length-1];
            if(ara[i] == '/')newitem = list[length-2]/list[length-1];
            deleteLast();
            deleteLast();
            insertItem(newitem);
        }
        i++;

    }
    result = list[length-1];
    deleteLast;
    printf("%d\n",result);



}


void printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}
/*
int main(void)
{

    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. (Add from homework). 5. Print. 6. exit.\n");
        printf("7. Get Length. 8. Insert Item At. 9. Clear.\n");
        printf("10. Delete Last. 11. Delete All.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
         else if(ch==7)
        {
            printf("%d\n",addLength());
        }
         else if(ch==8)
        {
            int item,position;
            scanf("%d %d", &position,&item);
            insertItemAt(position,item);
        }
         else if(ch==9)
        {
            clear();
        }
         else if(ch==10)
        {
            deleteLast();
        }
         else if(ch==11)
        {
            deleteAll();
        }

    }

}*/

 int main()
{
    int ch;
    initializeList();
    while(1){
        printf("1.Postfix. 2.Exit\n");
        scanf("%d",&ch);
        if(ch == 1)postFix();
        else if(ch == 2)break;
    }
}

