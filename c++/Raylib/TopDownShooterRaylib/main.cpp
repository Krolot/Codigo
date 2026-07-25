#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH_ZERO = 0;
const int SCREEN_HEIGHT_ZERO = 0;

class CBullet{
private:
    Vector2 position;
    Vector2 velocity;
    float lifetime;
    int damage;
    int bRadius = 7;
    Color bColor = BLUE;
public:
    CBullet(Vector2 p, Vector2 v, float l, int d);

    void Update();
    void Draw();
    bool IsAlive();
    Vector2 GetPos();
    int GetRadius();
};

CBullet::CBullet(Vector2 p, Vector2 v, float l, int d)
{
    position = p;
    velocity = v;
    lifetime = l;
    damage = d;
}

void CBullet::Update()
{
    float dt = GetFrameTime();

    lifetime -= dt;

    position = Vector2Add(position,Vector2Scale(velocity, dt));
}

bool CBullet::IsAlive()
{
    return lifetime > 0;
}

void CBullet::Draw()
{
    DrawCircleV(position, bRadius, bColor);
}

Vector2 CBullet::GetPos()
{
    return position;
}

int CBullet::GetRadius()
{
    return bRadius;
}

class CEnemy{
private:
    Vector2 position;
    float speed;
    int health;
    int bRadius;

public:
    CEnemy(Vector2 p, float s);

    void Update(Vector2 playerPos);
    void Draw();
    Vector2 GetPos();
    int GetRadius();
};

CEnemy::CEnemy(Vector2 p, float s)
{
    position = p;
    speed = s;
    health = 100;
    bRadius = 20;
}

void CEnemy::Update(Vector2 playerPos)
{
    float dt = GetFrameTime();

    Vector2 direction = Vector2Subtract(playerPos, position);

    direction = Vector2Normalize(direction);

    position = Vector2Add(position,Vector2Scale(direction, speed * dt));
}

void CEnemy::Draw()
{
    DrawCircleV(position, bRadius, RED);
}

Vector2 CEnemy::GetPos()
{
    return position;
}

int CEnemy::GetRadius()
{
    return bRadius;
}

class CPlayer{
private:

    int health;
    int maxVelocity;
    float speed;
    int bRadius;
    Vector2 velocity;
    Vector2 position;

public:

    CPlayer(int h, float s, int mV, Vector2 p);
    Vector2 GetPos();
    int GetRadius();

    void UpdateMovement();
    void Move();

    void Collisions();

    void SetPos(Vector2 p);

    bool IsMoving();

    void Shoot(vector<CBullet>& bullets);

    void DrawCrosshair();

};

CPlayer::CPlayer(int h, float s, int mV, Vector2 p)
{
    health = h;
    speed = s;
    maxVelocity = mV;

    position = p;

    velocity = {0,0};
    bRadius = 15;
}

void CPlayer::Move()
{
    float dt = GetFrameTime();

    if(IsKeyDown(KEY_W))
        velocity.y -= speed * dt;

    if(IsKeyDown(KEY_S))
        velocity.y += speed * dt;

    if(IsKeyDown(KEY_A))
        velocity.x -= speed * dt;

    if(IsKeyDown(KEY_D))
        velocity.x += speed * dt;

    if(!IsMoving())
    {
        velocity = Vector2MoveTowards(velocity,{0,0},speed * dt);
    }

    float length = Vector2Length(velocity);

    if(length > maxVelocity)
    {
        velocity = Vector2Scale(Vector2Normalize(velocity),maxVelocity );
    }
}
bool CPlayer::IsMoving()
{
    return (IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D));
}

void CPlayer::UpdateMovement()
{
    float dt = GetFrameTime();
    position = Vector2Add(position,Vector2Scale(velocity,dt));

    Collisions();
}

