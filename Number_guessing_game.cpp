#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int randnum;
int guessnum;
bool tf = false;
int guesscounter = 0;
int guesscounter2 = 3;
int lifelinenum;
char keycheck;
int score = 10;
int riddlenum;

void number_generate()
{
    srand(time(0));
    randnum = rand() % 100;
}

void guess()
{
    cout << "\nEnter your guessed number: ";
    cin >> guessnum;
}

void numchecker()
{
    if (randnum == guessnum)
    {
        cout << "\nCorrect! (+10 points)\n";
        score += 10;
        tf = true;
    }
    else
    {
        cout << "Wrong guess! (-2 points)\n";
        score -= 2;
        tf = false;
    }
}

void lifelines(int r1, int r2, int r3, int r4)
{
    cout << "\nDo you want to use a lifeline? (y/n): ";
    cin >> keycheck;

    if (keycheck != 'y') return;

    cout << "\n1. Mathematical riddle (-2)";
    cout << "\n2. One extra guess (-2)\n";
    cout << "Choose lifeline: ";
    cin >> lifelinenum;

    switch (lifelinenum)
    {
        case 1:
            riddlenum = rand() % 4;

            if (riddlenum == 0)
                cout << "\nrandnum * 2 + 10 = " << r1;
            else if (riddlenum == 1)
                cout << "\nrandnum / 2 + 5 = " << r2;
            else if (riddlenum == 2)
                cout << "\nrandnum + 20 = " << r3;
            else
                cout << "\nLast digit of randnum = " << r4;

            score -= 2;
            break;

        case 2:
            guesscounter2++;
            cout << "\nExtra chance granted!";
            score -= 2;
            break;

        default:
            cout << "\nInvalid lifeline!";
    }
}

void feedbacksystem()
{
    if (!tf)
    {
        if (randnum > 50)
            cout << "\nHint: Number is above 50\n";
        else
            cout << "\nHint: Number is 50 or below\n";
    }
}

int main()
{
    char start;
    cout << "\nNUMBER GUESSING GAME\n";
    cout << "Press 's' and Enter to start: ";
    cin >> start;

    if (start != 's') return 0;

    number_generate();

    // Easy riddles (no trigonometry)
    int r1 = randnum * 2 + 10;
    int r2 = randnum / 2 + 5;
    int r3 = randnum + 20;
    int r4 = randnum % 10;

    time_t startTime = time(0);

    cout << "\nGame Started! You have 30 seconds.\n";

    do
    {
        time_t currentTime = time(0);
        int elapsed = difftime(currentTime, startTime);

        cout << "\rTime left: " << 30 - elapsed << " seconds   ";

        if (elapsed >= 30)
        {
            cout << "\n\nTime's up!";
            break;
        }

        lifelines(r1, r2, r3, r4);
        guess();
        numchecker();
        feedbacksystem();
      
        if (tf) break;

        guesscounter++;

    } while (guesscounter < guesscounter2);

    cout << "\n\nGAME OVER";
    cout << "\nCorrect number: " << randnum;
    cout << "\nFinal Score: " << score << endl;

    return 0;
}
 
