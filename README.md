# Console Chess Game in C++

![image](https://github.com/JJ-Kira/Chess/assets/72421493/3502ea7c-9688-4796-989a-e8463e967a1c)

Welcome to the Console Chess Game, a 2-player chess program implemented in C++ that showcases Object-Oriented Programming (OOP) principles. Experience the classic game of chess with a simple and intuitive console interface, where strategic planning and execution lead to victory.

## Game Features

- **2-Player Mode**: Engage in a chess match against a friend in a turn-based system.
- **Unicode Chess Characters**: Enjoy a visually rich console experience with Unicode chess characters that represent each piece on the board.
- **Console-Based UI**: Simple and clean text-based interface for straightforward game visualization and move input.
- **OOP-Driven Design**: Carefully structured with C++ classes to encapsulate behavior and properties, promoting clean, maintainable, and reusable code.

## Technical Aspects

This project exemplifies several fundamental OOP concepts:

- **Inheritance**: The game pieces (e.g., `Bishop`, `King`) derive from the `Piece` class, enabling shared behavior and attributes while allowing for specific implementations.
- **Encapsulation**: Core components (`Board`, `Player`, `Square`) manage their state privately, offering controlled access through public member functions.
- **Abstraction**: `Piece` serves as an abstract base class, outlining a common interface for all concrete piece classes. This allows manipulation of all pieces through their common interface without concerning the underlying specifics.
- **Polymorphism**: Virtual functions provide the ability to override and offer specific implementations for piece movement, while interacting with pieces through base class pointers or references.
- **Modularity**: Each class is self-contained, with clear responsibilities, promoting a modular design that is easy to navigate and extend.

## Simplicity of Use

Playing the game is as simple as running the executable and entering moves in standard chess notation. The console handles all game rules and move validations, allowing players to focus on their strategies. The use of Unicode characters in the console creates an engaging board display that is both familiar and easy to read.

![image](https://github.com/JJ-Kira/Chess/assets/72421493/c34f8ab9-6967-4a01-86db-cf9c526a3b2d)

## How to Play

Players take turns to input moves using standard algebraic notation (e.g., `e2 e4`). The console verifies move legality according to the rules of chess.

![image](https://github.com/JJ-Kira/Chess/assets/72421493/9b783ca5-4e33-4f9d-9d58-35b9cd5f5dce)

### Starting the Game

Compile `main.cpp` with the provided class files and execute the binary. Ensure the console is appropriately sized to accommodate the board display.

### Making a Move

Input your move when prompted, and the game will handle the rest, including piece captures, turn tracking, and win detection.

![image](https://github.com/JJ-Kira/Chess/assets/72421493/a976c0fe-ab35-47ff-92d7-7700aa63f601)
