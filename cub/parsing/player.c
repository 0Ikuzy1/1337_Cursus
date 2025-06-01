# include "parsing.h"

void init_player(t_player *player, char direction, t_map *map)
{
    // Set position based on map coordinates (center of starting cell)
    player->x = map->player_x * BLOCK + BLOCK / 2.0f;
    player->y = map->player_y * BLOCK + BLOCK / 2.0f;

    // Corrected angle calculations
    if (direction == 'N')
        player->angle = 3 * PI / 2;   // 270° (up)
    else if (direction == 'S')
        player->angle = PI / 2;       // 90° (down)
    else if (direction == 'E')
        player->angle = 0;            // 0° (right)
    else if (direction == 'W')
        player->angle = PI;           // 180° (left)
    else
        player->angle = 0;            // Default to east

    // Reset movement flags
    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
    player->left_rotate = false;
    player->right_rotate = false;
}

int key_press(int keycode, t_player *player)
{
    if(keycode == W)
        player->key_up = true;
    if(keycode == S)
        player->key_down = true;
    if(keycode == A)
        player->key_left = true;
    if(keycode == D)
        player->key_right = true;
    if(keycode == LEFT)
        player->left_rotate = true;
    if(keycode == RIGHT)
        player->right_rotate = true;
    if (keycode == ESC) 
        exit(0);
    return 0;
}

int key_release(int keycode, t_player *player)
{
    if(keycode == W)
        player->key_up = false;
    if(keycode == S)
        player->key_down = false;
    if(keycode == A)
        player->key_left = false;
    if(keycode == D)
        player->key_right = false;
    if(keycode == LEFT)
        player->left_rotate = false;
    if(keycode == RIGHT)
        player->right_rotate = false;
    return 0;
}

void move_player(t_player *player, t_game *game)
{
    int speed = 3;
    float angle_speed = 0.03;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);
    float new_x, new_y;

    if (player->left_rotate)
        player->angle -= angle_speed;
    if (player->right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;

    // FORWARD - move in facing direction
    if (player->key_up)
    {
        new_x = player->x + cos_angle * speed;
        new_y = player->y + sin_angle * speed;
        if (!touch(new_x, new_y, game)) {
            player->x = new_x;
            player->y = new_y;
        }
    }
    // BACKWARD - move opposite to facing direction
    if (player->key_down)
    {
        new_x = player->x - cos_angle * speed;
        new_y = player->y - sin_angle * speed;
        if (!touch(new_x, new_y, game)) {
            player->x = new_x;
            player->y = new_y;
        }
    }
    // STRAFE LEFT - move left relative to facing direction
    if (player->key_left)
    {
        new_x = player->x + sin_angle * speed;  // Changed from - to +
        new_y = player->y - cos_angle * speed;  // Changed from + to -
        if (!touch(new_x, new_y, game)) {
            player->x = new_x;
            player->y = new_y;
    }
    }
    // STRAFE RIGHT - move right relative to facing direction
    if (player->key_right)
    {
        new_x = player->x - sin_angle * speed;  // Changed from + to -
        new_y = player->y + cos_angle * speed;  // Changed from - to +
        if (!touch(new_x, new_y, game)) {
            player->x = new_x;
            player->y = new_y;
        }
}
}

