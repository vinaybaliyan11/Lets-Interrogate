#include<bits/stdc++.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define clr() system("cls")
using namespace std;
int wow;

void start();
void signup();
void sign();
int check();
void login();
int srch();
void menu();
void play();
void leaderb();
void profile();
void afans();
void ansa(char a);
void ansb(char a);
void ansc(char a);
void ansd(char a);
void root_set();
void set1();
void set2();
void set3();
void set4();
void set5();
void rules();
void achieve();
void record();
void info();
void rem(char un[20]);
void update(char un[20]);
void admin();

struct node
{
        int age;
        char name[20], uname[20], pass[20], title[20], school[20], nat[20];

        int score, zer, ten, twe, thi, fort, fif; //for playing record

        int strk, mxstrk; //for "achievement" section
};

struct node *ob = NULL;

void cons()
{
        ob->age = 0;

        strcpy(ob->name, "null");
        strcpy(ob->uname, "null");
        strcpy(ob->pass, "null");
        strcpy(ob->title, "null");
        strcpy(ob->school, "null");
        strcpy(ob->nat, "null");

        ob->score = ob->zer = ob->ten = ob->twe = ob->thi = ob->fort = ob->fif = 0;

        ob->strk = ob->mxstrk = 0;
}
void fordelay(int j)
{
        int i, k;
        for (i = 0; i < j; i++)
                k = i;
}

void start()
{
        int op, x;
        system("color 09");
        do
        {
                x = 1;
                clr();
                cout << "\t\t\t\t\t\xB3\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\       LET'S INTERROGATE        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3\xB3\n\n";
                cout << "\t\t\t\t\t1.Login\n\t\t\t\t\t2.Signup\n\t\t\t\t\t3.Exit\n\n";
                cout << "\t\t\t\t\tEnter option\n\t\t\t\t\t";
                cin >> op;

                switch (op)
                {
                case 1:
                        login();
                        break;
                case 2:
                        signup();
                        break;
                case 3:
                        exit(0);
                case 4:
                        admin();
                        break;
                default:
                        cout << "Wrong input\ntry again", x = 0;
                }

        } while (!x);
}

void admin()
{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        FILE *fin = fopen("quiz.dat", "rb");
        while (fread(tmp, sizeof(struct node), 1, fin))
                cout << tmp->uname << " " << tmp->pass;
        getchar();
        start();
}

int check(char u[20])
{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        FILE *fin = fopen("quiz.dat", "rb");
        fseek(fin, 0, SEEK_SET);
        while (fread(tmp, sizeof(struct node), 1, fin))
        {
                if (strcmp(tmp->uname, u) == 0)
                        return 0;
        }

        return 1;
}

