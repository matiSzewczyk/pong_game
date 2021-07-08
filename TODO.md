[x] - We should change the resolution - "Windows doesn't like windows that are bigger than the desktop. This includes windows created with VideoMode::getDesktopMode(): with the window decorations (borders and titlebar) added, you end up with a window which is slightly bigger than the desktop."\n
[x] - Change the way the players are positioned so that they spawn\n
    on the very edge relative to the screen resolution.\n
[x] - Change the way the map bounds are created, to do that i need to pass the window and replace\n
    1080/1920 with window.getGlobalBounds(); (the current method doesn't work if someone uses a different res\n
    than FullHD\n
[x] - Need to add a score system\n
[ ] - Remove the warnings wherever we use window.getSize().\n
    It uses int's and we're setting the position of objects with sf::Vector2f.\n
[ ] - add some bonus memes to the map (white edges, line across the middle) [optional]\n
[ ] - A pause menu would be nice\n
[ ] - make the movement of the player impact the angle of the bounce, atm it only inverts it.\n
    Angle of bounce is ALWAYS 75.f.\n

