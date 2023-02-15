#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s;
    int nums[10] = {0};
    scanf("%s", s);
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 48 && s[i] <= 57){
            nums[s[i]]++;
        }
        i++;
    }
    
    for(int j = 0; j < 10; j++){
        printf("%d ", nums[j]);
    }
    return 0;
}
