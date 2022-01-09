cmake_minimum_required(VERSION 3.21.3)

project (minigames)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/Template)
add_subdirectory(src/Menu)
add_subdirectory(src/InputValidation)
add_subdirectory(src/GameWelcome)
add_subdirectory(src/GameTicTacToe)
add_subdirectory(src/GameQuartzParchmentShears)
add_subdirectory(src/GameObject)
add_subdirectory(src/GameHangman)
add_subdirectory(src/GameGuessNumber)
add_subdirectory(src/ClassPlayer)

target_link_libraries(${PROJECT_NAME} 
                                    Template
                                    Menu
                                    InputValidation
                                    GameWelcome
                                    GameTicTacToe
                                    GameQuartzParchmentShears
                                    GameObject
                                    GameHangman
                                    GameGuessNumber
                                    ClassPlayer)
