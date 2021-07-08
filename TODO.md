[x] - We should change the resolution - "Windows doesn't like windows that are bigger than the desktop.
    This includes windows created with VideoMode::getDesktopMode(): with the window decorations (borders and titlebar) added, you end up with a window which is slightly bigger than the desktop."  
[x] - Change the way the players are positioned so that they spawn
    on the very edge relative to the screen resolution.  
[x] - Change the way the map bounds are created, to do that i need to pass the window and replace
    1080/1920 with window.getGlobalBounds(); (the current method doesn't work if someone uses a different res
    than FullHD.  
[x] - Need to add a score system.  
[x] - Remove the warnings wherever we use window.getSize().  
[x] - Remove the warnings in switch/case within main.cpp.  
[ ] - add some bonus memes to the map (white edges, line across the middle) [optional].  
[ ] - A pause menu would be nice.  
[ ] - make the movement of the player impact the angle of the bounce, atm it only inverts it.
    Angle of bounce is ALWAYS 75.f.  

