
#include<stdio.h>
#include<stdlib.h>
struct tree{
    struct tree* right;
    int id;
    int grd;
    struct tree* left;
};

void printLevelOrder(struct tree* root,char character,int lvl,int pre){
    if (root != NULL){
        printLevelOrder(root->left,'l',lvl - 1,root->grd);
        printLevelOrder(root->right,'r',lvl - 1,root->grd);
    }


    if (lvl == 0 && root != NULL){
        if(pre == -1){
            printf("%d %d",root->id,root->grd);
        }
        
            if(character == 'r')
                printf("%d %d (%d R) ",root->id,root->grd,pre);
            else if(character == 'l')
                printf("%d %d (%d L) ",root->id,root->grd,pre);
        
        
    }   
    
}
int counterLevel(struct tree* root){
    if (root == NULL){
        return 0;
    }
    int rightmaxseviye = counterLevel(root->right) + 1;

    int leftmaxseviye = counterLevel(root->left) + 1;
    if (leftmaxseviye < rightmaxseviye)
        return rightmaxseviye;

    else
        return leftmaxseviye;
}
void showTree(struct tree* root){
    int i=0;
    int lvl = counterLevel(root);
    while( i < lvl){
        printLevelOrder(root,'N',i,-1);
        printf("\n");
        i++;
    }
}

void sort(struct tree *root){
    if(root== NULL){




        return;
    }
    sort(root->left);
    printf("%d %d\n",root->id,root->grd);
    sort(root->right);
}
struct tree * insert(struct tree* root,int grade,int studentNum){
    if(root == NULL){


        struct tree *head = (struct tree*)malloc(sizeof(struct tree));
        head->grd = grade;
        head->left = NULL;
        head->id = studentNum;
        head->right = NULL;
        return head;
    }


    if(root->grd < grade){
        root->right = insert(root->right,grade,studentNum);
        return root;
    }


    root->left = insert(root->left,grade,studentNum);
    return root;
}

int main(){
    int studentGrade;
    int studentNum;
    struct tree *head = NULL;
    scanf("%d%d",&studentNum,&studentGrade);
    while(studentNum != -1){
        head = insert(head,studentGrade,studentNum);
        scanf("%d%d",&studentNum,&studentGrade);
    }
    sort(head);
    printf("\n");
    showTree(head);


    return 0;
}