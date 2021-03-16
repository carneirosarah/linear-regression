#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double avg (double arg[], long int length) {
    
    printf("%li\n", length);
    double sum = 0.0;

    for (int i=0; i < length; i++) {
        sum = sum + arg[i];
    }

    return sum/length; 
}

int main () {

    // read instance
    FILE *fp;
    char buff[255];
    long int N = pow(2, 16);
    double x_list[N], y_list[N];
    int split;
    long int i = 0;

    fp = fopen("linear.txt", "r");
    
    if (fp != NULL) {
        
        while (fgets(buff, 255, (FILE*)fp))
        {
            split = strcspn(buff, " ");
            char * x = malloc(split+1);
            char * y = malloc(strlen(buff)-split);
            strncpy (x, buff, split);
            strncpy(y, buff+5, strlen(buff));
            x_list[i] = atof(x);
            y_list[i] = atof(y);
            //printf("%li %f %f\n", i, x_list[i], y_list[i]);
            free(x);
            free(y);
            i = i + 1;
        }

        double x_average = avg(x_list, N);
        double y_average = avg(y_list, N);
        printf("%f %f\n", x_average, y_average);
    }

    fclose(fp);
}

