#include <raylib.h>
#include <vector>
#include "presets.hpp"
#include <cmath>

int main(){
    int current_preset{1};
    InitWindow(window_width, window_height, "chaos");
    SetTargetFPS(60);
    Color color;

    Camera3D camera = {0};
    camera.position = (Vector3){ 0.0f, 75.0f, 90.0f }; 
    camera.target = (Vector3){ 0.0f, 0.0f, 25.0f };     
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         
    camera.fovy = 45.0f;                              
    camera.projection = CAMERA_PERSPECTIVE;
    float cameraAngle{0};
    float cameraDistance{90.0};
    float radius_scalar=1.5;

    while(!WindowShouldClose()){
        float current_scale = (current_preset == 2) ? 5 : 1.0f;
        substeps = (current_preset == 2) ? 20: 2;
        cameraDistance = (current_preset == 2) ? 10: 90;
        

        switch (current_preset) {
            case 1: color = RED; break;
            case 2: color = BLUE; break;
        
        }

        if(IsKeyPressed(KEY_R))reset();
        if(IsKeyPressed(KEY_ONE) && current_preset != 1){current_preset=1; reset();P=10;B=(8.0/3.0);R=28; camera.target.z = 25;radius_scalar=1.5;camera.target.y=0;}
        if(IsKeyPressed(KEY_TWO) && current_preset != 2){current_preset=2; reset();P=0.001;B=0.2;R=1.1; camera.target.z = 25;radius_scalar=0.3;camera.target.y=0;}

        if(IsKeyDown(KEY_RIGHT)){
            cameraAngle += 0.02;
            camera.position.x = camera.target.x + sinf(cameraAngle) * cosf(cameraPitch) * cameraDistance;
            camera.position.z = camera.target.z + cosf(cameraAngle) * cosf(cameraPitch) * cameraDistance;
        }
        if(IsKeyDown(KEY_LEFT)){
            cameraAngle -= 0.02;
            camera.position.x = camera.target.x + sinf(cameraAngle) * cosf(cameraPitch) * cameraDistance;
            camera.position.z = camera.target.z + cosf(cameraAngle) * cosf(cameraPitch) * cameraDistance;
        }

        Vector2 MousePosition = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){isdragging=true;}
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){isdragging=false;}
        if(isdragging){
            float mouseDeltaX = GetMouseDelta().x;
            float mouseDeltaY = GetMouseDelta().y;
            cameraAngle -= mouseDeltaX * 0.005;
            cameraPitch += mouseDeltaY * 0.005f;

            if (cameraPitch > 1.5f) cameraPitch = 1.5f;
            if (cameraPitch < 0.05f) cameraPitch = 0.05f;

            camera.position.x = camera.target.x + sinf(cameraAngle) * cameraDistance;
            camera.position.z = camera.target.z + cosf(cameraAngle) * cameraDistance;
            camera.position.y = camera.target.y + sinf(cameraPitch) * cameraDistance;
        }
        

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        
        switch (current_preset) {
            case 1: preset1();break;
            case 2: preset2();break;
        
        }
        if(positions.size() > 3000){
            positions.erase(positions.begin());
        }

        

        for(int i{0}; i < positions.size() - 1 ;++i){
            Vector3 p1 = { positions[i].x * current_scale, positions[i].y * current_scale, positions[i].z * current_scale };
            Vector3 p2 = { positions[i+1].x * current_scale, positions[i+1].y * current_scale, positions[i+1].z * current_scale };
            DrawLine3D(p1, p2, color);
        }

        if(!positions.empty()){
            Vector3 scaled_back = { 
                positions.back().x * current_scale, 
                positions.back().y * current_scale, 
                positions.back().z * current_scale 
            };
            DrawSphere(scaled_back, radius_scalar * current_scale, color);
        }



        //DrawGrid(100, 4); optional grid
        EndMode3D();
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
    

}
