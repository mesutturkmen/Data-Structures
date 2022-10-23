#include <stdio.h>
#include <stdlib.h>

int main(){
	int row,column;
    int i,j,a,b,e,f;
    int c=0,l=0;
    int gecici;
    int r=0,flag =0;
    
	scanf("%d",&row);
    scanf("%d",&column);
    int dizi[row][column];
	 for(i=0;i<row;i++){
		for(j=0;j<column;j++){
	 		dizi[i][j]=0;
	    }
	}
	scanf("%d",&a);
    for(i=0;i<50;i++){
        scanf("%d",&b);
		dizi[a][b]=1;
		scanf("%d",&a);
        if(a==-1){
            break;
        }
    }

	int sayi=1;
	for(e=0;e<row;e++){
		for(f=0;f<column;f++){
			if(dizi[e][f]!=0 ){

				if(dizi[e][f+1]!=0 && f!=column-1){
                    if(dizi[e][f]!=1){
                        dizi[e][f+1]=dizi[e][f];
                    }
                    c=1;
                    dizi[e][f+1]=sayi;
                    dizi[e][f]=sayi;
                    
				}
                if(dizi[e][f]==1){
                    dizi[e][f]=sayi;
                }
				if(dizi[e-1][f+1]!=0 && f!=column-1 && e!=0 ){
                    dizi[e][f]=dizi[e-1][f+1];
				}

				if(dizi[e-1][f-1]!=0 && e!=0 && f!=0){
                    dizi[e][f]=dizi[e-1][f-1];
				}
                if(dizi[e][f]==-1){
                    if(c==0){
                        column=row+1;
                    }
                }
                if(dizi[e-1][f]!=0 && e!=0){
                    dizi[e][f]=dizi[e-1][f];
				}
				if(c==0){
                    sayi=dizi[e][f]+1;
				}
				c=0;
			}
		}
	}
    //traverseArray();
    for(i=5;i<22;i++){
        for(a=0;a<row;a++){
            for(b=0;b<column;b++){
                if(dizi[a][b]!=0){
                    if(b!=column-1 && dizi[a][b]!=dizi[a][b+1] && dizi[a][b+1]!=0 ){
                        if(dizi[a][b]<dizi[a][b+1]){
                            dizi[a][b+1]=dizi[a][b];
                        }


                    }
                    if( a!=0 && dizi[a][b]!=dizi[a-1][b] && dizi[a-1][b]!=0){
                        if(dizi[a-1][b]>=dizi[a][b]){
                            dizi[a-1][b]=dizi[a][b];
                        }
                        
                        dizi[a][b]=dizi[a-1][b];
                        
                    }
                    if(dizi[a][b]!=dizi[a-1][b+1] && dizi[a-1][b+1]!=0 && b!=column-1 && a!=0){
                        if(dizi[a-1][b+1]>=dizi[a][b]){
                            dizi[a-1][b+1]=dizi[a][b];
                        }
                        
                        dizi[a][b]=dizi[a-1][b+1];
                    
                        
                    }
                    if(dizi[a+1][b+1]!=0 && b!=column-1  && a!=row-1 && dizi[a][b]!=dizi[a+1][b+1] ){
                        if(dizi[a+1][b+1]>=dizi[a][b]){
                            dizi[a+1][b+1]=dizi[a][b];
                        }
                        
                            dizi[a][b]=dizi[a+1][b+1];
                        
                    }

                }
            }
        }
	}
    
	int biggest=1;
    //findBiggest();
    i=0;
	 while(i<row){
	 	for(j=0;j<column;j++){
            if(biggest<dizi[i][j]){
                 biggest=dizi[i][j];
             }
	 	}
        i++;
	 }
	int sonuc[biggest];
    c=1;
	while(c<biggest+1){
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                    if(dizi[i][j]==c){
                        r+=1;
                    }
            }
        }
        sonuc[c-1]=r;
        r=0;
        c++;
	}
    j=0;
	while(j<c){
        for(i=0;i<c-2;i++){
            if(sonuc[i]>sonuc[i+1]){
                gecici=sonuc[i];
                sonuc[i]=sonuc[i+1];
                sonuc[i+1]=gecici;
            }
        }j++;
	}
    i=0;
	while(i<c-1){
        
        if(sonuc[i]==0){
            biggest=biggestcle-1;
        }
        i++;
          
	}
	printf("%d ",biggest);
    i=0;
	while(i<c-1){
        
        if(sonuc[i]!=0 && i!=c-2){
            printf("%d ",sonuc[i]);
        }
        else if(sonuc[i]!=0 && i==c-2){
            printf("%d",sonuc[i]);

        }
    i++;
	}
   printf("\n");
    
}
void traverseArray(int array[][50],int row,int column,int flag){
    for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(array[i][j]!=0){
                flag+=1;

            }
		}
	}

}
void diziOlustur(row,column){
    int i,j;
    int dizi[i][j];
    for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			dizi[i][j]=0;
		}
	}
    
}
void findBiggest(int dizii){
    int i,j,biggest,dizi[40][50],column,row;
    for(i=0;i<row;i++){
		for(j=0;j<column;j++){
            if(biggest<dizi[i][j]){
                biggest=dizi[i][j];
            }
		}
	}
}