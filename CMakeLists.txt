cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Command.h Interpreter.cpp Interpreter.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h DataReaderServer.cpp DataReaderServer.h Client.cpp Client.h Maps.cpp Maps.h PrintCommand.cpp PrintCommand.h VarCommand.cpp VarCommand.h SetCommand.cpp SetCommand.h GlobalNewSockfd.cpp GlobalNewSockfd.h EnterIfWhile.cpp EnterIfWhile.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Number.cpp Number.h Div.cpp Div.h BinaryExpression.cpp BinaryExpression.h ExpressionParser.cpp ExpressionParser.h GlobalMutex.cpp GlobalMutex.h IfWhileCommand.cpp IfWhileCommand.h GarbageVector.cpp GarbageVector.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")