void CPlayer::Collisions()
{
    if(position.x > SCREEN_WIDTH)
        position.x = SCREEN_WIDTH;

    if(position.x < SCREEN_WIDTH_ZERO)
        position.x = SCREEN_WIDTH_ZERO;

    if(position.y > SCREEN_HEIGHT)
        position.y = SCREEN_HEIGHT;

    if(position.y < SCREEN_HEIGHT_ZERO)
        position.y = SCREEN_HEIGHT_ZERO;
}

void CPlayer::Shoot(vector<CBullet>& bullets)
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse = GetMousePosition();

        Vector2 direction = Vector2Subtract(mouse, position);

        direction = Vector2Normalize(direction);

        Vector2 bulletVelocity = Vector2Scale(direction,800);

        bullets.push_back(CBullet(position, bulletVelocity, 2, 10));
    }
}

void CPlayer::DrawCrosshair()
{
    HideCursor();

    Vector2 mouse = GetMousePosition();

    DrawRectangle(mouse.x - 12,mouse.y - 2,25,5,WHITE);

    DrawRectangle(mouse.x - 2,mouse.y - 12,5,25,WHITE);

}
Vector2 CPlayer::GetPos()
{
    return position;
}

int CPlayer::GetRadius(){
    return bRadius;
}
void SpawnEnemy(vector<CEnemy>& enemies)
{
    Vector2 spawn;
    int side = GetRandomValue(0,3);
    if(side == 0)
        spawn = {0,(float)GetRandomValue(0,SCREEN_HEIGHT)};

    if(side == 1)
        spawn = {SCREEN_WIDTH,(float)GetRandomValue(0,SCREEN_HEIGHT)};

    if(side == 2)
        spawn = {(float)GetRandomValue(0,SCREEN_WIDTH),0};

    if(side == 3)
        spawn = {(float)GetRandomValue(0,SCREEN_WIDTH),SCREEN_HEIGHT};

    enemies.push_back(CEnemy(spawn,150));
}

int main()
{
    Vector2 startPos = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2}; 

    CPlayer Player(100,900,300,startPos);
    vector<CBullet> bullets;
    vector<CEnemy> enemies;

    int score = 0;

    float enemyTimer = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Shooter");

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        // UPDATE

        Player.Move();

        Player.UpdateMovement();

        Player.Shoot(bullets);

        for(auto& bullet : bullets)
            bullet.Update();

        for(auto it = bullets.begin(); it != bullets.end();)
        {
            if(!it->IsAlive())
                it = bullets.erase(it);

            else
                it++;
        }

        enemyTimer += GetFrameTime();

        if(enemyTimer >= 0.5)
        {

            SpawnEnemy(enemies);

            enemyTimer = 0;

        }

        for(auto& enemy : enemies)
        {
            enemy.Update(Player.GetPos());

            if(CheckCollisionCircles(Player.GetPos(),Player.GetRadius(),enemy.GetPos(),enemy.GetRadius()))
            {
                CloseWindow();
                return 0;
            }
        }

        for(auto enemy = enemies.begin(); enemy != enemies.end(); )
        {
            bool enemyDead = false;

            for(auto bullet = bullets.begin(); bullet != bullets.end(); )
            {
                if(CheckCollisionCircles(
                    bullet->GetPos(),
                    bullet->GetRadius(),
                    enemy->GetPos(),
                    enemy->GetRadius()))
                {
                    enemyDead = true;

                    bullet = bullets.erase(bullet);
                    break;
                }
                else
                {
                    bullet++;
                }
            }

            if(enemyDead)
            {
                enemy = enemies.erase(enemy);
                score++;
            }
            else
                enemy++;
        }

        
        // DRAW
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("Score: %i", score), 50, 50, 20, RAYWHITE);

            DrawCircleV(Player.GetPos(),Player.GetRadius(),WHITE);

            for(auto& bullet : bullets)
                bullet.Draw();

            for(auto& enemy : enemies)
                enemy.Draw();

            Player.DrawCrosshair();
        EndDrawing();
    }
    CloseWindow();

}