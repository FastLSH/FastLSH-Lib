#include "LSH.h"

int main() {

    //new object of LSH
    LSH mlsh(1000,1000,56,200,1,1.2,100);

    //read from file		
    mlsh.loadSetQ("./dataset/dataset1000NoIndex.csv",0);
    mlsh.loadSetN("./dataset/dataset1000NoIndex.csv",0);

    mlsh.setComputeMode(1);
    mlsh.setThreadMode(1);

    mlsh.reportStatus();

    vector2D candidate = mlsh.getCandidateSet();

    // you can put your code here and use the candidate in the next step

    return 0;
}
