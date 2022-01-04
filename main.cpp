//
//  main.cpp
//  project5
//
//  Created by Kama Svoboda on 5/13/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#include <iostream>
#include "DataSource.h"
#include <time.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Check Command Line Arguments
    bool validInput = true; //the program expects 1 word at time we need to validate that.
    if(!(argc == 4)){
        validInput = false;
    }
    clock_t tStart = clock();
    if(validInput){
        DataSource *d1 = new DataSource(argv[1], argv[2], argv[3]);
        // Read input file?
        
        if(d1->readInputFile()){
            d1->run();
        }else{
            cout << "There was an error with reading" << endl;
        }
        
        // Write to Output
        if(d1->writeOutput()){
            
        }else{
            cout << "There was an error with writing" << endl;
        }
        delete d1;
    }else{
        // If wrong - >
        // Print Usage
        // Return Failure
        cout << "Usage: "<< endl;
        return 0;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
