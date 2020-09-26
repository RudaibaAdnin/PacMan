#include "iGraphics.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int x=110,y=30,i,j,foodx,foody,mode=0,ghost_x1=110,ghost_y1=210,dx=4,dy=4,ghost_x2=510,ghost_y2=210,cnt=0;
int ghost1_flag1=1, ghost1_flag2=1,ghost1colorflag=1,ghost2colorflag=1;
int ghost3_flag1=1,ghost3_flag2=1,ghost3colorflag=1;
int ghost_x3=110,ghost_y3=210,center_x=30,center_y=30,ghost2_flag1=1;
int ghost2_flag2=1,level=1,highscore,score1=0,random_x,pacmanmouth=0;
int ghost_x4=435,ghost_y4=50,ghost4_flag1=1, ghost4_flag2=1,ghost4colorflag=1,score2=0,score,score3=0,score4=0;
int ghost1_flag3=1, ghost2_flag3=1,ghost3_flag3=1,ghost4_flag3=1;
char str[80],str2[80];

int a[8][8]=
{
    {0,1,1,1,1,1,1,0},
    {0,0,1,0,0,1,0,0},
    {0,1,1,1,1,1,1,0},
    {0,1,0,1,0,0,1,0},
    {1,1,0,1,0,0,1,1},
    {0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,1,0,1,1,0}
};// for drawing food

int b[8][8]=
{
    {0,1,1,1,1,1,1,0},
    {0,0,1,0,0,1,0,0},
    {0,1,1,1,1,1,1,0},
    {0,1,0,1,0,0,1,0},
    {1,1,0,1,0,0,1,1},
    {0,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,1,0},
    {0,1,1,1,0,1,1,0}
}; // for drawing maze

void drawfoodat()
{
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(a[i][j]==1)
            {
                iSetColor(255,255,255);
                foodx=((80+80*j)+80*j)/2;
                foody=((80+80*i)+80*i)/2;
                if(((foodx<=(x+30))&&(foodx>=(x-30)))&&((foody<=(y+30))&&(foody>=(y-30))))
                {
                    a[i][j]=0; // vanishing the food
                    cnt=cnt+10;
                    if(cnt>=350)
                    {
                        mode=4;
                    }



                    if((cnt>=200&&cnt<=250))
                    {
                        ghost1_flag1=0;
                        ghost1colorflag=0; // blue
                    }
                    else
                    {

                        ghost1_flag1=1;
                        ghost1colorflag=1;
                    }

                    if(cnt>=100&&cnt<=150)
                    {
                        ghost2_flag1=0;
                        ghost2colorflag=0;
                    }
                    else
                    {

                        ghost2_flag1=1;
                        ghost2colorflag=1;
                    }

                    if(cnt>=240&&cnt<=270)
                    {
                        ghost3_flag1=0;
                        ghost3colorflag=0;
                    }
                    else
                    {

                        ghost3_flag1=1;
                        ghost3colorflag=1;
                    }


                    if(cnt>=270&&cnt<=320)
                    {
                        ghost4_flag1=0;
                        ghost4colorflag=0;
                    }
                    else
                    {


                        ghost4_flag1=1;
                        ghost4colorflag=1;
                    }

                }
            }
            iFilledCircle(foodx,foody,10);
        }
    }
}


void highscoreat()
{


    FILE * fp;


    fp = fopen("highscore.txt", "r");

    while(!feof(fp))
    {
        fscanf(fp,"%d",&highscore);
    }

    fclose(fp);
    if(score>=highscore)
    {
        highscore=score;
        fp=fopen("highscore.txt","w"); // updating highscore
        fprintf(fp,"%d",cnt);// printing highscore
    }

    fclose(fp);
    itoa(highscore,str2,10); // converting highscore into a string


}







void drawmainscreenat()
{
    iSetColor(100,149,237);
    iFilledRectangle(0,0,1000,800);
}


