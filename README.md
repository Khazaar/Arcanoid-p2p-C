# Arcanoid-p2p-C
Arcanoid game for two players

Presentation:
https://www.slideshare.net/secret/HmpZhBxGONOMpk

Video:
https://drive.google.com/file/d/1MJr_0sgzz9ouhGdAhR6eN0yNVLuJR_GZ/view?usp=sharing

Controls:
Press R to run game. Press A and D to move player A. Press J and L to move player B

Rules:
Whenever ball hits a racket, Total hits increases +1;
When ball falls out of margin, opposite player gets +1 score and Total hits becomes 0;
Whenever Total hits becomes equal to 12, game moves to the next Level and Total hits becomes 0;
Ball velocity increases each next Level;
It is impossible to loose, after Level 3 ”friendship wins”

Implementation:
Init()
Generates borders according to the Level number (case statement used)
initRacketA/B()
Defines racket A/B parameters
initBall()
Defines initial ball parameters (x, y, velocity, alpha)
moveBall()
Sets x and y for the ball
runBall()
Moves ball according to its velocity and alpha, checks collisions, reflections
putRacketA/B()
Generates rackets
putBall()
Generates ball
moveRacketA/B()
Moves rackets, checks collisions
show()
Prints field array and game data
main()
Organises game cycle until isWon and Q not pressed. Implements all rules.
