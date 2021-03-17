#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double avg (double vec[], long int length) {

    double sum = 0.0;

    for (int i=0; i < length; i++) {
        sum = sum + vec[i];
    }

    return sum/length; 
}

double var (double vec[], long int length, double avg) {
    
    double sum = 0.0;

    for (int i=0; i < length; i++) {
        sum = sum + pow(vec[i] - avg, 2);
    }

    return sum; 
}

double conv (double x[], double x_avg, double y[], double y_avg, long int length) {
    
    double sum = 0.0;

    for (int i=0; i < length; i++) {
        sum = sum + ((x[i] - x_avg) * (y[i] - y_avg));
    }

    return sum; 
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
            printf("%li %f %f\n", i, x_list[i], y_list[i]);
            free(x);
            free(y);
            i = i + 1;
        }

        double x_average = avg(x_list, N);
        double y_average = avg(y_list, N);
        double x_var = var(x_list, N, x_average);
        double y_var = var(x_list, N, y_average);
        double conv_x_y = conv(x_list, x_average, y_list, y_average, N);
        
        double ro = conv_x_y/sqrt(x_var * y_var);
        double beta = conv_x_y/x_var;
        double alfa = y_average - (beta * x_average);
        printf("%f %f %f\n", alfa, beta, ro);
    }

    fclose(fp);
}

