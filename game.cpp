#include "raylib.h"

int main()
{
    //Make an int to add value for the game window
    int width = 500;
    int height{650};
    //Initiating the new window for raylib
    
    InitWindow(width,height,"Daniel");
    //Circle Variables
    int cx{30};
    int cy{200};
    int radius{20};

    //Circle Collision Variables
    int left_circle_x_collision{cx - radius};
    int right_circle_x_collision{cx + radius};
    int top_circle_x_collision{cy - radius};
    int bottom_circle_x_collision{cy + radius};

    //Rectangle Variables
    int px{300};
    int py{100};
    int rectWidth{50};
    int rectHeight{50};
    int direction{10};


    //Axe Edges
    int left_axe_collision{px};
    int right_axe_collision{px + rectWidth};
    int top_axe_collision{py};
    int bottom_axe_collision{py + rectHeight};
    
    //Setting the game FPS
    SetTargetFPS(60);

    //Bool
    bool collision_with_axe = (left_axe_collision <= right_circle_x_collision) &&
                              (right_axe_collision >= left_circle_x_collision) &&
                              (top_axe_collision <= bottom_circle_x_collision) &&
                              (bottom_axe_collision >= top_circle_x_collision);

    //Opening and keeping the window open algo
    while(WindowShouldClose() == false) {

        BeginDrawing();

        ClearBackground(WHITE);
        //Draw a circle to the window canvas

        if(collision_with_axe) {
            DrawText("Game Over", 250, 250,20, RED);
        } else {

            //Update the collision status
             left_circle_x_collision = cx - radius;
             right_circle_x_collision = cx + radius;
             top_circle_x_collision = cy - radius;
             bottom_circle_x_collision = cy + radius;
             //Update the axe collision status
             left_axe_collision = px;
             right_axe_collision = px + rectWidth;
             top_axe_collision = py;
             bottom_axe_collision = py + rectHeight;
             //Collision
             collision_with_axe = (left_axe_collision <= right_circle_x_collision) &&
                              (right_axe_collision >= left_circle_x_collision) &&
                              (top_axe_collision <= bottom_circle_x_collision) &&
                              (bottom_axe_collision >= top_circle_x_collision);


            DrawCircle(cx,cy,radius,BLUE);
            //Drawing the Square for the axe

            DrawRectangle(px, py, rectWidth, rectHeight,RED);
            //Checking for the key press

            if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT) && cx < width) {
                cx = (cx + 10);
            }
            if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) && cx > 0) {
                cx = (cx - 10);
            }
            

            // Moving the Rectangle
            py += direction;
            if(py > height) {
                direction = -direction;
            }

            if(py < 0) {
                direction = 10;
            }

        }
        EndDrawing();
        // ...
    }

}