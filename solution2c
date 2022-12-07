#include <stdio.h>
#include <stdlib.h>



void main(){
	int s1,s2;
	int y1,y2;
	int grup=0;
	int sayi=0;
	int temp=1;
	int deger=0;
	
	scanf("%d %d",&s1,&s2);
	
	int matrix[s1][s2];
	
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			matrix[i][j]=0;
		}
	}
	
	
	scanf("%d%d",&y1,&y2);
	while(y1!=-1){
		
		matrix[y1][y2]=1;
		scanf("%d%d",&y1,&y2);
		
	}
	
	
	/*printf("\n\nMatrix Yazdır 1\n\n");
	
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}*/
	
	
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			if(matrix[i][j]!=0 ){
				
			
				if(j!=s2-1 && matrix[i][j+1]!=0){
					    if(matrix[i][j]==1){
						matrix[i][j]=temp;
						matrix[i][j+1]=temp;
						temp=1;
					    }
					    else{
						matrix[i][j+1]=matrix[i][j];
					    }
				}	
				
				if(matrix[i][j]==1){
				    matrix[i][j]=temp;
				}
			
				
				if(i!=0 && j!=0 && matrix[i-1][j-1]!=0){
                    			matrix[i][j]=matrix[i-1][j-1];
				}
				if(i!=0 && j!=s2-1 && matrix[i-1][j+1]!=0){
                    			matrix[i][j]=matrix[i-1][j+1];
				}
				if(i!=0 && matrix[i-1][j]!=0){
                    			matrix[i][j]=matrix[i-1][j];
				}
				
				if(deger==0){
                    			temp=matrix[i][j]+1;
				}
				deger=0;
			}
		}
	}
	
	
	/*printf("Matrix Yazdır 2\n\n");
	
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");*/
	
	
    for(int i=0;i<10;i++){
        for(int a=0;a<s1;a++){
            for(int b=0;b<s2;b++){
                if(matrix[a][b]!=0){
			if(matrix[a-1][b]!=0 && matrix[a][b]!=matrix[a-1][b] && a!=0){
		                if(matrix[a-1][b]<matrix[a][b]){
		                    matrix[a][b]=matrix[a-1][b];
		                }
		                else{
		                    matrix[a-1][b]=matrix[a][b];
		                }
                   	 }
                
                
                	if(matrix[a-1][b+1]!=0 && matrix[a][b]!=matrix[a-1][b+1] && a!=0 && b!=s2-1){
		                if(matrix[a-1][b+1]<matrix[a][b]){
		                    matrix[a][b]=matrix[a-1][b+1];
		                }
		                else{
		                    matrix[a-1][b+1]=matrix[a][b];
		                }
                  	  }
                
    		 	if(matrix[a][b+1]!=0 && matrix[a][b+1]!=matrix[a][b] && b!=s2-1){
                        	if(matrix[a][b]<matrix[a][b+1]){
                        	    matrix[a][b+1]=matrix[a][b];
                        	}

                   	 }
                    
           	 	
    		 	if(matrix[a+1][b+1]!=0 && matrix[a][b]!=matrix[a+1][b+1] && a!=s1-1 && b!=s2-1){
		                if(matrix[a+1][b+1]<matrix[a][b]){
		                    matrix[a][b]=matrix[a+1][b+1];
		                }
		                else{
		                    matrix[a+1][b+1]=matrix[a][b];
		                }
                   	 }

                }
            }
        }
	}
	
	
	
	int m=1;
	int n=0;
	int flag=0;
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
		    if(m<matrix[i][j]){
		        m=matrix[i][j];
		    }
		}
	}
	int newArr[m];
	for(deger=1;deger<m+1;deger++){
        	for(int i=0;i<s1;i++){
		    for(int j=0;j<s2;j++){
		            if(matrix[i][j]==deger){
		                n+=1;
		            }
		    }
        }
        newArr[deger-1]=n;
        n=0;
	}
	for(int j=0;j<deger;j++){
		for(int i=0;i<deger-2;i++){
		    if(newArr[i]>newArr[i+1]){
		        flag=newArr[i];
		        newArr[i]=newArr[i+1];
		        newArr[i+1]=flag;
		    }
		}
	}
	for(int i=0;i<deger-1;i++){
            if(newArr[i]==0){
                m=m-1;
            }
	}
	printf("%d ",m);
	for(int i=0;i<deger-1;i++){
            if(newArr[i]!=0){
                printf("%d ",newArr[i]);
            }
	}
	printf("\n");
	/*for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}*/



}
