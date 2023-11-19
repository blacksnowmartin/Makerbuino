#include <Gamebuino.h>
Gamebuino gb;
[..]
void setup() {
  gb.begin();    // Initialize the *buino
  gb.titleScreen();
}  

void loop() {
  if (gb.update()) { // update screen etc
    [...]
    gb.display.setColor(GRAY);
 
    if (gb.buttons.pressed(BTN_UP)) { 
      gb.display.drawLine(x+4,y-1,x+4,0);  
      // check if the laser hit the alien ship
      hit = gb.collideRectRect(x+4,0,1,y-1, alienX,alienY,8,8);
    }
 
    if (hit) {
      gb.sound.playNote(40, 20, 0);
      gb.sound.playNote(10, 20, 0);
      gb.sound.playNote(30, 20, 0);
    }
  }
}
