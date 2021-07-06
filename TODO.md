[x] - We should change the resolution - "Windows doesn't like windows that are bigger than the desktop. This includes windows created with VideoMode::getDesktopMode(): with the window decorations (borders and titlebar) added, you end up with a window which is slightly bigger than the desktop."
[ ] - Change the way the players are positioned so that they spawn
    on the very edge relative to the screen resolution.
[ ] - Change the way the map bounds are created, to do that i need to pass the window and replace
    1080/1920 with window.getGlobalBounds(); (the current method doesn't work if someone uses a different res
    than FullHD

