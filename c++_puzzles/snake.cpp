void select_level();
void logic();
void create_new_food();
void input();
void display();
void border();
void update_tail_cord();
void show_score();
void game_over();
int main();
int gd=0,gm,i;
int x,y,food_x,food_y,width_snk=850,height_snk=600,key,length=0;
int score,tail_x[100],tail_y[100],margin_x=30,margin_y=30;
int life=2,run=0,old_key,del=60,lvl;
int pause;
bool gameover=false;
void display_food();
void game_start();
void snake_starter()
{


    initgraph(&gd,&gm,"");


    initwindow(width_snk,height_snk,"Multi Game System (Snake_game)",50,50,0);

      setbkcolor(COLOR(217, 229, 249));
    cleardevice();
      settextstyle(8,0,4);
      setcolor(BLUE);
   outtextxy(100,100,"Select Level");
    select_level();
     settextstyle(8,0,2);
      setbkcolor(COLOR(84, 92, 104));
    cleardevice();

    setbkcolor(COLOR(34, 104, 226)); // background  color of view port
     border();
    game_start();


closegraph();

}

void game_start()
{
     x=width_snk/2;
    y=height_snk/2;

    create_new_food();

while(!gameover||life)
    {



        if(kbhit())
        {
          input();

        }
        if(key==32)
        {    pause=1;
            display();
        }
        display();
        logic();
          show_score();



    }
      settextstyle(8,0,5);
      cleardevice();
     outtextxy(300,250,"GAME OVER!");
       sprintf(str,"Score : %d",score);
       outtextxy(300,350,str);
       delay(1000);


}

void input()
{
       key=getKey();


}

void display()
{


 setviewport(margin_x,margin_y,(width_snk-margin_x),height_snk-margin_y,1);
     display_food();
     setfillstyle(1,4);
    circle(x,y,8); //Face
    floodfill(x,y,15);
    circle(x-3,y,2); //eyes
    circle(x+3,y,2);  //eyes
    setcolor(15);


     for(int k=1;k<length;k++)
     {
       setfillstyle(1,COLOR(161, 186, 24));
     circle(tail_x[k],tail_y[k],6);  //tail
     floodfill(tail_x[k],tail_y[k],15);

     }

    delay(del); //controls speed

    if(pause==1)
    {

        outtextxy(20,20,"Paused");
        if(getch()==32)
            {pause=1;

        outtextxy(20,40,"Press Arrow Keys to Resume");
            }
        else
             pause=0;

        display();


    }


    clearviewport();


}

void logic()
{
     int prev_x2,prev_y2;

           int prev_x=tail_x[1];
            int prev_y=tail_y[1];
            tail_x[1]=x;
            tail_y[1]=y;
for(int s=2;s<length;s++)
            {

                prev_x2=tail_x[s];
                prev_y2=tail_y[s];

                tail_x[s]=prev_x;
                tail_y[s]=prev_y;

                prev_x=prev_x2;

                prev_y=prev_y2;

            }




                switch(key)
                {

                case LEFT:
                             x=x-run;
                            break;

                case RIGHT:
                             x=x+run;

                              break;

                case UP:

                        y=y-run;

                        break;

                case DOWN:
                            y=y+run;
                            break;

                case ESC:
                        cleardevice();

                        outtextxy(300,300,"Thank you....");
                        delay(1200);

                        exit(1);
            }
              // end of switch







if(x<=(5)||y<=(5)||x>=(width_snk-margin_x-33)||y>=(height_snk-margin_y-33))
    {
      game_over();
     }


     for(int b=2;b<=length;b++)  //to check if head collapse with tail
     {
         if(tail_x[b]==x && tail_y[b]==y)
                game_over();

     }

if((x>=(food_x-10)&&x<=(food_x+10))&&(y<=(food_y+10)&&y>=(food_y-10))) //to check if food eaten
        {
            length++;
            if(length==1)
            {

            length=length+1;
            }
            score+=5;
            if(lvl==1&&score>75)
            {
                lvl=2;
                run=9;
              del=70;
            }
            if(lvl==2&&score>150)
            {
                lvl=3;
                run=10;
              del=60;

            }
            create_new_food();

        }

}
// end of logic function



void create_new_food()
{
    int min_x=margin_x+10,max_x=width_snk-margin_x-27;
    int min_y=margin_y+10,max_y=height_snk-margin_y-29;
      srand(time(NULL));
     food_x=rand()%(max_x-min_x)+min_x;
     food_y=rand()%(max_y-min_y)+min_y;
}
void display_food()
{
    int t=getcolor();

     setcolor(14);
     setfillstyle(1,15);
    circle(food_x,food_y,5);
     circle(food_x,food_y,2);
    setcolor(t);


}

void show_score()
{
    int t=getbkcolor(),t1=getcolor();
    char str[128];
    setbkcolor(8);

     setviewport(30,7,230,29,1);

    if(lvl==1)
    sprintf(str,"Level : Easy ");
    else if(lvl==2)
         sprintf(str,"Level : Medium ");
    else
    {
      clearviewport();
     sprintf(str,"Level: Hard ");
    }
   outtextxy(0,0,str);
     setbkcolor(0);
    setcolor(15);
    setviewport(width_snk-300,7,width_snk-50,30,1);


    sprintf(str,"Score: %d ",score);
 outtextxy(0,0,str);
    sprintf(str," Life: %d",life);
 outtextxy(130,0,str);
 setbkcolor(t);
 setcolor(t1);



}

void border()
{
  int t;
    // rectangle(margin_x-5,margin_y-5,width_snk-margin_x+3,height_snk-margin_y+3);
  //   rectangle(margin_x-2,margin_y-2,width_snk-margin_x,height_snk-margin_y);

      t=getbkcolor();

     setviewport(0,0,width_snk,height_snk,1);
     setbkcolor(COLOR(84, 92, 104));
     setcolor(WHITE);
     outtextxy(width_snk-200,height_snk-20,"Press ESC to Exit");
     setbkcolor(t);
}


void game_over()
{
    gameover=true;
     life--;
    if(life>=0)
     {

         key=' ';
          length=0;
         game_start();
     }


}

void select_level()
{
    int ch;
    static int y_crd=0;



    setviewport(300,150,600,400,1);

     outtextxy(5,5,"Easy  ");
     outtextxy(5,45,"Medium");
     outtextxy(5,85,"Hard ");
     rectangle(0,y_crd,150,y_crd+35);
     ch=getch();
     if(ch==13)
     {

         if(y_crd==0)
         {
              run=8;
              del=50;
              lvl=1;
         }
            else if(y_crd==40)
         {
               run=9;
              del=70;
              lvl=2;
         }
            else if(y_crd==80)
         {
           run=10;
              del=60;
              lvl=3;
         }
         return;

     }
     else
     {
         if(ch==DOWN||ch==RIGHT)

                  {
                      y_crd=y_crd+40;
                  if(y_crd>80)
                    y_crd=0;
                  }

                  else if(ch==UP||ch==LEFT)
                  {
                      y_crd=y_crd-40;
                  if(y_crd<0)
                    y_crd=80;
                  }
                  clearviewport();
                 select_level();
     }



}