void  drawpacmanat()
{

    if (pacmanmouth==0)
    {


        double xa[]= {x+5,x+30,x+30};
        double ya[]= {y,y+30,y-30};
        //iFilledCircle(x-10,y+10,5);
        iSetColor(200,255,0);
        iFilledCircle(x,y,30);
        iSetColor(0,0,0);


        iFilledPolygon(xa,ya,3);
        ////iFilledCircle(x+10,y+10,5);
        //iFilledEllipse(x,y-10,12,5);
    }
    if (pacmanmouth==1)
    {


        double xa[]= {x-5,x-30,x-30};
        double ya[]= {y,y+30,y-30};
        //iFilledCircle(x-10,y+10,5);
        iSetColor(200,255,0);
        iFilledCircle(x,y,30);
        iSetColor(0,0,0);


        iFilledPolygon(xa,ya,3);
        ////iFilledCircle(x+10,y+10,5);
        //iFilledEllipse(x,y-10,12,5);
    }
    if (pacmanmouth==2)
    {


        double xa[]= {x-5,x-30,x+30};
        double ya[]= {y,y+30,y+30};
        //iFilledCircle(x-10,y+10,5);
        iSetColor(200,255,0);
        iFilledCircle(x,y,30);
        iSetColor(0,0,0);


        iFilledPolygon(xa,ya,3);
        ////iFilledCircle(x+10,y+10,5);
        //iFilledEllipse(x,y-10,12,5);
    }
    if (pacmanmouth==3)
    {


        double xa[]= {x-5,x-30,x+30};
        double ya[]= {y,y-30,y-30};
        //iFilledCircle(x-10,y+10,5);
        iSetColor(200,255,0);
        iFilledCircle(x,y,30);
        iSetColor(0,0,0);


        iFilledPolygon(xa,ya,3);
        ////iFilledCircle(x+10,y+10,5);
        //iFilledEllipse(x,y-10,12,5);
    }
    if(ghost1_flag1==1&&ghost1_flag3==1)
    {
        if(((ghost_x1<=(x+40))&&(ghost_x1>=(x-40)))&&((ghost_y1<=(y+40))&&(ghost_y1>=(y-40))))
        {
            mode=2;
        }
    }
    if(ghost2_flag1==1&&ghost2_flag3==1)
    {
        if(((ghost_x2<=(x+40))&&(ghost_x2>=(x-40)))&&((ghost_y2<=(y+40))&&(ghost_y2>=(y-40))))
        {
            mode=2;
        }
    }


    if(ghost3_flag1==1&&ghost3_flag3==1)
    {
        if(((ghost_x3<=(x+40))&&(ghost_x3>=(x-40)))&&((ghost_y3<=(y+40))&&(ghost_y3>=(y-40))))
        {
            mode=2;
        }
    }
    if(ghost4_flag1==1&&ghost4_flag3==1)
    {
        if(((ghost_x4<=(x+40))&&(ghost_x4>=(x-40)))&&((ghost_y4<=(y+40))&&(ghost_y4>=(y-40))))
        {
            mode=2;
        }
    }


}

void drawghost1at()
{



    if(ghost1colorflag==1)
    {

        iSetColor(0,255,255);
        iFilledRectangle(ghost_x1-30,ghost_y1-35,60,30);
        iFilledCircle(ghost_x1,ghost_y1,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x1-15,ghost_y1+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x1+15,ghost_y1+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x1,ghost_y1-10,10,5);


    }
    if(ghost1colorflag==0)
    {
        iSetColor(0,0,255);
        iFilledRectangle(ghost_x1-30,ghost_y1-35,60,30);

        iFilledCircle(ghost_x1,ghost_y1,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x1-15,ghost_y1+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x1+15,ghost_y1+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x1,ghost_y1-10,10,5);


    }


}





void drawghost2at()
{
    if(ghost2colorflag==1)
    {

        iSetColor(130,220,245);
        iFilledRectangle(ghost_x2-30,ghost_y2-35,60,35);

        iFilledCircle(ghost_x2,ghost_y2,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x2-15,ghost_y2+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x2+15,ghost_y2+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x2,ghost_y2-10,10,5);


    }
    if(ghost2colorflag==0)
    {

        iSetColor(0,0,255);
        iFilledRectangle(ghost_x2-30,ghost_y2-35,60,35);


        iSetColor(0,0,255);
        iFilledCircle(ghost_x2,ghost_y2,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x2-15,ghost_y2+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x2+15,ghost_y2+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x2,ghost_y2-10,10,5);


    }


}

void drawghost4at()
{


    if(ghost4colorflag==1)
    {
        iSetColor(118,252,237);
        iFilledRectangle(ghost_x4-30,ghost_y4-35,60,35);

        iSetColor(118,252,237);
        iFilledCircle(ghost_x4,ghost_y4,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x4-15,ghost_y4+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x4+15,ghost_y4+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x4,ghost_y4-10,10,5);


    }
    if(ghost4colorflag==0)
    {
        iSetColor(0,0,255);
        iFilledRectangle(ghost_x4-30,ghost_y4-35,60,35);


        iSetColor(0,0,255);
        iFilledCircle(ghost_x4,ghost_y4,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x4-15,ghost_y4+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x4+15,ghost_y4+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x4,ghost_y4-10,10,5);

    }
}




