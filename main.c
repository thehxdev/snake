#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h>
#include <assert.h>

#include <raylib.h>

typedef struct {
    int x, y;
} GridVec2;

#define CELL_COUNT 20
#define CELL_SIZE 40

const int WINDOW_WIDTH = CELL_COUNT * CELL_SIZE, WINDOW_HEIGHT = WINDOW_WIDTH;
const Color TARGET_COLOR = GOLD;
const Color SNAKE_HEAD_COLOR = SKYBLUE;
const Color SNAKE_COLOR = BLUE;
const Color BACKGROUND_COLOR = {0x18, 0x18, 0x18, 0xff};

GridVec2 grid_vec2_random(void)
{
    return (GridVec2) {
        rand() % CELL_COUNT, rand() % CELL_COUNT,
    };
}

int main(void)
{
    srand(time(NULL));

    GridVec2 target_pos = grid_vec2_random();
    struct {
        GridVec2 cells[CELL_COUNT * CELL_COUNT];
        GridVec2 vel;
        int last_idx;
    } snake;

    snake.last_idx = 0;
    snake.cells[0] = (GridVec2) {
        CELL_COUNT/2-1, CELL_COUNT/2-1
    };
    snake.vel = (GridVec2) {
        0, 0
    };

    GridVec2 *snake_head = &snake.cells[0];
    float dt_acc = 0.0f;
    bool gameover = false;

    SetTraceLogLevel(LOG_INFO);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake!");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        // Update
        {
            dt_acc += dt;
            if (dt_acc >= 0.045f) {
                dt_acc = 0.0f;
                for (int i = snake.last_idx; i > 0; i--)
                    snake.cells[i] = snake.cells[i-1];
                snake_head->x = (snake_head->x + snake.vel.x) % CELL_COUNT;
                if (snake_head->x < 0)
                    snake_head->x = CELL_COUNT - 1;
                snake_head->y = (snake_head->y + snake.vel.y) % CELL_COUNT;
                if (snake_head->y < 0)
                    snake_head->y = CELL_COUNT - 1;
            }

            for (int i = 1; i < snake.last_idx; i++) {
                GridVec2 cell = snake.cells[i];
                if (snake_head->x == cell.x && snake_head->y == cell.y) {
                    gameover = true;
                }
            }

            if (IsKeyPressed(KEY_DOWN) && snake.vel.y != -1) {
                snake.vel.x = 0;
                snake.vel.y = 1;
            } else if (IsKeyPressed(KEY_UP) && snake.vel.y != 1) {
                snake.vel.x = 0;
                snake.vel.y = -1;
            } else if (IsKeyPressed(KEY_RIGHT) && snake.vel.x != -1) {
                snake.vel.y = 0;
                snake.vel.x = 1;
            } else if (IsKeyPressed(KEY_LEFT) && snake.vel.x != 1) {
                snake.vel.y = 0;
                snake.vel.x = -1;
            }

            if (snake_head->x == target_pos.x && snake_head->y == target_pos.y) {
                target_pos = grid_vec2_random();
                // The first cell is the snake's head so in this indexing starts from 1.
                snake.last_idx++;
                snake.cells[snake.last_idx] = snake.cells[snake.last_idx - 1];
            }
        }

        // Draw
        BeginDrawing();
        {
            if (!gameover) {
                ClearBackground(BACKGROUND_COLOR);

                DrawRectangle(
                    snake_head->x * CELL_SIZE,
                    snake_head->y * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE,
                    SNAKE_HEAD_COLOR
                );
                for (int i = 1; i <= snake.last_idx; i++) {
                    GridVec2 cell = snake.cells[i];
                    DrawRectangle(
                        cell.x * CELL_SIZE,
                        cell.y * CELL_SIZE,
                        CELL_SIZE,
                        CELL_SIZE,
                        SNAKE_COLOR
                    );
                }

                DrawRectangle(
                    target_pos.x * CELL_SIZE,
                    target_pos.y * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE,
                    TARGET_COLOR
                );
            } else {
                DrawText("Game Over!", 20, 20, 30, RAYWHITE);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
