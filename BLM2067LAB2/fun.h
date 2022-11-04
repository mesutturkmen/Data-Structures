struct nodeFB
{
	int id;
	int age;
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
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

typedef struct nodeFB nodeFB;
typedef struct nodeGS nodeGS;
typedef struct newNodeFB newNodeFB;
typedef struct newNodeGS newNodeGS;


void insertFB(nodeFB **r,int kimlik,int yas){
	nodeFB *root;
	root = *r;
	if(root == NULL){
		root = (nodeFB*)malloc(sizeof(nodeFB));
		root -> next = NULL;
		root -> id = kimlik;
		root -> age = yas;
		*r = root;
		return;
	}
	if(root-> id > kimlik){
		nodeFB* temp = (nodeFB*)malloc(sizeof(nodeFB));
		temp -> id = kimlik;
		temp -> age = yas;
		temp -> next = root;
		*r = temp;
		return;
	}
	nodeFB * iter = root;
	while(iter -> next != NULL && iter->next->id < kimlik){
		iter = iter -> next;
	}
	nodeFB* temp = (nodeFB*)malloc(sizeof(nodeFB));
	temp -> id = kimlik;
	temp -> age = yas;
	temp -> next = iter->next;
	iter->next = temp;

}

void insertGS(struct nodeGS **r,int kimlik){
	nodeGS *root;
	root = *r;
	if(root == NULL){
		root = (nodeGS*)malloc(sizeof(nodeGS));
		root -> next = NULL;
		root -> id = kimlik;
		*r = root;
		return;
	}
	if(root-> id < kimlik){
		nodeGS* temp = (nodeGS*)malloc(sizeof(nodeGS));
		temp -> id = kimlik;
		temp -> next = root;
		*r = temp;
		return;
	}
	nodeGS * iter = root;
	while(iter -> next != NULL && iter->next->id > kimlik){
		iter = iter -> next;
	}
	nodeGS* temp = (nodeGS*)malloc(sizeof(nodeGS));
	temp -> id = kimlik;
	temp -> next = iter->next;
	iter->next = temp;

}

void printFB(nodeFB *root){
	nodeFB *gecici = root;
	while(gecici!=NULL){
		printf("%d %d\n",gecici->id,gecici->age);
		gecici = gecici-> next;
	}
	printf("\n");
}
void printGS(nodeGS *root){
	nodeGS *gecici = root;
	while(gecici!=NULL){
		printf("%d\n",gecici->id);
		gecici = gecici-> next;
	}
	printf("\n");
}
void createFinalList(newNodeFB **newR, nodeFB *rootFB, nodeGS *rootGS){
	newNodeFB *newRoot;
	newNodeGS *temp;
	nodeFB *iterFB = rootFB;
	nodeGS *iterGS = rootGS;
	newRoot = (newNodeFB*)malloc(sizeof(newNodeFB));
	newRoot -> id = iterFB ->id;
	newRoot -> age = iterFB ->age;
	iterFB = iterFB ->next;
	*newR = newRoot;
	while(iterFB!= NULL){
		newRoot -> next = (newNodeGS*)malloc(sizeof(newNodeGS));
		temp = newRoot -> next;
		temp -> id = iterGS -> id;
		iterGS = iterGS -> next;
		temp -> next = (newNodeFB*)malloc(sizeof(newNodeFB));
		newRoot = temp->next;
		newRoot -> id = iterFB -> id;
		newRoot -> age = iterFB ->age;
		iterFB = iterFB -> next;
	}
	newRoot->next = (newNodeGS*)malloc(sizeof(newNodeGS));
	temp = newRoot -> next;
	temp -> id = iterGS -> id;
	temp ->next = NULL;
}
void printAll(newNodeFB *newRoot){
	newNodeFB *newIterFB;
	newNodeGS *newIterGS;
	newIterFB = newRoot;
	while(newIterFB != NULL){
		printf("%d %d\n",newIterFB->id,newIterFB->age);
		newIterGS = newIterFB -> next;
		printf("%d\n",newIterGS->id);
		newIterFB = newIterGS->next;
	}
}
// Bu lab kapsaminda kullanilacak butun fonksiyon tanimlarini bu dosyanin icine yazmaniz gerekmektedir.
// Tanimlanmasi zorunlu fonksiyonlar icerisinden kendi tanimayacaginiz baska fonksiyonlari cagirabilirsiniz.
// main.c dosyasinda bir degisiklik yapmayiniz.
// Sisteme function.h dosyasinin ismini OgrenciNumarasi.h olarak yukleyiniz.


