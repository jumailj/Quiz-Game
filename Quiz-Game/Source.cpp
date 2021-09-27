#include "core.h"

float mousePosX;
float mousePosY;

const int windowWidht = 900;
const int windowHeight = 500;

void Elements();
void RadioAcitveButtons();


char question[20] = " 10 + 3 = ";
char pointes[15] = "points: 99";
char currentQuestions[20] = "questions: 9/10";

// data for the option box number;
char optionsText[4][3] = { {"00"},{"00"},{"00"},{"00"} };

//random one contain the correct answer; -->
int options[4] = { 0,0,0,0 }; // > answerInRandomOption()


int Number[2];
int globalAnswer = 0;
int AnswerInRandomOption = 0;

int globalPoint = 0;
int globalQuestionCount = 0;

void ChangQuestionsAndChangeValues() {

    Number[0] = GenerateRandomNumber(20, 40);
    Number[1] = GenerateRandomNumber(20, 40);
    globalAnswer = Number[0] + Number[1];
    AnswerInRandomOption = GenerateRandomNumber(0, 3);


    options[AnswerInRandomOption] = globalAnswer;
    for (int i = 0; i < 4; i++) {

        if (i == AnswerInRandomOption) {
            continue;
        }

        options[i] = globalAnswer + GenerateRandomNumber(2, 15);
    }
    // inseart number to text gui
    for (int i = 0; i < 4; i++) {
        sprintf(optionsText[i], "%d", options[i]);
    }
    sprintf(question, " %d + %d", Number[0], Number[1]);

}

Color box1Color = Color(RAYWHITE);
Color box2Color = Color(RAYWHITE);
Color box3Color = Color(RAYWHITE);
Color box4Color = Color(RAYWHITE);


bool ClickRegister[4] = { false,false,false,false };

int main(void)
{
   
    srand(time(NULL));

    InitWindow(windowWidht, windowHeight, "Quiz Game");

    Texture2D background = LoadTexture("game_background.png");
    Texture2D answerBoxGui[4] = { LoadTexture("answer_box.png"), LoadTexture("answer_box.png"),LoadTexture("answer_box.png"),LoadTexture("answer_box.png") };

    Texture2D closeButton = LoadTexture("close_button.png");
    Texture2D restartButton = LoadTexture("restart_button.png");

    SetTargetFPS(60);


    ChangQuestionsAndChangeValues();
    while (!WindowShouldClose())
    {


        BeginDrawing();
        ClearBackground(RAYWHITE);
        mousePosX = GetMousePosition().x;
        mousePosY = GetMousePosition().y;


        if (IsKeyPressed(KEY_SPACE)) {
            globalPoint = 0;
            globalQuestionCount = 0;
            ChangQuestionsAndChangeValues();
        }


        if (ClickRegister[AnswerInRandomOption] == true) {
            std::cout << "answer ture" << std::endl;
            globalPoint += 1;
            globalQuestionCount++;
            
            ChangQuestionsAndChangeValues();

        }
        else {

            for (int i = 0; i < 4; i++) {
                if (i == AnswerInRandomOption) {
                    continue;
                }
                if ( ClickRegister[i] == true) {
                    globalPoint -= 0;
                    globalQuestionCount++;
                    
                    ChangQuestionsAndChangeValues();

                    }   
                 }
             }

         sprintf(pointes, "points: %d", globalPoint);
         sprintf(currentQuestions, "questions: %d", globalQuestionCount);

       RadioAcitveButtons();
       DrawTexture(background, 0, 0, RAYWHITE);
       DrawTexture(answerBoxGui[0], 70, 312, box1Color);
       DrawTexture(answerBoxGui[1], 520, 312, box2Color);
       DrawTexture(answerBoxGui[2], 70, 412, box3Color);
       DrawTexture(answerBoxGui[3], 520, 412, box4Color);
       DrawTexture(restartButton, 10, 10, RED);
        Elements();

        if (globalQuestionCount >= 10) {


           
        }
        

        EndDrawing();
    }



    CloseWindow(); 
    //UnloadTexture(background);
  
    return 0;
}


void RadioAcitveButtons() {

    // box-01;
    if ((mousePosX >= 70 && mousePosX <= 380) && (mousePosY >= 312 && mousePosY <= 360)) {
        box1Color = DARKBROWN;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            box1Color = BLUE;
            ClickRegister[0] = true;

        }
        else {
            ClickRegister[0] = false;
        }
    }
    else {
        box1Color = RAYWHITE;
    }
    // box-02;
    if ((mousePosX >= 520 && mousePosX <= 830) && (mousePosY >= 311 && mousePosY <= 362)) {
        box2Color = DARKBROWN;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            box2Color = BLUE;
            ClickRegister[1] = true;
        }
        else {
            ClickRegister[1] = false;
        }
    }
    else {
        box2Color = RAYWHITE;
    }
    // box-03;
    if ((mousePosX >= 70 && mousePosX <= 380) && (mousePosY >= 412 && mousePosY <= 463)) {
        box3Color = DARKBROWN;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            box3Color = BLUE;
            ClickRegister[2] = true;
        }
        else {
            ClickRegister[2] = false;
        }
    }
    else {
        box3Color = RAYWHITE;
    }
    //box-04;
    if ((mousePosX >= 520 && mousePosX <= 830) && (mousePosY >= 412 && mousePosY <= 463)) {
        box4Color = DARKBROWN;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            box4Color = BLUE;
            ClickRegister[3] = true;
        }
        else {
            ClickRegister[3] = false;
        }
    }
    else {
        box4Color = RAYWHITE;
    }

}

void Elements() {
  DrawText(question, 270, 150, 80, BLACK);
  DrawText(pointes, 20, 15, 40, BLACK);
  DrawText(currentQuestions, 600, 15, 40, BLACK);
 
  // answer numbers (options)
  DrawText(optionsText[0], 200, 320, 40, BLACK);
  DrawText(optionsText[1], 650, 320, 40, BLACK);
  DrawText(optionsText[2], 200, 420, 40, BLACK);
  DrawText(optionsText[3], 650, 420, 40, BLACK);
  DrawText("press space to restart", 320, 475,20, BLACK);

    // answer box;

}

