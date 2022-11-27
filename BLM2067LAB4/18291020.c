
#include<stdio.h>
#include<stdlib.h>

int dimension_stack=6;
int uststack=0;
int *employees;
typedef struct customer_q{
    int finish;
    int in;
    int waiting;
    int out;
    int account_id;
    struct customer_q* after;
    int musteri_no;
}customerQ;
void push(int ident_employee){
    if(uststack >= dimension_stack){
        return;
    }
    else{
    employees[uststack]=ident_employee;
    uststack++;} 
}

int pop(){
    return employees[--uststack];
}
customerQ* head=NULL;
customerQ* temp=NULL;
customerQ* final = NULL;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bastir(int howmanyhours[]){
    temp = head;
    while(temp!=NULL){
        printf("%d %d ",temp->account_id,temp->musteri_no);
          printf("%d %d ",temp->in+temp->waiting,temp->in+temp->out+temp->waiting);
         printf("%d\n",temp->waiting);
        temp = temp->after;
    }
    printf("\n");
    int k=5;
    while(k>=0){
        printf("%d %d\n",k+1,howmanyhours[k]);
        k--;
    }
}
void enque(int cus_account_id,int customerinside,int customeroutside,int employee_identity,int waiting){
    if(head==NULL){
        head = (customerQ*)malloc(sizeof(customerQ));
        head->out = customeroutside;
        head->account_id = cus_account_id;
        head->after = NULL;
        head->in = customerinside;
        head->finish = 0;
        head->musteri_no = employee_identity;
        temp = head;
        final = head;
        head -> waiting = waiting;
        return;
    }
    final->after = (customerQ*)malloc(sizeof(customerQ));
    final = final->after;
    final->out = customeroutside;
    final->account_id = cus_account_id;
    final->finish = 0;
    final->in = customerinside;
    final->after = NULL;
    final->waiting = waiting;
    final->musteri_no = employee_identity;
}
 
void selectionSort(int array[], int size)
{
    int i, j, index_min;
 
   
    for (i = 0; i < size-1; i++)
    {
       
        index_min = i;
        for (j = i+1; j < size; j++)
          if (array[j] < array[index_min])
            index_min = j;
 

           if(index_min != i)
            swap(&array[index_min], &array[i]);
    }
}


int main(){
    int j=0;
    int cus_account_id;
    int kontrol=0;
    int howmanyhours[6] = {0,0,0,0,0,0};
    int priority[6] = {0,0,0,0,0,0};
    employees = (int*)malloc(sizeof(int)*dimension_stack);
    int counter=0;
    while(j<dimension_stack){
        push(j+1);
        j++;
    }
    int v_b=1;
    int ust1=0;
    int customerinside;
    int customeroutside;
    int ident_employee;
    int i=1;
    scanf("%d",&cus_account_id);
    scanf("%d",&customerinside);
    scanf("%d",&customeroutside);
    while(cus_account_id != -1){
        while( ust1 || customerinside == i){
        if(cus_account_id == -1){
            break;
        }
            if(uststack == 0){
                ust1 = 1;
                break;
            }
                ust1 = 0;
            
            enque(cus_account_id,customerinside,customeroutside,pop(),i-customerinside);
            howmanyhours[final->musteri_no-1] += customeroutside;
            scanf("%d",&cus_account_id);
            if(cus_account_id==-1){
                break;
            }
            scanf("%d",&customerinside);
            scanf("%d",&customeroutside);
        }
        while(v_b){
            while(((temp->finish == 1)|| (temp->in + temp->out) > i+1) && temp->after!= NULL){
                temp = temp->after;
            }
            if(((temp->in + temp->out) <= i+1)){
                temp->finish = 1;
                priority[counter] = temp->musteri_no;
                counter++;
                if(temp->after == NULL)
                    break;
                temp = temp ->after;
            }
            else{v_b = 0;}
        }
        selectionSort(priority,counter);
        int ctr1=0;
        while(ctr1<counter){
            push(priority[ctr1++]);
        }
        int z=0;
        while(z<6){
            priority[z++] = 0;
        }
        counter = 0;
        temp = head;
        i++;
        v_b=1;
    }
    bastir(howmanyhours);
    return 0;
}