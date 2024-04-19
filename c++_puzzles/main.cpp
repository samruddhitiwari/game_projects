#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void selection_page();
 int width=1000,height=600,x_bar=5,y_bar=10;
#include "get_key.c"
#include  "puzzle.cpp"
#include  "snake.cpp"
#include "sudoku.cpp"
int bk;
int main()
{
    int ch=0;
    bool selection=false;
    int gd=0,gm;
    initgraph(&gd,&gm,"");


    initwindow(width,height,"Multi Game System",70,50,0);
    bk=COLOR(29, 103, 224);
     setbkcolor(bk);
     cleardevice();

      {

      settextstyle(8,0,4);
      rectangle(300,100,665,150);
      rectangle(305,105,660,145);
     outtextxy(312,110,"MULTI GAME SYSTEM");
      }

  selection_page();



      while(selection!=true)

         {


ch=getKey();
if(ch==13||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch==ESC)
           {
               if(ch==13)
               {
                   if(y_bar==10)
                     ch='1';
                   else if(y_bar==55)
                      ch='2';
                   else if(y_bar==100)
                       ch='3';
                   else
                         ch=ESC;
               }
               if(ch=='4')
                 ch=ESC;
               selection=true;

           }
           else
           {

               if(ch==DOWN||ch==RIGHT)

                  {
                      y_bar=y_bar+45;
                  if(y_bar>150)
                    y_bar=10;
                  }

                  else if(ch==UP||ch==LEFT)
                  {
                      y_bar=y_bar-45;
                  if(y_bar<10)
                    y_bar=145;
                  }

                   selection_page();


           }


    }


     switch(ch)
          {

          case '1':
                     closegraph();
                     puzzle_starter();

                   break;
          case '2':
                    closegraph();
                    snake_starter();

                    break;
            case '3':

                      closegraph();
                      sudoku_starter();
                      break;
            case ESC:
                       void end_msg();
                       cleardevice();
                          end_msg();
                       //getch();
                      exit(1);


          }



      closegraph();

      return 0;


}

void selection_page()
{
    outtextxy(100,300,"Select");

    setbkcolor(COLOR(106, 133, 160));
     setviewport(250,350,463,530,1);
     clearviewport();
    setbkcolor(COLOR(05,25,200));

     outtextxy(40,5,"1:Puzzle");
      outtextxy(40,50,"2:Snake ");
      outtextxy(40,95,"3:Suduko");
      outtextxy(40,140,"4:Exit  ");
      //bar(x_bar,y_bar,x_bar+30,y_bar+25);

      rectangle(x_bar,y_bar+7,x_bar+20,y_bar+13);
      line(x_bar+13,y_bar,x_bar+29,y_bar+10);
       line(x_bar+13,y_bar+20,x_bar+29,y_bar+10);
       line(x_bar+12,y_bar,x_bar+29,y_bar+10);
       line(x_bar+12,y_bar+20,x_bar+29,y_bar+10);


}


void end_msg()
{
         setviewport(0,0,840,500,1);
                       //outtextxy(10,100,"Thank you....");
                        outtextxy(20,100,"Created By: ");
                        //outtextxy(70,350,"Mohd Raghib");
                         readimagefile("mr_pic.jpg",50,250,160,350);
                         if(kbhit())
                         {
                             getch();

                         }
                         settextstyle(8,0,2);
                         outtextxy(50,370,"Mohd Raghib");


                         readimagefile("amir.jpg",350,250,470,350);
                         outtextxy(350,370,"Mohd Amir Usmani");

                         readimagefile("mucu.jpg",650,250,760,350);
                          outtextxy(650,370,"Mukkaram Azam");
                         getch();
                      // delay(1200);


}

