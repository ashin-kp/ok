#include<stdio.h>
int main() {
    int n,n1,n2;
    printf("enter the size of universal set:");
    scanf("%d",&n);
    int U[n];           //creates a array for storing universal set
    printf("enter the elements of universal set:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&U[i]);
    }

    printf("enter the size of set1");
    scanf("%d",&n1);
    int set1[n1];
    printf("enter the elements of set1:");
    for(int i=0;i<n;i++) {
        scanf("%d",&set1[i]);
    }

    printf("enter the size of set2");
    scanf("%d",&n2);
    int set2[n2];
    printf("enter the elements of set2");
    for(int i=0;i<n2;i++) {
        scanf("%d",&set2[i]);
    }

    //create bit vectors
    int s1[n],s2[n];
    for(int i=0;i<n;i++) {
        s1[i] = 0;
        s2[i] = 0;
        for(int j=0;i<n1;j++) {
            if( U[i] == set1[j] ){
                s1[i] = 1;
                break;
            }
        }
        for(int j=0;j<n2;j++) {
            if ( U[i] == set2[j]) {
                s2[i] = 1;
                break;
            }
        }
    }

    int Union[n];
    int intersection[n];

    for(int i=0;i<n;i++) {
        Union[i] = (s1[i] || s2[i]);
        intersection[i] = (s1[i] && s2[i]);
    }
    printf("bit vectors of set 1:");
    for(int i=0;i<n;i++) {
        printf("%d",s1[i]);
    }
    printf("bit vectors of set 2:");
    for(int i=0;i<n;i++) {
        printf("%d",s2[i]);
    }
    printf("union (s1 U s1):");
    for(int i=0;i<n;i++)
        printf("%d" ,Union[i]);
    printf("intersection (s1  s1):");
    for(int i=0;i<n;i++)
        printf("%d" ,intersection[i]);
    return 0;
}