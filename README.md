
#Trading Console Application
This C++ project is a trading simulation console application that utilizes various data structures for optimal performance on large datasets. It includes different trading algorithms, custom operators, and simulations of real-world trading scenarios. This project was developed while learning Object-Oriented Programming (OOP) and modular design.

#Features
OOP Design: The application is built using Object-Oriented Programming best practices.
Data Structures: Efficient use of vectors and sets to manage historical stock prices and optimize searches.
Trading Simulation: Includes random decision-making logic for realistic trading behavior (buy/sell actions).
Historical Data Handling: Manages and retrieves historical prices using multiple search and storage mechanisms.

#Requirements
C++ Compiler: A modern C++ compiler (e.g., g++, clang++).
#Build System: Visual Studio or Code::Blocks for project configuration.

#
How to Run
---------------------- Bash Commands -------------------
git clone https://github.com/your-username/trading-console-app.git
cd trading-console-app
g++ -o tradingApp main.cpp Bourse.cpp Date.cpp Trader.cpp -std=c++11
./tradingApp
----------------------------------------------------


Simulation Details
Trader Aleatoire: The trader randomly chooses between buying, selling, or doing nothing, based on stock data.
Historical Data: Prices are loaded from CSV files and stored using efficient data structures like sets and vectors.
Portfolio Management: Traders manage a portfolio of stocks and cash balance, with a focus on transaction limits per day.

See Presentation.PDF For more details 
