/*
 * Handmade Hero by Casey
 * http://handmadehero.org
 *
 * Linux / OSX
 * http://davidgow.net/handmadepenguin/ch1.html
 * */

#include <SDL.h>
#include <stdio.h>

bool HandleEvent(SDL_Event *Event) {
  bool ShouldQuit = false;

  switch(Event->type) {
    case SDL_QUIT:
    {
      printf("SDL_QUIT\n");
      ShouldQuit = true;
    } break;

    case SDL_WINDOWEVENT:
    {
      switch(Event->window.event) {
        case SDL_WINDOWEVENT_RESIZED:
        {
          printf("SDL_WINDOWEVENT_RESIZED (%d, %d)\n",
                 Event->window.data1,
                 Event->window.data2);
        } break;

        case SDL_WINDOWEVENT_FOCUS_GAINED:
        {
          printf("SDL_WINDOWEVENT_FOCUS_GAINED\n");
        } break;

        case SDL_WINDOWEVENT_EXPOSED:
        {
          printf("Window exposed");
          SDL_Window *Window     = SDL_GetWindowFromID(Event->window.windowID);
          SDL_Renderer *Renderer = SDL_GetRenderer(Window);
          static bool isWhite    = true;

          if (isWhite == true) {
            SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
            isWhite = false;
          }
          else {
            SDL_SetRenderDrawColor(Renderer, 0 , 0, 0, 255);
            isWhite = true;
          }

          SDL_RenderClear(Renderer);
          SDL_RenderPresent(Renderer);
        } break;
      }
    } break;
  }

  return(ShouldQuit);
}

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *Window= SDL_CreateWindow("Handmade Hero",
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
                                       640,
                                       480,
                                       SDL_WINDOW_RESIZABLE);

  if (Window) {
    // Creates a "Renderer" for our window.
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, 0);

    if (Renderer) {
      // infinite loop
      for(;;) {
        SDL_Event Event;
        SDL_WaitEvent(&Event);
        if (HandleEvent(&Event)) {
          break;
        }
      }
    }
    else {
      // logging
    }
  }
  else {
    // logging
  }

  SDL_Quit();
  return 0;
}