void drawghost3at()
{



    if(ghost3colorflag==1)
    {

        iSetColor(118,252,237);
        iFilledRectangle(ghost_x3-30,ghost_y3-35,60,35);
        iSetColor(118,252,237);
        iFilledCircle(ghost_x3,ghost_y3,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x3-15,ghost_y3+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x3+15,ghost_y3+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x3,ghost_y3-10,10,5);


    }
    if(ghost3colorflag==0)
    {
        iSetColor(0,0,255);
        iFilledRectangle(ghost_x3-30,ghost_y3-35,60,35);


        iSetColor(0,0,255);
        iFilledCircle(ghost_x3,ghost_y3,30);

        iSetColor(0,0,0);
        iFilledCircle(ghost_x3-15,ghost_y3+10,5);
        iSetColor(0,0,0);
        iFilledCircle(ghost_x3+15,ghost_y3+10,5);
        iSetColor(0,0,0);
        iFilledEllipse(ghost_x3,ghost_y3-10,10,5);


    }


}

//void randomnumberat()
//{

//random_x=((rand())*1.0)/RAND_MAX;

//}

void drawmazeat()
{
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(b[i][j]==0)
            {
                iSetColor(72,118,255);
                iFilledRectangle(80*j,80*i,80,80);
            }
        }
    }
}