void sign()
{
        clr();
        system("color F9");
        int op, len, i;
        char ch, p1[20], p2[20];

        cout << "\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\  SIGNUP  \xB1\xB1\xB1\xB1\xB1\xB1\n\n";
        cout << "1.Name* : " << ob->name << endl;
        cout << "2.Age* : " << ob->age << endl;
        cout << "3.Username* : " << ob->uname << endl;
        cout << "4.Password* : " << ob->pass << endl;
        cout << "5.Title : " << ob->title << endl;
        cout << "6. School : " << ob->school << endl;
        cout << "7.Nationality : " << ob->nat << endl;
        cout << "8.Submit\n9.Back to Start Menu\n";

        cout << "\nNote-fields marked with asterix(*) should be filled mandatorily";
        cout << "\n    -username is unique and can't be changed later";
        cout << "\n    -password should contain only alphanumerics";
        cout << "\n    -age should be above 5 and below 120 to be eligible\n\n";
        cout << "Enter option\n";
        fflush(stdin);
        cin >> op;
        switch (op)
        {
        case 1:
                cout << "Enter name: ";
                cin >> ob->name;
                getchar();
                sign();
                break;
        case 2:
                cout << "Enter age: ";
                cin >> ob->age;
                if (ob->age <= 5 || ob->age >= 120)
                {
                        cout << "Age should be above 5 and below 120 to be eligible\n";
                        ob->age = 0;
                }
                getchar();
                sign();
                break;
        case 3:
                cout << "Enter user name\n";
                cin >> ob->uname;
                if (!check(ob->uname))
                {
                        cout << "User name already exists\n";
                        fordelay(1000000000);
                        strcpy(ob->uname, "null");
                }
                getchar();
                sign();
                break;
        case 4:
                cout << "Enter password\n";
                i = 0;
                do
                {
                        p1[i] = getch();
                        i++;
                        if ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122))
                                cout << "*";
                } while ((p1[i - 1] >= 48 && p1[i - 1] <= 57) || (p1[i - 1] >= 65 && p1[i - 1] <= 90) || (p1[i - 1] >= 97 && p1[i - 1] <= 122));
                p1[i - 1] = '\0';

                cout << "\nEnter password again for confirmation\n";
                i = 0;
                do
                {
                        p2[i] = getch();
                        i++;
                        if ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122))
                                cout << "*";
                } while ((p2[i - 1] >= 48 && p2[i - 1] <= 57) || (p2[i - 1] >= 65 && p2[i - 1] <= 90) || (p2[i - 1] >= 97 && p2[i - 1] <= 122));
                p2[i - 1] = '\0';

                if (!strcmp(p1, p2))
                {
                        len = strlen(p1);
                        for (i = 0; i < len; ++i)
                        {
                                if (!((p1[i] >= 48 && p1[i] <= 57) || (p1[i] >= 65 && p1[i] <= 90) || (p1[i] >= 97 && p1[i] <= 122)))
                                        break;
                        }

                        if (i != len)
                        {
                                cout << "Password should contain only alphanumerics\n";
                                cout << "Password not created\n";
                        }
                        else
                                strcpy(ob->pass, p1);
                }
                else
                        cout << "Password not created\n";

                getchar();
                sign();
                break;
        case 5:
                cout << "Enter title\n";
                cin >> ob->title;
                getchar();
                sign();
                break;
        case 6:
                cout << "Enter school\n";
                cin >> ob->school;
                getchar();
                sign();
                break;
        case 7:
                cout << "Enter nationality\n";
                cin >> ob->nat;
                getchar();
                sign();
                break;
        case 8:
                cout << "Are you sure(y/n)?\n";
                cin >> ch;
                if (ch == 'y')
                {
                        if (strcmp(ob->name, "null") != 0 && ob->age != 0 && strcmp(ob->uname, "null") != 0 && strcmp(ob->pass, "null") != 0)
                                wow = 1;
                        else
                        {
                                cout << "Please fill all the mandatory fields.\nPress any key to try again.\n";
                                getchar();
                                sign();
                        }
                }
                else
                {
                        cout << "Press any key to continue\n";
                        getchar();
                        sign();
                }
                break;
        case 9:
                return;
        default:
                cout << "Wrong input\npress any key to try again\n";
                for(int i=0;i<5;i++)
                {
                    cout << ".";
                    Sleep(1.0);
                }
                sign();
        }
}

void signup()
{
        wow = 0;

        ob = (struct node *)malloc(sizeof(struct node));
        cons();
        sign();

        if (wow)
        {
                FILE *out = fopen("quiz.dat", "ab");
                fwrite(ob, sizeof(struct node), 1, out);
                fclose(out);
                cout << "\nPROCESSING";
                for (int i = 0; i <= 5; i++)
                {
                        fordelay(100000000);
                        cout << ".";
                }
                clr();

                cout << "\nCongratulations!\nYou have successfully registered.\n";
                getchar();
        }

        free(ob);

        start();
}

int srch(char u[], char p[])
{
        int f = 0;

        FILE *in = fopen("quiz.dat", "rb");
        fseek(in, 0, SEEK_SET);

        struct node *tmp = (struct node *)malloc(sizeof(struct node));

        while (fread(tmp, sizeof(struct node), 1, in))
        {
                if (!strcmp(u, tmp->uname) && !strcmp(p, tmp->pass))
                {
                        ob = (struct node *)malloc(sizeof(struct node));
                        ob = tmp;
                        {
                                f = 1;
                                break;
                        }
                }
        }

        fclose(in);

        return f;
}

