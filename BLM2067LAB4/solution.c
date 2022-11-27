#include<stdio.h>
#include<stdlib.h>

int stktop=0,stksize=6;
int *calisanlar;
typedef struct mq{
    int hesapNo;
    int in;
    int out;
    int cId;
    int itsOver;
    int bekleme;
    struct mq* next;
}musterique;

musterique* root=NULL;
musterique* lastone = NULL;
musterique* iter=NULL;

int pop(){
    return calisanlar[--stktop];
}

void push(int idCalisan){
    if(stktop>=stksize){
        return;
    }
    calisanlar[stktop++]=idCalisan; 
}

void enque(int mushesapNo,int musin,int musout,int calisanId,int bekleme){
    if(root==NULL){
        root = (musterique*)malloc(sizeof(musterique));
        root->next = NULL;
        root->hesapNo = mushesapNo;
        root->in = musin;
        root->out = musout;
        root->cId = calisanId;
        root->itsOver = 0;
        root -> bekleme = bekleme;
        lastone = root;
        iter = root;
        return;
    }
    lastone->next = (musterique*)malloc(sizeof(musterique));
    lastone = lastone->next;
    lastone->hesapNo = mushesapNo;
    lastone->in = musin;
    lastone->out = musout;
    lastone->cId = calisanId;
    lastone->itsOver = 0;
    lastone->bekleme = bekleme;
    lastone->next = NULL;
}
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void print(int kimkacsaat[]){
    iter = root;
    while(iter!=NULL){
        printf("%d %d %d %d %d\n",iter->hesapNo,iter->cId,iter->in+iter->bekleme,iter->in+iter->out+iter->bekleme,iter->bekleme);
        iter = iter->next;
    }
    printf("\n");
    for(int i=5;i>=0;i--){
        printf("%d %d\n",i+1,kimkacsaat[i]);
    }
}
int main(){
    int oncelik[6] = {0};
    int sayac=0;
    calisanlar = (int*)malloc(sizeof(int)*stksize);
    for(int i=0;i<stksize;i++){
        push(i+1);
    }
    int mushesapNo,musin,musout,idCalisan,i=1,checkb=0,wb=1,bstktop=0;
    int kimkacsaat[6] = {0};
    scanf("%d%d%d",&mushesapNo,&musin,&musout);
    while(mushesapNo != -1){
        while(musin == i || bstktop){
            if(stktop == 0){
                bstktop = 1;
                break;
            }else{
                bstktop = 0;
            }
            enque(mushesapNo,musin,musout,pop(),i-musin);
            kimkacsaat[lastone->cId-1] += musout;
            scanf("%d",&mushesapNo);
            if(mushesapNo==-1){
                break;
            }
            scanf("%d%d",&musin,&musout);
        }
        if(mushesapNo == -1){
            break;
        }
        while(wb){
            while(iter->next!= NULL && ((iter->in + iter->out) > i+1 || (iter->itsOver == 1))){
                iter = iter->next;
            }
            if(((iter->in + iter->out) <= i+1)){
                iter->itsOver = 1;
                oncelik[sayac++] = iter->cId;
                if(iter->next == NULL)
                    break;
                iter = iter ->next;
            }else{
                wb = 0;
            }
        }
        bubbleSort(oncelik,sayac);
        for(int i=0;i<sayac;i++){
            push(oncelik[i]);
        }
        for(int i=0;i<6;i++){
            oncelik[i] = 0;
        }
        sayac = 0;
        wb=1;
        iter = root;
        i++;
    }
    print(kimkacsaat);
    return 0;
}