void iDraw()
{
    if(mode==0) // initialize window
    {
        iSetColor(255,192,203);
        iFilledRectangle(0,0,1000,800);
        iSetColor(255,0,0);
        iText(300,550,"THE PACMAN", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);
        iFilledRectangle(550,500,100,100);

        double xa[]= {600,600+35,600+35};
        double ya[]= {550,550-35,550+35};
        iSetColor(255,255,0);
        iFilledCircle(600,550,35);
        iSetColor(0,0,0);
        iFilledPolygon(xa,ya,3);
        iSetColor(0,0,255);

        iText(300,400,"MAIN MENU", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(70,240,"PRESS s TO START THE GAME.PRESS y TO QUIT THE GAME", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(70,190,"PRESS h TO SEE HIGHSCORE", GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(mode==3) // highscore
    {
        iSetColor(131,252,237);
        iFilledRectangle(0,0,1000,800);
        iSetColor(255,0,0);
        iText(300,500,"THE PACMAN", GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,0,0);
        iText(300,240,"HIGHSCORE", GLUT_BITMAP_TIMES_ROMAN_24);
        highscoreat();
        iText(500,240,str2, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(300,150,"PRESS s TO START THE GAME", GLUT_BITMAP_TIMES_ROMAN_24);



    }


    if(mode==1) // game start
    {
        iClear();
        drawfoodat();
        drawpacmanat();
        drawmazeat();
        if(((ghost_x1<=(x+40))&&(ghost_x1>=(x-40)))&&((ghost_y1<=(y+40))&&(ghost_y1>=(y-40)))&&ghost1_flag1==0)
        {

            score1=20;
            ghost1_flag2=0;
            ghost1_flag3=2;



        }
        if(ghost1_flag2==1)
        {
            drawghost1at();


        }
        if(((ghost_x2<=(x+40))&&(ghost_x2>=(x-40)))&&((ghost_y2<=(y+40))&&(ghost_y2>=(y-40)))&&ghost2_flag1==0)
        {

            score2=20;
            ghost2_flag2=0;
            ghost2_flag3=2;

        }
        if(ghost2_flag2==1)
        {
            drawghost2at();
        }
        if(((ghost_x3<=(x+40))&&(ghost_x3>=(x-40)))&&((ghost_y3<=(y+40))&&(ghost_y3>=(y-40)))&&ghost3_flag1==0)
        {

            score3=50;
            ghost3_flag2=0;
            ghost3_flag3=2;


        }
        if(ghost3_flag2==1)
        {
            drawghost3at();
        }
        if(((ghost_x4<=(x+40))&&(ghost_x4>=(x-40)))&&((ghost_y4<=(y+40))&&(ghost_y4>=(y-40)))&&ghost4_flag1==0)
        {

            score4=50;
            ghost4_flag2=0;
            ghost4_flag3=2;


        }
        if(ghost4_flag2==1)
        {
            drawghost4at();

        }

        score=cnt+score1+score2+score3+score4; //various score for eating the ghosts
        itoa(score,str,10);

        highscoreat();//calling the highscore function
        iSetColor(255,218,185);
        iFilledRectangle(640,0,300,650);
        iSetColor(0,0,205);

        iText(650,600,"POINT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(750,600,str,GLUT_BITMAP_TIMES_ROMAN_24) ;
        iText(650,500,"THE PACMAN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(650,450,"GHOST",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(650,400,"YOU CAN EAT THE GHOST",GLUT_BITMAP_HELVETICA_12);
        iText(650,350,"WHEN IT TURNS BLUE",GLUT_BITMAP_HELVETICA_12);
        iText(650,300,"PRESS y TO QUIT",GLUT_BITMAP_HELVETICA_12);
        iText(650,250,"Press h TO SEE HIGHSCORE",GLUT_BITMAP_HELVETICA_12);
        iSetColor(0,0,0);
        iFilledRectangle(670,75,160,150);
        iSetColor(255,255,0);
        iFilledCircle(745,150,65);

        double xa[]= {745,745+65,745+65};
        double ya[]= {150,150+65,150-65};


        iSetColor(0,0,0);
        iFilledPolygon(xa,ya,3);







    }
    if(mode==2) // game over
    {
        drawmainscreenat();
        iSetColor(200,0,0);
        iText(300,550,"THE PACMAN",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);
        iFilledRectangle(550,500,100,100);
        double xa[]= {600,600+35,600+35};
        double ya[]= {550,550-35,550+35};
        iSetColor(255,255,0);
        iFilledCircle(600,550,35);
        iSetColor(0,0,0);
        iFilledPolygon(xa,ya,3);
        iSetColor(0,0,255);



        iText(100,320,"GAME OVER.DO YOU WANT TO QUIT?",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,250,"PRESS 'Y' THEN",GLUT_BITMAP_TIMES_ROMAN_24);
        //highscoreat();
        iText(100,200,"HIGHSCORE",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(270,200,str2,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(100,100,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(270,100,str,GLUT_BITMAP_TIMES_ROMAN_24);



    }
    if(mode==4) // wining
    {
        drawmainscreenat();
        iSetColor(200,0,0);
        iText(270,320,"YOU WIN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(270,240,"DO YOU WANT TO PLAY LEVEL TWO?",GLUT_BITMAP_TIMES_ROMAN_24);


    }




}


void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

void iKeyboard(unsigned char key)
{

    if(key == 'h')
    {
        mode=3;
    }

    if(key == 's')
    {
        mode=1;
    }

    if(key == 'y')
    {
        exit (0);
    }


}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)

    {
        pacmanmouth=1;
        x-=5;
        if(x<80+center_x&&y<320)
        {
            x=80+center_x;
        }
        if(x<80+center_x&&y>400)
        {
            x=80+center_x;
        }
        if(x<160+center_x&&(y>80&&y<160))
        {
            x=160+center_x;
        }
        if((x>=320&&x<=400+center_x)&&(y>=80&&y<=160))
        {
            x=400+center_x;

        }
        if((x<=240+center_x&&x>=160)&&(y>=240&&y<=400))
        {
            x=240+center_x;
        }
        if((x>=400&&x<=480+center_x)&&(y>=240&&y<=400))
        {
            x=480+center_x;
        }
        if((x>=320&&x<=400+center_x)&&(y>=560&&y<=640))
        {
            x=400+center_x;
        }
        if((x>=320&&x<=400+center_x)&&(y>=80&&y<=160))
        {
            x=400+center_x;
        }
        if((x>=400&&x<=480+center_x)&&(y>=480&&y<=560))
        {
            x=480+center_x;
        }
        if((x<=0+center_x)&&(y>=320&&y<=400))
        {
            x=0+center_x;
        }






    }
    if(key == GLUT_KEY_RIGHT)
    {
        pacmanmouth=0;
        x+=5;
        if(x>=560-center_x&&y<=320)
        {
            x=560-center_x;
        }
        if(x>=560-center_x&&y>=400)
        {
            x=560-center_x;
        }

        if(x>=560-center_x&&y>=400)
        {
            x=560-center_x;
        }
        if((x>=240-center_x&&x<=320)&&(y>=80&&y<=160))
        {
            x=240-center_x;
        }
        if((x>=480-center_x&&x<=560)&&(y>=80&&y<=160))
        {
            x=480-center_x;
        }
        if((x>=160-center_x&&x<=240)&&(y>=240&&y<=400))
        {
            x=160-center_x;
        }

        if((x>=320-center_x&&x<=400)&&(y>=560&&y<=640))
        {
            x=320-center_x;
        }
        if((x>=320-center_x&&x<=400)&&(y>=240&&y<=400))
        {
            x=320-center_x;
        }


        if((x>=160-center_x&&x<=240)&&(y>=480&&y<=560))
        {
            x=160-center_x;
        }
        if((x>=640-center_x)&&(y>=320&&y<=400))
        {
            x=640-center_x;
        }






    }
    if(key == GLUT_KEY_UP)
    {

        pacmanmouth=2;
        y+=5;
        if(x<160&&(y>=80-center_y&&y<=160))
        {
            y=80-center_y;
        }
        if((x<=240&&x>=160)&&(y>=240-center_y&&y<=320))
        {
            y=240-center_y;
        }
        if((x<=480&&x>=160)&&(y>=480-center_y&&y<=560))
        {
            y=480-center_y;
        }
        if((x>=480&&x<=560)&&(y>=80-center_y&&y<=160))
        {
            y=80-center_y;
        }

        if((x>=320&&x<=480)&&(y>=240-center_y&&y<=400))
        {
            y=240-center_y;
        }

        if((x>=240&&x<=400)&&(y>=80-center_y&&y<=160))
        {
            y=80-center_y;
        }
        if((x>=80&&x<=560)&&(y>=640-center_y))
        {
            y=640-center_y;
        }
        if((x<=80&&x>=0)&&(y>=400-center_y&&y<=480))
        {
            y=400-center_y;
        }
        if((x>=560&&x<=640)&&(y>=400-center_y&&y<=480))
        {
            y=400-center_y;
        }









    }
    if(key == GLUT_KEY_DOWN)
    {
        pacmanmouth=3;
        y-=5;
        if((x>=160&&x<=320)&&(y>=480&&y<=560+center_y))
        {
            y=560+center_y;
        }
        if((x>=400&&x<=480)&&(y>=480&&y<=560+center_y))
        {
            y=560+center_y;
        }



        if((x>=160&&x<=240)&&(y>=320&&y<=400+center_y))
        {
            y=400+center_y;
        }
        if((x>=80&&x<=160)&&(y>=80&&y<=160+center_y))
        {
            y=160+center_y;
        }
        if((x>=320&&x<=480)&&(y>=240&&y<=400+center_y))
        {
            y=400+center_y;
        }
        if((x>=240&&x<=400)&&(y>=80&&y<=160+center_y))
        {
            y=160+center_y;
        }

        if((x>=480&&x<=560)&&(y>=80&&y<=160+center_y))
        {
            y=160+center_y;
        }
        if((x>=560&&x<=640)&&(y>=240&&y<=320+center_y))
        {
            y=320+center_y;
        }

        if((x>=0&&x<=80)&&(y>=240&&y<=320+center_y))
        {
            y=320+center_y;
        }
        if((x>=80&&x<=560)&&(y<=0+center_y))
        {
            y=0+center_y;
        }




    }
}

void ghostmove1()
{
    ghost_x1 = 110;
    ghost_y1 += dy;


    //if(ghost_x1 >120 || ghost_x1 < 80)dx = -dx;
    if(ghost_y1 > 640 || ghost_y1 < 200)dy = -dy;

}
void ghostmove2()
{
    ghost_x2 = 510;
    ghost_y2 += dy;


    // if(ghost_x2 >500 || ghost_x2 < 520)dx = -dx;
    if(ghost_y2 > 640 || ghost_y2 < 200)dy = -dy;

}


void ghostmove3()
{


    if(ghost_x3<=510&&ghost_y3<=210)
    {
        ghost_x3+=5;
    }
    if(ghost_x3>=510)
    {

        ghost_y3+=5;
    }
    if(ghost_y3>=440)

    {
        ghost_x3-=5;

    }



    if(ghost_x3<=110)
    {
        ghost_y3-=5;


    }
}
void ghostmove4()
{

    if(ghost_x4<=435&&ghost_y4<=40)
    {
        ghost_x4+=5;
    }
    if(ghost_x4>=435)
    {

        ghost_y4+=5;
    }
    if(ghost_y4>=200)

    {
        ghost_x4-=5;

    }
    if(ghost_x4<=200)
    {
        ghost_y4-=5;
    }

}
int main()
{


    iSetTimer(100,ghostmove3);
    iSetTimer(100,ghostmove1);
    iSetTimer(100,ghostmove2);
    iSetTimer(100,ghostmove4);
    PlaySound("pacman_beginning.wav", NULL, SND_ASYNC | SND_LOOP);
    iInitialize(850,640, "Pacman");
    return 0;
}