void login()
{
        int x, i;
        char s1[20], p[20], ch;
        system("color FD");
        do
        {
                clr();

                ch = 'n';

                cout << "\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  LOGIN  \xB1\xB1\xB1\xB1\xB1\xB3\n\n";
                cout << "Enter username :\n";
                cin >> s1;
                cout << "Enter password : \n";

                i = 0;
                do
                {
                        fflush(stdin);
                        p[i] = getch();
                        i++;
                        if ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122))
                                cout << "*";
                } while ((p[i - 1] >= 48 && p[i - 1] <= 57) || (p[i - 1] >= 65 && p[i - 1] <= 90) || (p[i - 1] >= 97 && p[i - 1] <= 122));
                p[i - 1] = '\0';

                x = srch(s1, p);

                if (!x)
                {
                        cout << "\nInvalid credentials\n";
                        cout << "Do you wish to try again?(y/n)\n";
                        cin >> ch;
                }

                else
                {
                        cout << "\nLOADING";
                        for (int i = 0; i <= 5; i++)
                        {
                                fordelay(100000000);
                                cout << ".";
                        }
                        menu();
                }

        } while (ch == 'y');

        start();
}

void update(char un[20])
{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        FILE *fin = fopen("quiz.dat", "rb");
        fseek(fin, 0, SEEK_SET);

        int i = 0;
        while (fread(tmp, sizeof(struct node), 1, fin))
        {
                if (strcmp(tmp->uname, un) == 0)
                {
                        FILE *fout = fopen("quiz.dat", "rb+");

                        fseek(fout, i * sizeof(struct node), SEEK_SET);
                        getchar();
                        fwrite(ob, sizeof(struct node), 1, fout);
                        fclose(fout);
                        break;
                }
                ++i;
        }

        fclose(fin);
}

void menu()
{
        clr();

        int op;
        system("color F2");
        cout << "\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  HOME  \xB1\xB1\xB1\xB1\xB1\xB3\n\n";
        cout << "WELCOME " << ob->name << " !!" << "\n\n";
        cout << "1.Play Quiz\n2.View Leaderboard\n3.Profile\n4.Log Out\n";
        cout << "\nEnter option\n";
        cin >> op;
        switch (op)
        {
        case 1:
                play();
                update(ob->uname);
                getchar();
                menu();
        case 2:
                leaderb();
                update(ob->uname);
                getchar();
                menu();
        case 3:
                profile();
                update(ob->uname);
                getchar();
                menu();
        case 4:
                update(ob->uname);
                free(ob);
                start();
        default:
                cout << "Wrong input\ntry again\n";
                menu();
        }
}

void play()
{
        clr();
        system("color 0B");
        int op;

        cout << "\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  HOME : PLAY-QUIZ  \xB1\xB1\xB1\xB1\xB1\xB3\n\n";
        cout << "1.Let's Go\n2.Rules and Regulations\n3.Achievements\n4.Back to Menu\n";
        cout << "Enter option\n";
        cin >> op;

        switch (op)
        {
        case 1:
                root_set();
                break;
        case 2:
                rules();
                break;
        case 3:
                achieve();
                break;
        case 4:
                menu();
                break;
        default:
                cout << "Wrong input\ntry again\n";
                play();
        }
}

void rules()
{
        clr();
        system("color 07");
        cout << "\xB1\ PLAY QUIZ - RULES AND REGULATIONS \xB1\n\n";
        cout << "1.Total score for each topic is 50.\n2.Only one option is correct out of the given four.\n";
        cout << "3.Just Enter the option which you feel is correct and sincerely follow the given  instructions.\n";
        cout << "4.There is no time limit.\n5.As soon as you assign a 'title' or your 'nationality' you can view it/them on   top of your screen while playing.\n";
        cout << "6.Players make it to the Leaderboard based on their total score.\n";
        cout << "\nBest of Luck!\n\nclick any key to return to 'play' menu\n";
        getch();
        play();
}

