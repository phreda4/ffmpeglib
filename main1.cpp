#include <stdio.h>
#include <time.h>

#include "graf.h"
#include "video.h"

SDL_Event evt;

////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
char filename[64];
if (argc>1) { strcpy(filename,argv[1]); } else { strcpy(filename,"salud.mp4");}
	
//------------------------------------------------------------------------	
gr_init(filename,800,600,0);

av_register_all();
avformat_network_init();

//videoopen(filename,512,300);

int salida=0;
while (!salida) {
	
	SDL_PollEvent(&evt);
	switch (evt.type) {
	    case SDL_KEYDOWN:
	      switch(evt.key.keysym.sym) {
	    	case SDLK_F1: videoclose();break;
	    	case SDLK_F2: videoopen("ccc.mp4",512,300);break;
	    	case SDLK_F3: videoopen("Titanic.ts",512,300);break;
	    	case SDLK_F4: videoopen("bigbuckbunny_480x272.h265",512,300);break;
	    	case SDLK_F5: videoresize(700,500);break;
			case SDLK_F6: videoresize(512,500);break;	    	
	    	case SDLK_ESCAPE: salida=1;break;
			default:break;
      		}
      	  break;
		case SDL_QUIT:
			salida = 1;
			break;
		default:
			break;
		}
	SDL_Delay(10);		
	gr_cls(0);
	redrawframe(10,10);	// video
	gr_color1=0xff00;gr_line(10,450,600,40);
	gr_color1=0xff0000;gr_line(600,450,10,40);
	gr_redraw();
	}
	
videoclose();
gr_fin();
return 0;
}
