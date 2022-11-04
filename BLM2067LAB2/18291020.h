struct nodeFB
{
    int id;
    int old;
    struct nodeFB *next;
};

struct nodeGS
{
    int id;
    struct nodeGS *next;
};

struct newNodeFB
{
    int id;
    int old;
    struct newNodeGS *next;
};

struct newNodeGS
{
    int id;
    struct newNodeFB *next;
};
void createFinalList(struct newNodeFB** head_fb, struct nodeFB* headFB, struct nodeGS* headGS)
{
    struct newNodeFB* fb= (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
 if((*head_fb) == NULL)
 {
     (*head_fb) = fb;
 }

 while(headGS != NULL || headFB != NULL)
 {
     struct newNodeGS* gs = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
     fb->old = headFB->old;
     fb->id = headFB->id;
     fb->next = gs;

     gs->id = headGS->id;
     fb= (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
     gs->next = fb;
     headGS = headGS->next;
     headFB = headFB->next;

 }

}
void printAll(struct newNodeFB *head_fb) {
    struct newNodeFB* temporary = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
    struct newNodeGS* temporaryGS = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
temporary = head_fb;
    while(temporary->next != NULL)
    {
        printf("%d %d\n",temporary->id,temporary->old);
        temporaryGS =temporary->next;
        printf("%d\n",temporaryGS->id);
        
        temporary=temporaryGS->next;
    }
}
void insertFB(struct nodeFB **head, int no, int old)
{
    struct nodeFB *yeni_nd = (struct nodeFB*)malloc(sizeof(struct nodeFB));
    struct nodeFB* temporary;
    if( (*head) == NULL)
    {
        yeni_nd->next = NULL;
        yeni_nd->old = old;
        yeni_nd->id = no;
        

        (*head) = yeni_nd; 
        return;
    }
    if((*head)->id > no) 
    {
        yeni_nd->next= (*head);
        yeni_nd->old = old;
        yeni_nd->id = no;

        (*head) = yeni_nd; 
        return;
    }

    temporary = (*head);
    
    while(temporary->next != NULL && temporary->next->id < no)
    {
        temporary = temporary->next;
    }
    yeni_nd->next = temporary ->next;
    temporary->next = yeni_nd;
    yeni_nd -> old = old;
    yeni_nd-> id = no;
    //return r ;

}
void printFB(struct nodeFB* head)
{
    while(head !=NULL)
    {
        printf("%d %d\n",head->id, head->old);
        head = head->next;
    }
    printf("\n");
}

void printGS(struct nodeGS* head)
{
    while(head !=NULL)
    {
        printf("%d\n",head->id);
        head = head->next;
    }
    printf("\n");
}

void insertGS(struct nodeGS**head, int no)
{
    struct nodeGS *yeni_nd = (struct nodeGS*)malloc(sizeof(struct nodeGS));
    if( (*head) == NULL)
    {
        yeni_nd->next = NULL;
        yeni_nd->id = no;

        (*head) = yeni_nd;
        return;
    }
    if((*head)->id < no) 
    {
        yeni_nd->next= (*head);
        yeni_nd->id = no;

        (*head) = yeni_nd;
        return;
    }
    else{
    struct nodeGS* temporary;
    temporary = (*head);
    while(temporary->next != NULL && temporary->next->id > no)
    {
        temporary = temporary->next;
    }
    yeni_nd->next = temporary ->next;
    temporary->next = yeni_nd;
    yeni_nd-> id = no;
    }


}