void achieve()
{
        clr();
        system("color 07");
        int points = 50 * ob->fif + 40 * ob->fort + 30 * ob->thi + 20 * ob->twe + 10 * ob->ten;

        cout << "\xB1\  PLAY QUIZ - ACHIEVEMENTS \xB1\n\n";
        cout << "1. Score 100 points overall  ";
        if (points >= 100)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "2. Score 500 points overall  ";
        if (points >= 500)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "3. Score 1000 points overall  ";
        if (points >= 1000)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "4. Achieve 5 perfect scores of 50 ";
        if (ob->fif >= 5)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "5. Achieve 10 perfect scores of 50 ";
        if (ob->fif >= 10)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "6. Achieve 25 perfect scores of 50 ";
        if (ob->fif >= 25)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "7. Consecutive 10 answers correct ";
        if (ob->mxstrk >= 10)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "8. Consecutive 20 answers correct ";
        if (ob->mxstrk >= 20)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "9. Consecutive 50 answers correct ";
        if (ob->mxstrk >= 50)
                cout << "|UNLOCKED|";
        "\n";
        cout << "10. Play more than 10 games ";
        if (ob->fif + ob->fort + ob->thi + ob->twe + ob->ten + ob->zer >= 10)
                cout << "|UNLOCKED|";
        cout << "\n";
        cout << "\n\nclick any key to return to 'play' menu\n";
        getch();
        play();
}

void root_set()
{
        ob->score = 0;
        srand(time(0));
        int x = rand() % 5 + 1;

        switch (x)
        {
        case 1:
                set1();
                break;
        case 2:
                set2();
                break;
        case 3:
                set3();
                break;
        case 4:
                set4();
                break;
        case 5:
                set5();
                break;
        }
}

void afans()
{
        getchar();
        clr();
        cout << "\t\t\t\t\t\t\xB3\xB1\xB1\xB1\xB1\xB1\  QUIZ  \xB1\xB1\xB1\xB1\xB1\xB3\n\n";
        cout << "Name: " << ob->name << " " << "Age: " << ob->age << " ";
        if (strcmpi(ob->title, "null"))
                cout << " Title: " << ob->title << " ";
        if (strcmpi(ob->nat, "null"))
                cout << " Nationality: " << ob->nat << " ";
        cout << "Score: " << ob->score << " ";
        cout << "\n\n";
}

void ansa(char a)
{
        cout << "\n";
        if (a == 'a')
        {
                cout << "Correct answer";
                ob->score += 10;
                ob->strk++;
                ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
        }
        else if (a == 'b' || 'c' || 'd')
        {

            cout << "Incorrect answer\ncorrect answer:a"; ob->strk = 0;
        }
        else
                cout << "Wrong input", ob->strk = 0;
}

void ansb(char a)
{
        cout << "\n";
        if (a == 'b')
        {
                cout << "Correct answer";
                ob->score += 10;
                ob->strk++;
                ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
        }
        else if (a == 'a' || 'c' || 'd')
                cout << "Incorrect answer\ncorrect answer:b", ob->strk = 0;
        else
                cout << "Wrong input", ob->strk = 0;
}

void ansc(char a)
{
        cout << "\n";
        if (a == 'c')
        {
                cout << "Correct answer";
                ob->score += 10;
                ob->strk++;
                ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
        }
        else if (a == 'a' || 'b' || 'd')
                cout << "Incorrect answer\ncorrect answer:c", ob->strk = 0;
        else
                cout << "Wrong input", ob->strk = 0;
}

void ansd(char a)
{
        cout << "\n";
        if (a == 'd')
        {
                cout << "Correct answer";
                ob->score += 10;
                ob->strk++;
                ob->mxstrk = ob->mxstrk > ob->strk ? ob->mxstrk : ob->strk;
        }
        else if (a == 'a' || 'b' || 'c')
                cout << "Incorrect answer\ncorrect answer:d", ob->strk = 0;
        else
                cout << "Wrong input", ob->strk = 0;
}

