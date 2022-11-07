
struct nodeStudent
{
	int std;
	int arasinav;
	struct nodeStudent *after;
};

struct nodeClass
{
	int cls_number;
	double cls_avg;
	struct nodeClass *after;
	struct nodeStudent *stdpointer;
};


void printAll(struct nodeClass* initial) {
	struct nodeStudent* tmpstd;
	while (initial != NULL) {
        printf("%d %.2f\n", initial->cls_number, initial->cls_avg);


		tmpstd = initial->stdpointer;


		while (tmpstd != NULL){
			printf("%d %d\n", tmpstd->std, tmpstd->arasinav);
			tmpstd = tmpstd->after;
		}
        initial = initial->after; 
    }



}
void add_node(struct nodeClass* sinif, int clss_no) {
  struct nodeClass* yeni_nd = NULL;

  yeni_nd = (struct nodeClass*)malloc(sizeof(struct nodeClass));
  sinif->after = yeni_nd;

  yeni_nd->cls_number = clss_no;
}
void insert(struct nodeClass** initial, int number, int arasinav) {
    int class;
	struct nodeStudent* newstudent = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	newstudent->arasinav = arasinav;



	if (*initial == NULL)
	{
        for (int j = 2; j < 5; j++)
		{
			struct nodeClass* dugum = (struct nodeClass*)malloc(sizeof(struct nodeClass));

            dugum->cls_number = j;
     
           
		}
		struct nodeClass* yeni_nd = (struct nodeClass*) malloc(sizeof(struct nodeClass));


		struct nodeClass* temporary;


		yeni_nd->cls_number = 1;


		*initial = yeni_nd;
		temporary = *initial;

		for (int j = 2; j < 5; j++)
		{
			struct nodeClass* yeni_nd = (struct nodeClass*)malloc(sizeof(struct nodeClass));
            yeni_nd->cls_number = j;
     
            temporary->after = yeni_nd;
            temporary = temporary->after;
		}
	}
	newstudent->std = number;

	struct nodeClass* whichcls;

	struct nodeStudent* tmpstd;

	whichcls = *initial;
    while(number > 10){


        number /=10;

    }
    if(number == 6){class = 1;}
    else if(number == 7){class = 2;}
    else if(number == 8){class = 3;}
    else{class =4;}
	for (int i = 1; i < class; i++){
		whichcls = whichcls->after;
	}
	

	if (whichcls->stdpointer == NULL || whichcls->stdpointer->arasinav <= newstudent->arasinav) {

		newstudent->after = whichcls->stdpointer;  
    	whichcls->stdpointer = newstudent; 
    } 
    
    
    else{
    	tmpstd = whichcls->stdpointer; 
    	while (tmpstd->after != NULL && tmpstd->after->arasinav > newstudent->arasinav){ 
    	    tmpstd = tmpstd->after; 
    	} 
    	newstudent->after = tmpstd->after; 
    	tmpstd->after = newstudent; 
    }
	
}

void computeClassAverage(struct nodeClass* initial) {
	struct nodeStudent* tmpstd;
    double addition=0;
	while (initial != NULL) {
        for(int k=0;k<4;k++){
            addition += initial->stdpointer->arasinav;

        }

		tmpstd = initial->stdpointer;
		int stdctr = 0;
		addition = 0;
		while (tmpstd != NULL){
			addition += tmpstd->arasinav;
			tmpstd = tmpstd->after;
			stdctr +=1;
		}
		initial->cls_avg = addition / stdctr;
        initial = initial->after; 
    } 
}


