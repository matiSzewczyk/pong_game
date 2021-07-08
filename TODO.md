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
[x] - Add some bonus memes to the map (white edges, line across the middle) [optional].  
[x] - A pause menu would be nice.  
[x] - Add a sign letting the players know how to pause the game.  
[ ] - make the movement of the player impact the angle of the bounce, atm it only inverts it.
    Angle of bounce is ALWAYS 75.f.  
[ ] - textClass.cpp has a lot of the same code, we could compact this and make it
shorter, however, if we wanted to use one function to display all the different text,
as an example we'd be forced to pass score along with the pauseMenu object which
is not very nice, makes no sense. Splitting the funcions as they are now ensures
we only pass the objects/variables we need but again, code that could be is not reused.
SEND HELP  
[ ] - I added +25 to stuff like movement boundries instead of taking a more professional
approach and getting xMapPiece.getSize().y, but i can't be bothered OMEGALUL  