void remark()
{
        cout << "Remark:";
        switch (ob->score)
        {
        case 0:
                cout << "Work hard - be stronger,swifter and smarter.";
                ob->zer++;
                break;
        case 10:
                cout << "Better luck next time,may the force be with you.";
                ob->ten++;
                break;
        case 20:
                cout << "Don't give up,you have the potential.";
                ob->twe++;
                break;
        case 30:
                cout << "You can scale new heights,just believe.";
                ob->thi++;
                break;
        case 40:
                cout << "So near yet so far,you are a good one buddy.";
                ob->fort++;
                break;
        case 50:
                cout << "Perfect! We have the genius here.";
                ob->fif++;
                break;
        }
        cout << "\n";
}

void set1()
{
        char a;
        system("color 0E");
        afans();
        cout << "Q 1.Which was Cristiano Ronaldo's first professional football team?\n";
        cout << "a)Sporting Lisbon\nb)F.C.Porto\nc)Manchester United\nd)Real Madrid\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 2.Who defeated Michael Phelps in Rio Olympics 2016 to give his country its first Gold Medal\n";
        cout << "a)Joseph Schooling\nb)Brian Roberts\nc)Lu Xei\nd)Carl Roberts\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 3.Who is the first lady Prime Minister in the world?\n";
        cout << "a)Indira Gandhi\nb)Margaret Thatcher\nc)Sirimavo Bandaranaike\nd)Angelique Fernandez\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();
        cout << "Q 4.______ was the first Chief Minister of Delhi\n";
        cout << "a)Chaudhary Brahm Prakash\nb)Shiela Dikshit\nc)Madan Lal Khurana\nd)Shushma Swaraj\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 5.Which of the following is not in India?\n";
        cout << "a)Yanam\nb)Itanagar\nc)Dilli\nd)Lansdowne\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();

        cout << "\nTHANK YOU " << ob->name << " " << "for playing our sports quiz.";
        cout << "\nHope you enjoyed it.\n\n";
        cout << "Your score: " << ob->score << "(out of 50)\n";
        remark();

        getchar();
}

void set2()
{
        char a;
        system("color 0E");
        afans();
        cout << "Q 1.With which party would you associate Kanshi Ram?\n";
        cout << "a)BJP\nb)BSP\nc)Samajwadi Party\nd)Janta Dal(United)\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 2.Who won the famous boxing fight - Thrilla in Manila?\n";
        cout << "a)Joe Frazier\nb)Muhammad Ali\nc)Mike Tyson\nd)Floyd Mayweather\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 3.Which football club won the IFA shield in 1912?\n";
        cout << "a)Manchester United\nb)Mohun Bagan\nc)East India F.C.\nd)Nottingham Forest\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 4.Which was Steven Smith's first IPL team?\n";
        cout << "a)Kochi Tuskers Kerala\nb).Pune Wasrriors India\nc)Rajasthan Royals\nd)Rising Pune Supergiants\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 5.This is the biggest scam in the world.\n";
        cout << "a)2G scam\nb)Coalgate\nc)Bofors scam\nd)Watergate\n";
        cout << "Enter option\n";

        cin >> a;
        ansd(a);
        afans();

        cout << "\nTHANK YOU " << ob->name << " for playing out sports quiz";
        cout << "\nHope you enjoyed it.\n\n";
        cout << "Your score: " << ob->score << " (out of 50)\n";
        remark();

        getchar();
}

void set3()
{
        char a;
        system("color 0E");
        afans();
        cout << "Q 1.To what sport will you associate Deepika Pallikal?\n";
        cout << "a)Golf\nb)Badminton\nc)Squash\nd)Tennis\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();
        cout << "Q 2.Wich country's Prime Minister resigned from his post to spend some family time recently?\n";
        cout << "a)Australia\nb)Turkey\nc)New Zealand\nd)Greece\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();
        cout << "Q 3.Which of these is an internet browser?\n";
        cout << "a)Quora\nb)Line\nc)Wynk\nd)UC\n";
        cout << "Enter option\n";

        cin >> a;
        ansd(a);
        afans();
        cout << "Q 4.What does the term 'karate' mean?\n";
        cout << "a)empty hands\nb)self defence\nc)fighting spirit\nd)peace of mind\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 5.Sonia Gandhi is an M.P. from which constituency?\n";
        cout << "a)Amethi\nb)Rai Barelli\nc)Kanpur\nd)Allahabad\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();

        cout << "\nTHANK YOU " << ob->name << " for playing out sports quiz";
        cout << "\nHope you enjoyed it.\n\n";
        cout << "Your score: " << ob->score << " (out of 50)\n";
        remark();

        getchar();
}

