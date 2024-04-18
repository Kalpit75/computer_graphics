#include<graphics.h>
int main()
{
	int width=GetSystemMetrics(SM_CXSCREEN);
	int height=GetSystemMetrics(SM_CYSCREEN);
	initwindow(width,height,"Color Fill Nepal Flag",WHITE);
   
	int Control_Box_Color=10;   // Light Green
	int Drawing_Color=15;       // white 
	
	// drawing 
	DRAWING:
	setcolor(LIGHTGRAY);

	//outer line form flag 
	line(100,10,100,700);
	line(100,700,800,700);
	line(800,700,800,10);
	line(800,10,100,10);

	// draw line to maek flag
    line(300,30,300,650);
    line(315,30,315,650);
    line(300,30,315,30);  //upper top
    line(300,650,315,650);  //lower bottom
    
    //create blue border of flag
    line(315,30,670,290);
    line(670,290,370,290);
    line(390,290,670,550);
    line(670,550,300,550);

    //inner blue line
    line(315,48,645,290);
    line(314,47,644,289);
    line(316,49,646,291); 
    line(630,278,358,278);
//    line(629,277,357,277);
//    line(631,279,359,279);
    line(358,278,630,535);
    line(357,277,629,534);
    line(359,279,631,536);
    line(653,535,315,535);
//    line(652,534,314,534);
//    line(654,536,316,536);
    //sun
    circle(415,440,40);
    //moon
    arc(415,205,180,0,40);
    arc(415,175,215,325,50);
    
    setcolor(15);
     
	setcolor(Control_Box_Color);
	rectangle(1100,20,1350,600);
	
	int Box_Dis=16;
	int Box_Width=216;
	int top_1=40;
	int left_1=1100+Box_Dis;
	int right_1=left_1+Box_Width;
	int bottom_1=90;

	int box_L_left=1100+Box_Dis;
	int box_L_top=40;
	int box_L_bottom=90;
	int box_L_right=left_1+Box_Width;
	int box_R_left=left_1+117;
	int box_R_top=top_1;
	int box_R_bottom=bottom_1;
	int box_R_right=right_1+117;
	
	setcolor(Drawing_Color);
	
	for(int i=0;i<5;i++,top_1+=80,bottom_1+=80)
	{
		rectangle(left_1,top_1,right_1,bottom_1);
	}
	
     
     // box colors
     
         setfillstyle(SOLID_FILL,BLUE);
         floodfill(box_L_left+20,box_L_top+20,15);
         
         setfillstyle(SOLID_FILL,GREEN);
         floodfill(box_L_left+20,box_L_top+20+80,15);    
         
         setfillstyle(SOLID_FILL,WHITE);
         floodfill(box_L_left+20,box_L_top+20+160,15);   
         
         setfillstyle(SOLID_FILL,RED);
         floodfill(box_L_left+20,box_L_top+20+240,15);   
         
         setfillstyle(SOLID_FILL,MAGENTA);
         floodfill(box_L_left+20,box_L_top+20+320,15);   
         
        
    // instruction
      setcolor(LIGHTGREEN);
       settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
       outtextxy(box_L_left,box_L_top+320+80,(char*)"---INSTRUTIONS---");
       setcolor(LIGHTBLUE);
       settextstyle(4,HORIZ_DIR,1);
       outtextxy(box_L_left,box_L_top+320+105,(char*)"ColorPick-'Rclick'");
       outtextxy(box_L_left+20,box_L_top+320+130,(char*)"Relaunch-'F1'");
       outtextxy(box_L_left+30,box_L_top+320+155,(char*)"Save-'Enter'");
       
  
    
   int Pick_Color=15;
    while(1)
    {
    	POINT cursor;
    	Start:
        	GetCursorPos(&cursor);
    //  color boxes
         // Blue box
		if(((cursor.x>=box_L_left) && (cursor.y>=box_L_top))&&((cursor.x<=box_L_right)&(cursor.y<=box_L_bottom)))
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			Pick_Color=1;
		}
		// Green box 
		if(((cursor.x>=box_L_left) && (cursor.y>=box_L_top+80))&&((cursor.x<=box_L_right)&(cursor.y<=box_L_bottom+80)))
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			Pick_Color=2;
		}	
		// cyan
		if(((cursor.x>=box_L_left) && (cursor.y>=box_L_top+160))&&((cursor.x<=box_L_right)&(cursor.y<=box_L_bottom+160)))
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			Pick_Color=15;
		}
		// RED
		if(((cursor.x>=box_L_left) && (cursor.y>=box_L_top+240))&&((cursor.x<=box_L_right)&(cursor.y<=box_L_bottom+240)))
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			Pick_Color=4;
		}
		// Magenta
		if(((cursor.x>=box_L_left) && (cursor.y>=box_L_top+320))&&((cursor.x<=box_L_right)&(cursor.y<=box_L_bottom+320)))
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			Pick_Color=5;
		}
		
		if(GetAsyncKeyState(VK_RETURN))
		{
			writeimagefile("img.jpg",0,0,1000,700);
		}
		if(GetAsyncKeyState(VK_F1))
		{
			cleardevice();
			delay(400);
			goto DRAWING;
		}
    	if(GetAsyncKeyState(VK_LBUTTON))
    	{
		    if(cursor.x >= 1000)
		    {
		    	goto Start;
			}
	        else
	    	{
    		setfillstyle(SOLID_FILL,Pick_Color);
    		floodfill(cursor.x,cursor.y,LIGHTGRAY);
        	}
		}
	}
	getch();
	closegraph();
}
