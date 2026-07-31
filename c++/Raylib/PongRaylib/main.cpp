#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

class CPongPlayer{
    private:
    Vector2 pos;
    Vector2 size;
    Rectangle collisionBox;
    int score;
    float speed;

    public:

    CPongPlayer(Vector2 p, Vector2 si, int s, float speed);
    void Move(bool isUp);
    void AddScore();
    void Draw();
    void Collisions();
    int GetScore();
    Rectangle GetHitBox();
};

CPongPlayer::CPongPlayer(Vector2 p, Vector2 si, int s, float sp)
{
    pos = p;
    score = s;
    size = si;
    speed = sp;

    collisionBox.x = pos.x;
    collisionBox.y = pos.y;
    collisionBox.width = size.x;
    collisionBox.height = size.y;
}

void CPongPlayer::Move(bool isUp)
{
    float dt = GetFrameTime();

    if (isUp)
        pos.y -= speed * dt;

    else
        pos.y += speed * dt;

    collisionBox.x = pos.x;
    collisionBox.y = pos.y;
}

void CPongPlayer::Draw()
{
    DrawRectangleV(pos, size, MAROON);
}

void CPongPlayer::Collisions()
{
    if (pos.y < 0)
        pos.y = 0;

    if (pos.y > screenHeight - size.y)
        pos.y = screenHeight - size.y;

    collisionBox.x = pos.x;
    collisionBox.y = pos.y;
}

Rectangle CPongPlayer::GetHitBox()
{
    return collisionBox;
}

void CPongPlayer::AddScore()
{
    score += 1;
}

int CPongPlayer::GetScore()
{
    return score;
}

class CPongBall{
    private:
    Vector2 pos;
    Vector2 velocity;
    Rectangle collisionBox;
    int speed;
    int ballRadius;

    public:

    CPongBall(Vector2 p, Vector2 dir, int sp, int radius);
    void Move();
    void Draw();
    void ResetPos(bool isLeft);
    void Collisions();
    void ModifyXDirection(bool isLeft);
    Vector2 GetPos();
    Rectangle GetHitBox();
};

CPongBall::CPongBall(Vector2 p, Vector2 dir, int sp, int radius)
{
    pos = p;
    velocity = dir;
    speed = sp;
    ballRadius = radius;

    collisionBox.x = pos.x - radius;
    collisionBox.y = pos.y - radius;
    collisionBox.width = radius * 2;
    collisionBox.height = radius * 2;
}

void CPongBall::Move()
{
    float dt = GetFrameTime();

    pos.x += velocity.x * speed * dt;
    pos.y += velocity.y * speed * dt;

    collisionBox.x = pos.x - ballRadius;
    collisionBox.y = pos.y - ballRadius;
}

void CPongBall::Draw()
{
    DrawCircleV(pos, ballRadius, MAROON);
}

void CPongBall::Collisions()
{
    if (pos.y >= screenHeight - ballRadius)
    {
        pos.y = screenHeight - ballRadius;
        velocity.y = -velocity.y;
    }

    if (pos.y <= ballRadius)
    {
        pos.y = ballRadius;
        velocity.y = -velocity.y;
    }
}

void CPongBall::ModifyXDirection(bool isLeft)
{
    if (isLeft)
        velocity = {1, velocity.y};
    if (!isLeft)
        velocity = {-1, velocity.y};
}

Vector2 CPongBall::GetPos()
{
    return pos;
}

Rectangle CPongBall::GetHitBox()
{
    return collisionBox;
}

void CPongBall::ResetPos(bool isLeft)
{
    pos = {screenWidth / 2, screenHeight / 2};

    if (isLeft)
        velocity = {1, velocity.y};
    if (!isLeft)
        velocity = {-1, velocity.y};
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    CPongPlayer Player1(Vector2 {50, screenHeight / 2}, Vector2{10, 100}, 0, 500.0f);
    CPongPlayer Player2(Vector2 {750, screenHeight / 2}, Vector2{10, 100}, 0, 500.0f);
    CPongBall Ball(Vector2 {screenWidth / 2, screenHeight / 2}, Vector2{-1,-1}, 250, 15);

    InitWindow(screenWidth, screenHeight, "Pongo");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyDown(KEY_W))
            Player1.Move(1);
        if (IsKeyDown(KEY_S))
            Player1.Move(0);
            
        if (IsKeyDown(KEY_UP))
            Player2.Move(1);
        if (IsKeyDown(KEY_DOWN))
            Player2.Move(0);

        if (CheckCollisionRecs(Player1.GetHitBox(), Ball.GetHitBox()))
            Ball.ModifyXDirection(1);
        if (CheckCollisionRecs(Player2.GetHitBox(), Ball.GetHitBox()))
            Ball.ModifyXDirection(0);

        if (Ball.GetPos().x < 0)
        {
            Player2.AddScore();
            Ball.ResetPos(0);
        }
            
        if (Ball.GetPos().x > screenWidth)
        {
            Player1.AddScore();
            Ball.ResetPos(1);
        }    

        Ball.Move();

        Player1.Collisions();
        Player2.Collisions();
        Ball.Collisions();
        
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            Player1.Draw();
            Player2.Draw();
            Ball.Draw();

            DrawText(TextFormat("%0i", Player1.GetScore()), screenWidth / 2 - 50, 20, 30, MAROON);
            DrawText(TextFormat("%0i", Player2.GetScore()), screenWidth / 2 + 50, 20, 30, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