void set4()
{
        char a;
        system("color 0E");
        afans();
        cout << "Q 1.What is the name of the Twitter Bird?\n";
        cout << "a)Dorsey Jr.\nb)Tweet Bird\nc)Bluebee\nd)Larry Bird\n";
        cout << "Enter option\n";

        cin >> a;
        ansd(a);
        afans();
        cout << "Q 2.Who founded the Indian National Congress?\n";
        cout << "a)Lala Lajpat Rai\nb)A.O.Hume\nc)Motilal Nehru\nd)Lord Cornwallis\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 3.Pick the odd one out.(remember this is a Politics Quiz)?\n";
        cout << "a)India\nb)China\nc)Switzerland\nd)Argentina\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();
        cout << "Q 4.What does the term 'karate' mean?\n";
        cout << "a)empty hands\nb)self defence\nc)fighting spirit\nd)peace of mind\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 5.First individual medal for independent India in Olympics was won by _____?\n";
        cout << "a)Leander Paes\nb)Mark Andrews\nc)Abhinav Bindra\nd)K.D. Jadhav\n";
        cout << "Enter option\n";

        cin >> a;
        ansd(a);
        afans();

        cout << "\nTHANK YOU " << ob->name << " for playing out sports quiz";
        cout << "\nHope you enjoyed it.\n\n";
        cout << "Your score: " << ob->score << " (out of 50)\n";
        remark();

        getchar();
}

void set5()
{
        char a;
        system("color 0E");
        afans();
        cout << "Q 1.Who was India's first Deputy Prime Minister?\n";
        cout << "a)Morarji Desai\nb)I.K.Gujral\nc)Sardar Vallabhai Patel\nd)Shyama Prasad Mukherjee\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();
        cout << "Q 2.What does 'h' stand for in http?\n";
        cout << "a)hyper\nb)heirarchical\nc)hypo\nd)hello\n";
        cout << "Enter option\n";

        cin >> a;
        ansa(a);
        afans();
        cout << "Q 3.Which famous annual cycling event is held in France?\n";
        cout << "a)Cyclomania\nb)Around France in 80 days\nc)Francycle\nd)Tour de France\n";
        cout << "Enter option\n";

        cin >> a;
        ansd(a);
        afans();
        cout << "Q 4.Fill in the blanks.If Kiloo is to Subway Surfers,then ____ is to Temple Run.\n";
        cout << "a)Vanilla\nb)Supercell\nc)Imangi\nd)King\n";
        cout << "Enter option\n";

        cin >> a;
        ansc(a);
        afans();
        cout << "Q 5.Which Indian cricketer partenered V.V.S. Laxman in his magnicient innings of    281 not out?\n";
        cout << "a)Md. Kaif\nb)Rahul Dravid\nc)Sachin Tendulkar\nd)M.S. Dhoni\n";
        cout << "Enter option\n";

        cin >> a;
        ansb(a);
        afans();

        cout << "\nTHANK YOU " << ob->name << " for playing out sports quiz";
        cout << "\nHope you enjoyed it.\n\n";
        cout << "Your score: " << ob->score << " (out of 50)\n";
        remark();

        getchar();
}

void rem(char un[20])
{
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        FILE *fin = fopen("quiz.dat", "rb");
        FILE *fout = fopen("temp.dat", "wb");
        fseek(fin, 0, SEEK_SET);

        while (fread(tmp, sizeof(struct node), 1, fin))
        {
                if (strcmp(tmp->uname, un))
                        fwrite(tmp, sizeof(struct node), 1, fout);
        }
        fclose(fin);
        fclose(fout);
        remove("quiz.dat");
        rename("temp.dat", "quiz.dat");
}

