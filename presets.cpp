#include "presets.hpp"
#include <raylib.h>
#include <vector>

Vector3 operator*(float scalar, Vector3& v){
    return Vector3{v.x*scalar,v.y*scalar,v.z*scalar};
}

void reset(){
    currentpos={0.01f, 0.5f, 0.05f};
    positions.clear();

}

std::vector<Vector3> preset1() {
    float sub_dt = dt / substeps;
    for (float i = 0.0f; i < substeps; ++i) {
        float nx = currentpos.x + dt * (P * (currentpos.y - currentpos.x));
        float ny = currentpos.y + dt * (currentpos.x * (R - currentpos.z) - currentpos.y);
        float nz = currentpos.z + dt * (currentpos.x * currentpos.y - B * currentpos.z);
        currentpos = {nx, ny, nz};
        positions.push_back(currentpos);
    }
    return positions;
}

std::vector<Vector3> preset2(){
    float sub_dt = dt / substeps;
    for (float i = 0.0f; i < substeps; ++i){
        float nx = currentpos.x + dt * (currentpos.x * currentpos.y  + currentpos.x * (-P + 1/B ) + currentpos.z);
        float ny = currentpos.y + dt * (-B*currentpos.y - currentpos.x * currentpos.x);
        float nz = currentpos.z + dt * (-R * currentpos.z - currentpos.x);
        currentpos = {nx,ny,nz};
        positions.push_back(currentpos);

    }
    return positions;

}

