#include <vector>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>

// void disp(&arr){

// }

int main(){
    
    //number of steps
    int n = 5; 

    //variables 
    int sign_arr[n][n]; 
    double alpha[n][n]; 
    double gamma[n]; 
    double P[n][n]; 

    std::cout << "------------------------------------------------------\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "|                            EULER                   |\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "------------------------------------------------------\n";
   // output_to_file(forward_euler_result.first,forward_euler_result.second, "forward_euler.dat"); 

   // Making all the signs in the vector equal to the corresponding equation
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sign_arr[i][j] = -1; 
        }
    }

    for (int i = 0; i < n; i++){
        int temp = i; 
        while (temp != 0){
            sign_arr[i][temp-1] = 1; 
            temp--; 
        }
    }
    //////////////////////////////////////////////////

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            P[i][j] = 0; 
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            alpha[i][j] = 0.33/4.2; 
            gamma[i] = 1; 
            P[i][0] = 1; 
        }
    }








    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << P[i][j] << std::endl; 
        }
    } 
    std::cout << std::endl; 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << alpha[i][j] << std::endl; 
        }
    } 

    double p_tmp; 

    for (int stp = 0; stp < n-1; stp++){
        //double p_tmp = 0; 
        for (int i = 0; i < n; i++){
            p_tmp = 0;
            for (int j = 0; j < n; j++){
                if (i == j){
                    p_tmp = p_tmp - gamma[i]*P[i][stp];
                } else if (i != j){
                        p_tmp = p_tmp + sign_arr[i][j]*alpha[i][j]*P[i][stp]*P[j][stp]; 
                    }
                }
            
            p_tmp = p_tmp*0.1 + P[i][stp];
            std::cout << "P_TMP : " << p_tmp << std::endl << std::endl;  
            P[i][stp+1] = p_tmp;
        }  
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << P[i][j] << " "; 
        }
        std::cout << std::endl; 
    }

}