void profile()
{
        clr();
        int op;
        char ch;
        system("color 04");
        cout << "\t\t\t\t\t    \xB3\xB1\xB1\xB1\xB1\xB1\  HOME - PROFILE  \xB1\xB1\xB1\xB1\xB1\xB3\n";
        cout << "\n1.View Playing Record\n2.Player information\n3.Deactivate Account\n4.Back to Menu\n";
        cout << "Enter option\n";
        cin >> op;

        switch (op)
        {
        case 1:
                record();
                getchar();
                profile();
                break;
        case 2:
                info();
                getchar();
                profile();
                break;
        case 3:
                cout << "Are you sure?(y/n)\n";
                cin >> ch;
                if (ch == 'y')
                {
                        rem(ob->uname);
                        cout << "Deactivating.";
                        for(int i=0;i<5;i++)
                        {
                                cout << ".";

                        }
                        cout << "Account successfully deleted\n";
                        free(ob);
                        getchar();
                        start();
                }
                else
                {
                        getchar();
                        profile();
                }
                break;
        case 4:
                menu();
                break;
        default:
                cout << "Wrong input\ntry again\n";
                getchar();
                profile();
        }
}

void record()
{
        clr();


        cout << "Overall\n\ngames played - " << ob->fif + ob->fort + ob->thi + ob->twe + ob->ten + ob->zer << endl;
        cout << "Total score - " << 50 * ob->fif + 40 * ob->fort + 30 * ob->thi + 20 * ob->twe + 10 * ob->ten << endl;
        cout << "\n50s\t" << ob->fif << "\n40s\t" << ob->fort << "\n30s\t" << ob->thi << "\n20s\t" << ob->twe << "\10s\t" << ob->ten << "\n0s\t" << ob->zer;
        cout << "\nClick any key to return to PROFILE page\n";
        getch();
        profile();
}

void info()
{
        clr();

        int op;
        char ch;

        cout << "PROFILE - PLAYER INFORMATION\n\n";

        cout << "Current information\n";
        cout << "1.Name: " << ob->name << endl;
        cout << "2.Age: " << ob->age << endl;
        cout << "3.Password: " << ob->pass << endl;
        cout << "4.School: " << ob->school << endl;
        cout << "5.Nationality: " << ob->nat << endl;
        cout << "6.Title: " << ob->title << endl;
        cout << "\nAny changes?(y/n)\n";
        cin >> ch;
        if (ch == 'n')
        {
                update(ob->uname);
                profile();
        }
        else if (ch == 'y')
        {
                cout << "Enter the field no. to which you want to make changes\n";

                cin >> op;
                switch (op)
                {
                case 1:

                        cout << "Enter name" << endl;

                        cin >> ob->name;
                        info();
                        break;
                case 2:

                        cout << "Enter age" << endl;

                        cin >> ob->age;
                        info();
                        break;
                case 3:

                        cout << "Enter password" << endl;

                        cin >> ob->pass;
                        info();
                        break;
                case 4:

                        cout << "Enter school" << endl;

                        cin >> ob->school;
                        info();
                        break;
                case 5:

                        cout << "Enter nationality" << endl;

                        cin >> ob->nat;
                        info();
                        break;
                case 6:

                        cout << "Enter title\n";

                        cin >> ob->title;
                        info();
                        break;
                default:

                        cout << "Wrong input";
                        getchar();
                        info();
                }
        }
        else
        {
                cout << "Work input";
                getchar();
                info();
        }
}
//section for leaderb() starts

struct node1
{
        int age;
        char name[20], uname[20], pass[20], title[20], school[20], nat[20];

        int score, zer, ten, twe, thi, fort, fif; //for playing record

        int strk, mxstrk; //for "achievement" section
        struct node1 *next;
};

