#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int no;
    int not;
    struct t* left;
    struct t* right;
}tree;

tree* add(tree* n,int ogrencino,int notu){
    if(n == NULL){
        tree *root = (tree*)malloc(sizeof(tree));
        root->left = NULL;
        root->right = NULL;
        root->no = ogrencino;
        root->not = notu;
        return root;
    }
    if(n->not > notu){
        n->left = add(n->left,ogrencino,notu);
        return n;
    }
    n->right = add(n->right,ogrencino,notu);
    return n;
}
void notsirala(struct t* n){
    if(n == NULL){
        return;
    }
    notsirala(n->left);
    printf("%d %d\n",n->no,n->not);
    notsirala(n->right);
}
int levelSayac(tree* n){
    if (n == NULL){
        return 0;
    }
    int lmaxLvl = 1 + levelSayac(n->left);
    int rmaxLvl = 1 + levelSayac(n->right);
    if (lmaxLvl > rmaxLvl)
        return lmaxLvl;
    else
        return rmaxLvl;
}
void levelPrinter(tree* n,int before,int level,char way){
    if (n != NULL && level == 0){
        if(before == -1){
            printf("%d %d",n->no,n->not);
        }
        else{
            if(way == 'l')
                printf("%d %d (%d L) ",n->no,n->not,before);
            else if(way == 'r')
                printf("%d %d (%d R) ",n->no,n->not,before);
        }
        
    }   
    else if (n != NULL){
        levelPrinter(n->left,n->not,level - 1,'l');
        levelPrinter(n->right,n->not,level - 1,'r');
    }
    
}
void treeprint(tree* n){
    int level = levelSayac(n);
    for (int i = 0; i < level; i++){
        levelPrinter(n,-1,i,'n');
        printf("\n");
    }
}

int main(){
    tree* root = NULL;
    int ogrencinotu,ogrencino;
    scanf("%d%d",&ogrencino,&ogrencinotu);
    while(ogrencino != -1){
        root = add(root,ogrencino,ogrencinotu);
        scanf("%d%d",&ogrencino,&ogrencinotu);
    }
    notsirala(root);
    printf("\n");
    treeprint(root);


    return 0;
}