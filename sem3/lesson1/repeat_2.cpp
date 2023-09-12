#include <iostream>
#include <cmath>

struct Point_3D {
    double x, y, z;
};



Point_3D* middle( Point_3D *const A, Point_3D *const B){
    double x_mid = 0.5*(A->x + B->x);
    double y_mid = 0.5*(A->y + B->y);
    double z_mid = 0.5*(A->z + B->z);
    return new Point_3D {x_mid, y_mid, z_mid};
}

double distance(Point_3D *const A, Point_3D *const B){
    return sqrt(pow(A->x-B->x,2)+pow(A->y-B->y, 2)+pow(A->z-B->z, 2));
}

Point_3D* centre_of_mass(){
Point_3D p[10];
    for(int i=0;i<10;i++){
    p[i].x=rand()%15;
    p[i].y=rand()%15;
    p[i].z=rand()%15;
    }
    double x_mass = 0;
    double y_mass = 0;
    double z_mass = 0;
    for (int i=0;i<10;i++){
        x_mass+=p[i].x;
        y_mass+=p[i].y;
        z_mass+=p[i].z;
    }
    return new Point_3D {x_mass/10, y_mass/10, z_mass/10};
}

int main(){
    auto M = new Point_3D{1,4,9};
    auto N = new Point_3D{3,8,-3};
    auto C = middle (M,N);
    auto D = centre_of_mass();
    std::cout << C->x <<" "<< C->y <<" "<< C->z << std::endl;
    std::cout << distance(M,N) << std::endl;
    std::cout << D->x <<" "<< D->y <<" "<< D->z << std::endl;
    
}
    