struct node1 *current = NULL, *head = NULL;
void create(struct node *p)
{

        cout << p->name << endl;
        struct node1 *n_node = (struct node1 *)malloc(sizeof(struct node1));
        n_node->age = p->age;
        strcpy(n_node->name, p->name);
        strcpy(n_node->uname, p->uname);
        strcpy(n_node->pass, p->pass);
        strcpy(n_node->title, p->title);
        strcpy(n_node->school, p->school);
        strcpy(n_node->nat, p->nat);
        n_node->score = p->score;
        n_node->zer = p->zer;
        n_node->ten = p->ten;
        n_node->twe = p->twe;
        n_node->thi = p->thi;
        n_node->fort = p->fort;
        n_node->fif = p->fif;
        n_node->strk = p->strk;
        n_node->mxstrk = p->mxstrk;
        n_node->next = NULL;
        if (head == NULL)
        {
                head = n_node;
                current = n_node;
        }
        else
        {
                current->next = n_node;
                current = n_node;
        }
}

void sortll(struct node1 *first)
{
        struct node1 *new1 = first;
        struct node1 *count;
        for (; new1->next != NULL; new1 = new1->next)
        {
                for (count = new1->next; count != NULL; count = count->next)
                {
                        if ((50 * new1->fif + 40 * new1->fort + 30 * new1->thi + 20 * new1->twe + 10 * new1->ten) < (50 * count->fif + 40 * count->fort + 30 * count->thi + 20 * count->twe + 10 * count->ten))
                        {
                                int temp = new1->score;
                                new1->score = count->score;
                                count->score = temp;
                                temp = new1->age;
                                new1->age = count->age;
                                count->age = temp;
                                temp = new1->strk;
                                new1->strk = count->strk;
                                count->strk = temp;
                                temp = new1->mxstrk;
                                new1->mxstrk = count->mxstrk;
                                count->mxstrk = temp;
                                temp = new1->zer;
                                new1->zer = count->zer;
                                count->zer = temp;
                                temp = new1->ten;
                                new1->ten = count->ten;
                                count->ten = temp;
                                temp = new1->twe;
                                new1->twe = count->twe;
                                count->twe = temp;
                                temp = new1->thi;
                                new1->thi = count->thi;
                                count->thi = temp;
                                temp = new1->fort;
                                new1->fort = count->fort;
                                count->fort = temp;
                                temp = new1->fif;
                                new1->fif = count->fif;
                                count->fif = temp;
                                char tem[20];
                                strcpy(tem, new1->name);
                                strcpy(new1->name, count->name);
                                strcpy(count->name, tem);
                                strcpy(tem, new1->uname);
                                strcpy(new1->uname, count->uname);
                                strcpy(count->uname, tem);
                                strcpy(tem, new1->title);
                                strcpy(new1->title, count->title);
                                strcpy(count->title, tem);
                                strcpy(tem, new1->school);
                                strcpy(new1->school, count->school);
                                strcpy(count->school, tem);
                                strcpy(tem, new1->nat);
                                strcpy(new1->nat, count->nat);
                                strcpy(count->nat, tem);
                                strcpy(tem, new1->pass);
                                strcpy(new1->pass, count->pass);
                                strcpy(count->pass, tem);
                        }
                }
        }
}

void display(struct node1 *first)
{
        clr();
        struct node1 *nw = first;
        int i = 1;
        system("color 0B");
        cout << "\t\t\t\t      \xB3\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\   LEADERBOARD   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB3\n\n";
        cout << "\t\t\t\tRANK\tNAME\tSCORE\tAGE\tSCHOOL\t   NATIONALITY\n";
        cout << "\t\t\t\t----\t-----\t-----\t---\t------\t   -----------\n";
        while (nw)
        {

                cout << "\t\t\t\t" << i++ << "\t" << nw->name << "\t" << (50 * nw->fif + 40 * nw->fort + 30 * nw->thi + 20 * nw->twe + 10 * nw->ten) << "\t" << nw->age << "\t" << nw->school << "\t\t" << nw->nat <<endl;
                nw = nw->next;
        }
}

void leaderb()
{
        clr();

        FILE *fin = fopen("quiz.dat", "rb");
        fseek(fin, 0, SEEK_SET);
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        while (fread(tmp, sizeof(struct node), 1, fin))
        {
                create(tmp);
        }
        fclose(fin);
        sortll(head);
        display(head);
        head = NULL;
}

int main()
{
        start();
        return 0;
}
